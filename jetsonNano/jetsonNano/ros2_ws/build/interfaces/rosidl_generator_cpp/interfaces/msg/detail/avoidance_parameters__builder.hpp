// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from interfaces:msg/AvoidanceParameters.idl
// generated code does not contain a copyright notice

#ifndef INTERFACES__MSG__DETAIL__AVOIDANCE_PARAMETERS__BUILDER_HPP_
#define INTERFACES__MSG__DETAIL__AVOIDANCE_PARAMETERS__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "interfaces/msg/detail/avoidance_parameters__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace interfaces
{

namespace msg
{

namespace builder
{

class Init_AvoidanceParameters_big
{
public:
  explicit Init_AvoidanceParameters_big(::interfaces::msg::AvoidanceParameters & msg)
  : msg_(msg)
  {}
  ::interfaces::msg::AvoidanceParameters big(::interfaces::msg::AvoidanceParameters::_big_type arg)
  {
    msg_.big = std::move(arg);
    return std::move(msg_);
  }

private:
  ::interfaces::msg::AvoidanceParameters msg_;
};

class Init_AvoidanceParameters_left
{
public:
  Init_AvoidanceParameters_left()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_AvoidanceParameters_big left(::interfaces::msg::AvoidanceParameters::_left_type arg)
  {
    msg_.left = std::move(arg);
    return Init_AvoidanceParameters_big(msg_);
  }

private:
  ::interfaces::msg::AvoidanceParameters msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::interfaces::msg::AvoidanceParameters>()
{
  return interfaces::msg::builder::Init_AvoidanceParameters_left();
}

}  // namespace interfaces

#endif  // INTERFACES__MSG__DETAIL__AVOIDANCE_PARAMETERS__BUILDER_HPP_
