// generated from rosidl_typesupport_fastrtps_cpp/resource/idl__type_support.cpp.em
// with input from interfaces:msg/ObstaclesId.idl
// generated code does not contain a copyright notice
#include "interfaces/msg/detail/obstacles_id__rosidl_typesupport_fastrtps_cpp.hpp"
#include "interfaces/msg/detail/obstacles_id__struct.hpp"

#include <limits>
#include <stdexcept>
#include <string>
#include "rosidl_typesupport_cpp/message_type_support.hpp"
#include "rosidl_typesupport_fastrtps_cpp/identifier.hpp"
#include "rosidl_typesupport_fastrtps_cpp/message_type_support.h"
#include "rosidl_typesupport_fastrtps_cpp/message_type_support_decl.hpp"
#include "rosidl_typesupport_fastrtps_cpp/wstring_conversion.hpp"
#include "fastcdr/Cdr.h"


// forward declaration of message dependencies and their conversion functions

namespace interfaces
{

namespace msg
{

namespace typesupport_fastrtps_cpp
{

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_interfaces
cdr_serialize(
  const interfaces::msg::ObstaclesId & ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  // Member: obstacle_left
  cdr << (ros_message.obstacle_left ? true : false);
  // Member: obstacle_middle
  cdr << (ros_message.obstacle_middle ? true : false);
  // Member: obstacle_right
  cdr << (ros_message.obstacle_right ? true : false);
  // Member: big_obstacle
  cdr << (ros_message.big_obstacle ? true : false);
  return true;
}

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_interfaces
cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  interfaces::msg::ObstaclesId & ros_message)
{
  // Member: obstacle_left
  {
    uint8_t tmp;
    cdr >> tmp;
    ros_message.obstacle_left = tmp ? true : false;
  }

  // Member: obstacle_middle
  {
    uint8_t tmp;
    cdr >> tmp;
    ros_message.obstacle_middle = tmp ? true : false;
  }

  // Member: obstacle_right
  {
    uint8_t tmp;
    cdr >> tmp;
    ros_message.obstacle_right = tmp ? true : false;
  }

  // Member: big_obstacle
  {
    uint8_t tmp;
    cdr >> tmp;
    ros_message.big_obstacle = tmp ? true : false;
  }

  return true;
}

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_interfaces
get_serialized_size(
  const interfaces::msg::ObstaclesId & ros_message,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // Member: obstacle_left
  {
    size_t item_size = sizeof(ros_message.obstacle_left);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: obstacle_middle
  {
    size_t item_size = sizeof(ros_message.obstacle_middle);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: obstacle_right
  {
    size_t item_size = sizeof(ros_message.obstacle_right);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: big_obstacle
  {
    size_t item_size = sizeof(ros_message.big_obstacle);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  return current_alignment - initial_alignment;
}

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_interfaces
max_serialized_size_ObstaclesId(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  full_bounded = true;
  is_plain = true;


  // Member: obstacle_left
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint8_t);
  }

  // Member: obstacle_middle
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint8_t);
  }

  // Member: obstacle_right
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint8_t);
  }

  // Member: big_obstacle
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint8_t);
  }

  return current_alignment - initial_alignment;
}

static bool _ObstaclesId__cdr_serialize(
  const void * untyped_ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  auto typed_message =
    static_cast<const interfaces::msg::ObstaclesId *>(
    untyped_ros_message);
  return cdr_serialize(*typed_message, cdr);
}

static bool _ObstaclesId__cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  void * untyped_ros_message)
{
  auto typed_message =
    static_cast<interfaces::msg::ObstaclesId *>(
    untyped_ros_message);
  return cdr_deserialize(cdr, *typed_message);
}

static uint32_t _ObstaclesId__get_serialized_size(
  const void * untyped_ros_message)
{
  auto typed_message =
    static_cast<const interfaces::msg::ObstaclesId *>(
    untyped_ros_message);
  return static_cast<uint32_t>(get_serialized_size(*typed_message, 0));
}

static size_t _ObstaclesId__max_serialized_size(char & bounds_info)
{
  bool full_bounded;
  bool is_plain;
  size_t ret_val;

  ret_val = max_serialized_size_ObstaclesId(full_bounded, is_plain, 0);

  bounds_info =
    is_plain ? ROSIDL_TYPESUPPORT_FASTRTPS_PLAIN_TYPE :
    full_bounded ? ROSIDL_TYPESUPPORT_FASTRTPS_BOUNDED_TYPE : ROSIDL_TYPESUPPORT_FASTRTPS_UNBOUNDED_TYPE;
  return ret_val;
}

static message_type_support_callbacks_t _ObstaclesId__callbacks = {
  "interfaces::msg",
  "ObstaclesId",
  _ObstaclesId__cdr_serialize,
  _ObstaclesId__cdr_deserialize,
  _ObstaclesId__get_serialized_size,
  _ObstaclesId__max_serialized_size
};

static rosidl_message_type_support_t _ObstaclesId__handle = {
  rosidl_typesupport_fastrtps_cpp::typesupport_identifier,
  &_ObstaclesId__callbacks,
  get_message_typesupport_handle_function,
};

}  // namespace typesupport_fastrtps_cpp

}  // namespace msg

}  // namespace interfaces

namespace rosidl_typesupport_fastrtps_cpp
{

template<>
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_EXPORT_interfaces
const rosidl_message_type_support_t *
get_message_type_support_handle<interfaces::msg::ObstaclesId>()
{
  return &interfaces::msg::typesupport_fastrtps_cpp::_ObstaclesId__handle;
}

}  // namespace rosidl_typesupport_fastrtps_cpp

#ifdef __cplusplus
extern "C"
{
#endif

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, interfaces, msg, ObstaclesId)() {
  return &interfaces::msg::typesupport_fastrtps_cpp::_ObstaclesId__handle;
}

#ifdef __cplusplus
}
#endif
