// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from interfaces:msg/Obstacles.idl
// generated code does not contain a copyright notice

#ifndef INTERFACES__MSG__DETAIL__OBSTACLES__TRAITS_HPP_
#define INTERFACES__MSG__DETAIL__OBSTACLES__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "interfaces/msg/detail/obstacles__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

namespace interfaces
{

namespace msg
{

inline void to_flow_style_yaml(
  const Obstacles & msg,
  std::ostream & out)
{
  out << "{";
  // member: front
  {
    out << "front: ";
    rosidl_generator_traits::value_to_yaml(msg.front, out);
    out << ", ";
  }

  // member: rear
  {
    out << "rear: ";
    rosidl_generator_traits::value_to_yaml(msg.rear, out);
    out << ", ";
  }

  // member: us_error
  {
    out << "us_error: ";
    rosidl_generator_traits::value_to_yaml(msg.us_error, out);
    out << ", ";
  }

  // member: lidar_error
  {
    out << "lidar_error: ";
    rosidl_generator_traits::value_to_yaml(msg.lidar_error, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const Obstacles & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: front
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "front: ";
    rosidl_generator_traits::value_to_yaml(msg.front, out);
    out << "\n";
  }

  // member: rear
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "rear: ";
    rosidl_generator_traits::value_to_yaml(msg.rear, out);
    out << "\n";
  }

  // member: us_error
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "us_error: ";
    rosidl_generator_traits::value_to_yaml(msg.us_error, out);
    out << "\n";
  }

  // member: lidar_error
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "lidar_error: ";
    rosidl_generator_traits::value_to_yaml(msg.lidar_error, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const Obstacles & msg, bool use_flow_style = false)
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
  const interfaces::msg::Obstacles & msg,
  std::ostream & out, size_t indentation = 0)
{
  interfaces::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use interfaces::msg::to_yaml() instead")]]
inline std::string to_yaml(const interfaces::msg::Obstacles & msg)
{
  return interfaces::msg::to_yaml(msg);
}

template<>
inline const char * data_type<interfaces::msg::Obstacles>()
{
  return "interfaces::msg::Obstacles";
}

template<>
inline const char * name<interfaces::msg::Obstacles>()
{
  return "interfaces/msg/Obstacles";
}

template<>
struct has_fixed_size<interfaces::msg::Obstacles>
  : std::integral_constant<bool, true> {};

template<>
struct has_bounded_size<interfaces::msg::Obstacles>
  : std::integral_constant<bool, true> {};

template<>
struct is_message<interfaces::msg::Obstacles>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // INTERFACES__MSG__DETAIL__OBSTACLES__TRAITS_HPP_
