// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from interfaces:msg/Lidar.idl
// generated code does not contain a copyright notice

#ifndef INTERFACES__MSG__DETAIL__LIDAR__STRUCT_H_
#define INTERFACES__MSG__DETAIL__LIDAR__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

/// Struct defined in msg/Lidar in the package interfaces.
typedef struct interfaces__msg__Lidar
{
  /// true when there is a high intensity on the left
  bool left_lidar;
  /// same as "left"
  bool right_lidar;
  /// minimum distance with an obstacle on the left
  float left_min;
  /// same as "left"
  float right_min;
} interfaces__msg__Lidar;

// Struct for a sequence of interfaces__msg__Lidar.
typedef struct interfaces__msg__Lidar__Sequence
{
  interfaces__msg__Lidar * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} interfaces__msg__Lidar__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // INTERFACES__MSG__DETAIL__LIDAR__STRUCT_H_
