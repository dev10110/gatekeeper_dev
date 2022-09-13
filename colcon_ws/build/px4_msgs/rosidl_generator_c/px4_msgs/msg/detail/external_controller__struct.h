// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from px4_msgs:msg/ExternalController.idl
// generated code does not contain a copyright notice

#ifndef PX4_MSGS__MSG__DETAIL__EXTERNAL_CONTROLLER__STRUCT_H_
#define PX4_MSGS__MSG__DETAIL__EXTERNAL_CONTROLLER__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Struct defined in msg/ExternalController in the package px4_msgs.
typedef struct px4_msgs__msg__ExternalController
{
  uint64_t timestamp;
  bool use_geometric_control;
} px4_msgs__msg__ExternalController;

// Struct for a sequence of px4_msgs__msg__ExternalController.
typedef struct px4_msgs__msg__ExternalController__Sequence
{
  px4_msgs__msg__ExternalController * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} px4_msgs__msg__ExternalController__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // PX4_MSGS__MSG__DETAIL__EXTERNAL_CONTROLLER__STRUCT_H_
