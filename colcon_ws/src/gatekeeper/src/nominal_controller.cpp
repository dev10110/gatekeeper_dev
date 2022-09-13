#include <chrono>
#include <functional>
#include <memory>

#include <rclcpp/rclcpp.hpp>
#include <sensor_msgs/msg/joy.hpp>
#include <dasc_msgs/msg/quad_trajectory.hpp>
#include <builtin_interfaces/msg/time.hpp>
#include <geometry_msgs/msg/point.hpp>
#include <visualization_msgs/msg/marker_array.hpp>

#include <tf2/exceptions.h>
#include <tf2_ros/transform_listener.h>
#include <tf2_ros/buffer.h>


/* nominal_controller.cpp
 * 
 * this file subscribes to the joystick, and the quadrotors current position. 
 * based on the joystick commands, it proposes flying at some speed in the direction commanded by the joysticks.'
 *
 */


using namespace std::chrono_literals;
using namespace std::placeholders;

class NominalController : public rclcpp::Node
{
  public:
  NominalController() 
    : Node("nominal_controller")
  {

    start_time = this->get_clock()->now();

    traj_pub_ = this->create_publisher<dasc_msgs::msg::QuadTrajectory>("/nominal_trajectory", 10);
    
    //joy_sub_ = this->create_subscription<sensor_msgs::msg::Joy>("/joy", 10, 
    //    std::bind(&NominalController::joy_callback, this, _1));

    // initialize the listener
    //tf_buffer_ = std::make_unique<tf2_ros::Buffer>(this->get_clock());
    //transform_listener_ = std::make_shared<tf2_ros::TransformListener>(*tf_buffer_);

    timer_ = this->create_wall_timer(1000ms,
        std::bind(&NominalController::timer_callback, this));
    

    marker_pub_ = this->create_publisher<visualization_msgs::msg::MarkerArray>("nominal_traj", 10);

    publish_one_trajectory();

  }


  private:

  // messages from tf
  double last_x = 0;
  double last_y = 0;
  double last_z = 0;
  double last_yaw = 0;

  // targets
  
  double target_x = 0.0;
  double target_y = 0.0;
  double target_z = 1.0;
  double target_yaw = 0.0;

  // commands from joystick
  //double vx;
  //double vy;
  //double vz;
  //double yaw_rate;

  // rclcpp
  rclcpp::TimerBase::SharedPtr timer_;
  // rclcpp::Subscription<sensor_msgs::msg::Joy>::SharedPtr joy_sub_{nullptr};
  rclcpp::Publisher<dasc_msgs::msg::QuadTrajectory>::SharedPtr traj_pub_{nullptr};
  std::shared_ptr<tf2_ros::TransformListener> transform_listener_{nullptr};
  std::unique_ptr<tf2_ros::Buffer> tf_buffer_;
  rclcpp::Publisher<visualization_msgs::msg::MarkerArray>::SharedPtr marker_pub_;

  builtin_interfaces::msg::Time last_tf_stamp;
  builtin_interfaces::msg::Time start_time;


  double clampToPi(double yaw){
    return std::atan2(std::sin(yaw), std::cos(yaw));
    return yaw;
  }


  void publish_one_trajectory() {

    // construct the desired trajectory
    dasc_msgs::msg::QuadTrajectory msg = dasc_msgs::msg::QuadTrajectory();
    
    msg.header.stamp = start_time;
    msg.header.frame_id = "world";

    double dt = 0.01;
    double T = 15.0;

    double t= 0.0;
    double x = 0.0;
    double vx = 0.5;

    double R = 0.5;

    // first T seconds spin around
    while (true){
      double th =  2.0 * M_PI * t / T;

      msg.ts.push_back(t);
      msg.xs.push_back(0.0); // R * std::cos(th) - R);
      msg.ys.push_back(0.0); // R * std::sin(th) );
      msg.zs.push_back(1.0);
      msg.vxs.push_back(0.0);
      msg.vys.push_back(0.0);
      msg.vzs.push_back(0.0);
      msg.yaws.push_back(th);

      t += dt;
      x += vx * dt;
      if (t > T) break;
    }
    
    // next T seconds go forward
    while (true) {
       double f=  (t - T) / T;

      msg.ts.push_back(t);
      msg.xs.push_back(3*f); // R * std::cos(th) - R);
      msg.ys.push_back(0.0); // R * std::sin(th) );
      msg.zs.push_back(1.0);
      msg.vxs.push_back(0.0);
      msg.vys.push_back(0.0);
      msg.vzs.push_back(0.0);
      msg.yaws.push_back(0.0);

      t += dt;
      x += vx * dt;

      if (f > 1) break;
    }
    // next 5 seconds go forward
    while (true) {
       double f=  (t - 2*T) / T;

      msg.ts.push_back(t);
      msg.xs.push_back(3*(1.0-f)); // R * std::cos(th) - R);
      msg.ys.push_back(0.0); // R * std::sin(th) );
      msg.zs.push_back(1.0);
      msg.vxs.push_back(0.0);
      msg.vys.push_back(0.0);
      msg.vzs.push_back(0.0);
      msg.yaws.push_back(0.0);

      t += dt;
      x += vx * dt;
      if (f > 1) break;
    }

    traj_pub_ -> publish(msg);
    RCLCPP_INFO(this->get_logger(), "PUBLISHED");    
    // // create marker array
    // visualization_msgs::msg::MarkerArray markers;

    // markers.markers.resize(1);
    // for (int i=0; i < msg.ts.size(); i++){
    // 	geometry_msgs::msg::Point point;
    // 	point.x = msg.xs[i];
    //     point.y = msg.ys[i];
    //     point.z = msg.zs[i];
    //     markers.markers[0].points.push_back(point);
    // }
    // markers.markers[0].header.frame_id = "world";
    // markers.markers[0].header.stamp = msg.header.stamp;
    // markers.markers[0].ns = "world";
    // markers.markers[0].id = 0;
    // markers.markers[0].type = visualization_msgs::msg::Marker::CUBE_LIST;
    // markers.markers[0].scale.x = 0.1;
    // markers.markers[0].scale.y = 0.1;
    // markers.markers[0].scale.z = 0.1;
    // markers.markers[0].action = visualization_msgs::msg::Marker::ADD;
   
    // marker_pub_ -> publish(markers);



  }

