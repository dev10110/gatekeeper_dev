#pragma once
#ifndef _GATEKEEPER_
#define _GATEKEEPER_

#include <chrono>

#include <rclcpp/rclcpp.hpp>

#include <geometry_msgs/msg/vector3.hpp>
#include <sensor_msgs/msg/point_cloud2.hpp>
#include <dasc_msgs/msg/quad_trajectory.hpp>

#include <octomap/octomap.h>
#include <pcl/point_types.h>
#include <pcl/filters/passthrough.h>
#include <pcl/filters/voxel_grid.h>
#include <pcl/common/transforms.h>
#include <pcl_conversions/pcl_conversions.h>

#include <tf2/exceptions.h>
#include <tf2_ros/transform_listener.h>
#include <tf2_ros/buffer.h>

#include "gatekeeper/transforms.hpp"

using PCLPoint = pcl::PointXYZ;
using PCLPointCloud = pcl::PointCloud<PCLPoint>;
using OcTreeT = octomap::OcTree;

namespace ph = std::placeholders;

using namespace std::chrono_literals;

namespace gatekeeper {


class Gatekeeper : public rclcpp::Node {

  protected:

    // rclcpp
    rclcpp::Subscription<sensor_msgs::msg::PointCloud2>::SharedPtr m_pointCloudSub;
    rclcpp::Subscription<dasc_msgs::msg::QuadTrajectory>::SharedPtr m_nominalTrajSub;
    rclcpp::Publisher<dasc_msgs::msg::QuadTrajectory>::SharedPtr m_committedTrajPub;

    std::shared_ptr<tf2_ros::Buffer> m_buffer_;
    std::shared_ptr<tf2_ros::TransformListener> m_tf_listener;
    rclcpp::Publisher<sensor_msgs::msg::PointCloud2>::SharedPtr occupied_pcl_pub_;
    rclcpp::Publisher<sensor_msgs::msg::PointCloud2>::SharedPtr free_pcl_pub_;
    rclcpp::TimerBase::SharedPtr pub_timer_;

    // octree
    std::shared_ptr<OcTreeT> m_octree;

    // pcl
    pcl::PassThrough<PCLPoint> pass_x, pass_y, pass_z;

    // parameters
    double m_res = 0.05;
    double m_treeDepth = 16;
    double m_maxTreeDepth = 16;
    double m_maxRange = 3.0;
    double probHit = 0.7;
    double probMiss = 0.4;
    double thresMin = 0.12;
    double thresMax = 0.97;
    double numMax = std::numeric_limits<double>::max();
    double numMin = -std::numeric_limits<double>::max();

    std::string m_worldFrameId = "world";
    

    // functions
    void insertScan(
        const geometry_msgs::msg::Vector3 &sensorOrigin,
        const PCLPointCloud& pc);

    void cloud_callback(
        const sensor_msgs::msg::PointCloud2::SharedPtr msg);
   
    void nominalTraj_callback(
		   const dasc_msgs::msg::QuadTrajectory::SharedPtr msg);

    void publish_occupied_pcl();
    void publish_free_pcl();
    void assume_free_space();

 public:
   Gatekeeper();   

};




} // namespace gatekeeper


#endif // _GATEKEEPER_
