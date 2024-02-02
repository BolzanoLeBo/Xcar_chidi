// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from interfaces:msg/ObstaclesId.idl
// generated code does not contain a copyright notice

#ifndef INTERFACES__MSG__DETAIL__OBSTACLES_ID__STRUCT_HPP_
#define INTERFACES__MSG__DETAIL__OBSTACLES_ID__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


#ifndef _WIN32
# define DEPRECATED__interfaces__msg__ObstaclesId __attribute__((deprecated))
#else
# define DEPRECATED__interfaces__msg__ObstaclesId __declspec(deprecated)
#endif

namespace interfaces
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct ObstaclesId_
{
  using Type = ObstaclesId_<ContainerAllocator>;

  explicit ObstaclesId_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->obstacle_left = false;
      this->obstacle_middle = false;
      this->obstacle_right = false;
      this->big_obstacle = false;
    }
  }

  explicit ObstaclesId_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_alloc;
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->obstacle_left = false;
      this->obstacle_middle = false;
      this->obstacle_right = false;
      this->big_obstacle = false;
    }
  }

  // field types and members
  using _obstacle_left_type =
    bool;
  _obstacle_left_type obstacle_left;
  using _obstacle_middle_type =
    bool;
  _obstacle_middle_type obstacle_middle;
  using _obstacle_right_type =
    bool;
  _obstacle_right_type obstacle_right;
  using _big_obstacle_type =
    bool;
  _big_obstacle_type big_obstacle;

  // setters for named parameter idiom
  Type & set__obstacle_left(
    const bool & _arg)
  {
    this->obstacle_left = _arg;
    return *this;
  }
  Type & set__obstacle_middle(
    const bool & _arg)
  {
    this->obstacle_middle = _arg;
    return *this;
  }
  Type & set__obstacle_right(
    const bool & _arg)
  {
    this->obstacle_right = _arg;
    return *this;
  }
  Type & set__big_obstacle(
    const bool & _arg)
  {
    this->big_obstacle = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    interfaces::msg::ObstaclesId_<ContainerAllocator> *;
  using ConstRawPtr =
    const interfaces::msg::ObstaclesId_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<interfaces::msg::ObstaclesId_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<interfaces::msg::ObstaclesId_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      interfaces::msg::ObstaclesId_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<interfaces::msg::ObstaclesId_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      interfaces::msg::ObstaclesId_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<interfaces::msg::ObstaclesId_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<interfaces::msg::ObstaclesId_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<interfaces::msg::ObstaclesId_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__interfaces__msg__ObstaclesId
    std::shared_ptr<interfaces::msg::ObstaclesId_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__interfaces__msg__ObstaclesId
    std::shared_ptr<interfaces::msg::ObstaclesId_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const ObstaclesId_ & other) const
  {
    if (this->obstacle_left != other.obstacle_left) {
      return false;
    }
    if (this->obstacle_middle != other.obstacle_middle) {
      return false;
    }
    if (this->obstacle_right != other.obstacle_right) {
      return false;
    }
    if (this->big_obstacle != other.big_obstacle) {
      return false;
    }
    return true;
  }
  bool operator!=(const ObstaclesId_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct ObstaclesId_

// alias to use template instance with default allocator
using ObstaclesId =
  interfaces::msg::ObstaclesId_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace interfaces

#endif  // INTERFACES__MSG__DETAIL__OBSTACLES_ID__STRUCT_HPP_
