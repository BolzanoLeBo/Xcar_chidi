// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from interfaces:msg/AvoidanceParameters.idl
// generated code does not contain a copyright notice

#ifndef INTERFACES__MSG__DETAIL__AVOIDANCE_PARAMETERS__STRUCT_H_
#define INTERFACES__MSG__DETAIL__AVOIDANCE_PARAMETERS__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

/// Struct defined in msg/AvoidanceParameters in the package interfaces.
typedef struct interfaces__msg__AvoidanceParameters
{
  /// true : go by the left/ false : go by the right
  bool left;
  /// true : go back before avoidance/ false : avoid directly
  bool big;
} interfaces__msg__AvoidanceParameters;

// Struct for a sequence of interfaces__msg__AvoidanceParameters.
typedef struct interfaces__msg__AvoidanceParameters__Sequence
{
  interfaces__msg__AvoidanceParameters * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} interfaces__msg__AvoidanceParameters__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // INTERFACES__MSG__DETAIL__AVOIDANCE_PARAMETERS__STRUCT_H_
