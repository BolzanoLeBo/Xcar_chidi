// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from interfaces:msg/WebMode.idl
// generated code does not contain a copyright notice

#ifndef INTERFACES__MSG__DETAIL__WEB_MODE__STRUCT_HPP_
#define INTERFACES__MSG__DETAIL__WEB_MODE__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


#ifndef _WIN32
# define DEPRECATED__interfaces__msg__WebMode __attribute__((deprecated))
#else
# define DEPRECATED__interfaces__msg__WebMode __declspec(deprecated)
#endif

namespace interfaces
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct WebMode_
{
  using Type = WebMode_<ContainerAllocator>;

  explicit WebMode_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::DEFAULTS_ONLY == _init)
    {
      this->button = 0;
      this->throttle = 0.0f;
      this->steering = 0.0f;
      this->reverse = false;
    } else if (rosidl_runtime_cpp::MessageInitialization::ZERO == _init) {
      this->button = 0;
      this->throttle = 0.0f;
      this->steering = 0.0f;
      this->reverse = false;
    }
  }

  explicit WebMode_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_alloc;
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::DEFAULTS_ONLY == _init)
    {
      this->button = 0;
      this->throttle = 0.0f;
      this->steering = 0.0f;
      this->reverse = false;
    } else if (rosidl_runtime_cpp::MessageInitialization::ZERO == _init) {
      this->button = 0;
      this->throttle = 0.0f;
      this->steering = 0.0f;
      this->reverse = false;
    }
  }

  // field types and members
  using _button_type =
    int8_t;
  _button_type button;
  using _throttle_type =
    float;
  _throttle_type throttle;
  using _steering_type =
    float;
  _steering_type steering;
  using _reverse_type =
    bool;
  _reverse_type reverse;

  // setters for named parameter idiom
  Type & set__button(
    const int8_t & _arg)
  {
    this->button = _arg;
    return *this;
  }
  Type & set__throttle(
    const float & _arg)
  {
    this->throttle = _arg;
    return *this;
  }
  Type & set__steering(
    const float & _arg)
  {
    this->steering = _arg;
    return *this;
  }
  Type & set__reverse(
    const bool & _arg)
  {
    this->reverse = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    interfaces::msg::WebMode_<ContainerAllocator> *;
  using ConstRawPtr =
    const interfaces::msg::WebMode_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<interfaces::msg::WebMode_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<interfaces::msg::WebMode_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      interfaces::msg::WebMode_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<interfaces::msg::WebMode_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      interfaces::msg::WebMode_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<interfaces::msg::WebMode_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<interfaces::msg::WebMode_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<interfaces::msg::WebMode_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__interfaces__msg__WebMode
    std::shared_ptr<interfaces::msg::WebMode_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__interfaces__msg__WebMode
    std::shared_ptr<interfaces::msg::WebMode_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const WebMode_ & other) const
  {
    if (this->button != other.button) {
      return false;
    }
    if (this->throttle != other.throttle) {
      return false;
    }
    if (this->steering != other.steering) {
      return false;
    }
    if (this->reverse != other.reverse) {
      return false;
    }
    return true;
  }
  bool operator!=(const WebMode_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct WebMode_

// alias to use template instance with default allocator
using WebMode =
  interfaces::msg::WebMode_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace interfaces

#endif  // INTERFACES__MSG__DETAIL__WEB_MODE__STRUCT_HPP_
