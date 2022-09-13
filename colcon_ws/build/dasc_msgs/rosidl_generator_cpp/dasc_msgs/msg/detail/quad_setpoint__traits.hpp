// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from dasc_msgs:msg/QuadSetpoint.idl
// generated code does not contain a copyright notice

#ifndef DASC_MSGS__MSG__DETAIL__QUAD_SETPOINT__TRAITS_HPP_
#define DASC_MSGS__MSG__DETAIL__QUAD_SETPOINT__TRAITS_HPP_

#include "dasc_msgs/msg/detail/quad_setpoint__struct.hpp"
#include <rosidl_runtime_cpp/traits.hpp>
#include <stdint.h>
#include <type_traits>

// Include directives for member types
// Member 'header'
#include "std_msgs/msg/detail/header__traits.hpp"

namespace rosidl_generator_traits
{

template<>
inline const char * data_type<dasc_msgs::msg::QuadSetpoint>()
{
  return "dasc_msgs::msg::QuadSetpoint";
}

template<>
inline const char * name<dasc_msgs::msg::QuadSetpoint>()
{
  return "dasc_msgs/msg/QuadSetpoint";
}

template<>
struct has_fixed_size<dasc_msgs::msg::QuadSetpoint>
  : std::integral_constant<bool, has_fixed_size<std_msgs::msg::Header>::value> {};

template<>
struct has_bounded_size<dasc_msgs::msg::QuadSetpoint>
  : std::integral_constant<bool, has_bounded_size<std_msgs::msg::Header>::value> {};

template<>
struct is_message<dasc_msgs::msg::QuadSetpoint>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // DASC_MSGS__MSG__DETAIL__QUAD_SETPOINT__TRAITS_HPP_
