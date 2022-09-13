// generated from rosidl_typesupport_fastrtps_c/resource/idl__type_support_c.cpp.em
// with input from dasc_msgs:msg/QuadTrajectory.idl
// generated code does not contain a copyright notice
#include "dasc_msgs/msg/detail/quad_trajectory__rosidl_typesupport_fastrtps_c.h"


#include <cassert>
#include <limits>
#include <string>
#include "rosidl_typesupport_fastrtps_c/identifier.h"
#include "rosidl_typesupport_fastrtps_c/wstring_conversion.hpp"
#include "rosidl_typesupport_fastrtps_cpp/message_type_support.h"
#include "dasc_msgs/msg/rosidl_typesupport_fastrtps_c__visibility_control.h"
#include "dasc_msgs/msg/detail/quad_trajectory__struct.h"
#include "dasc_msgs/msg/detail/quad_trajectory__functions.h"
#include "fastcdr/Cdr.h"

#ifndef _WIN32
# pragma GCC diagnostic push
# pragma GCC diagnostic ignored "-Wunused-parameter"
# ifdef __clang__
#  pragma clang diagnostic ignored "-Wdeprecated-register"
#  pragma clang diagnostic ignored "-Wreturn-type-c-linkage"
# endif
#endif
#ifndef _WIN32
# pragma GCC diagnostic pop
#endif

// includes and forward declarations of message dependencies and their conversion functions

#if defined(__cplusplus)
extern "C"
{
#endif

#include "rosidl_runtime_c/primitives_sequence.h"  // ts, vxs, vys, vzs, xs, yaws, ys, zs
#include "rosidl_runtime_c/primitives_sequence_functions.h"  // ts, vxs, vys, vzs, xs, yaws, ys, zs
#include "std_msgs/msg/detail/header__functions.h"  // header

// forward declare type support functions
ROSIDL_TYPESUPPORT_FASTRTPS_C_IMPORT_dasc_msgs
size_t get_serialized_size_std_msgs__msg__Header(
  const void * untyped_ros_message,
  size_t current_alignment);

ROSIDL_TYPESUPPORT_FASTRTPS_C_IMPORT_dasc_msgs
size_t max_serialized_size_std_msgs__msg__Header(
  bool & full_bounded,
  size_t current_alignment);

ROSIDL_TYPESUPPORT_FASTRTPS_C_IMPORT_dasc_msgs
const rosidl_message_type_support_t *
  ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, std_msgs, msg, Header)();


using _QuadTrajectory__ros_msg_type = dasc_msgs__msg__QuadTrajectory;

static bool _QuadTrajectory__cdr_serialize(
  const void * untyped_ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  const _QuadTrajectory__ros_msg_type * ros_message = static_cast<const _QuadTrajectory__ros_msg_type *>(untyped_ros_message);
  // Field name: header
  {
    const message_type_support_callbacks_t * callbacks =
      static_cast<const message_type_support_callbacks_t *>(
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(
        rosidl_typesupport_fastrtps_c, std_msgs, msg, Header
      )()->data);
    if (!callbacks->cdr_serialize(
        &ros_message->header, cdr))
    {
      return false;
    }
  }

  // Field name: ts
  {
    size_t size = ros_message->ts.size;
    auto array_ptr = ros_message->ts.data;
    cdr << static_cast<uint32_t>(size);
    cdr.serializeArray(array_ptr, size);
  }

  // Field name: xs
  {
    size_t size = ros_message->xs.size;
    auto array_ptr = ros_message->xs.data;
    cdr << static_cast<uint32_t>(size);
    cdr.serializeArray(array_ptr, size);
  }

  // Field name: ys
  {
    size_t size = ros_message->ys.size;
    auto array_ptr = ros_message->ys.data;
    cdr << static_cast<uint32_t>(size);
    cdr.serializeArray(array_ptr, size);
  }

  // Field name: zs
  {
    size_t size = ros_message->zs.size;
    auto array_ptr = ros_message->zs.data;
    cdr << static_cast<uint32_t>(size);
    cdr.serializeArray(array_ptr, size);
  }

  // Field name: yaws
  {
    size_t size = ros_message->yaws.size;
    auto array_ptr = ros_message->yaws.data;
    cdr << static_cast<uint32_t>(size);
    cdr.serializeArray(array_ptr, size);
  }

  // Field name: vxs
  {
    size_t size = ros_message->vxs.size;
    auto array_ptr = ros_message->vxs.data;
    cdr << static_cast<uint32_t>(size);
    cdr.serializeArray(array_ptr, size);
  }

  // Field name: vys
  {
    size_t size = ros_message->vys.size;
    auto array_ptr = ros_message->vys.data;
    cdr << static_cast<uint32_t>(size);
    cdr.serializeArray(array_ptr, size);
  }

  // Field name: vzs
  {
    size_t size = ros_message->vzs.size;
    auto array_ptr = ros_message->vzs.data;
    cdr << static_cast<uint32_t>(size);
    cdr.serializeArray(array_ptr, size);
  }

  return true;
}

