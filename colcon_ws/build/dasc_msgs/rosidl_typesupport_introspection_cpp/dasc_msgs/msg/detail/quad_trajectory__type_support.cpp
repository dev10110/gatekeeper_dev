// generated from rosidl_typesupport_introspection_cpp/resource/idl__type_support.cpp.em
// with input from dasc_msgs:msg/QuadTrajectory.idl
// generated code does not contain a copyright notice

#include "array"
#include "cstddef"
#include "string"
#include "vector"
#include "rosidl_runtime_c/message_type_support_struct.h"
#include "rosidl_typesupport_cpp/message_type_support.hpp"
#include "rosidl_typesupport_interface/macros.h"
#include "dasc_msgs/msg/detail/quad_trajectory__struct.hpp"
#include "rosidl_typesupport_introspection_cpp/field_types.hpp"
#include "rosidl_typesupport_introspection_cpp/identifier.hpp"
#include "rosidl_typesupport_introspection_cpp/message_introspection.hpp"
#include "rosidl_typesupport_introspection_cpp/message_type_support_decl.hpp"
#include "rosidl_typesupport_introspection_cpp/visibility_control.h"

namespace dasc_msgs
{

namespace msg
{

namespace rosidl_typesupport_introspection_cpp
{

void QuadTrajectory_init_function(
  void * message_memory, rosidl_runtime_cpp::MessageInitialization _init)
{
  new (message_memory) dasc_msgs::msg::QuadTrajectory(_init);
}

void QuadTrajectory_fini_function(void * message_memory)
{
  auto typed_message = static_cast<dasc_msgs::msg::QuadTrajectory *>(message_memory);
  typed_message->~QuadTrajectory();
}

size_t size_function__QuadTrajectory__ts(const void * untyped_member)
{
  const auto * member = reinterpret_cast<const std::vector<double> *>(untyped_member);
  return member->size();
}

const void * get_const_function__QuadTrajectory__ts(const void * untyped_member, size_t index)
{
  const auto & member =
    *reinterpret_cast<const std::vector<double> *>(untyped_member);
  return &member[index];
}

void * get_function__QuadTrajectory__ts(void * untyped_member, size_t index)
{
  auto & member =
    *reinterpret_cast<std::vector<double> *>(untyped_member);
  return &member[index];
}

void resize_function__QuadTrajectory__ts(void * untyped_member, size_t size)
{
  auto * member =
    reinterpret_cast<std::vector<double> *>(untyped_member);
  member->resize(size);
}

size_t size_function__QuadTrajectory__xs(const void * untyped_member)
{
  const auto * member = reinterpret_cast<const std::vector<double> *>(untyped_member);
  return member->size();
}

const void * get_const_function__QuadTrajectory__xs(const void * untyped_member, size_t index)
{
  const auto & member =
    *reinterpret_cast<const std::vector<double> *>(untyped_member);
  return &member[index];
}

void * get_function__QuadTrajectory__xs(void * untyped_member, size_t index)
{
  auto & member =
    *reinterpret_cast<std::vector<double> *>(untyped_member);
  return &member[index];
}

void resize_function__QuadTrajectory__xs(void * untyped_member, size_t size)
{
  auto * member =
    reinterpret_cast<std::vector<double> *>(untyped_member);
  member->resize(size);
}

size_t size_function__QuadTrajectory__ys(const void * untyped_member)
{
  const auto * member = reinterpret_cast<const std::vector<double> *>(untyped_member);
  return member->size();
}

const void * get_const_function__QuadTrajectory__ys(const void * untyped_member, size_t index)
{
  const auto & member =
    *reinterpret_cast<const std::vector<double> *>(untyped_member);
  return &member[index];
}

void * get_function__QuadTrajectory__ys(void * untyped_member, size_t index)
{
  auto & member =
    *reinterpret_cast<std::vector<double> *>(untyped_member);
  return &member[index];
}

void resize_function__QuadTrajectory__ys(void * untyped_member, size_t size)
{
  auto * member =
    reinterpret_cast<std::vector<double> *>(untyped_member);
  member->resize(size);
}

size_t size_function__QuadTrajectory__zs(const void * untyped_member)
{
  const auto * member = reinterpret_cast<const std::vector<double> *>(untyped_member);
  return member->size();
}

const void * get_const_function__QuadTrajectory__zs(const void * untyped_member, size_t index)
{
  const auto & member =
    *reinterpret_cast<const std::vector<double> *>(untyped_member);
  return &member[index];
}

void * get_function__QuadTrajectory__zs(void * untyped_member, size_t index)
{
  auto & member =
    *reinterpret_cast<std::vector<double> *>(untyped_member);
  return &member[index];
}

void resize_function__QuadTrajectory__zs(void * untyped_member, size_t size)
{
  auto * member =
    reinterpret_cast<std::vector<double> *>(untyped_member);
  member->resize(size);
}

size_t size_function__QuadTrajectory__yaws(const void * untyped_member)
{
  const auto * member = reinterpret_cast<const std::vector<double> *>(untyped_member);
  return member->size();
}

const void * get_const_function__QuadTrajectory__yaws(const void * untyped_member, size_t index)
{
  const auto & member =
    *reinterpret_cast<const std::vector<double> *>(untyped_member);
  return &member[index];
}

void * get_function__QuadTrajectory__yaws(void * untyped_member, size_t index)
{
  auto & member =
    *reinterpret_cast<std::vector<double> *>(untyped_member);
  return &member[index];
}

void resize_function__QuadTrajectory__yaws(void * untyped_member, size_t size)
{
  auto * member =
    reinterpret_cast<std::vector<double> *>(untyped_member);
  member->resize(size);
}

size_t size_function__QuadTrajectory__vxs(const void * untyped_member)
{
  const auto * member = reinterpret_cast<const std::vector<double> *>(untyped_member);
  return member->size();
}

const void * get_const_function__QuadTrajectory__vxs(const void * untyped_member, size_t index)
{
  const auto & member =
    *reinterpret_cast<const std::vector<double> *>(untyped_member);
  return &member[index];
}

void * get_function__QuadTrajectory__vxs(void * untyped_member, size_t index)
{
  auto & member =
    *reinterpret_cast<std::vector<double> *>(untyped_member);
  return &member[index];
}

void resize_function__QuadTrajectory__vxs(void * untyped_member, size_t size)
{
  auto * member =
    reinterpret_cast<std::vector<double> *>(untyped_member);
  member->resize(size);
}

size_t size_function__QuadTrajectory__vys(const void * untyped_member)
{
  const auto * member = reinterpret_cast<const std::vector<double> *>(untyped_member);
  return member->size();
}

const void * get_const_function__QuadTrajectory__vys(const void * untyped_member, size_t index)
{
  const auto & member =
    *reinterpret_cast<const std::vector<double> *>(untyped_member);
  return &member[index];
}

void * get_function__QuadTrajectory__vys(void * untyped_member, size_t index)
{
  auto & member =
    *reinterpret_cast<std::vector<double> *>(untyped_member);
  return &member[index];
}

void resize_function__QuadTrajectory__vys(void * untyped_member, size_t size)
{
  auto * member =
    reinterpret_cast<std::vector<double> *>(untyped_member);
  member->resize(size);
}

size_t size_function__QuadTrajectory__vzs(const void * untyped_member)
{
  const auto * member = reinterpret_cast<const std::vector<double> *>(untyped_member);
  return member->size();
}

const void * get_const_function__QuadTrajectory__vzs(const void * untyped_member, size_t index)
{
  const auto & member =
    *reinterpret_cast<const std::vector<double> *>(untyped_member);
  return &member[index];
}

void * get_function__QuadTrajectory__vzs(void * untyped_member, size_t index)
{
  auto & member =
    *reinterpret_cast<std::vector<double> *>(untyped_member);
  return &member[index];
}

void resize_function__QuadTrajectory__vzs(void * untyped_member, size_t size)
{
  auto * member =
    reinterpret_cast<std::vector<double> *>(untyped_member);
  member->resize(size);
}

static const ::rosidl_typesupport_introspection_cpp::MessageMember QuadTrajectory_message_member_array[9] = {
  {
    "header",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    ::rosidl_typesupport_introspection_cpp::get_message_type_support_handle<std_msgs::msg::Header>(),  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(dasc_msgs::msg::QuadTrajectory, header),  // bytes offset in struct
    nullptr,  // default value
    nullptr,  // size() function pointer
    nullptr,  // get_const(index) function pointer
    nullptr,  // get(index) function pointer
    nullptr  // resize(index) function pointer
  },
  {
    "ts",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_DOUBLE,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(dasc_msgs::msg::QuadTrajectory, ts),  // bytes offset in struct
    nullptr,  // default value
    size_function__QuadTrajectory__ts,  // size() function pointer
    get_const_function__QuadTrajectory__ts,  // get_const(index) function pointer
    get_function__QuadTrajectory__ts,  // get(index) function pointer
    resize_function__QuadTrajectory__ts  // resize(index) function pointer
  },
  {
    "xs",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_DOUBLE,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(dasc_msgs::msg::QuadTrajectory, xs),  // bytes offset in struct
    nullptr,  // default value
    size_function__QuadTrajectory__xs,  // size() function pointer
    get_const_function__QuadTrajectory__xs,  // get_const(index) function pointer
    get_function__QuadTrajectory__xs,  // get(index) function pointer
    resize_function__QuadTrajectory__xs  // resize(index) function pointer
  },
  {
    "ys",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_DOUBLE,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(dasc_msgs::msg::QuadTrajectory, ys),  // bytes offset in struct
    nullptr,  // default value
    size_function__QuadTrajectory__ys,  // size() function pointer
    get_const_function__QuadTrajectory__ys,  // get_const(index) function pointer
    get_function__QuadTrajectory__ys,  // get(index) function pointer
    resize_function__QuadTrajectory__ys  // resize(index) function pointer
  },
  {
    "zs",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_DOUBLE,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(dasc_msgs::msg::QuadTrajectory, zs),  // bytes offset in struct
    nullptr,  // default value
    size_function__QuadTrajectory__zs,  // size() function pointer
    get_const_function__QuadTrajectory__zs,  // get_const(index) function pointer
    get_function__QuadTrajectory__zs,  // get(index) function pointer
    resize_function__QuadTrajectory__zs  // resize(index) function pointer
  },
  {
    "yaws",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_DOUBLE,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(dasc_msgs::msg::QuadTrajectory, yaws),  // bytes offset in struct
    nullptr,  // default value
    size_function__QuadTrajectory__yaws,  // size() function pointer
    get_const_function__QuadTrajectory__yaws,  // get_const(index) function pointer
    get_function__QuadTrajectory__yaws,  // get(index) function pointer
    resize_function__QuadTrajectory__yaws  // resize(index) function pointer
  },
  {
    "vxs",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_DOUBLE,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(dasc_msgs::msg::QuadTrajectory, vxs),  // bytes offset in struct
    nullptr,  // default value
    size_function__QuadTrajectory__vxs,  // size() function pointer
    get_const_function__QuadTrajectory__vxs,  // get_const(index) function pointer
    get_function__QuadTrajectory__vxs,  // get(index) function pointer
    resize_function__QuadTrajectory__vxs  // resize(index) function pointer
  },
  {
    "vys",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_DOUBLE,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(dasc_msgs::msg::QuadTrajectory, vys),  // bytes offset in struct
    nullptr,  // default value
    size_function__QuadTrajectory__vys,  // size() function pointer
    get_const_function__QuadTrajectory__vys,  // get_const(index) function pointer
    get_function__QuadTrajectory__vys,  // get(index) function pointer
    resize_function__QuadTrajectory__vys  // resize(index) function pointer
  },
  {
    "vzs",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_DOUBLE,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(dasc_msgs::msg::QuadTrajectory, vzs),  // bytes offset in struct
    nullptr,  // default value
    size_function__QuadTrajectory__vzs,  // size() function pointer
    get_const_function__QuadTrajectory__vzs,  // get_const(index) function pointer
    get_function__QuadTrajectory__vzs,  // get(index) function pointer
    resize_function__QuadTrajectory__vzs  // resize(index) function pointer
  }
};

static const ::rosidl_typesupport_introspection_cpp::MessageMembers QuadTrajectory_message_members = {
  "dasc_msgs::msg",  // message namespace
  "QuadTrajectory",  // message name
  9,  // number of fields
  sizeof(dasc_msgs::msg::QuadTrajectory),
  QuadTrajectory_message_member_array,  // message members
  QuadTrajectory_init_function,  // function to initialize message memory (memory has to be allocated)
  QuadTrajectory_fini_function  // function to terminate message instance (will not free memory)
};

static const rosidl_message_type_support_t QuadTrajectory_message_type_support_handle = {
  ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
  &QuadTrajectory_message_members,
  get_message_typesupport_handle_function,
};

}  // namespace rosidl_typesupport_introspection_cpp

}  // namespace msg

}  // namespace dasc_msgs


namespace rosidl_typesupport_introspection_cpp
{

template<>
ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_message_type_support_t *
get_message_type_support_handle<dasc_msgs::msg::QuadTrajectory>()
{
  return &::dasc_msgs::msg::rosidl_typesupport_introspection_cpp::QuadTrajectory_message_type_support_handle;
}

}  // namespace rosidl_typesupport_introspection_cpp

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, dasc_msgs, msg, QuadTrajectory)() {
  return &::dasc_msgs::msg::rosidl_typesupport_introspection_cpp::QuadTrajectory_message_type_support_handle;
}

#ifdef __cplusplus
}
#endif
