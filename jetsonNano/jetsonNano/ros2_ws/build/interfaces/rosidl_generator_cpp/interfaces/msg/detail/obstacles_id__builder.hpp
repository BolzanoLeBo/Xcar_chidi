// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from interfaces:msg/ObstaclesId.idl
// generated code does not contain a copyright notice

#ifndef INTERFACES__MSG__DETAIL__OBSTACLES_ID__BUILDER_HPP_
#define INTERFACES__MSG__DETAIL__OBSTACLES_ID__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "interfaces/msg/detail/obstacles_id__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace interfaces
{

namespace msg
{

namespace builder
{

class Init_ObstaclesId_big_obstacle
{
public:
  explicit Init_ObstaclesId_big_obstacle(::interfaces::msg::ObstaclesId & msg)
  : msg_(msg)
  {}
  ::interfaces::msg::ObstaclesId big_obstacle(::interfaces::msg::ObstaclesId::_big_obstacle_type arg)
  {
    msg_.big_obstacle = std::move(arg);
    return std::move(msg_);
  }

private:
  ::interfaces::msg::ObstaclesId msg_;
};

class Init_ObstaclesId_obstacle_right
{
public:
  explicit Init_ObstaclesId_obstacle_right(::interfaces::msg::ObstaclesId & msg)
  : msg_(msg)
  {}
  Init_ObstaclesId_big_obstacle obstacle_right(::interfaces::msg::ObstaclesId::_obstacle_right_type arg)
  {
    msg_.obstacle_right = std::move(arg);
    return Init_ObstaclesId_big_obstacle(msg_);
  }

private:
  ::interfaces::msg::ObstaclesId msg_;
};

class Init_ObstaclesId_obstacle_middle
{
public:
  explicit Init_ObstaclesId_obstacle_middle(::interfaces::msg::ObstaclesId & msg)
  : msg_(msg)
  {}
  Init_ObstaclesId_obstacle_right obstacle_middle(::interfaces::msg::ObstaclesId::_obstacle_middle_type arg)
  {
    msg_.obstacle_middle = std::move(arg);
    return Init_ObstaclesId_obstacle_right(msg_);
  }

private:
  ::interfaces::msg::ObstaclesId msg_;
};

class Init_ObstaclesId_obstacle_left
{
public:
  Init_ObstaclesId_obstacle_left()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_ObstaclesId_obstacle_middle obstacle_left(::interfaces::msg::ObstaclesId::_obstacle_left_type arg)
  {
    msg_.obstacle_left = std::move(arg);
    return Init_ObstaclesId_obstacle_middle(msg_);
  }

private:
  ::interfaces::msg::ObstaclesId msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::interfaces::msg::ObstaclesId>()
{
  return interfaces::msg::builder::Init_ObstaclesId_obstacle_left();
}

}  // namespace interfaces

#endif  // INTERFACES__MSG__DETAIL__OBSTACLES_ID__BUILDER_HPP_
