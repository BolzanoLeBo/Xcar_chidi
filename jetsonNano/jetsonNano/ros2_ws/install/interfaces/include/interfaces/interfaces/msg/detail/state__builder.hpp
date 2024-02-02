// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from interfaces:msg/State.idl
// generated code does not contain a copyright notice

#ifndef INTERFACES__MSG__DETAIL__STATE__BUILDER_HPP_
#define INTERFACES__MSG__DETAIL__STATE__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "interfaces/msg/detail/state__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace interfaces
{

namespace msg
{

namespace builder
{

class Init_State_message_index
{
public:
  explicit Init_State_message_index(::interfaces::msg::State & msg)
  : msg_(msg)
  {}
  ::interfaces::msg::State message_index(::interfaces::msg::State::_message_index_type arg)
  {
    msg_.message_index = std::move(arg);
    return std::move(msg_);
  }

private:
  ::interfaces::msg::State msg_;
};

class Init_State_state_name
{
public:
  explicit Init_State_state_name(::interfaces::msg::State & msg)
  : msg_(msg)
  {}
  Init_State_message_index state_name(::interfaces::msg::State::_state_name_type arg)
  {
    msg_.state_name = std::move(arg);
    return Init_State_message_index(msg_);
  }

private:
  ::interfaces::msg::State msg_;
};

class Init_State_previous_state
{
public:
  explicit Init_State_previous_state(::interfaces::msg::State & msg)
  : msg_(msg)
  {}
  Init_State_state_name previous_state(::interfaces::msg::State::_previous_state_type arg)
  {
    msg_.previous_state = std::move(arg);
    return Init_State_state_name(msg_);
  }

private:
  ::interfaces::msg::State msg_;
};

class Init_State_current_state
{
public:
  Init_State_current_state()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_State_previous_state current_state(::interfaces::msg::State::_current_state_type arg)
  {
    msg_.current_state = std::move(arg);
    return Init_State_previous_state(msg_);
  }

private:
  ::interfaces::msg::State msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::interfaces::msg::State>()
{
  return interfaces::msg::builder::Init_State_current_state();
}

}  // namespace interfaces

#endif  // INTERFACES__MSG__DETAIL__STATE__BUILDER_HPP_