static bool _QuadTrajectory__cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  void * untyped_ros_message)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  _QuadTrajectory__ros_msg_type * ros_message = static_cast<_QuadTrajectory__ros_msg_type *>(untyped_ros_message);
  // Field name: header
  {
    const message_type_support_callbacks_t * callbacks =
      static_cast<const message_type_support_callbacks_t *>(
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(
        rosidl_typesupport_fastrtps_c, std_msgs, msg, Header
      )()->data);
    if (!callbacks->cdr_deserialize(
        cdr, &ros_message->header))
    {
      return false;
    }
  }

  // Field name: ts
  {
    uint32_t cdrSize;
    cdr >> cdrSize;
    size_t size = static_cast<size_t>(cdrSize);
    if (ros_message->ts.data) {
      rosidl_runtime_c__double__Sequence__fini(&ros_message->ts);
    }
    if (!rosidl_runtime_c__double__Sequence__init(&ros_message->ts, size)) {
      return "failed to create array for field 'ts'";
    }
    auto array_ptr = ros_message->ts.data;
    cdr.deserializeArray(array_ptr, size);
  }

  // Field name: xs
  {
    uint32_t cdrSize;
    cdr >> cdrSize;
    size_t size = static_cast<size_t>(cdrSize);
    if (ros_message->xs.data) {
      rosidl_runtime_c__double__Sequence__fini(&ros_message->xs);
    }
    if (!rosidl_runtime_c__double__Sequence__init(&ros_message->xs, size)) {
      return "failed to create array for field 'xs'";
    }
    auto array_ptr = ros_message->xs.data;
    cdr.deserializeArray(array_ptr, size);
  }

  // Field name: ys
  {
    uint32_t cdrSize;
    cdr >> cdrSize;
    size_t size = static_cast<size_t>(cdrSize);
    if (ros_message->ys.data) {
      rosidl_runtime_c__double__Sequence__fini(&ros_message->ys);
    }
    if (!rosidl_runtime_c__double__Sequence__init(&ros_message->ys, size)) {
      return "failed to create array for field 'ys'";
    }
    auto array_ptr = ros_message->ys.data;
    cdr.deserializeArray(array_ptr, size);
  }

  // Field name: zs
  {
    uint32_t cdrSize;
    cdr >> cdrSize;
    size_t size = static_cast<size_t>(cdrSize);
    if (ros_message->zs.data) {
      rosidl_runtime_c__double__Sequence__fini(&ros_message->zs);
    }
    if (!rosidl_runtime_c__double__Sequence__init(&ros_message->zs, size)) {
      return "failed to create array for field 'zs'";
    }
    auto array_ptr = ros_message->zs.data;
    cdr.deserializeArray(array_ptr, size);
  }

  // Field name: yaws
  {
    uint32_t cdrSize;
    cdr >> cdrSize;
    size_t size = static_cast<size_t>(cdrSize);
    if (ros_message->yaws.data) {
      rosidl_runtime_c__double__Sequence__fini(&ros_message->yaws);
    }
    if (!rosidl_runtime_c__double__Sequence__init(&ros_message->yaws, size)) {
      return "failed to create array for field 'yaws'";
    }
    auto array_ptr = ros_message->yaws.data;
    cdr.deserializeArray(array_ptr, size);
  }

  // Field name: vxs
  {
    uint32_t cdrSize;
    cdr >> cdrSize;
    size_t size = static_cast<size_t>(cdrSize);
    if (ros_message->vxs.data) {
      rosidl_runtime_c__double__Sequence__fini(&ros_message->vxs);
    }
    if (!rosidl_runtime_c__double__Sequence__init(&ros_message->vxs, size)) {
      return "failed to create array for field 'vxs'";
    }
    auto array_ptr = ros_message->vxs.data;
    cdr.deserializeArray(array_ptr, size);
  }

  // Field name: vys
  {
    uint32_t cdrSize;
    cdr >> cdrSize;
    size_t size = static_cast<size_t>(cdrSize);
    if (ros_message->vys.data) {
      rosidl_runtime_c__double__Sequence__fini(&ros_message->vys);
    }
    if (!rosidl_runtime_c__double__Sequence__init(&ros_message->vys, size)) {
      return "failed to create array for field 'vys'";
    }
    auto array_ptr = ros_message->vys.data;
    cdr.deserializeArray(array_ptr, size);
  }

  // Field name: vzs
  {
    uint32_t cdrSize;
    cdr >> cdrSize;
    size_t size = static_cast<size_t>(cdrSize);
    if (ros_message->vzs.data) {
      rosidl_runtime_c__double__Sequence__fini(&ros_message->vzs);
    }
    if (!rosidl_runtime_c__double__Sequence__init(&ros_message->vzs, size)) {
      return "failed to create array for field 'vzs'";
    }
    auto array_ptr = ros_message->vzs.data;
    cdr.deserializeArray(array_ptr, size);
  }

  return true;
}

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_dasc_msgs
size_t get_serialized_size_dasc_msgs__msg__QuadTrajectory(
  const void * untyped_ros_message,
  size_t current_alignment)
{
  const _QuadTrajectory__ros_msg_type * ros_message = static_cast<const _QuadTrajectory__ros_msg_type *>(untyped_ros_message);
  (void)ros_message;
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // field.name header

  current_alignment += get_serialized_size_std_msgs__msg__Header(
    &(ros_message->header), current_alignment);
  // field.name ts
  {
    size_t array_size = ros_message->ts.size;
    auto array_ptr = ros_message->ts.data;
    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);
    (void)array_ptr;
    size_t item_size = sizeof(array_ptr[0]);
    current_alignment += array_size * item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name xs
  {
    size_t array_size = ros_message->xs.size;
    auto array_ptr = ros_message->xs.data;
    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);
    (void)array_ptr;
    size_t item_size = sizeof(array_ptr[0]);
    current_alignment += array_size * item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name ys
  {
    size_t array_size = ros_message->ys.size;
    auto array_ptr = ros_message->ys.data;
    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);
    (void)array_ptr;
    size_t item_size = sizeof(array_ptr[0]);
    current_alignment += array_size * item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name zs
  {
    size_t array_size = ros_message->zs.size;
    auto array_ptr = ros_message->zs.data;
    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);
    (void)array_ptr;
    size_t item_size = sizeof(array_ptr[0]);
    current_alignment += array_size * item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name yaws
  {
    size_t array_size = ros_message->yaws.size;
    auto array_ptr = ros_message->yaws.data;
    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);
    (void)array_ptr;
    size_t item_size = sizeof(array_ptr[0]);
    current_alignment += array_size * item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name vxs
  {
    size_t array_size = ros_message->vxs.size;
    auto array_ptr = ros_message->vxs.data;
    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);
    (void)array_ptr;
    size_t item_size = sizeof(array_ptr[0]);
    current_alignment += array_size * item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name vys
  {
    size_t array_size = ros_message->vys.size;
    auto array_ptr = ros_message->vys.data;
    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);
    (void)array_ptr;
    size_t item_size = sizeof(array_ptr[0]);
    current_alignment += array_size * item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name vzs
  {
    size_t array_size = ros_message->vzs.size;
    auto array_ptr = ros_message->vzs.data;
    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);
    (void)array_ptr;
    size_t item_size = sizeof(array_ptr[0]);
    current_alignment += array_size * item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  return current_alignment - initial_alignment;
}

static uint32_t _QuadTrajectory__get_serialized_size(const void * untyped_ros_message)
{
  return static_cast<uint32_t>(
    get_serialized_size_dasc_msgs__msg__QuadTrajectory(
      untyped_ros_message, 0));
}

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_dasc_msgs
size_t max_serialized_size_dasc_msgs__msg__QuadTrajectory(
  bool & full_bounded,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;
  (void)full_bounded;

  // member: header
  {
    size_t array_size = 1;


    for (size_t index = 0; index < array_size; ++index) {
      current_alignment +=
        max_serialized_size_std_msgs__msg__Header(
        full_bounded, current_alignment);
    }
  }
  // member: ts
  {
    size_t array_size = 0;
    full_bounded = false;
    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);

    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }
  // member: xs
  {
    size_t array_size = 0;
    full_bounded = false;
    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);

    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }
  // member: ys
  {
    size_t array_size = 0;
    full_bounded = false;
    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);

    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }
  // member: zs
  {
    size_t array_size = 0;
    full_bounded = false;
    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);

    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }
  // member: yaws
  {
    size_t array_size = 0;
    full_bounded = false;
    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);

    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }
  // member: vxs
  {
    size_t array_size = 0;
    full_bounded = false;
    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);

    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }
  // member: vys
  {
    size_t array_size = 0;
    full_bounded = false;
    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);

    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }
  // member: vzs
  {
    size_t array_size = 0;
    full_bounded = false;
    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);

    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }

  return current_alignment - initial_alignment;
}

static size_t _QuadTrajectory__max_serialized_size(bool & full_bounded)
{
  return max_serialized_size_dasc_msgs__msg__QuadTrajectory(
    full_bounded, 0);
}


static message_type_support_callbacks_t __callbacks_QuadTrajectory = {
  "dasc_msgs::msg",
  "QuadTrajectory",
  _QuadTrajectory__cdr_serialize,
  _QuadTrajectory__cdr_deserialize,
  _QuadTrajectory__get_serialized_size,
  _QuadTrajectory__max_serialized_size
};

static rosidl_message_type_support_t _QuadTrajectory__type_support = {
  rosidl_typesupport_fastrtps_c__identifier,
  &__callbacks_QuadTrajectory,
  get_message_typesupport_handle_function,
};

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, dasc_msgs, msg, QuadTrajectory)() {
  return &_QuadTrajectory__type_support;
}

#if defined(__cplusplus)
}
#endif
