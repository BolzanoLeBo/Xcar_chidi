// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from interfaces:msg/TrackingPosAngle.idl
// generated code does not contain a copyright notice

#ifndef INTERFACES__MSG__DETAIL__TRACKING_POS_ANGLE__STRUCT_HPP_
#define INTERFACES__MSG__DETAIL__TRACKING_POS_ANGLE__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


#ifndef _WIN32
# define DEPRECATED__interfaces__msg__TrackingPosAngle __attribute__((deprecated))
#else
# define DEPRECATED__interfaces__msg__TrackingPosAngle __declspec(deprecated)
#endif

namespace interfaces
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct TrackingPosAngle_
{
  using Type = TrackingPosAngle_<ContainerAllocator>;

  explicit TrackingPosAngle_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->min_angle = 0.0f;
      this->max_angle = 0.0f;
      this->cam_angle = 0.0f;
      this->person_detected = false;
    }
  }

  explicit TrackingPosAngle_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_alloc;
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->min_angle = 0.0f;
      this->max_angle = 0.0f;
      this->cam_angle = 0.0f;
      this->person_detected = false;
    }
  }

  // field types and members
  using _min_angle_type =
    float;
  _min_angle_type min_angle;
  using _max_angle_type =
    float;
  _max_angle_type max_angle;
  using _cam_angle_type =
    float;
  _cam_angle_type cam_angle;
  using _person_detected_type =
    bool;
  _person_detected_type person_detected;

  // setters for named parameter idiom
  Type & set__min_angle(
    const float & _arg)
  {
    this->min_angle = _arg;
    return *this;
  }
  Type & set__max_angle(
    const float & _arg)
  {
    this->max_angle = _arg;
    return *this;
  }
  Type & set__cam_angle(
    const float & _arg)
  {
    this->cam_angle = _arg;
    return *this;
  }
  Type & set__person_detected(
    const bool & _arg)
  {
    this->person_detected = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    interfaces::msg::TrackingPosAngle_<ContainerAllocator> *;
  using ConstRawPtr =
    const interfaces::msg::TrackingPosAngle_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<interfaces::msg::TrackingPosAngle_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<interfaces::msg::TrackingPosAngle_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      interfaces::msg::TrackingPosAngle_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<interfaces::msg::TrackingPosAngle_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      interfaces::msg::TrackingPosAngle_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<interfaces::msg::TrackingPosAngle_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<interfaces::msg::TrackingPosAngle_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<interfaces::msg::TrackingPosAngle_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__interfaces__msg__TrackingPosAngle
    std::shared_ptr<interfaces::msg::TrackingPosAngle_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__interfaces__msg__TrackingPosAngle
    std::shared_ptr<interfaces::msg::TrackingPosAngle_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const TrackingPosAngle_ & other) const
  {
    if (this->min_angle != other.min_angle) {
      return false;
    }
    if (this->max_angle != other.max_angle) {
      return false;
    }
    if (this->cam_angle != other.cam_angle) {
      return false;
    }
    if (this->person_detected != other.person_detected) {
      return false;
    }
    return true;
  }
  bool operator!=(const TrackingPosAngle_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct TrackingPosAngle_

// alias to use template instance with default allocator
using TrackingPosAngle =
  interfaces::msg::TrackingPosAngle_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace interfaces

#endif  // INTERFACES__MSG__DETAIL__TRACKING_POS_ANGLE__STRUCT_HPP_
