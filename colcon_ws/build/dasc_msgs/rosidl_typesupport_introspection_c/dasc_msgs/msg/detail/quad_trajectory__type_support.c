// generated from rosidl_typesupport_introspection_c/resource/idl__type_support.c.em
// with input from dasc_msgs:msg/QuadTrajectory.idl
// generated code does not contain a copyright notice

#include <stddef.h>
#include "dasc_msgs/msg/detail/quad_trajectory__rosidl_typesupport_introspection_c.h"
#include "dasc_msgs/msg/rosidl_typesupport_introspection_c__visibility_control.h"
#include "rosidl_typesupport_introspection_c/field_types.h"
#include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/message_introspection.h"
#include "dasc_msgs/msg/detail/quad_trajectory__functions.h"
#include "dasc_msgs/msg/detail/quad_trajectory__struct.h"


// Include directives for member types
// Member `header`
#include "std_msgs/msg/header.h"
// Member `header`
#include "std_msgs/msg/detail/header__rosidl_typesupport_introspection_c.h"
// Member `ts`
// Member `xs`
// Member `ys`
// Member `zs`
// Member `yaws`
// Member `vxs`
// Member `vys`
// Member `vzs`
#include "rosidl_runtime_c/primitives_sequence_functions.h"

#ifdef __cplusplus
extern "C"
{
#endif

void QuadTrajectory__rosidl_typesupport_introspection_c__QuadTrajectory_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  dasc_msgs__msg__QuadTrajectory__init(message_memory);
}

void QuadTrajectory__rosidl_typesupport_introspection_c__QuadTrajectory_fini_function(void * message_memory)
{
  dasc_msgs__msg__QuadTrajectory__fini(message_memory);
}

static rosidl_typesupport_introspection_c__MessageMember QuadTrajectory__rosidl_typesupport_introspection_c__QuadTrajectory_message_member_array[9] = {
  {
    "header",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(dasc_msgs__msg__QuadTrajectory, header),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "ts",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_DOUBLE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(dasc_msgs__msg__QuadTrajectory, ts),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "xs",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_DOUBLE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(dasc_msgs__msg__QuadTrajectory, xs),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "ys",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_DOUBLE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(dasc_msgs__msg__QuadTrajectory, ys),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "zs",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_DOUBLE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(dasc_msgs__msg__QuadTrajectory, zs),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "yaws",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_DOUBLE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(dasc_msgs__msg__QuadTrajectory, yaws),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "vxs",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_DOUBLE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(dasc_msgs__msg__QuadTrajectory, vxs),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "vys",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_DOUBLE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(dasc_msgs__msg__QuadTrajectory, vys),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "vzs",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_DOUBLE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(dasc_msgs__msg__QuadTrajectory, vzs),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers QuadTrajectory__rosidl_typesupport_introspection_c__QuadTrajectory_message_members = {
  "dasc_msgs__msg",  // message namespace
  "QuadTrajectory",  // message name
  9,  // number of fields
  sizeof(dasc_msgs__msg__QuadTrajectory),
  QuadTrajectory__rosidl_typesupport_introspection_c__QuadTrajectory_message_member_array,  // message members
  QuadTrajectory__rosidl_typesupport_introspection_c__QuadTrajectory_init_function,  // function to initialize message memory (memory has to be allocated)
  QuadTrajectory__rosidl_typesupport_introspection_c__QuadTrajectory_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t QuadTrajectory__rosidl_typesupport_introspection_c__QuadTrajectory_message_type_support_handle = {
  0,
  &QuadTrajectory__rosidl_typesupport_introspection_c__QuadTrajectory_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_dasc_msgs
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, dasc_msgs, msg, QuadTrajectory)() {
  QuadTrajectory__rosidl_typesupport_introspection_c__QuadTrajectory_message_member_array[0].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, std_msgs, msg, Header)();
  if (!QuadTrajectory__rosidl_typesupport_introspection_c__QuadTrajectory_message_type_support_handle.typesupport_identifier) {
    QuadTrajectory__rosidl_typesupport_introspection_c__QuadTrajectory_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &QuadTrajectory__rosidl_typesupport_introspection_c__QuadTrajectory_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif
