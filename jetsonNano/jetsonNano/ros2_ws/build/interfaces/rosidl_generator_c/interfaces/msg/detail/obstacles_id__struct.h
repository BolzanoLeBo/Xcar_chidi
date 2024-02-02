// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from interfaces:msg/ObstaclesId.idl
// generated code does not contain a copyright notice

#ifndef INTERFACES__MSG__DETAIL__OBSTACLES_ID__STRUCT_H_
#define INTERFACES__MSG__DETAIL__OBSTACLES_ID__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

/// Struct defined in msg/ObstaclesId in the package interfaces.
typedef struct interfaces__msg__ObstaclesId
{
  /// there is an obstacle on the left
  bool obstacle_left;
  /// there is an obstacle on the middle
  bool obstacle_middle;
  /// there is an obstacle on the rigth
  bool obstacle_right;
  /// there is a big obstacle
  bool big_obstacle;
} interfaces__msg__ObstaclesId;

// Struct for a sequence of interfaces__msg__ObstaclesId.
typedef struct interfaces__msg__ObstaclesId__Sequence
{
  interfaces__msg__ObstaclesId * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} interfaces__msg__ObstaclesId__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // INTERFACES__MSG__DETAIL__OBSTACLES_ID__STRUCT_H_
