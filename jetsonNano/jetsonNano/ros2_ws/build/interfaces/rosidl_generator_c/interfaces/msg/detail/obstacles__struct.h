// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from interfaces:msg/Obstacles.idl
// generated code does not contain a copyright notice

#ifndef INTERFACES__MSG__DETAIL__OBSTACLES__STRUCT_H_
#define INTERFACES__MSG__DETAIL__OBSTACLES__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

/// Struct defined in msg/Obstacles in the package interfaces.
typedef struct interfaces__msg__Obstacles
{
  int8_t front;
  int8_t rear;
  /// signal
  int8_t us_error;
  /// signal
  int8_t lidar_error;
} interfaces__msg__Obstacles;

// Struct for a sequence of interfaces__msg__Obstacles.
typedef struct interfaces__msg__Obstacles__Sequence
{
  interfaces__msg__Obstacles * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} interfaces__msg__Obstacles__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // INTERFACES__MSG__DETAIL__OBSTACLES__STRUCT_H_
