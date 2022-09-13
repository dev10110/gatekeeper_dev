// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from dasc_msgs:msg/QuadSetpoint.idl
// generated code does not contain a copyright notice

#ifndef DASC_MSGS__MSG__DETAIL__QUAD_SETPOINT__STRUCT_H_
#define DASC_MSGS__MSG__DETAIL__QUAD_SETPOINT__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Include directives for member types
// Member 'header'
#include "std_msgs/msg/detail/header__struct.h"

// Struct defined in msg/QuadSetpoint in the package dasc_msgs.
typedef struct dasc_msgs__msg__QuadSetpoint
{
  std_msgs__msg__Header header;
  double x;
  double y;
  double z;
  double yaw;
} dasc_msgs__msg__QuadSetpoint;

// Struct for a sequence of dasc_msgs__msg__QuadSetpoint.
typedef struct dasc_msgs__msg__QuadSetpoint__Sequence
{
  dasc_msgs__msg__QuadSetpoint * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} dasc_msgs__msg__QuadSetpoint__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // DASC_MSGS__MSG__DETAIL__QUAD_SETPOINT__STRUCT_H_
