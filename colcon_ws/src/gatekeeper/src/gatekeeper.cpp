/* gatekeeper.cpp
 *
 * this file listens to sensor messages, 
 * builds an octomap of the world
 * and listens to extended trajectories
 * if they are safe, it republishes them as committed trajectories
 */


#include "gatekeeper/gatekeeper.hpp"

namespace gatekeeper {


Gatekeeper::Gatekeeper()
  : Node("gatekeeper")
{

  // initialize pubs and subs
  
  m_pointCloudSub = this->create_subscription<sensor_msgs::msg::PointCloud2>("/camera/points", 10, 
      std::bind(&Gatekeeper::cloud_callback, this, ph::_1));

  m_nominalTrajSub = this->create_subscription<dasc_msgs::msg::QuadTrajectory>("/nominal_trajectory", 10, 
      std::bind(&Gatekeeper::nominalTraj_callback, this, ph::_1));
  
  m_buffer_ = std::make_unique<tf2_ros::Buffer>(this->get_clock());
  m_tf_listener = std::make_unique<tf2_ros::TransformListener>(*m_buffer_);
  occupied_pcl_pub_ = this->create_publisher<sensor_msgs::msg::PointCloud2>("/occupied_octomap", 2);
  free_pcl_pub_ = this->create_publisher<sensor_msgs::msg::PointCloud2>("/free_octomap", 2);
  m_committedTrajPub = this->create_publisher<dasc_msgs::msg::QuadTrajectory>("/committed_trajectory", 10);

  pub_timer_ = this->create_wall_timer(500ms,
      std::bind(&Gatekeeper::publish_occupied_pcl, this));


  // initialize octomap
  m_octree = std::make_shared<OcTreeT>(m_res);
  m_octree->setProbHit(probHit);
  m_octree->setProbMiss(probMiss);
  m_octree->setClampingThresMin(thresMin);
  m_octree->setClampingThresMax(thresMax);

  // preinitialize the set of free space
  assume_free_space();

  // initialize filters
  pass_x.setFilterFieldName("x");
  pass_y.setFilterFieldName("y");
  pass_z.setFilterFieldName("z");
  
  pass_x.setFilterLimits(numMin, numMax);
  pass_y.setFilterLimits(numMin, numMax);
  pass_z.setFilterLimits(numMin, numMax);
}

void Gatekeeper::assume_free_space(){


  RCLCPP_INFO(this->get_logger(), "here");
  for (double x = -2.0; x <= 2.0; x += 0.05){
    for (double y = -2.0; y <= 2.0; y += 0.05){
      for (double z = 0.0; z <= 2.0; z += 0.05){

        m_octree->updateNode(x,y,z,(float)-0.9,true);
      }
    }
  }
  m_octree->updateInnerOccupancy();

  RCLCPP_INFO(this->get_logger(), "here");

}


void Gatekeeper::cloud_callback(
  const sensor_msgs::msg::PointCloud2::SharedPtr msg)
{

  auto start = std::chrono::steady_clock::now();


  // convert ros msg into pcl
  PCLPointCloud pc;
  pcl::fromROSMsg(*msg, pc);


  // transform pcl to the world frame
  geometry_msgs::msg::TransformStamped sensorToWorldTf;
  
  std::string fromFrameRel = msg->header.frame_id;
  std::string toFrameRel = "world";

  try {
    sensorToWorldTf = m_buffer_->lookupTransform(
            toFrameRel, fromFrameRel,
            tf2::TimePointZero);
  } catch (tf2::TransformException & ex) {
          RCLCPP_INFO(
            this->get_logger(), "Could not transform %s to %s: %s",
            toFrameRel.c_str(), fromFrameRel.c_str(), ex.what());
          return;
  }

  Eigen::Matrix4f sensorToWorld = pcl_ros::transformAsMatrix(sensorToWorldTf);

  
  // directly transform to map frame:
  pcl::transformPointCloud(pc, pc, sensorToWorld);
  
  // filter the points
  //pass_x.setInputCloud(pc.makeShared());
  //pass_x.filter(pc);
  //pass_y.setInputCloud(pc.makeShared());
  //pass_y.filter(pc);
  //pass_z.setInputCloud(pc.makeShared());
  //pass_z.filter(pc);
  
  // naive implementation of z filter
  //PCLPointCloud filtered;
  //for (const auto & point : pc.points){
  //  if (point.z > numMin && point.z < numMax){
  //    filtered.push_back(point);
  //  }
  //}

  // downsample pointcloud
  pcl::VoxelGrid<PCLPoint> vox;
  vox.setInputCloud(pc.makeShared());
  vox.setLeafSize(0.1, 0.1, 0.1);
  vox.filter(pc);


  insertScan(sensorToWorldTf.transform.translation, pc);
  
  auto end = std::chrono::steady_clock::now();
  std::chrono::duration<double, std::milli> elapsed_ms = end - start;

  RCLCPP_INFO(this->get_logger(), "PointCloudInsertion: %f ms, octree_size: %zu", elapsed_ms.count(), m_octree->size());
}

void Gatekeeper::nominalTraj_callback(const dasc_msgs::msg::QuadTrajectory::SharedPtr nom_msg){
 

  int maxI = -1;

  // check if the trajectory is in unoccupied space
  for (size_t i=0; i < nom_msg->ts.size(); i++){


    RCLCPP_INFO(this->get_logger(), "checking point %f, %f, %f", 
        nom_msg->xs[i],
        nom_msg->ys[i],
        nom_msg->zs[i]);

    auto node = m_octree->search(
        nom_msg->xs[i],
        nom_msg->ys[i],
        nom_msg->zs[i]);

    if (node == nullptr){
      // in free space, return
      RCLCPP_INFO(this->get_logger(), "this node is unknown");
      maxI = i-1;
      break;
    }
    
    bool occ = m_octree->isNodeOccupied(node);
    if (occ) {
      RCLCPP_INFO(this->get_logger(), "this node is occupied");
      maxI = i-1;
      break;
    }

  }

  // if we got to here, all nodes are known and 

  RCLCPP_INFO(this->get_logger(),"Republishing Nominal Traj");

  dasc_msgs::msg::QuadTrajectory com_msg;
  com_msg.header = nom_msg->header;
  for (size_t i =0; i < maxI; i++){
    com_msg.ts.push_back(nom_msg->ts[i]);
    com_msg.xs.push_back(nom_msg->xs[i]);
    com_msg.ys.push_back(nom_msg->ys[i]);
    com_msg.zs.push_back(nom_msg->zs[i]);
    com_msg.vxs.push_back(nom_msg->vxs[i]);
    com_msg.vys.push_back(nom_msg->vys[i]);
    com_msg.vzs.push_back(nom_msg->vzs[i]);
    com_msg.yaws.push_back(nom_msg->yaws[i]);
  }

  m_committedTrajPub -> publish(com_msg);

}


void Gatekeeper::insertScan( const geometry_msgs::msg::Vector3 &sensorOrigin,
  const PCLPointCloud& pc)
{


  // make an octomap pointcloud
  octomap::Pointcloud octomap_pc;

  octomap_pc.reserve(pc.size());

  for (auto it = pc.begin(); it != pc.end(); ++it){
    octomap_pc.push_back(it->x, it->y, it->z);
  }


  // call the octomap insert method
  octomap::point3d origin (sensorOrigin.x, sensorOrigin.y, sensorOrigin.z);

  auto start = std::chrono::steady_clock::now();

  m_octree->insertPointCloud(octomap_pc, origin, m_maxRange);

  auto end = std::chrono::steady_clock::now();
  std::chrono::duration<double, std::milli> elapsed_ms = end - start;

  //RCLCPP_INFO(this->get_logger(), "insert(): %f ms", elapsed_ms.count());

  // prune map
  m_octree->prune();

}


void Gatekeeper::publish_occupied_pcl() {

  // on a timer-callback, we collect the current octomap and republish it

  // if there is no data, dont publish
  if (m_octree->size() < 1) {
    RCLCPP_WARN(this->get_logger(), "No points in octree - not publishing pcl yet...");
    return;
  }

  PCLPointCloud pc;
  for (auto it = m_octree->begin(m_maxTreeDepth), end=m_octree->end(); it!=end; ++it) {
    if (m_octree->isNodeOccupied(*it)){
        PCLPoint p (it.getX(), it.getY(), it.getZ());
        pc.push_back(p);
    }
  }

  // convert to ROS msg
  sensor_msgs::msg::PointCloud2 msg;
  
  pcl::toROSMsg(pc, msg);

  msg.header.stamp = this->get_clock()->now();
  msg.header.frame_id = "world";

  occupied_pcl_pub_->publish(msg);

}


void Gatekeeper::publish_free_pcl() {

  // on a timer-callback, we collect the current octomap and republish it

  // if there is no data, dont publish
  if (m_octree->size() < 1) {
    RCLCPP_WARN(this->get_logger(), "No points in octree - not publishing pcl yet...");
    return;
  }

  PCLPointCloud pc;
  for (auto it = m_octree->begin(m_maxTreeDepth), end=m_octree->end(); it!=end; ++it) {
    if (! (m_octree-> isNodeOccupied(*it))){
        PCLPoint p (it.getX(), it.getY(), it.getZ());
        pc.push_back(p);
    }
  }

  // convert to ROS msg
  sensor_msgs::msg::PointCloud2 msg;
  
  pcl::toROSMsg(pc, msg);

  msg.header.stamp = this->get_clock()->now();
  msg.header.frame_id = "world";

  free_pcl_pub_->publish(msg);

}



} // namespace gatekeeper


int main(int argc, char**argv){

  rclcpp::init(argc, argv);

  auto node = std::make_shared<gatekeeper::Gatekeeper>();
  rclcpp::spin(node);

  rclcpp::shutdown();

}
