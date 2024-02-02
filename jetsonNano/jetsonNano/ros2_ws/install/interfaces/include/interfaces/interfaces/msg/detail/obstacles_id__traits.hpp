// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from interfaces:msg/ObstaclesId.idl
// generated code does not contain a copyright notice

#ifndef INTERFACES__MSG__DETAIL__OBSTACLES_ID__TRAITS_HPP_
#define INTERFACES__MSG__DETAIL__OBSTACLES_ID__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "interfaces/msg/detail/obstacles_id__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

namespace interfaces
{

namespace msg
{

inline void to_flow_style_yaml(
  const ObstaclesId & msg,
  std::ostream & out)
{
  out << "{";
  // member: obstacle_left
  {
    out << "obstacle_left: ";
    rosidl_generator_traits::value_to_yaml(msg.obstacle_left, out);
    out << ", ";
  }

  // member: obstacle_middle
  {
    out << "obstacle_middle: ";
    rosidl_generator_traits::value_to_yaml(msg.obstacle_middle, out);
    out << ", ";
  }

  // member: obstacle_right
  {
    out << "obstacle_right: ";
    rosidl_generator_traits::value_to_yaml(msg.obstacle_right, out);
    out << ", ";
  }

  // member: big_obstacle
  {
    out << "big_obstacle: ";
    rosidl_generator_traits::value_to_yaml(msg.big_obstacle, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const ObstaclesId & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: obstacle_left
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "obstacle_left: ";
    rosidl_generator_traits::value_to_yaml(msg.obstacle_left, out);
    out << "\n";
  }

  // member: obstacle_middle
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "obstacle_middle: ";
    rosidl_generator_traits::value_to_yaml(msg.obstacle_middle, out);
    out << "\n";
  }

  // member: obstacle_right
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "obstacle_right: ";
    rosidl_generator_traits::value_to_yaml(msg.obstacle_right, out);
    out << "\n";
  }

  // member: big_obstacle
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "big_obstacle: ";
    rosidl_generator_traits::value_to_yaml(msg.big_obstacle, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const ObstaclesId & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace msg

}  // namespace interfaces

namespace rosidl_generator_traits
{

[[deprecated("use interfaces::msg::to_block_style_yaml() instead")]]
inline void to_yaml(
  const interfaces::msg::ObstaclesId & msg,
  std::ostream & out, size_t indentation = 0)
{
  interfaces::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use interfaces::msg::to_yaml() instead")]]
inline std::string to_yaml(const interfaces::msg::ObstaclesId & msg)
{
  return interfaces::msg::to_yaml(msg);
}

template<>
inline const char * data_type<interfaces::msg::ObstaclesId>()
{
  return "interfaces::msg::ObstaclesId";
}

template<>
inline const char * name<interfaces::msg::ObstaclesId>()
{
  return "interfaces/msg/ObstaclesId";
}

template<>
struct has_fixed_size<interfaces::msg::ObstaclesId>
  : std::integral_constant<bool, true> {};

template<>
struct has_bounded_size<interfaces::msg::ObstaclesId>
  : std::integral_constant<bool, true> {};

template<>
struct is_message<interfaces::msg::ObstaclesId>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // INTERFACES__MSG__DETAIL__OBSTACLES_ID__TRAITS_HPP_
