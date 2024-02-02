// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from interfaces:msg/State.idl
// generated code does not contain a copyright notice
#include "interfaces/msg/detail/state__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


// Include directives for member types
// Member `state_name`
#include "rosidl_runtime_c/string_functions.h"

bool
interfaces__msg__State__init(interfaces__msg__State * msg)
{
  if (!msg) {
    return false;
  }
  // current_state
  msg->current_state = 0;
  // previous_state
  msg->previous_state = -1;
  // state_name
  if (!rosidl_runtime_c__String__init(&msg->state_name)) {
    interfaces__msg__State__fini(msg);
    return false;
  }
  // message_index
  msg->message_index = 2;
  return true;
}

void
interfaces__msg__State__fini(interfaces__msg__State * msg)
{
  if (!msg) {
    return;
  }
  // current_state
  // previous_state
  // state_name
  rosidl_runtime_c__String__fini(&msg->state_name);
  // message_index
}

bool
interfaces__msg__State__are_equal(const interfaces__msg__State * lhs, const interfaces__msg__State * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // current_state
  if (lhs->current_state != rhs->current_state) {
    return false;
  }
  // previous_state
  if (lhs->previous_state != rhs->previous_state) {
    return false;
  }
  // state_name
  if (!rosidl_runtime_c__String__are_equal(
      &(lhs->state_name), &(rhs->state_name)))
  {
    return false;
  }
  // message_index
  if (lhs->message_index != rhs->message_index) {
    return false;
  }
  return true;
}

bool
interfaces__msg__State__copy(
  const interfaces__msg__State * input,
  interfaces__msg__State * output)
{
  if (!input || !output) {
    return false;
  }
  // current_state
  output->current_state = input->current_state;
  // previous_state
  output->previous_state = input->previous_state;
  // state_name
  if (!rosidl_runtime_c__String__copy(
      &(input->state_name), &(output->state_name)))
  {
    return false;
  }
  // message_index
  output->message_index = input->message_index;
  return true;
}

interfaces__msg__State *
interfaces__msg__State__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  interfaces__msg__State * msg = (interfaces__msg__State *)allocator.allocate(sizeof(interfaces__msg__State), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(interfaces__msg__State));
  bool success = interfaces__msg__State__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
interfaces__msg__State__destroy(interfaces__msg__State * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    interfaces__msg__State__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
interfaces__msg__State__Sequence__init(interfaces__msg__State__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  interfaces__msg__State * data = NULL;

  if (size) {
    data = (interfaces__msg__State *)allocator.zero_allocate(size, sizeof(interfaces__msg__State), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = interfaces__msg__State__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        interfaces__msg__State__fini(&data[i - 1]);
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
interfaces__msg__State__Sequence__fini(interfaces__msg__State__Sequence * array)
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
      interfaces__msg__State__fini(&array->data[i]);
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

interfaces__msg__State__Sequence *
interfaces__msg__State__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  interfaces__msg__State__Sequence * array = (interfaces__msg__State__Sequence *)allocator.allocate(sizeof(interfaces__msg__State__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = interfaces__msg__State__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
interfaces__msg__State__Sequence__destroy(interfaces__msg__State__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    interfaces__msg__State__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
interfaces__msg__State__Sequence__are_equal(const interfaces__msg__State__Sequence * lhs, const interfaces__msg__State__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!interfaces__msg__State__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
interfaces__msg__State__Sequence__copy(
  const interfaces__msg__State__Sequence * input,
  interfaces__msg__State__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(interfaces__msg__State);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    interfaces__msg__State * data =
      (interfaces__msg__State *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!interfaces__msg__State__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          interfaces__msg__State__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!interfaces__msg__State__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
