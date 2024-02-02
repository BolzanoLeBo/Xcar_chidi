// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from interfaces:msg/TrackingPosAngle.idl
// generated code does not contain a copyright notice

#ifndef INTERFACES__MSG__DETAIL__TRACKING_POS_ANGLE__TRAITS_HPP_
#define INTERFACES__MSG__DETAIL__TRACKING_POS_ANGLE__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "interfaces/msg/detail/tracking_pos_angle__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

namespace interfaces
{

namespace msg
{

inline void to_flow_style_yaml(
  const TrackingPosAngle & msg,
  std::ostream & out)
{
  out << "{";
  // member: min_angle
  {
    out << "min_angle: ";
    rosidl_generator_traits::value_to_yaml(msg.min_angle, out);
    out << ", ";
  }

  // member: max_angle
  {
    out << "max_angle: ";
    rosidl_generator_traits::value_to_yaml(msg.max_angle, out);
    out << ", ";
  }

  // member: cam_angle
  {
    out << "cam_angle: ";
    rosidl_generator_traits::value_to_yaml(msg.cam_angle, out);
    out << ", ";
  }

  // member: person_detected
  {
    out << "person_detected: ";
    rosidl_generator_traits::value_to_yaml(msg.person_detected, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const TrackingPosAngle & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: min_angle
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "min_angle: ";
    rosidl_generator_traits::value_to_yaml(msg.min_angle, out);
    out << "\n";
  }

  // member: max_angle
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "max_angle: ";
    rosidl_generator_traits::value_to_yaml(msg.max_angle, out);
    out << "\n";
  }

  // member: cam_angle
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "cam_angle: ";
    rosidl_generator_traits::value_to_yaml(msg.cam_angle, out);
    out << "\n";
  }

  // member: person_detected
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "person_detected: ";
    rosidl_generator_traits::value_to_yaml(msg.person_detected, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const TrackingPosAngle & msg, bool use_flow_style = false)
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
  const interfaces::msg::TrackingPosAngle & msg,
  std::ostream & out, size_t indentation = 0)
{
  interfaces::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use interfaces::msg::to_yaml() instead")]]
inline std::string to_yaml(const interfaces::msg::TrackingPosAngle & msg)
{
  return interfaces::msg::to_yaml(msg);
}

template<>
inline const char * data_type<interfaces::msg::TrackingPosAngle>()
{
  return "interfaces::msg::TrackingPosAngle";
}

template<>
inline const char * name<interfaces::msg::TrackingPosAngle>()
{
  return "interfaces/msg/TrackingPosAngle";
}

template<>
struct has_fixed_size<interfaces::msg::TrackingPosAngle>
  : std::integral_constant<bool, true> {};

template<>
struct has_bounded_size<interfaces::msg::TrackingPosAngle>
  : std::integral_constant<bool, true> {};

template<>
struct is_message<interfaces::msg::TrackingPosAngle>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // INTERFACES__MSG__DETAIL__TRACKING_POS_ANGLE__TRAITS_HPP_
