// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from interfaces:msg/Userdistance.idl
// generated code does not contain a copyright notice

#ifndef INTERFACES__MSG__DETAIL__USERDISTANCE__STRUCT_HPP_
#define INTERFACES__MSG__DETAIL__USERDISTANCE__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


#ifndef _WIN32
# define DEPRECATED__interfaces__msg__Userdistance __attribute__((deprecated))
#else
# define DEPRECATED__interfaces__msg__Userdistance __declspec(deprecated)
#endif

namespace interfaces
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct Userdistance_
{
  using Type = Userdistance_<ContainerAllocator>;

  explicit Userdistance_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->distance_tracking = 0.0f;
    }
  }

  explicit Userdistance_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_alloc;
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->distance_tracking = 0.0f;
    }
  }

  // field types and members
  using _distance_tracking_type =
    float;
  _distance_tracking_type distance_tracking;

  // setters for named parameter idiom
  Type & set__distance_tracking(
    const float & _arg)
  {
    this->distance_tracking = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    interfaces::msg::Userdistance_<ContainerAllocator> *;
  using ConstRawPtr =
    const interfaces::msg::Userdistance_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<interfaces::msg::Userdistance_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<interfaces::msg::Userdistance_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      interfaces::msg::Userdistance_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<interfaces::msg::Userdistance_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      interfaces::msg::Userdistance_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<interfaces::msg::Userdistance_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<interfaces::msg::Userdistance_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<interfaces::msg::Userdistance_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__interfaces__msg__Userdistance
    std::shared_ptr<interfaces::msg::Userdistance_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__interfaces__msg__Userdistance
    std::shared_ptr<interfaces::msg::Userdistance_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const Userdistance_ & other) const
  {
    if (this->distance_tracking != other.distance_tracking) {
      return false;
    }
    return true;
  }
  bool operator!=(const Userdistance_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct Userdistance_

// alias to use template instance with default allocator
using Userdistance =
  interfaces::msg::Userdistance_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace interfaces

#endif  // INTERFACES__MSG__DETAIL__USERDISTANCE__STRUCT_HPP_
