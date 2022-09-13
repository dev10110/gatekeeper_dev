// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from dasc_msgs:msg/QuadSetpoint.idl
// generated code does not contain a copyright notice

#ifndef DASC_MSGS__MSG__DETAIL__QUAD_SETPOINT__BUILDER_HPP_
#define DASC_MSGS__MSG__DETAIL__QUAD_SETPOINT__BUILDER_HPP_

#include "dasc_msgs/msg/detail/quad_setpoint__struct.hpp"
#include <rosidl_runtime_cpp/message_initialization.hpp>
#include <algorithm>
#include <utility>


namespace dasc_msgs
{

namespace msg
{

namespace builder
{

class Init_QuadSetpoint_yaw
{
public:
  explicit Init_QuadSetpoint_yaw(::dasc_msgs::msg::QuadSetpoint & msg)
  : msg_(msg)
  {}
  ::dasc_msgs::msg::QuadSetpoint yaw(::dasc_msgs::msg::QuadSetpoint::_yaw_type arg)
  {
    msg_.yaw = std::move(arg);
    return std::move(msg_);
  }

private:
  ::dasc_msgs::msg::QuadSetpoint msg_;
};

class Init_QuadSetpoint_z
{
public:
  explicit Init_QuadSetpoint_z(::dasc_msgs::msg::QuadSetpoint & msg)
  : msg_(msg)
  {}
  Init_QuadSetpoint_yaw z(::dasc_msgs::msg::QuadSetpoint::_z_type arg)
  {
    msg_.z = std::move(arg);
    return Init_QuadSetpoint_yaw(msg_);
  }

private:
  ::dasc_msgs::msg::QuadSetpoint msg_;
};

class Init_QuadSetpoint_y
{
public:
  explicit Init_QuadSetpoint_y(::dasc_msgs::msg::QuadSetpoint & msg)
  : msg_(msg)
  {}
  Init_QuadSetpoint_z y(::dasc_msgs::msg::QuadSetpoint::_y_type arg)
  {
    msg_.y = std::move(arg);
    return Init_QuadSetpoint_z(msg_);
  }

private:
  ::dasc_msgs::msg::QuadSetpoint msg_;
};

class Init_QuadSetpoint_x
{
public:
  explicit Init_QuadSetpoint_x(::dasc_msgs::msg::QuadSetpoint & msg)
  : msg_(msg)
  {}
  Init_QuadSetpoint_y x(::dasc_msgs::msg::QuadSetpoint::_x_type arg)
  {
    msg_.x = std::move(arg);
    return Init_QuadSetpoint_y(msg_);
  }

private:
  ::dasc_msgs::msg::QuadSetpoint msg_;
};

class Init_QuadSetpoint_header
{
public:
  Init_QuadSetpoint_header()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_QuadSetpoint_x header(::dasc_msgs::msg::QuadSetpoint::_header_type arg)
  {
    msg_.header = std::move(arg);
    return Init_QuadSetpoint_x(msg_);
  }

private:
  ::dasc_msgs::msg::QuadSetpoint msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::dasc_msgs::msg::QuadSetpoint>()
{
  return dasc_msgs::msg::builder::Init_QuadSetpoint_header();
}

}  // namespace dasc_msgs

#endif  // DASC_MSGS__MSG__DETAIL__QUAD_SETPOINT__BUILDER_HPP_
