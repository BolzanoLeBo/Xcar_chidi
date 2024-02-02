// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from interfaces:msg/InitButton.idl
// generated code does not contain a copyright notice

#ifndef INTERFACES__MSG__DETAIL__INIT_BUTTON__STRUCT_HPP_
#define INTERFACES__MSG__DETAIL__INIT_BUTTON__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


#ifndef _WIN32
# define DEPRECATED__interfaces__msg__InitButton __attribute__((deprecated))
#else
# define DEPRECATED__interfaces__msg__InitButton __declspec(deprecated)
#endif

namespace interfaces
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct InitButton_
{
  using Type = InitButton_<ContainerAllocator>;

  explicit InitButton_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::DEFAULTS_ONLY == _init)
    {
      this->button = false;
    } else if (rosidl_runtime_cpp::MessageInitialization::ZERO == _init) {
      this->button = false;
    }
  }

  explicit InitButton_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_alloc;
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::DEFAULTS_ONLY == _init)
    {
      this->button = false;
    } else if (rosidl_runtime_cpp::MessageInitialization::ZERO == _init) {
      this->button = false;
    }
  }

  // field types and members
  using _button_type =
    bool;
  _button_type button;

  // setters for named parameter idiom
  Type & set__button(
    const bool & _arg)
  {
    this->button = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    interfaces::msg::InitButton_<ContainerAllocator> *;
  using ConstRawPtr =
    const interfaces::msg::InitButton_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<interfaces::msg::InitButton_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<interfaces::msg::InitButton_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      interfaces::msg::InitButton_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<interfaces::msg::InitButton_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      interfaces::msg::InitButton_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<interfaces::msg::InitButton_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<interfaces::msg::InitButton_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<interfaces::msg::InitButton_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__interfaces__msg__InitButton
    std::shared_ptr<interfaces::msg::InitButton_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__interfaces__msg__InitButton
    std::shared_ptr<interfaces::msg::InitButton_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const InitButton_ & other) const
  {
    if (this->button != other.button) {
      return false;
    }
    return true;
  }
  bool operator!=(const InitButton_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct InitButton_

// alias to use template instance with default allocator
using InitButton =
  interfaces::msg::InitButton_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace interfaces

#endif  // INTERFACES__MSG__DETAIL__INIT_BUTTON__STRUCT_HPP_
