// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from interfaces:msg/Userdistance.idl
// generated code does not contain a copyright notice

#ifndef INTERFACES__MSG__DETAIL__USERDISTANCE__BUILDER_HPP_
#define INTERFACES__MSG__DETAIL__USERDISTANCE__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "interfaces/msg/detail/userdistance__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace interfaces
{

namespace msg
{

namespace builder
{

class Init_Userdistance_distance_tracking
{
public:
  Init_Userdistance_distance_tracking()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::interfaces::msg::Userdistance distance_tracking(::interfaces::msg::Userdistance::_distance_tracking_type arg)
  {
    msg_.distance_tracking = std::move(arg);
    return std::move(msg_);
  }

private:
  ::interfaces::msg::Userdistance msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::interfaces::msg::Userdistance>()
{
  return interfaces::msg::builder::Init_Userdistance_distance_tracking();
}

}  // namespace interfaces

#endif  // INTERFACES__MSG__DETAIL__USERDISTANCE__BUILDER_HPP_
