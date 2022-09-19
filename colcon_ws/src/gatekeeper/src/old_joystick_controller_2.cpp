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
        //"/committed_trajectory", 10);
        "/nominal_trajectory", 10);

    traj_viz_pub_ =
        this->create_publisher<nav_msgs::msg::Path>("/nomimal_traj_viz", 10);

    joy_sub_ = this->create_subscription<sensor_msgs::msg::Joy>(
        "/joy", 100, std::bind(&JoystickController::joy_callback, this, _1));

    // initialize the listener
    tf_buffer_ = std::make_unique<tf2_ros::Buffer>(this->get_clock());
    transform_listener_ =
        std::make_shared<tf2_ros::TransformListener>(*tf_buffer_);

    // get the initial transform
    while (true) {
      RCLCPP_INFO(this->get_logger(), "HERE");
      try {
        auto transformStamped = tf_buffer_->lookupTransform(
            "world", "drone1", this->get_clock()->now(), 200ms);

        last_x = transformStamped.transform.translation.x;
        last_y = transformStamped.transform.translation.y;
        last_z = transformStamped.transform.translation.z;
        last_yaw = tf2::getYaw(transformStamped.transform.rotation);
        break;

      } catch (tf2::TransformException &ex) {
        RCLCPP_INFO(this->get_logger(), "Could not transform %s to %s: %s",
                    "drone1", "world", ex.what());
      }
    }
  }

private:
  // messages from tf
  double last_x = 0;
  double last_y = 0;
  double last_z = 0;
  double last_yaw = 0;

  double target_x = 0;
  double target_y = 0;
  double target_z = 0;
  double target_yaw = 0;

  double vel_x = 0.0;
  double vel_y = 0.0;
  double vel_z = 0.0;
  double vel_th = 0.0;

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

  void joy_callback(const sensor_msgs::msg::Joy::SharedPtr msg) {

    double cmd_throttle = msg->axes[1];
    double cmd_yaw = -msg->axes[0];
    double cmd_pitch = msg->axes[3];
    double cmd_roll = -msg->axes[2];

    double T = 0.5; // horizon

    double tau = 0.0;

    vel_x = tau * vel_x + (1 - tau) * cmd_pitch;
    vel_y = tau * vel_y + (1 - tau) * cmd_roll;
    vel_z = tau * vel_z + (1 - tau) * cmd_throttle;
    vel_th = tau * vel_th + (1 - tau) * 3 * cmd_yaw;

    // get the transform
    try {
      auto transformStamped = tf_buffer_->lookupTransform(
          "world", "drone1", msg->header.stamp, 100ms);

      if (vel_x != 0.0) {
        last_x = transformStamped.transform.translation.x;
        target_x = last_x + vel_x * T;
      }
      if (vel_y != 0.0) {
        last_y = transformStamped.transform.translation.y;
        target_y = last_y + vel_y * T;
      }
      if (vel_z != 0.0) {
        last_z = transformStamped.transform.translation.z;
        target_z = last_z + vel_z * T;
      }
      if (vel_th != 0.0) {
        last_yaw = tf2::getYaw(transformStamped.transform.rotation);
        target_yaw = dyn::clampToPi(last_yaw + vel_th * T);
      }

    } catch (tf2::TransformException &ex) {
      RCLCPP_INFO(this->get_logger(), "Could not transform %s to %s: %s",
                  "drone1", "world", ex.what());
      return;
    }

    // construct the desired trajectory
    dasc_msgs::msg::QuadTrajectory traj = dasc_msgs::msg::QuadTrajectory();

    traj.header.stamp = msg->header.stamp;
    traj.header.frame_id = "world";

    traj.ts.push_back(0.0);
    traj.xs.push_back(target_x);
    traj.ys.push_back(target_y);
    traj.zs.push_back(target_z);
    traj.yaws.push_back(target_yaw);
    traj.vxs.push_back(0 * vel_x);
    traj.vys.push_back(0 * vel_y);
    traj.vzs.push_back(0 * vel_z);

    traj.ts.push_back(T);
    traj.xs.push_back(target_x);
    traj.ys.push_back(target_y);
    traj.zs.push_back(target_z);
    traj.yaws.push_back(target_yaw);
    traj.vxs.push_back(0 * vel_x);
    traj.vys.push_back(0 * vel_y);
    traj.vzs.push_back(0 * vel_z);

    // traj.ts.push_back(0.0);
    // traj.xs.push_back(NAN);
    // traj.ys.push_back(NAN);
    // traj.zs.push_back(NAN);
    // traj.yaws.push_back(last_yaw);
    // traj.vxs.push_back(vel_x);
    // traj.vys.push_back(vel_y);
    // traj.vzs.push_back(vel_z);

    // traj.ts.push_back(T);
    // traj.xs.push_back(NAN);
    // traj.ys.push_back(NAN);
    // traj.zs.push_back(NAN);
    // traj.yaws.push_back(NAN);
    // traj.vxs.push_back(0.0);
    // traj.vys.push_back(0.0);
    // traj.vzs.push_back(0.0);
    //     for (int i = 0; i < 20; i++) {
    //
    //       double f = (double)i / 20.0;
    //
    //       traj.ts.push_back(f * T);
    //       traj.xs.push_back((1.0 - f) * last_x + f * target_x);
    //       traj.ys.push_back((1.0 - f) * last_y + f * target_y);
    //       traj.zs.push_back((1.0 - f) * last_z + f * target_z);
    //       traj.yaws.push_back(dyn::interpolate_angles(last_yaw, target_yaw,
    //       f)); traj.vxs.push_back(0*vel_x); traj.vys.push_back(0*vel_y);
    //       traj.vzs.push_back(0*vel_z);
    //     }

    // // publish desired trajectory
    RCLCPP_INFO(this->get_logger(), "PUBLISHING! Last: %f, Target: %f",
                last_yaw, target_yaw);
    traj_pub_->publish(traj);

    nav_msgs::msg::Path path = dasc_msgs::msg::toPathMsg(traj);

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
