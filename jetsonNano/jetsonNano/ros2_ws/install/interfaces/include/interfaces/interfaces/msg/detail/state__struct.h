// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from interfaces:msg/State.idl
// generated code does not contain a copyright notice

#ifndef INTERFACES__MSG__DETAIL__STATE__STRUCT_H_
#define INTERFACES__MSG__DETAIL__STATE__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Include directives for member types
// Member 'state_name'
#include "rosidl_runtime_c/string.h"

/// Struct defined in msg/State in the package interfaces.
typedef struct interfaces__msg__State
{
  int8_t current_state;
  int8_t previous_state;
  rosidl_runtime_c__String state_name;
  int8_t message_index;
} interfaces__msg__State;

// Struct for a sequence of interfaces__msg__State.
typedef struct interfaces__msg__State__Sequence
{
  interfaces__msg__State * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} interfaces__msg__State__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // INTERFACES__MSG__DETAIL__STATE__STRUCT_H_
