// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from px4_msgs:msg/ExternalController.idl
// generated code does not contain a copyright notice

#ifndef PX4_MSGS__MSG__DETAIL__EXTERNAL_CONTROLLER__BUILDER_HPP_
#define PX4_MSGS__MSG__DETAIL__EXTERNAL_CONTROLLER__BUILDER_HPP_

#include "px4_msgs/msg/detail/external_controller__struct.hpp"
#include <rosidl_runtime_cpp/message_initialization.hpp>
#include <algorithm>
#include <utility>


namespace px4_msgs
{

namespace msg
{

namespace builder
{

class Init_ExternalController_use_geometric_control
{
public:
  explicit Init_ExternalController_use_geometric_control(::px4_msgs::msg::ExternalController & msg)
  : msg_(msg)
  {}
  ::px4_msgs::msg::ExternalController use_geometric_control(::px4_msgs::msg::ExternalController::_use_geometric_control_type arg)
  {
    msg_.use_geometric_control = std::move(arg);
    return std::move(msg_);
  }

private:
  ::px4_msgs::msg::ExternalController msg_;
};

class Init_ExternalController_timestamp
{
public:
  Init_ExternalController_timestamp()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_ExternalController_use_geometric_control timestamp(::px4_msgs::msg::ExternalController::_timestamp_type arg)
  {
    msg_.timestamp = std::move(arg);
    return Init_ExternalController_use_geometric_control(msg_);
  }

private:
  ::px4_msgs::msg::ExternalController msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::px4_msgs::msg::ExternalController>()
{
  return px4_msgs::msg::builder::Init_ExternalController_timestamp();
}

}  // namespace px4_msgs

#endif  // PX4_MSGS__MSG__DETAIL__EXTERNAL_CONTROLLER__BUILDER_HPP_
