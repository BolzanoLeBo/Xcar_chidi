// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from interfaces:msg/Lidar.idl
// generated code does not contain a copyright notice

#ifndef INTERFACES__MSG__DETAIL__LIDAR__STRUCT_HPP_
#define INTERFACES__MSG__DETAIL__LIDAR__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


#ifndef _WIN32
# define DEPRECATED__interfaces__msg__Lidar __attribute__((deprecated))
#else
# define DEPRECATED__interfaces__msg__Lidar __declspec(deprecated)
#endif

namespace interfaces
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct Lidar_
{
  using Type = Lidar_<ContainerAllocator>;

  explicit Lidar_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::DEFAULTS_ONLY == _init)
    {
      this->left_lidar = false;
      this->right_lidar = false;
    } else if (rosidl_runtime_cpp::MessageInitialization::ZERO == _init) {
      this->left_lidar = false;
      this->right_lidar = false;
      this->left_min = 0.0f;
      this->right_min = 0.0f;
    }
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->left_min = 0.0f;
      this->right_min = 0.0f;
    }
  }

  explicit Lidar_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_alloc;
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::DEFAULTS_ONLY == _init)
    {
      this->left_lidar = false;
      this->right_lidar = false;
    } else if (rosidl_runtime_cpp::MessageInitialization::ZERO == _init) {
      this->left_lidar = false;
      this->right_lidar = false;
      this->left_min = 0.0f;
      this->right_min = 0.0f;
    }
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->left_min = 0.0f;
      this->right_min = 0.0f;
    }
  }

  // field types and members
  using _left_lidar_type =
    bool;
  _left_lidar_type left_lidar;
  using _right_lidar_type =
    bool;
  _right_lidar_type right_lidar;
  using _left_min_type =
    float;
  _left_min_type left_min;
  using _right_min_type =
    float;
  _right_min_type right_min;

  // setters for named parameter idiom
  Type & set__left_lidar(
    const bool & _arg)
  {
    this->left_lidar = _arg;
    return *this;
  }
  Type & set__right_lidar(
    const bool & _arg)
  {
    this->right_lidar = _arg;
    return *this;
  }
  Type & set__left_min(
    const float & _arg)
  {
    this->left_min = _arg;
    return *this;
  }
  Type & set__right_min(
    const float & _arg)
  {
    this->right_min = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    interfaces::msg::Lidar_<ContainerAllocator> *;
  using ConstRawPtr =
    const interfaces::msg::Lidar_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<interfaces::msg::Lidar_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<interfaces::msg::Lidar_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      interfaces::msg::Lidar_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<interfaces::msg::Lidar_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      interfaces::msg::Lidar_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<interfaces::msg::Lidar_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<interfaces::msg::Lidar_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<interfaces::msg::Lidar_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__interfaces__msg__Lidar
    std::shared_ptr<interfaces::msg::Lidar_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__interfaces__msg__Lidar
    std::shared_ptr<interfaces::msg::Lidar_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const Lidar_ & other) const
  {
    if (this->left_lidar != other.left_lidar) {
      return false;
    }
    if (this->right_lidar != other.right_lidar) {
      return false;
    }
    if (this->left_min != other.left_min) {
      return false;
    }
    if (this->right_min != other.right_min) {
      return false;
    }
    return true;
  }
  bool operator!=(const Lidar_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct Lidar_

// alias to use template instance with default allocator
using Lidar =
  interfaces::msg::Lidar_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace interfaces

#endif  // INTERFACES__MSG__DETAIL__LIDAR__STRUCT_HPP_
