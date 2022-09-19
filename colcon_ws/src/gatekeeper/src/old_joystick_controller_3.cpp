#include <chrono>
#include <functional>
#include <memory>

#include <builtin_interfaces/msg/time.hpp>
#include <dasc_msgs/msg/quad_trajectory.hpp>
#include <geometry_msgs/msg/point.hpp>
#include <nav_msgs/msg/path.hpp>
#include <rclcpp/rclcpp.hpp>
#include <sensor_msgs/msg/joy.hpp>

#include "gatekeeper/dynamics.hpp"
#include "gatekeeper/visualization.hpp"

#include <tf2/exceptions.h>
#include <tf2/utils.h>
#include <tf2_ros/buffer.h>
#include <tf2_ros/transform_listener.h>

/* joystick_controller.cpp
 *
 * this file subscribes to the joystick, and the quadrotors current position.
 * based on the joystick commands, it proposes flying at some speed in the
 * direction commanded by the joysticks.'
 *
 */

using namespace std::chrono_literals;
using namespace std::placeholders;

class JoystickController : public rclcpp::Node {
public:
  JoystickController() : Node("joystick_controller") {

    rclcpp::Parameter simTime("use_sim_time", rclcpp::ParameterValue(true));
    this->set_parameter(simTime);

    traj_pub_ = this->create_publisher<dasc_msgs::msg::QuadTrajectory>(
        "/committed_trajectory", 10);
    // "/nominal_trajectory", 10);

    traj_viz_pub_ =
        this->create_publisher<nav_msgs::msg::Path>("/nominal_traj_viz", 10);

    joy_sub_ = this->create_subscription<sensor_msgs::msg::Joy>(
        "/joy", 100, std::bind(&JoystickController::joy_callback, this, _1));

    // initialize the listener
    tf_buffer_ = std::make_unique<tf2_ros::Buffer>(this->get_clock());
    transform_listener_ =
        std::make_shared<tf2_ros::TransformListener>(*tf_buffer_);

    timer_ = this->create_wall_timer(
        1000ms, std::bind(&JoystickController::timer_callback, this));
  }

private:
  // messages from tf
  double last_x = 0;
  double last_y = 0;
  double last_z = 0;
  double last_yaw = 0;

  double target_x = 0;
  double target_y = 0;
  double target_z = 1.0;
  double target_yaw = 0;

  double vel_x = 0.0;
  double vel_y = 0.0;
  double vel_z = 0.0;
  double vel_t = 0.0;

  // rclcpp
  rclcpp::TimerBase::SharedPtr timer_;
  rclcpp::Subscription<sensor_msgs::msg::Joy>::SharedPtr joy_sub_{nullptr};
  rclcpp::Publisher<dasc_msgs::msg::QuadTrajectory>::SharedPtr traj_pub_{
      nullptr};
  rclcpp::Publisher<nav_msgs::msg::Path>::SharedPtr traj_viz_pub_;

  std::shared_ptr<tf2_ros::TransformListener> transform_listener_{nullptr};
  std::unique_ptr<tf2_ros::Buffer> tf_buffer_;
  builtin_interfaces::msg::Time start_time;
  builtin_interfaces::msg::Time last_tf_stamp;

  geometry_msgs::msg::TransformStamped transformStamped;

  void joy_callback(const sensor_msgs::msg::Joy::SharedPtr msg) {

    double cmd_throttle = msg->axes[1];
    // double cmd_yaw = -msg->axes[0];
    double cmd_pitch = msg->axes[3];
    double cmd_roll = msg->axes[2];

    double cmd_yaw = 0.0;
    if (msg->buttons[7] == 1)
      cmd_yaw -= 1.0;
    if (msg->buttons[6] == 1)
      cmd_yaw += 1.0;

    vel_x = cmd_pitch * std::cos(last_yaw) - cmd_roll * std::sin(last_yaw);
    vel_y = cmd_pitch * std::sin(last_yaw) + cmd_roll * std::cos(last_yaw);
    vel_z = cmd_throttle;
    vel_t = cmd_yaw;

    double dt = 0.1;

    target_x += vel_x * dt;
    target_y += vel_y * dt;
    target_z += vel_z * dt;
    target_yaw += vel_t * dt;

    return;
  }

  double saturate(double y, double x, double R) {
    if (y < x - R)
      return (x - R);
    if (y > x + R)
      return (x + R);
    return y;
  }

  void timer_callback() {

    double T = 1.0; // horizon

    // get the transform
    try {
      transformStamped = tf_buffer_->lookupTransform("world", "drone1",
                                                     tf2::TimePointZero, 100ms);

      last_x = transformStamped.transform.translation.x;
      last_y = transformStamped.transform.translation.y;
      last_z = transformStamped.transform.translation.z;
      last_yaw = tf2::getYaw(transformStamped.transform.rotation);

    } catch (tf2::TransformException &ex) {
      RCLCPP_INFO(this->get_logger(), "Could not transform %s to %s: %s",
                  "drone1", "world", ex.what());
      return;
    }

    // saturate cmds
    target_x = saturate(target_x, last_x, 1.0);
    target_y = saturate(target_y, last_y, 1.0);
    target_z = saturate(target_z, last_z, 1.0);
    target_yaw = dyn::clampToPi(saturate(target_yaw, last_yaw, 1.0 * M_PI));

    double x = last_x;
    double y = last_y;
    double z = last_z;
    double yaw = last_yaw;

    // construct the desired trajectory
    dasc_msgs::msg::QuadTrajectory traj = dasc_msgs::msg::QuadTrajectory();

    traj.header.stamp = transformStamped.header.stamp;
    traj.header.frame_id = "world";

    for (int i = 0; i < 20; i++) {

      double f = (double)i / 20.0;

      traj.ts.push_back(f * T);
      traj.xs.push_back(x);
      traj.ys.push_back(y);
      traj.zs.push_back(z);
      traj.yaws.push_back(yaw);
      traj.vxs.push_back(0 * vel_x);
      traj.vys.push_back(0 * vel_y);
      traj.vzs.push_back(0 * vel_z);

      x += vel_x * T / 20.0;
      y += vel_y * T / 20.0;
      z += vel_z * T / 20.0;
      yaw += vel_t * T / 20.0;

      x = saturate(x, last_x, 1.0);
      y = saturate(y, last_y, 1.0);
      z = saturate(z, last_z, 1.0);
      yaw = dyn::clampToPi(yaw);
    }

    // // publish desired trajectory
    RCLCPP_INFO(this->get_logger(), "PUBLISHING! Target: (%f, %f, %f, %f)",
                target_x, target_y, target_z, target_yaw);
    traj_pub_->publish(traj);

    nav_msgs::msg::Path path = dasc_msgs::msg::toPathMsg(traj);
    path.header.stamp = traj.header.stamp;
    path.header.frame_id = traj.header.frame_id;

    traj_viz_pub_->publish(path);
  }

}; // class JoystickController

int main(int argc, char **argv) {

  rclcpp::init(argc, argv);

  auto node = std::make_shared<JoystickController>();

  rclcpp::spin(node);

  rclcpp::shutdown();

  return 0;
}
