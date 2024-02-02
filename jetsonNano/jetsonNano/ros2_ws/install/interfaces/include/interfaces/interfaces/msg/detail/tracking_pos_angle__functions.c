// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from interfaces:msg/TrackingPosAngle.idl
// generated code does not contain a copyright notice
#include "interfaces/msg/detail/tracking_pos_angle__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


bool
interfaces__msg__TrackingPosAngle__init(interfaces__msg__TrackingPosAngle * msg)
{
  if (!msg) {
    return false;
  }
  // min_angle
  // max_angle
  // cam_angle
  // person_detected
  return true;
}

void
interfaces__msg__TrackingPosAngle__fini(interfaces__msg__TrackingPosAngle * msg)
{
  if (!msg) {
    return;
  }
  // min_angle
  // max_angle
  // cam_angle
  // person_detected
}

bool
interfaces__msg__TrackingPosAngle__are_equal(const interfaces__msg__TrackingPosAngle * lhs, const interfaces__msg__TrackingPosAngle * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // min_angle
  if (lhs->min_angle != rhs->min_angle) {
    return false;
  }
  // max_angle
  if (lhs->max_angle != rhs->max_angle) {
    return false;
  }
  // cam_angle
  if (lhs->cam_angle != rhs->cam_angle) {
    return false;
  }
  // person_detected
  if (lhs->person_detected != rhs->person_detected) {
    return false;
  }
  return true;
}

bool
interfaces__msg__TrackingPosAngle__copy(
  const interfaces__msg__TrackingPosAngle * input,
  interfaces__msg__TrackingPosAngle * output)
{
  if (!input || !output) {
    return false;
  }
  // min_angle
  output->min_angle = input->min_angle;
  // max_angle
  output->max_angle = input->max_angle;
  // cam_angle
  output->cam_angle = input->cam_angle;
  // person_detected
  output->person_detected = input->person_detected;
  return true;
}

interfaces__msg__TrackingPosAngle *
interfaces__msg__TrackingPosAngle__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  interfaces__msg__TrackingPosAngle * msg = (interfaces__msg__TrackingPosAngle *)allocator.allocate(sizeof(interfaces__msg__TrackingPosAngle), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(interfaces__msg__TrackingPosAngle));
  bool success = interfaces__msg__TrackingPosAngle__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
interfaces__msg__TrackingPosAngle__destroy(interfaces__msg__TrackingPosAngle * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    interfaces__msg__TrackingPosAngle__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
interfaces__msg__TrackingPosAngle__Sequence__init(interfaces__msg__TrackingPosAngle__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  interfaces__msg__TrackingPosAngle * data = NULL;

  if (size) {
    data = (interfaces__msg__TrackingPosAngle *)allocator.zero_allocate(size, sizeof(interfaces__msg__TrackingPosAngle), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = interfaces__msg__TrackingPosAngle__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        interfaces__msg__TrackingPosAngle__fini(&data[i - 1]);
      }
      allocator.deallocate(data, allocator.state);
      return false;
    }
  }
  array->data = data;
  array->size = size;
  array->capacity = size;
  return true;
}

void
interfaces__msg__TrackingPosAngle__Sequence__fini(interfaces__msg__TrackingPosAngle__Sequence * array)
{
  if (!array) {
    return;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();

  if (array->data) {
    // ensure that data and capacity values are consistent
    assert(array->capacity > 0);
    // finalize all array elements
    for (size_t i = 0; i < array->capacity; ++i) {
      interfaces__msg__TrackingPosAngle__fini(&array->data[i]);
    }
    allocator.deallocate(array->data, allocator.state);
    array->data = NULL;
    array->size = 0;
    array->capacity = 0;
  } else {
    // ensure that data, size, and capacity values are consistent
    assert(0 == array->size);
    assert(0 == array->capacity);
  }
}

interfaces__msg__TrackingPosAngle__Sequence *
interfaces__msg__TrackingPosAngle__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  interfaces__msg__TrackingPosAngle__Sequence * array = (interfaces__msg__TrackingPosAngle__Sequence *)allocator.allocate(sizeof(interfaces__msg__TrackingPosAngle__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = interfaces__msg__TrackingPosAngle__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
interfaces__msg__TrackingPosAngle__Sequence__destroy(interfaces__msg__TrackingPosAngle__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    interfaces__msg__TrackingPosAngle__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
interfaces__msg__TrackingPosAngle__Sequence__are_equal(const interfaces__msg__TrackingPosAngle__Sequence * lhs, const interfaces__msg__TrackingPosAngle__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!interfaces__msg__TrackingPosAngle__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
interfaces__msg__TrackingPosAngle__Sequence__copy(
  const interfaces__msg__TrackingPosAngle__Sequence * input,
  interfaces__msg__TrackingPosAngle__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(interfaces__msg__TrackingPosAngle);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    interfaces__msg__TrackingPosAngle * data =
      (interfaces__msg__TrackingPosAngle *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!interfaces__msg__TrackingPosAngle__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          interfaces__msg__TrackingPosAngle__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!interfaces__msg__TrackingPosAngle__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
