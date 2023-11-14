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

class Init_State_current_state
{
public:
  Init_State_current_state()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::interfaces::msg::State current_state(::interfaces::msg::State::_current_state_type arg)
  {
    msg_.current_state = std::move(arg);
    return std::move(msg_);
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
