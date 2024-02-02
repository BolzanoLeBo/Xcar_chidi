// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from interfaces:msg/Lidar.idl
// generated code does not contain a copyright notice

#ifndef INTERFACES__MSG__DETAIL__LIDAR__BUILDER_HPP_
#define INTERFACES__MSG__DETAIL__LIDAR__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "interfaces/msg/detail/lidar__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace interfaces
{

namespace msg
{

namespace builder
{

class Init_Lidar_right_min
{
public:
  explicit Init_Lidar_right_min(::interfaces::msg::Lidar & msg)
  : msg_(msg)
  {}
  ::interfaces::msg::Lidar right_min(::interfaces::msg::Lidar::_right_min_type arg)
  {
    msg_.right_min = std::move(arg);
    return std::move(msg_);
  }

private:
  ::interfaces::msg::Lidar msg_;
};

class Init_Lidar_left_min
{
public:
  explicit Init_Lidar_left_min(::interfaces::msg::Lidar & msg)
  : msg_(msg)
  {}
  Init_Lidar_right_min left_min(::interfaces::msg::Lidar::_left_min_type arg)
  {
    msg_.left_min = std::move(arg);
    return Init_Lidar_right_min(msg_);
  }

private:
  ::interfaces::msg::Lidar msg_;
};

class Init_Lidar_right_lidar
{
public:
  explicit Init_Lidar_right_lidar(::interfaces::msg::Lidar & msg)
  : msg_(msg)
  {}
  Init_Lidar_left_min right_lidar(::interfaces::msg::Lidar::_right_lidar_type arg)
  {
    msg_.right_lidar = std::move(arg);
    return Init_Lidar_left_min(msg_);
  }

private:
  ::interfaces::msg::Lidar msg_;
};

class Init_Lidar_left_lidar
{
public:
  Init_Lidar_left_lidar()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_Lidar_right_lidar left_lidar(::interfaces::msg::Lidar::_left_lidar_type arg)
  {
    msg_.left_lidar = std::move(arg);
    return Init_Lidar_right_lidar(msg_);
  }

private:
  ::interfaces::msg::Lidar msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::interfaces::msg::Lidar>()
{
  return interfaces::msg::builder::Init_Lidar_left_lidar();
}

}  // namespace interfaces

#endif  // INTERFACES__MSG__DETAIL__LIDAR__BUILDER_HPP_
