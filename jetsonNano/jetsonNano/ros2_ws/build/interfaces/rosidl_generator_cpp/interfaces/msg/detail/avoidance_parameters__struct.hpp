// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from interfaces:msg/AvoidanceParameters.idl
// generated code does not contain a copyright notice

#ifndef INTERFACES__MSG__DETAIL__AVOIDANCE_PARAMETERS__STRUCT_HPP_
#define INTERFACES__MSG__DETAIL__AVOIDANCE_PARAMETERS__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


#ifndef _WIN32
# define DEPRECATED__interfaces__msg__AvoidanceParameters __attribute__((deprecated))
#else
# define DEPRECATED__interfaces__msg__AvoidanceParameters __declspec(deprecated)
#endif

namespace interfaces
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct AvoidanceParameters_
{
  using Type = AvoidanceParameters_<ContainerAllocator>;

  explicit AvoidanceParameters_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->left = false;
      this->big = false;
    }
  }

  explicit AvoidanceParameters_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_alloc;
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->left = false;
      this->big = false;
    }
  }

  // field types and members
  using _left_type =
    bool;
  _left_type left;
  using _big_type =
    bool;
  _big_type big;

  // setters for named parameter idiom
  Type & set__left(
    const bool & _arg)
  {
    this->left = _arg;
    return *this;
  }
  Type & set__big(
    const bool & _arg)
  {
    this->big = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    interfaces::msg::AvoidanceParameters_<ContainerAllocator> *;
  using ConstRawPtr =
    const interfaces::msg::AvoidanceParameters_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<interfaces::msg::AvoidanceParameters_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<interfaces::msg::AvoidanceParameters_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      interfaces::msg::AvoidanceParameters_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<interfaces::msg::AvoidanceParameters_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      interfaces::msg::AvoidanceParameters_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<interfaces::msg::AvoidanceParameters_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<interfaces::msg::AvoidanceParameters_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<interfaces::msg::AvoidanceParameters_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__interfaces__msg__AvoidanceParameters
    std::shared_ptr<interfaces::msg::AvoidanceParameters_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__interfaces__msg__AvoidanceParameters
    std::shared_ptr<interfaces::msg::AvoidanceParameters_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const AvoidanceParameters_ & other) const
  {
    if (this->left != other.left) {
      return false;
    }
    if (this->big != other.big) {
      return false;
    }
    return true;
  }
  bool operator!=(const AvoidanceParameters_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct AvoidanceParameters_

// alias to use template instance with default allocator
using AvoidanceParameters =
  interfaces::msg::AvoidanceParameters_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace interfaces

#endif  // INTERFACES__MSG__DETAIL__AVOIDANCE_PARAMETERS__STRUCT_HPP_
