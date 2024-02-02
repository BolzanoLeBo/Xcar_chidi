// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from interfaces:msg/UserLost.idl
// generated code does not contain a copyright notice

#ifndef INTERFACES__MSG__DETAIL__USER_LOST__BUILDER_HPP_
#define INTERFACES__MSG__DETAIL__USER_LOST__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "interfaces/msg/detail/user_lost__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace interfaces
{

namespace msg
{

namespace builder
{

class Init_UserLost_lost
{
public:
  Init_UserLost_lost()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::interfaces::msg::UserLost lost(::interfaces::msg::UserLost::_lost_type arg)
  {
    msg_.lost = std::move(arg);
    return std::move(msg_);
  }

private:
  ::interfaces::msg::UserLost msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::interfaces::msg::UserLost>()
{
  return interfaces::msg::builder::Init_UserLost_lost();
}

}  // namespace interfaces

#endif  // INTERFACES__MSG__DETAIL__USER_LOST__BUILDER_HPP_
