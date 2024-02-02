// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from interfaces:msg/TargetImage.idl
// generated code does not contain a copyright notice

#ifndef INTERFACES__MSG__DETAIL__TARGET_IMAGE__STRUCT_H_
#define INTERFACES__MSG__DETAIL__TARGET_IMAGE__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Include directives for member types
// Member 'image'
#include "rosidl_runtime_c/string.h"

/// Struct defined in msg/TargetImage in the package interfaces.
typedef struct interfaces__msg__TargetImage
{
  rosidl_runtime_c__String image;
} interfaces__msg__TargetImage;

// Struct for a sequence of interfaces__msg__TargetImage.
typedef struct interfaces__msg__TargetImage__Sequence
{
  interfaces__msg__TargetImage * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} interfaces__msg__TargetImage__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // INTERFACES__MSG__DETAIL__TARGET_IMAGE__STRUCT_H_
