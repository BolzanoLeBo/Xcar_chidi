// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from interfaces:msg/WebMode.idl
// generated code does not contain a copyright notice

#ifndef INTERFACES__MSG__DETAIL__WEB_MODE__STRUCT_H_
#define INTERFACES__MSG__DETAIL__WEB_MODE__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

/// Struct defined in msg/WebMode in the package interfaces.
typedef struct interfaces__msg__WebMode
{
  int8_t button;
  float throttle;
  float steering;
  bool reverse;
} interfaces__msg__WebMode;

// Struct for a sequence of interfaces__msg__WebMode.
typedef struct interfaces__msg__WebMode__Sequence
{
  interfaces__msg__WebMode * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} interfaces__msg__WebMode__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // INTERFACES__MSG__DETAIL__WEB_MODE__STRUCT_H_
