// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from px4_msgs:msg/ExternalController.idl
// generated code does not contain a copyright notice

#ifndef PX4_MSGS__MSG__DETAIL__EXTERNAL_CONTROLLER__STRUCT_HPP_
#define PX4_MSGS__MSG__DETAIL__EXTERNAL_CONTROLLER__STRUCT_HPP_

#include <rosidl_runtime_cpp/bounded_vector.hpp>
#include <rosidl_runtime_cpp/message_initialization.hpp>
#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>


#ifndef _WIN32
# define DEPRECATED__px4_msgs__msg__ExternalController __attribute__((deprecated))
#else
# define DEPRECATED__px4_msgs__msg__ExternalController __declspec(deprecated)
#endif

namespace px4_msgs
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct ExternalController_
{
  using Type = ExternalController_<ContainerAllocator>;

  explicit ExternalController_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->timestamp = 0ull;
      this->use_geometric_control = false;
    }
  }

  explicit ExternalController_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_alloc;
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->timestamp = 0ull;
      this->use_geometric_control = false;
    }
  }

  // field types and members
  using _timestamp_type =
    uint64_t;
  _timestamp_type timestamp;
  using _use_geometric_control_type =
    bool;
  _use_geometric_control_type use_geometric_control;

  // setters for named parameter idiom
  Type & set__timestamp(
    const uint64_t & _arg)
  {
    this->timestamp = _arg;
    return *this;
  }
  Type & set__use_geometric_control(
    const bool & _arg)
  {
    this->use_geometric_control = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    px4_msgs::msg::ExternalController_<ContainerAllocator> *;
  using ConstRawPtr =
    const px4_msgs::msg::ExternalController_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<px4_msgs::msg::ExternalController_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<px4_msgs::msg::ExternalController_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      px4_msgs::msg::ExternalController_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<px4_msgs::msg::ExternalController_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      px4_msgs::msg::ExternalController_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<px4_msgs::msg::ExternalController_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<px4_msgs::msg::ExternalController_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<px4_msgs::msg::ExternalController_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__px4_msgs__msg__ExternalController
    std::shared_ptr<px4_msgs::msg::ExternalController_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__px4_msgs__msg__ExternalController
    std::shared_ptr<px4_msgs::msg::ExternalController_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const ExternalController_ & other) const
  {
    if (this->timestamp != other.timestamp) {
      return false;
    }
    if (this->use_geometric_control != other.use_geometric_control) {
      return false;
    }
    return true;
  }
  bool operator!=(const ExternalController_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct ExternalController_

// alias to use template instance with default allocator
using ExternalController =
  px4_msgs::msg::ExternalController_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace px4_msgs

#endif  // PX4_MSGS__MSG__DETAIL__EXTERNAL_CONTROLLER__STRUCT_HPP_
