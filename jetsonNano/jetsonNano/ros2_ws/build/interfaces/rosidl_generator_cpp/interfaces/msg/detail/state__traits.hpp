// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from interfaces:msg/State.idl
// generated code does not contain a copyright notice

#ifndef INTERFACES__MSG__DETAIL__STATE__TRAITS_HPP_
#define INTERFACES__MSG__DETAIL__STATE__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "interfaces/msg/detail/state__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

namespace interfaces
{

namespace msg
{

inline void to_flow_style_yaml(
  const State & msg,
  std::ostream & out)
{
  out << "{";
  // member: current_state
  {
    out << "current_state: ";
    rosidl_generator_traits::value_to_yaml(msg.current_state, out);
    out << ", ";
  }

  // member: previous_state
  {
    out << "previous_state: ";
    rosidl_generator_traits::value_to_yaml(msg.previous_state, out);
    out << ", ";
  }

  // member: state_name
  {
    out << "state_name: ";
    rosidl_generator_traits::value_to_yaml(msg.state_name, out);
    out << ", ";
  }

  // member: message_index
  {
    out << "message_index: ";
    rosidl_generator_traits::value_to_yaml(msg.message_index, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const State & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: current_state
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "current_state: ";
    rosidl_generator_traits::value_to_yaml(msg.current_state, out);
    out << "\n";
  }

  // member: previous_state
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "previous_state: ";
    rosidl_generator_traits::value_to_yaml(msg.previous_state, out);
    out << "\n";
  }

  // member: state_name
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "state_name: ";
    rosidl_generator_traits::value_to_yaml(msg.state_name, out);
    out << "\n";
  }

  // member: message_index
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "message_index: ";
    rosidl_generator_traits::value_to_yaml(msg.message_index, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const State & msg, bool use_flow_style = false)
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
  const interfaces::msg::State & msg,
  std::ostream & out, size_t indentation = 0)
{
  interfaces::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use interfaces::msg::to_yaml() instead")]]
inline std::string to_yaml(const interfaces::msg::State & msg)
{
  return interfaces::msg::to_yaml(msg);
}

template<>
inline const char * data_type<interfaces::msg::State>()
{
  return "interfaces::msg::State";
}

template<>
inline const char * name<interfaces::msg::State>()
{
  return "interfaces/msg/State";
}

template<>
struct has_fixed_size<interfaces::msg::State>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<interfaces::msg::State>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<interfaces::msg::State>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // INTERFACES__MSG__DETAIL__STATE__TRAITS_HPP_
