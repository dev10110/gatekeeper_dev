// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from dasc_msgs:msg/QuadTrajectory.idl
// generated code does not contain a copyright notice

#ifndef DASC_MSGS__MSG__DETAIL__QUAD_TRAJECTORY__STRUCT_HPP_
#define DASC_MSGS__MSG__DETAIL__QUAD_TRAJECTORY__STRUCT_HPP_

#include <rosidl_runtime_cpp/bounded_vector.hpp>
#include <rosidl_runtime_cpp/message_initialization.hpp>
#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>


// Include directives for member types
// Member 'header'
#include "std_msgs/msg/detail/header__struct.hpp"

#ifndef _WIN32
# define DEPRECATED__dasc_msgs__msg__QuadTrajectory __attribute__((deprecated))
#else
# define DEPRECATED__dasc_msgs__msg__QuadTrajectory __declspec(deprecated)
#endif

namespace dasc_msgs
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct QuadTrajectory_
{
  using Type = QuadTrajectory_<ContainerAllocator>;

  explicit QuadTrajectory_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : header(_init)
  {
    (void)_init;
  }

  explicit QuadTrajectory_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : header(_alloc, _init)
  {
    (void)_init;
  }

  // field types and members
  using _header_type =
    std_msgs::msg::Header_<ContainerAllocator>;
  _header_type header;
  using _ts_type =
    std::vector<double, typename ContainerAllocator::template rebind<double>::other>;
  _ts_type ts;
  using _xs_type =
    std::vector<double, typename ContainerAllocator::template rebind<double>::other>;
  _xs_type xs;
  using _ys_type =
    std::vector<double, typename ContainerAllocator::template rebind<double>::other>;
  _ys_type ys;
  using _zs_type =
    std::vector<double, typename ContainerAllocator::template rebind<double>::other>;
  _zs_type zs;
  using _yaws_type =
    std::vector<double, typename ContainerAllocator::template rebind<double>::other>;
  _yaws_type yaws;
  using _vxs_type =
    std::vector<double, typename ContainerAllocator::template rebind<double>::other>;
  _vxs_type vxs;
  using _vys_type =
    std::vector<double, typename ContainerAllocator::template rebind<double>::other>;
  _vys_type vys;
  using _vzs_type =
    std::vector<double, typename ContainerAllocator::template rebind<double>::other>;
  _vzs_type vzs;

  // setters for named parameter idiom
  Type & set__header(
    const std_msgs::msg::Header_<ContainerAllocator> & _arg)
  {
    this->header = _arg;
    return *this;
  }
  Type & set__ts(
    const std::vector<double, typename ContainerAllocator::template rebind<double>::other> & _arg)
  {
    this->ts = _arg;
    return *this;
  }
  Type & set__xs(
    const std::vector<double, typename ContainerAllocator::template rebind<double>::other> & _arg)
  {
    this->xs = _arg;
    return *this;
  }
  Type & set__ys(
    const std::vector<double, typename ContainerAllocator::template rebind<double>::other> & _arg)
  {
    this->ys = _arg;
    return *this;
  }
  Type & set__zs(
    const std::vector<double, typename ContainerAllocator::template rebind<double>::other> & _arg)
  {
    this->zs = _arg;
    return *this;
  }
  Type & set__yaws(
    const std::vector<double, typename ContainerAllocator::template rebind<double>::other> & _arg)
  {
    this->yaws = _arg;
    return *this;
  }
  Type & set__vxs(
    const std::vector<double, typename ContainerAllocator::template rebind<double>::other> & _arg)
  {
    this->vxs = _arg;
    return *this;
  }
  Type & set__vys(
    const std::vector<double, typename ContainerAllocator::template rebind<double>::other> & _arg)
  {
    this->vys = _arg;
    return *this;
  }
  Type & set__vzs(
    const std::vector<double, typename ContainerAllocator::template rebind<double>::other> & _arg)
  {
    this->vzs = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    dasc_msgs::msg::QuadTrajectory_<ContainerAllocator> *;
  using ConstRawPtr =
    const dasc_msgs::msg::QuadTrajectory_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<dasc_msgs::msg::QuadTrajectory_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<dasc_msgs::msg::QuadTrajectory_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      dasc_msgs::msg::QuadTrajectory_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<dasc_msgs::msg::QuadTrajectory_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      dasc_msgs::msg::QuadTrajectory_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<dasc_msgs::msg::QuadTrajectory_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<dasc_msgs::msg::QuadTrajectory_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<dasc_msgs::msg::QuadTrajectory_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__dasc_msgs__msg__QuadTrajectory
    std::shared_ptr<dasc_msgs::msg::QuadTrajectory_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__dasc_msgs__msg__QuadTrajectory
    std::shared_ptr<dasc_msgs::msg::QuadTrajectory_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const QuadTrajectory_ & other) const
  {
    if (this->header != other.header) {
      return false;
    }
    if (this->ts != other.ts) {
      return false;
    }
    if (this->xs != other.xs) {
      return false;
    }
    if (this->ys != other.ys) {
      return false;
    }
    if (this->zs != other.zs) {
      return false;
    }
    if (this->yaws != other.yaws) {
      return false;
    }
    if (this->vxs != other.vxs) {
      return false;
    }
    if (this->vys != other.vys) {
      return false;
    }
    if (this->vzs != other.vzs) {
      return false;
    }
    return true;
  }
  bool operator!=(const QuadTrajectory_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct QuadTrajectory_

// alias to use template instance with default allocator
using QuadTrajectory =
  dasc_msgs::msg::QuadTrajectory_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace dasc_msgs

#endif  // DASC_MSGS__MSG__DETAIL__QUAD_TRAJECTORY__STRUCT_HPP_
