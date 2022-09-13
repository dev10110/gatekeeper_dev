// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from dasc_msgs:msg/QuadTrajectory.idl
// generated code does not contain a copyright notice

#ifndef DASC_MSGS__MSG__DETAIL__QUAD_TRAJECTORY__BUILDER_HPP_
#define DASC_MSGS__MSG__DETAIL__QUAD_TRAJECTORY__BUILDER_HPP_

#include "dasc_msgs/msg/detail/quad_trajectory__struct.hpp"
#include <rosidl_runtime_cpp/message_initialization.hpp>
#include <algorithm>
#include <utility>


namespace dasc_msgs
{

namespace msg
{

namespace builder
{

class Init_QuadTrajectory_vzs
{
public:
  explicit Init_QuadTrajectory_vzs(::dasc_msgs::msg::QuadTrajectory & msg)
  : msg_(msg)
  {}
  ::dasc_msgs::msg::QuadTrajectory vzs(::dasc_msgs::msg::QuadTrajectory::_vzs_type arg)
  {
    msg_.vzs = std::move(arg);
    return std::move(msg_);
  }

private:
  ::dasc_msgs::msg::QuadTrajectory msg_;
};

class Init_QuadTrajectory_vys
{
public:
  explicit Init_QuadTrajectory_vys(::dasc_msgs::msg::QuadTrajectory & msg)
  : msg_(msg)
  {}
  Init_QuadTrajectory_vzs vys(::dasc_msgs::msg::QuadTrajectory::_vys_type arg)
  {
    msg_.vys = std::move(arg);
    return Init_QuadTrajectory_vzs(msg_);
  }

private:
  ::dasc_msgs::msg::QuadTrajectory msg_;
};

class Init_QuadTrajectory_vxs
{
public:
  explicit Init_QuadTrajectory_vxs(::dasc_msgs::msg::QuadTrajectory & msg)
  : msg_(msg)
  {}
  Init_QuadTrajectory_vys vxs(::dasc_msgs::msg::QuadTrajectory::_vxs_type arg)
  {
    msg_.vxs = std::move(arg);
    return Init_QuadTrajectory_vys(msg_);
  }

private:
  ::dasc_msgs::msg::QuadTrajectory msg_;
};

class Init_QuadTrajectory_yaws
{
public:
  explicit Init_QuadTrajectory_yaws(::dasc_msgs::msg::QuadTrajectory & msg)
  : msg_(msg)
  {}
  Init_QuadTrajectory_vxs yaws(::dasc_msgs::msg::QuadTrajectory::_yaws_type arg)
  {
    msg_.yaws = std::move(arg);
    return Init_QuadTrajectory_vxs(msg_);
  }

private:
  ::dasc_msgs::msg::QuadTrajectory msg_;
};

class Init_QuadTrajectory_zs
{
public:
  explicit Init_QuadTrajectory_zs(::dasc_msgs::msg::QuadTrajectory & msg)
  : msg_(msg)
  {}
  Init_QuadTrajectory_yaws zs(::dasc_msgs::msg::QuadTrajectory::_zs_type arg)
  {
    msg_.zs = std::move(arg);
    return Init_QuadTrajectory_yaws(msg_);
  }

private:
  ::dasc_msgs::msg::QuadTrajectory msg_;
};

class Init_QuadTrajectory_ys
{
public:
  explicit Init_QuadTrajectory_ys(::dasc_msgs::msg::QuadTrajectory & msg)
  : msg_(msg)
  {}
  Init_QuadTrajectory_zs ys(::dasc_msgs::msg::QuadTrajectory::_ys_type arg)
  {
    msg_.ys = std::move(arg);
    return Init_QuadTrajectory_zs(msg_);
  }

private:
  ::dasc_msgs::msg::QuadTrajectory msg_;
};

class Init_QuadTrajectory_xs
{
public:
  explicit Init_QuadTrajectory_xs(::dasc_msgs::msg::QuadTrajectory & msg)
  : msg_(msg)
  {}
  Init_QuadTrajectory_ys xs(::dasc_msgs::msg::QuadTrajectory::_xs_type arg)
  {
    msg_.xs = std::move(arg);
    return Init_QuadTrajectory_ys(msg_);
  }

private:
  ::dasc_msgs::msg::QuadTrajectory msg_;
};

class Init_QuadTrajectory_ts
{
public:
  explicit Init_QuadTrajectory_ts(::dasc_msgs::msg::QuadTrajectory & msg)
  : msg_(msg)
  {}
  Init_QuadTrajectory_xs ts(::dasc_msgs::msg::QuadTrajectory::_ts_type arg)
  {
    msg_.ts = std::move(arg);
    return Init_QuadTrajectory_xs(msg_);
  }

private:
  ::dasc_msgs::msg::QuadTrajectory msg_;
};

class Init_QuadTrajectory_header
{
public:
  Init_QuadTrajectory_header()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_QuadTrajectory_ts header(::dasc_msgs::msg::QuadTrajectory::_header_type arg)
  {
    msg_.header = std::move(arg);
    return Init_QuadTrajectory_ts(msg_);
  }

private:
  ::dasc_msgs::msg::QuadTrajectory msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::dasc_msgs::msg::QuadTrajectory>()
{
  return dasc_msgs::msg::builder::Init_QuadTrajectory_header();
}

}  // namespace dasc_msgs

#endif  // DASC_MSGS__MSG__DETAIL__QUAD_TRAJECTORY__BUILDER_HPP_
