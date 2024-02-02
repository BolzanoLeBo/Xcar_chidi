// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from interfaces:msg/State.idl
// generated code does not contain a copyright notice

#ifndef INTERFACES__MSG__DETAIL__STATE__STRUCT_HPP_
#define INTERFACES__MSG__DETAIL__STATE__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


#ifndef _WIN32
# define DEPRECATED__interfaces__msg__State __attribute__((deprecated))
#else
# define DEPRECATED__interfaces__msg__State __declspec(deprecated)
#endif

namespace interfaces
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct State_
{
  using Type = State_<ContainerAllocator>;

  explicit State_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::DEFAULTS_ONLY == _init)
    {
      this->current_state = 0;
      this->previous_state = -1;
      this->message_index = 2;
    } else if (rosidl_runtime_cpp::MessageInitialization::ZERO == _init) {
      this->current_state = 0;
      this->previous_state = 0;
      this->state_name = "";
      this->message_index = 0;
    }
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->state_name = "";
    }
  }

  explicit State_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : state_name(_alloc)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::DEFAULTS_ONLY == _init)
    {
      this->current_state = 0;
      this->previous_state = -1;
      this->message_index = 2;
    } else if (rosidl_runtime_cpp::MessageInitialization::ZERO == _init) {
      this->current_state = 0;
      this->previous_state = 0;
      this->state_name = "";
      this->message_index = 0;
    }
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->state_name = "";
    }
  }

  // field types and members
  using _current_state_type =
    int8_t;
  _current_state_type current_state;
  using _previous_state_type =
    int8_t;
  _previous_state_type previous_state;
  using _state_name_type =
    std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>;
  _state_name_type state_name;
  using _message_index_type =
    int8_t;
  _message_index_type message_index;

  // setters for named parameter idiom
  Type & set__current_state(
    const int8_t & _arg)
  {
    this->current_state = _arg;
    return *this;
  }
  Type & set__previous_state(
    const int8_t & _arg)
  {
    this->previous_state = _arg;
    return *this;
  }
  Type & set__state_name(
    const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> & _arg)
  {
    this->state_name = _arg;
    return *this;
  }
  Type & set__message_index(
    const int8_t & _arg)
  {
    this->message_index = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    interfaces::msg::State_<ContainerAllocator> *;
  using ConstRawPtr =
    const interfaces::msg::State_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<interfaces::msg::State_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<interfaces::msg::State_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      interfaces::msg::State_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<interfaces::msg::State_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      interfaces::msg::State_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<interfaces::msg::State_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<interfaces::msg::State_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<interfaces::msg::State_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__interfaces__msg__State
    std::shared_ptr<interfaces::msg::State_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__interfaces__msg__State
    std::shared_ptr<interfaces::msg::State_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const State_ & other) const
  {
    if (this->current_state != other.current_state) {
      return false;
    }
    if (this->previous_state != other.previous_state) {
      return false;
    }
    if (this->state_name != other.state_name) {
      return false;
    }
    if (this->message_index != other.message_index) {
      return false;
    }
    return true;
  }
  bool operator!=(const State_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct State_

// alias to use template instance with default allocator
using State =
  interfaces::msg::State_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace interfaces

#endif  // INTERFACES__MSG__DETAIL__STATE__STRUCT_HPP_
