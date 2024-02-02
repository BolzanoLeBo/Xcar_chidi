// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from interfaces:msg/Obstacles.idl
// generated code does not contain a copyright notice

#ifndef INTERFACES__MSG__DETAIL__OBSTACLES__BUILDER_HPP_
#define INTERFACES__MSG__DETAIL__OBSTACLES__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "interfaces/msg/detail/obstacles__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace interfaces
{

namespace msg
{

namespace builder
{

class Init_Obstacles_lidar_error
{
public:
  explicit Init_Obstacles_lidar_error(::interfaces::msg::Obstacles & msg)
  : msg_(msg)
  {}
  ::interfaces::msg::Obstacles lidar_error(::interfaces::msg::Obstacles::_lidar_error_type arg)
  {
    msg_.lidar_error = std::move(arg);
    return std::move(msg_);
  }

private:
  ::interfaces::msg::Obstacles msg_;
};

class Init_Obstacles_us_error
{
public:
  explicit Init_Obstacles_us_error(::interfaces::msg::Obstacles & msg)
  : msg_(msg)
  {}
  Init_Obstacles_lidar_error us_error(::interfaces::msg::Obstacles::_us_error_type arg)
  {
    msg_.us_error = std::move(arg);
    return Init_Obstacles_lidar_error(msg_);
  }

private:
  ::interfaces::msg::Obstacles msg_;
};

class Init_Obstacles_rear
{
public:
  explicit Init_Obstacles_rear(::interfaces::msg::Obstacles & msg)
  : msg_(msg)
  {}
  Init_Obstacles_us_error rear(::interfaces::msg::Obstacles::_rear_type arg)
  {
    msg_.rear = std::move(arg);
    return Init_Obstacles_us_error(msg_);
  }

private:
  ::interfaces::msg::Obstacles msg_;
};

class Init_Obstacles_front
{
public:
  Init_Obstacles_front()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_Obstacles_rear front(::interfaces::msg::Obstacles::_front_type arg)
  {
    msg_.front = std::move(arg);
    return Init_Obstacles_rear(msg_);
  }

private:
  ::interfaces::msg::Obstacles msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::interfaces::msg::Obstacles>()
{
  return interfaces::msg::builder::Init_Obstacles_front();
}

}  // namespace interfaces

#endif  // INTERFACES__MSG__DETAIL__OBSTACLES__BUILDER_HPP_
