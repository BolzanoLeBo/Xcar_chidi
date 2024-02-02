// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from interfaces:msg/TrackingPosAngle.idl
// generated code does not contain a copyright notice

#ifndef INTERFACES__MSG__DETAIL__TRACKING_POS_ANGLE__BUILDER_HPP_
#define INTERFACES__MSG__DETAIL__TRACKING_POS_ANGLE__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "interfaces/msg/detail/tracking_pos_angle__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace interfaces
{

namespace msg
{

namespace builder
{

class Init_TrackingPosAngle_person_detected
{
public:
  explicit Init_TrackingPosAngle_person_detected(::interfaces::msg::TrackingPosAngle & msg)
  : msg_(msg)
  {}
  ::interfaces::msg::TrackingPosAngle person_detected(::interfaces::msg::TrackingPosAngle::_person_detected_type arg)
  {
    msg_.person_detected = std::move(arg);
    return std::move(msg_);
  }

private:
  ::interfaces::msg::TrackingPosAngle msg_;
};

class Init_TrackingPosAngle_cam_angle
{
public:
  explicit Init_TrackingPosAngle_cam_angle(::interfaces::msg::TrackingPosAngle & msg)
  : msg_(msg)
  {}
  Init_TrackingPosAngle_person_detected cam_angle(::interfaces::msg::TrackingPosAngle::_cam_angle_type arg)
  {
    msg_.cam_angle = std::move(arg);
    return Init_TrackingPosAngle_person_detected(msg_);
  }

private:
  ::interfaces::msg::TrackingPosAngle msg_;
};

class Init_TrackingPosAngle_max_angle
{
public:
  explicit Init_TrackingPosAngle_max_angle(::interfaces::msg::TrackingPosAngle & msg)
  : msg_(msg)
  {}
  Init_TrackingPosAngle_cam_angle max_angle(::interfaces::msg::TrackingPosAngle::_max_angle_type arg)
  {
    msg_.max_angle = std::move(arg);
    return Init_TrackingPosAngle_cam_angle(msg_);
  }

private:
  ::interfaces::msg::TrackingPosAngle msg_;
};

class Init_TrackingPosAngle_min_angle
{
public:
  Init_TrackingPosAngle_min_angle()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_TrackingPosAngle_max_angle min_angle(::interfaces::msg::TrackingPosAngle::_min_angle_type arg)
  {
    msg_.min_angle = std::move(arg);
    return Init_TrackingPosAngle_max_angle(msg_);
  }

private:
  ::interfaces::msg::TrackingPosAngle msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::interfaces::msg::TrackingPosAngle>()
{
  return interfaces::msg::builder::Init_TrackingPosAngle_min_angle();
}

}  // namespace interfaces

#endif  // INTERFACES__MSG__DETAIL__TRACKING_POS_ANGLE__BUILDER_HPP_
