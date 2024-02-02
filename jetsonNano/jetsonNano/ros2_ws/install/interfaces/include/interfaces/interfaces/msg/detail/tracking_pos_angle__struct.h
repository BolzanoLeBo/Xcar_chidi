// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from interfaces:msg/TrackingPosAngle.idl
// generated code does not contain a copyright notice

#ifndef INTERFACES__MSG__DETAIL__TRACKING_POS_ANGLE__STRUCT_H_
#define INTERFACES__MSG__DETAIL__TRACKING_POS_ANGLE__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

/// Struct defined in msg/TrackingPosAngle in the package interfaces.
typedef struct interfaces__msg__TrackingPosAngle
{
  float min_angle;
  float max_angle;
  float cam_angle;
  bool person_detected;
} interfaces__msg__TrackingPosAngle;

// Struct for a sequence of interfaces__msg__TrackingPosAngle.
typedef struct interfaces__msg__TrackingPosAngle__Sequence
{
  interfaces__msg__TrackingPosAngle * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} interfaces__msg__TrackingPosAngle__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // INTERFACES__MSG__DETAIL__TRACKING_POS_ANGLE__STRUCT_H_
