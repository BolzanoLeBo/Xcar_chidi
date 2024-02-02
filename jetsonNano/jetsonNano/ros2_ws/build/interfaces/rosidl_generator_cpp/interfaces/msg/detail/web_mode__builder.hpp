// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from interfaces:msg/WebMode.idl
// generated code does not contain a copyright notice

#ifndef INTERFACES__MSG__DETAIL__WEB_MODE__BUILDER_HPP_
#define INTERFACES__MSG__DETAIL__WEB_MODE__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "interfaces/msg/detail/web_mode__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace interfaces
{

namespace msg
{

namespace builder
{

class Init_WebMode_reverse
{
public:
  explicit Init_WebMode_reverse(::interfaces::msg::WebMode & msg)
  : msg_(msg)
  {}
  ::interfaces::msg::WebMode reverse(::interfaces::msg::WebMode::_reverse_type arg)
  {
    msg_.reverse = std::move(arg);
    return std::move(msg_);
  }

private:
  ::interfaces::msg::WebMode msg_;
};

class Init_WebMode_steering
{
public:
  explicit Init_WebMode_steering(::interfaces::msg::WebMode & msg)
  : msg_(msg)
  {}
  Init_WebMode_reverse steering(::interfaces::msg::WebMode::_steering_type arg)
  {
    msg_.steering = std::move(arg);
    return Init_WebMode_reverse(msg_);
  }

private:
  ::interfaces::msg::WebMode msg_;
};

class Init_WebMode_throttle
{
public:
  explicit Init_WebMode_throttle(::interfaces::msg::WebMode & msg)
  : msg_(msg)
  {}
  Init_WebMode_steering throttle(::interfaces::msg::WebMode::_throttle_type arg)
  {
    msg_.throttle = std::move(arg);
    return Init_WebMode_steering(msg_);
  }

private:
  ::interfaces::msg::WebMode msg_;
};

class Init_WebMode_button
{
public:
  Init_WebMode_button()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_WebMode_throttle button(::interfaces::msg::WebMode::_button_type arg)
  {
    msg_.button = std::move(arg);
    return Init_WebMode_throttle(msg_);
  }

private:
  ::interfaces::msg::WebMode msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::interfaces::msg::WebMode>()
{
  return interfaces::msg::builder::Init_WebMode_button();
}

}  // namespace interfaces

#endif  // INTERFACES__MSG__DETAIL__WEB_MODE__BUILDER_HPP_
