// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from interfaces:msg/InitButton.idl
// generated code does not contain a copyright notice

#ifndef INTERFACES__MSG__DETAIL__INIT_BUTTON__BUILDER_HPP_
#define INTERFACES__MSG__DETAIL__INIT_BUTTON__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "interfaces/msg/detail/init_button__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace interfaces
{

namespace msg
{

namespace builder
{

class Init_InitButton_button
{
public:
  Init_InitButton_button()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::interfaces::msg::InitButton button(::interfaces::msg::InitButton::_button_type arg)
  {
    msg_.button = std::move(arg);
    return std::move(msg_);
  }

private:
  ::interfaces::msg::InitButton msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::interfaces::msg::InitButton>()
{
  return interfaces::msg::builder::Init_InitButton_button();
}

}  // namespace interfaces

#endif  // INTERFACES__MSG__DETAIL__INIT_BUTTON__BUILDER_HPP_
