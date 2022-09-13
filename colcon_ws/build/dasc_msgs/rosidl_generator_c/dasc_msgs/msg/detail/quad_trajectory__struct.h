// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from dasc_msgs:msg/QuadTrajectory.idl
// generated code does not contain a copyright notice

#ifndef DASC_MSGS__MSG__DETAIL__QUAD_TRAJECTORY__STRUCT_H_
#define DASC_MSGS__MSG__DETAIL__QUAD_TRAJECTORY__STRUCT_H_

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
// Member 'ts'
// Member 'xs'
// Member 'ys'
// Member 'zs'
// Member 'yaws'
// Member 'vxs'
// Member 'vys'
// Member 'vzs'
#include "rosidl_runtime_c/primitives_sequence.h"

// Struct defined in msg/QuadTrajectory in the package dasc_msgs.
typedef struct dasc_msgs__msg__QuadTrajectory
{
  std_msgs__msg__Header header;
  rosidl_runtime_c__double__Sequence ts;
  rosidl_runtime_c__double__Sequence xs;
  rosidl_runtime_c__double__Sequence ys;
  rosidl_runtime_c__double__Sequence zs;
  rosidl_runtime_c__double__Sequence yaws;
  rosidl_runtime_c__double__Sequence vxs;
  rosidl_runtime_c__double__Sequence vys;
  rosidl_runtime_c__double__Sequence vzs;
} dasc_msgs__msg__QuadTrajectory;

// Struct for a sequence of dasc_msgs__msg__QuadTrajectory.
typedef struct dasc_msgs__msg__QuadTrajectory__Sequence
{
  dasc_msgs__msg__QuadTrajectory * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} dasc_msgs__msg__QuadTrajectory__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // DASC_MSGS__MSG__DETAIL__QUAD_TRAJECTORY__STRUCT_H_
