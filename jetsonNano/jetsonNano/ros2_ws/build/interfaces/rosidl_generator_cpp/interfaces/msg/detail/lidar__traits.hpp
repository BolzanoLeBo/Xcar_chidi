// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from interfaces:msg/Lidar.idl
// generated code does not contain a copyright notice

#ifndef INTERFACES__MSG__DETAIL__LIDAR__TRAITS_HPP_
#define INTERFACES__MSG__DETAIL__LIDAR__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "interfaces/msg/detail/lidar__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

namespace interfaces
{

namespace msg
{

inline void to_flow_style_yaml(
  const Lidar & msg,
  std::ostream & out)
{
  out << "{";
  // member: left_lidar
  {
    out << "left_lidar: ";
    rosidl_generator_traits::value_to_yaml(msg.left_lidar, out);
    out << ", ";
  }

  // member: right_lidar
  {
    out << "right_lidar: ";
    rosidl_generator_traits::value_to_yaml(msg.right_lidar, out);
    out << ", ";
  }

  // member: left_min
  {
    out << "left_min: ";
    rosidl_generator_traits::value_to_yaml(msg.left_min, out);
    out << ", ";
  }

  // member: right_min
  {
    out << "right_min: ";
    rosidl_generator_traits::value_to_yaml(msg.right_min, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const Lidar & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: left_lidar
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "left_lidar: ";
    rosidl_generator_traits::value_to_yaml(msg.left_lidar, out);
    out << "\n";
  }

  // member: right_lidar
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "right_lidar: ";
    rosidl_generator_traits::value_to_yaml(msg.right_lidar, out);
    out << "\n";
  }

  // member: left_min
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "left_min: ";
    rosidl_generator_traits::value_to_yaml(msg.left_min, out);
    out << "\n";
  }

  // member: right_min
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "right_min: ";
    rosidl_generator_traits::value_to_yaml(msg.right_min, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const Lidar & msg, bool use_flow_style = false)
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
  const interfaces::msg::Lidar & msg,
  std::ostream & out, size_t indentation = 0)
{
  interfaces::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use interfaces::msg::to_yaml() instead")]]
inline std::string to_yaml(const interfaces::msg::Lidar & msg)
{
  return interfaces::msg::to_yaml(msg);
}

template<>
inline const char * data_type<interfaces::msg::Lidar>()
{
  return "interfaces::msg::Lidar";
}

template<>
inline const char * name<interfaces::msg::Lidar>()
{
  return "interfaces/msg/Lidar";
}

template<>
struct has_fixed_size<interfaces::msg::Lidar>
  : std::integral_constant<bool, true> {};

template<>
struct has_bounded_size<interfaces::msg::Lidar>
  : std::integral_constant<bool, true> {};

template<>
struct is_message<interfaces::msg::Lidar>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // INTERFACES__MSG__DETAIL__LIDAR__TRAITS_HPP_
