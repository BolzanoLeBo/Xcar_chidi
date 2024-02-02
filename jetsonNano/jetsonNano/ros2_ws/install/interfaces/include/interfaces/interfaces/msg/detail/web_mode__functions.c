// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from interfaces:msg/WebMode.idl
// generated code does not contain a copyright notice
#include "interfaces/msg/detail/web_mode__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


bool
interfaces__msg__WebMode__init(interfaces__msg__WebMode * msg)
{
  if (!msg) {
    return false;
  }
  // button
  msg->button = 0;
  // throttle
  msg->throttle = 0.0f;
  // steering
  msg->steering = 0.0f;
  // reverse
  msg->reverse = false;
  return true;
}

void
interfaces__msg__WebMode__fini(interfaces__msg__WebMode * msg)
{
  if (!msg) {
    return;
  }
  // button
  // throttle
  // steering
  // reverse
}

bool
interfaces__msg__WebMode__are_equal(const interfaces__msg__WebMode * lhs, const interfaces__msg__WebMode * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // button
  if (lhs->button != rhs->button) {
    return false;
  }
  // throttle
  if (lhs->throttle != rhs->throttle) {
    return false;
  }
  // steering
  if (lhs->steering != rhs->steering) {
    return false;
  }
  // reverse
  if (lhs->reverse != rhs->reverse) {
    return false;
  }
  return true;
}

bool
interfaces__msg__WebMode__copy(
  const interfaces__msg__WebMode * input,
  interfaces__msg__WebMode * output)
{
  if (!input || !output) {
    return false;
  }
  // button
  output->button = input->button;
  // throttle
  output->throttle = input->throttle;
  // steering
  output->steering = input->steering;
  // reverse
  output->reverse = input->reverse;
  return true;
}

interfaces__msg__WebMode *
interfaces__msg__WebMode__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  interfaces__msg__WebMode * msg = (interfaces__msg__WebMode *)allocator.allocate(sizeof(interfaces__msg__WebMode), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(interfaces__msg__WebMode));
  bool success = interfaces__msg__WebMode__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
interfaces__msg__WebMode__destroy(interfaces__msg__WebMode * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    interfaces__msg__WebMode__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
interfaces__msg__WebMode__Sequence__init(interfaces__msg__WebMode__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  interfaces__msg__WebMode * data = NULL;

  if (size) {
    data = (interfaces__msg__WebMode *)allocator.zero_allocate(size, sizeof(interfaces__msg__WebMode), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = interfaces__msg__WebMode__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        interfaces__msg__WebMode__fini(&data[i - 1]);
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
interfaces__msg__WebMode__Sequence__fini(interfaces__msg__WebMode__Sequence * array)
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
      interfaces__msg__WebMode__fini(&array->data[i]);
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

interfaces__msg__WebMode__Sequence *
interfaces__msg__WebMode__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  interfaces__msg__WebMode__Sequence * array = (interfaces__msg__WebMode__Sequence *)allocator.allocate(sizeof(interfaces__msg__WebMode__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = interfaces__msg__WebMode__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
interfaces__msg__WebMode__Sequence__destroy(interfaces__msg__WebMode__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    interfaces__msg__WebMode__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
interfaces__msg__WebMode__Sequence__are_equal(const interfaces__msg__WebMode__Sequence * lhs, const interfaces__msg__WebMode__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!interfaces__msg__WebMode__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
interfaces__msg__WebMode__Sequence__copy(
  const interfaces__msg__WebMode__Sequence * input,
  interfaces__msg__WebMode__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(interfaces__msg__WebMode);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    interfaces__msg__WebMode * data =
      (interfaces__msg__WebMode *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!interfaces__msg__WebMode__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          interfaces__msg__WebMode__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!interfaces__msg__WebMode__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