  void joy_callback(const sensor_msgs::msg::Joy::SharedPtr msg){

  //   // get the transform
  //   try {
  //         auto transformStamped = tf_buffer_->lookupTransform(
  //           "world", "drone1",
  //           tf2::TimePointZero);
  //         
  //         last_x = transformStamped.transform.translation.x;
  //         last_y = transformStamped.transform.translation.y;
  //         last_z = transformStamped.transform.translation.z;
  //         last_tf_stamp = transformStamped.header.stamp;
  //       
  //   } catch (tf2::TransformException & ex) {
  //       RCLCPP_INFO(
  //         this->get_logger(), "Could not transform %s to %s: %s",
  //           "drone1", "world", ex.what());
  //         return;
  //   }



  //   double cmd_throttle = -msg->axes[0];
  //   double cmd_yaw      =  msg->axes[2];
  //   double cmd_pitch    = -msg->axes[1];
  //   double cmd_roll     =  msg->axes[3];

  //   target_x += cmd_pitch/10.0;
  //   target_y += cmd_roll/10.0;
  //   target_z += cmd_throttle/10.0;
  //   target_yaw += cmd_yaw / 10.0;


  //   // check that we are not too far
  //   target_x = std::max(last_x - 1.0, std::min(target_x, last_x + 1.0));
  //   target_y = std::max(last_y - 1.0, std::min(target_y, last_y + 1.0));
  //   target_z = std::max(last_z - 1.0, std::min(target_z, last_z + 1.0));
  //   target_yaw = clampToPi(target_yaw);

  //   RCLCPP_INFO(this->get_logger(), "TARGET %f, %f, %f, %f", target_x, target_y, target_z, target_yaw);
  //   //vx = cmd_roll/10.0;
  //   //vy = cmd_pitch/10.0;
  //   //vz = cmd_throttle/10.0;
  //   //yaw_rate = cmd_yaw / 10.0;

  }


  void timer_callback()
  {
	  publish_one_trajectory();
	  return;


   //  // construct the desired trajectory
   //  dasc_msgs::msg::QuadTrajectory msg = dasc_msgs::msg::QuadTrajectory();
   //  
   //  msg.header.stamp = last_tf_stamp;
   //  msg.header.frame_id = "world";

   //  msg.ts.push_back(0.0);
   //  msg.xs.push_back(last_x);
   //  msg.ys.push_back(last_y);
   //  msg.zs.push_back(last_z);
   //  msg.yaws.push_back(last_yaw);
   //  msg.vxs.push_back(0.0);
   //  msg.vys.push_back(0.0);
   //  msg.vzs.push_back(0.0);

   //  msg.ts.push_back(0.02);
   //  msg.xs.push_back(target_x);
   //  msg.ys.push_back(target_y);
   //  msg.zs.push_back(target_z);
   //  msg.yaws.push_back(target_yaw);
   //  msg.vxs.push_back(0.0);
   //  msg.vys.push_back(0.0);
   //  msg.vzs.push_back(0.0);
   //  
   //  /*
   //  double x = last_x;
   //  double y = last_y;
   //  double z = last_z;
   //  double yaw = last_yaw;

   //  double t = 0.0;
   //  double T = 2.0; // new plan is produced for next T seconds
   //  double dt = 0.05; // resolution of new plan
   //  int N = int(T / dt);

   //  for (int i=0; i < N; i++){

   //    msg.ts.push_back(t);
   //    msg.xs.push_back(x);
   //    msg.ys.push_back(y);
   //    msg.zs.push_back(z);
   //    msg.yaws.push_back(yaw);
   //    msg.vxs.push_back(vx);
   //    msg.vys.push_back(vy);
   //    msg.vzs.push_back(vz);

   //    x += dt * vx;
   //    y += dt * vy;
   //    z += dt * vz;
   //    yaw += dt * yaw_rate;
   //    t += dt;
   //  }
   //  */

   //  // publish desired trajectory
   //  traj_pub_ -> publish(msg);
  }

}; // class NominalController


int main(int argc, char** argv) {

  rclcpp::init(argc, argv);

  auto node = std::make_shared<NominalController>();

  rclcpp::spin(node);

  rclcpp::shutdown();

  return 0;
}



