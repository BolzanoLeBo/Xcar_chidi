// generated from rosidl_typesupport_fastrtps_c/resource/idl__type_support_c.cpp.em
// with input from interfaces:msg/ObstaclesId.idl
// generated code does not contain a copyright notice
#include "interfaces/msg/detail/obstacles_id__rosidl_typesupport_fastrtps_c.h"


#include <cassert>
#include <limits>
#include <string>
#include "rosidl_typesupport_fastrtps_c/identifier.h"
#include "rosidl_typesupport_fastrtps_c/wstring_conversion.hpp"
#include "rosidl_typesupport_fastrtps_cpp/message_type_support.h"
#include "interfaces/msg/rosidl_typesupport_fastrtps_c__visibility_control.h"
#include "interfaces/msg/detail/obstacles_id__struct.h"
#include "interfaces/msg/detail/obstacles_id__functions.h"
#include "fastcdr/Cdr.h"

#ifndef _WIN32
# pragma GCC diagnostic push
# pragma GCC diagnostic ignored "-Wunused-parameter"
# ifdef __clang__
#  pragma clang diagnostic ignored "-Wdeprecated-register"
#  pragma clang diagnostic ignored "-Wreturn-type-c-linkage"
# endif
#endif
#ifndef _WIN32
# pragma GCC diagnostic pop
#endif

// includes and forward declarations of message dependencies and their conversion functions

#if defined(__cplusplus)
extern "C"
{
#endif


// forward declare type support functions


using _ObstaclesId__ros_msg_type = interfaces__msg__ObstaclesId;

static bool _ObstaclesId__cdr_serialize(
  const void * untyped_ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  const _ObstaclesId__ros_msg_type * ros_message = static_cast<const _ObstaclesId__ros_msg_type *>(untyped_ros_message);
  // Field name: obstacle_left
  {
    cdr << (ros_message->obstacle_left ? true : false);
  }

  // Field name: obstacle_middle
  {
    cdr << (ros_message->obstacle_middle ? true : false);
  }

  // Field name: obstacle_right
  {
    cdr << (ros_message->obstacle_right ? true : false);
  }

  // Field name: big_obstacle
  {
    cdr << (ros_message->big_obstacle ? true : false);
  }

  return true;
}

static bool _ObstaclesId__cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  void * untyped_ros_message)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  _ObstaclesId__ros_msg_type * ros_message = static_cast<_ObstaclesId__ros_msg_type *>(untyped_ros_message);
  // Field name: obstacle_left
  {
    uint8_t tmp;
    cdr >> tmp;
    ros_message->obstacle_left = tmp ? true : false;
  }

  // Field name: obstacle_middle
  {
    uint8_t tmp;
    cdr >> tmp;
    ros_message->obstacle_middle = tmp ? true : false;
  }

  // Field name: obstacle_right
  {
    uint8_t tmp;
    cdr >> tmp;
    ros_message->obstacle_right = tmp ? true : false;
  }

  // Field name: big_obstacle
  {
    uint8_t tmp;
    cdr >> tmp;
    ros_message->big_obstacle = tmp ? true : false;
  }

  return true;
}  // NOLINT(readability/fn_size)

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_interfaces
size_t get_serialized_size_interfaces__msg__ObstaclesId(
  const void * untyped_ros_message,
  size_t current_alignment)
{
  const _ObstaclesId__ros_msg_type * ros_message = static_cast<const _ObstaclesId__ros_msg_type *>(untyped_ros_message);
  (void)ros_message;
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // field.name obstacle_left
  {
    size_t item_size = sizeof(ros_message->obstacle_left);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name obstacle_middle
  {
    size_t item_size = sizeof(ros_message->obstacle_middle);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name obstacle_right
  {
    size_t item_size = sizeof(ros_message->obstacle_right);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name big_obstacle
  {
    size_t item_size = sizeof(ros_message->big_obstacle);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  return current_alignment - initial_alignment;
}

static uint32_t _ObstaclesId__get_serialized_size(const void * untyped_ros_message)
{
  return static_cast<uint32_t>(
    get_serialized_size_interfaces__msg__ObstaclesId(
      untyped_ros_message, 0));
}

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_interfaces
size_t max_serialized_size_interfaces__msg__ObstaclesId(
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

  // member: obstacle_left
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint8_t);
  }
  // member: obstacle_middle
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint8_t);
  }
  // member: obstacle_right
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint8_t);
  }
  // member: big_obstacle
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint8_t);
  }

  return current_alignment - initial_alignment;
}

static size_t _ObstaclesId__max_serialized_size(char & bounds_info)
{
  bool full_bounded;
  bool is_plain;
  size_t ret_val;

  ret_val = max_serialized_size_interfaces__msg__ObstaclesId(
    full_bounded, is_plain, 0);

  bounds_info =
    is_plain ? ROSIDL_TYPESUPPORT_FASTRTPS_PLAIN_TYPE :
    full_bounded ? ROSIDL_TYPESUPPORT_FASTRTPS_BOUNDED_TYPE : ROSIDL_TYPESUPPORT_FASTRTPS_UNBOUNDED_TYPE;
  return ret_val;
}


static message_type_support_callbacks_t __callbacks_ObstaclesId = {
  "interfaces::msg",
  "ObstaclesId",
  _ObstaclesId__cdr_serialize,
  _ObstaclesId__cdr_deserialize,
  _ObstaclesId__get_serialized_size,
  _ObstaclesId__max_serialized_size
};

static rosidl_message_type_support_t _ObstaclesId__type_support = {
  rosidl_typesupport_fastrtps_c__identifier,
  &__callbacks_ObstaclesId,
  get_message_typesupport_handle_function,
};

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, interfaces, msg, ObstaclesId)() {
  return &_ObstaclesId__type_support;
}

#if defined(__cplusplus)
}
#endif
