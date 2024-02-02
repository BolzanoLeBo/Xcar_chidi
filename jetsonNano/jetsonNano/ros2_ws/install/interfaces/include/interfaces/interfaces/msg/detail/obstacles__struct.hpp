// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from interfaces:msg/Obstacles.idl
// generated code does not contain a copyright notice

#ifndef INTERFACES__MSG__DETAIL__OBSTACLES__STRUCT_HPP_
#define INTERFACES__MSG__DETAIL__OBSTACLES__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


#ifndef _WIN32
# define DEPRECATED__interfaces__msg__Obstacles __attribute__((deprecated))
#else
# define DEPRECATED__interfaces__msg__Obstacles __declspec(deprecated)
#endif

namespace interfaces
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct Obstacles_
{
  using Type = Obstacles_<ContainerAllocator>;

  explicit Obstacles_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::DEFAULTS_ONLY == _init)
    {
      this->front = 0;
      this->rear = 0;
      this->us_error = 0;
      this->lidar_error = 0;
    } else if (rosidl_runtime_cpp::MessageInitialization::ZERO == _init) {
      this->front = 0;
      this->rear = 0;
      this->us_error = 0;
      this->lidar_error = 0;
    }
  }

  explicit Obstacles_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_alloc;
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::DEFAULTS_ONLY == _init)
    {
      this->front = 0;
      this->rear = 0;
      this->us_error = 0;
      this->lidar_error = 0;
    } else if (rosidl_runtime_cpp::MessageInitialization::ZERO == _init) {
      this->front = 0;
      this->rear = 0;
      this->us_error = 0;
      this->lidar_error = 0;
    }
  }

  // field types and members
  using _front_type =
    int8_t;
  _front_type front;
  using _rear_type =
    int8_t;
  _rear_type rear;
  using _us_error_type =
    int8_t;
  _us_error_type us_error;
  using _lidar_error_type =
    int8_t;
  _lidar_error_type lidar_error;

  // setters for named parameter idiom
  Type & set__front(
    const int8_t & _arg)
  {
    this->front = _arg;
    return *this;
  }
  Type & set__rear(
    const int8_t & _arg)
  {
    this->rear = _arg;
    return *this;
  }
  Type & set__us_error(
    const int8_t & _arg)
  {
    this->us_error = _arg;
    return *this;
  }
  Type & set__lidar_error(
    const int8_t & _arg)
  {
    this->lidar_error = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    interfaces::msg::Obstacles_<ContainerAllocator> *;
  using ConstRawPtr =
    const interfaces::msg::Obstacles_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<interfaces::msg::Obstacles_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<interfaces::msg::Obstacles_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      interfaces::msg::Obstacles_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<interfaces::msg::Obstacles_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      interfaces::msg::Obstacles_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<interfaces::msg::Obstacles_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<interfaces::msg::Obstacles_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<interfaces::msg::Obstacles_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__interfaces__msg__Obstacles
    std::shared_ptr<interfaces::msg::Obstacles_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__interfaces__msg__Obstacles
    std::shared_ptr<interfaces::msg::Obstacles_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const Obstacles_ & other) const
  {
    if (this->front != other.front) {
      return false;
    }
    if (this->rear != other.rear) {
      return false;
    }
    if (this->us_error != other.us_error) {
      return false;
    }
    if (this->lidar_error != other.lidar_error) {
      return false;
    }
    return true;
  }
  bool operator!=(const Obstacles_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct Obstacles_

// alias to use template instance with default allocator
using Obstacles =
  interfaces::msg::Obstacles_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace interfaces

#endif  // INTERFACES__MSG__DETAIL__OBSTACLES__STRUCT_HPP_
