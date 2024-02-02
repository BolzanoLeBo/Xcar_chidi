// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from interfaces:msg/TargetImage.idl
// generated code does not contain a copyright notice

#ifndef INTERFACES__MSG__DETAIL__TARGET_IMAGE__STRUCT_HPP_
#define INTERFACES__MSG__DETAIL__TARGET_IMAGE__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


#ifndef _WIN32
# define DEPRECATED__interfaces__msg__TargetImage __attribute__((deprecated))
#else
# define DEPRECATED__interfaces__msg__TargetImage __declspec(deprecated)
#endif

namespace interfaces
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct TargetImage_
{
  using Type = TargetImage_<ContainerAllocator>;

  explicit TargetImage_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->image = "";
    }
  }

  explicit TargetImage_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : image(_alloc)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->image = "";
    }
  }

  // field types and members
  using _image_type =
    std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>;
  _image_type image;

  // setters for named parameter idiom
  Type & set__image(
    const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> & _arg)
  {
    this->image = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    interfaces::msg::TargetImage_<ContainerAllocator> *;
  using ConstRawPtr =
    const interfaces::msg::TargetImage_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<interfaces::msg::TargetImage_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<interfaces::msg::TargetImage_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      interfaces::msg::TargetImage_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<interfaces::msg::TargetImage_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      interfaces::msg::TargetImage_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<interfaces::msg::TargetImage_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<interfaces::msg::TargetImage_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<interfaces::msg::TargetImage_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__interfaces__msg__TargetImage
    std::shared_ptr<interfaces::msg::TargetImage_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__interfaces__msg__TargetImage
    std::shared_ptr<interfaces::msg::TargetImage_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const TargetImage_ & other) const
  {
    if (this->image != other.image) {
      return false;
    }
    return true;
  }
  bool operator!=(const TargetImage_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct TargetImage_

// alias to use template instance with default allocator
using TargetImage =
  interfaces::msg::TargetImage_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace interfaces

#endif  // INTERFACES__MSG__DETAIL__TARGET_IMAGE__STRUCT_HPP_
