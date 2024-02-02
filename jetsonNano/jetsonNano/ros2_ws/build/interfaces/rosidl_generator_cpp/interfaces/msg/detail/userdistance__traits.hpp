// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from interfaces:msg/Userdistance.idl
// generated code does not contain a copyright notice

#ifndef INTERFACES__MSG__DETAIL__USERDISTANCE__TRAITS_HPP_
#define INTERFACES__MSG__DETAIL__USERDISTANCE__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "interfaces/msg/detail/userdistance__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

namespace interfaces
{

namespace msg
{

inline void to_flow_style_yaml(
  const Userdistance & msg,
  std::ostream & out)
{
  out << "{";
  // member: distance_tracking
  {
    out << "distance_tracking: ";
    rosidl_generator_traits::value_to_yaml(msg.distance_tracking, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const Userdistance & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: distance_tracking
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "distance_tracking: ";
    rosidl_generator_traits::value_to_yaml(msg.distance_tracking, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const Userdistance & msg, bool use_flow_style = false)
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
  const interfaces::msg::Userdistance & msg,
  std::ostream & out, size_t indentation = 0)
{
  interfaces::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use interfaces::msg::to_yaml() instead")]]
inline std::string to_yaml(const interfaces::msg::Userdistance & msg)
{
  return interfaces::msg::to_yaml(msg);
}

template<>
inline const char * data_type<interfaces::msg::Userdistance>()
{
  return "interfaces::msg::Userdistance";
}

template<>
inline const char * name<interfaces::msg::Userdistance>()
{
  return "interfaces/msg/Userdistance";
}

template<>
struct has_fixed_size<interfaces::msg::Userdistance>
  : std::integral_constant<bool, true> {};

template<>
struct has_bounded_size<interfaces::msg::Userdistance>
  : std::integral_constant<bool, true> {};

template<>
struct is_message<interfaces::msg::Userdistance>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // INTERFACES__MSG__DETAIL__USERDISTANCE__TRAITS_HPP_
