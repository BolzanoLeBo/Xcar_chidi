// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from interfaces:msg/TargetImage.idl
// generated code does not contain a copyright notice

#ifndef INTERFACES__MSG__DETAIL__TARGET_IMAGE__BUILDER_HPP_
#define INTERFACES__MSG__DETAIL__TARGET_IMAGE__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "interfaces/msg/detail/target_image__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace interfaces
{

namespace msg
{

namespace builder
{

class Init_TargetImage_image
{
public:
  Init_TargetImage_image()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::interfaces::msg::TargetImage image(::interfaces::msg::TargetImage::_image_type arg)
  {
    msg_.image = std::move(arg);
    return std::move(msg_);
  }

private:
  ::interfaces::msg::TargetImage msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::interfaces::msg::TargetImage>()
{
  return interfaces::msg::builder::Init_TargetImage_image();
}

}  // namespace interfaces

#endif  // INTERFACES__MSG__DETAIL__TARGET_IMAGE__BUILDER_HPP_
