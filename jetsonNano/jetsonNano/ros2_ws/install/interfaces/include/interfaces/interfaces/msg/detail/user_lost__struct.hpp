// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from interfaces:msg/UserLost.idl
// generated code does not contain a copyright notice

#ifndef INTERFACES__MSG__DETAIL__USER_LOST__STRUCT_HPP_
#define INTERFACES__MSG__DETAIL__USER_LOST__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


#ifndef _WIN32
# define DEPRECATED__interfaces__msg__UserLost __attribute__((deprecated))
#else
# define DEPRECATED__interfaces__msg__UserLost __declspec(deprecated)
#endif

namespace interfaces
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct UserLost_
{
  using Type = UserLost_<ContainerAllocator>;

  explicit UserLost_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::DEFAULTS_ONLY == _init)
    {
      this->lost = false;
    } else if (rosidl_runtime_cpp::MessageInitialization::ZERO == _init) {
      this->lost = false;
    }
  }

  explicit UserLost_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_alloc;
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::DEFAULTS_ONLY == _init)
    {
      this->lost = false;
    } else if (rosidl_runtime_cpp::MessageInitialization::ZERO == _init) {
      this->lost = false;
    }
  }

  // field types and members
  using _lost_type =
    bool;
  _lost_type lost;

  // setters for named parameter idiom
  Type & set__lost(
    const bool & _arg)
  {
    this->lost = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    interfaces::msg::UserLost_<ContainerAllocator> *;
  using ConstRawPtr =
    const interfaces::msg::UserLost_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<interfaces::msg::UserLost_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<interfaces::msg::UserLost_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      interfaces::msg::UserLost_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<interfaces::msg::UserLost_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      interfaces::msg::UserLost_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<interfaces::msg::UserLost_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<interfaces::msg::UserLost_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<interfaces::msg::UserLost_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__interfaces__msg__UserLost
    std::shared_ptr<interfaces::msg::UserLost_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__interfaces__msg__UserLost
    std::shared_ptr<interfaces::msg::UserLost_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const UserLost_ & other) const
  {
    if (this->lost != other.lost) {
      return false;
    }
    return true;
  }
  bool operator!=(const UserLost_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct UserLost_

// alias to use template instance with default allocator
using UserLost =
  interfaces::msg::UserLost_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace interfaces

#endif  // INTERFACES__MSG__DETAIL__USER_LOST__STRUCT_HPP_
