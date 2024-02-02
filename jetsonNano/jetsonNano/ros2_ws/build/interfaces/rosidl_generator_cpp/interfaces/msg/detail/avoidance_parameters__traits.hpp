// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from interfaces:msg/AvoidanceParameters.idl
// generated code does not contain a copyright notice

#ifndef INTERFACES__MSG__DETAIL__AVOIDANCE_PARAMETERS__TRAITS_HPP_
#define INTERFACES__MSG__DETAIL__AVOIDANCE_PARAMETERS__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "interfaces/msg/detail/avoidance_parameters__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

namespace interfaces
{

namespace msg
{

inline void to_flow_style_yaml(
  const AvoidanceParameters & msg,
  std::ostream & out)
{
  out << "{";
  // member: left
  {
    out << "left: ";
    rosidl_generator_traits::value_to_yaml(msg.left, out);
    out << ", ";
  }

  // member: big
  {
    out << "big: ";
    rosidl_generator_traits::value_to_yaml(msg.big, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const AvoidanceParameters & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: left
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "left: ";
    rosidl_generator_traits::value_to_yaml(msg.left, out);
    out << "\n";
  }

  // member: big
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "big: ";
    rosidl_generator_traits::value_to_yaml(msg.big, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const AvoidanceParameters & msg, bool use_flow_style = false)
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
  const interfaces::msg::AvoidanceParameters & msg,
  std::ostream & out, size_t indentation = 0)
{
  interfaces::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use interfaces::msg::to_yaml() instead")]]
inline std::string to_yaml(const interfaces::msg::AvoidanceParameters & msg)
{
  return interfaces::msg::to_yaml(msg);
}

template<>
inline const char * data_type<interfaces::msg::AvoidanceParameters>()
{
  return "interfaces::msg::AvoidanceParameters";
}

template<>
inline const char * name<interfaces::msg::AvoidanceParameters>()
{
  return "interfaces/msg/AvoidanceParameters";
}

template<>
struct has_fixed_size<interfaces::msg::AvoidanceParameters>
  : std::integral_constant<bool, true> {};

template<>
struct has_bounded_size<interfaces::msg::AvoidanceParameters>
  : std::integral_constant<bool, true> {};

template<>
struct is_message<interfaces::msg::AvoidanceParameters>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // INTERFACES__MSG__DETAIL__AVOIDANCE_PARAMETERS__TRAITS_HPP_
