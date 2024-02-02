// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from interfaces:msg/SideObstacles.idl
// generated code does not contain a copyright notice
#include "interfaces/msg/detail/side_obstacles__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


bool
interfaces__msg__SideObstacles__init(interfaces__msg__SideObstacles * msg)
{
  if (!msg) {
    return false;
  }
  // left_lidar
  msg->left_lidar = false;
  // right_lidar
  msg->right_lidar = false;
  // left_min
  // right_min
  return true;
}

void
interfaces__msg__SideObstacles__fini(interfaces__msg__SideObstacles * msg)
{
  if (!msg) {
    return;
  }
  // left_lidar
  // right_lidar
  // left_min
  // right_min
}

bool
interfaces__msg__SideObstacles__are_equal(const interfaces__msg__SideObstacles * lhs, const interfaces__msg__SideObstacles * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // left_lidar
  if (lhs->left_lidar != rhs->left_lidar) {
    return false;
  }
  // right_lidar
  if (lhs->right_lidar != rhs->right_lidar) {
    return false;
  }
  // left_min
  if (lhs->left_min != rhs->left_min) {
    return false;
  }
  // right_min
  if (lhs->right_min != rhs->right_min) {
    return false;
  }
  return true;
}

bool
interfaces__msg__SideObstacles__copy(
  const interfaces__msg__SideObstacles * input,
  interfaces__msg__SideObstacles * output)
{
  if (!input || !output) {
    return false;
  }
  // left_lidar
  output->left_lidar = input->left_lidar;
  // right_lidar
  output->right_lidar = input->right_lidar;
  // left_min
  output->left_min = input->left_min;
  // right_min
  output->right_min = input->right_min;
  return true;
}

interfaces__msg__SideObstacles *
interfaces__msg__SideObstacles__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  interfaces__msg__SideObstacles * msg = (interfaces__msg__SideObstacles *)allocator.allocate(sizeof(interfaces__msg__SideObstacles), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(interfaces__msg__SideObstacles));
  bool success = interfaces__msg__SideObstacles__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
interfaces__msg__SideObstacles__destroy(interfaces__msg__SideObstacles * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    interfaces__msg__SideObstacles__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
interfaces__msg__SideObstacles__Sequence__init(interfaces__msg__SideObstacles__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  interfaces__msg__SideObstacles * data = NULL;

  if (size) {
    data = (interfaces__msg__SideObstacles *)allocator.zero_allocate(size, sizeof(interfaces__msg__SideObstacles), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = interfaces__msg__SideObstacles__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        interfaces__msg__SideObstacles__fini(&data[i - 1]);
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
interfaces__msg__SideObstacles__Sequence__fini(interfaces__msg__SideObstacles__Sequence * array)
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
      interfaces__msg__SideObstacles__fini(&array->data[i]);
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

interfaces__msg__SideObstacles__Sequence *
interfaces__msg__SideObstacles__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  interfaces__msg__SideObstacles__Sequence * array = (interfaces__msg__SideObstacles__Sequence *)allocator.allocate(sizeof(interfaces__msg__SideObstacles__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = interfaces__msg__SideObstacles__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
interfaces__msg__SideObstacles__Sequence__destroy(interfaces__msg__SideObstacles__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    interfaces__msg__SideObstacles__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
interfaces__msg__SideObstacles__Sequence__are_equal(const interfaces__msg__SideObstacles__Sequence * lhs, const interfaces__msg__SideObstacles__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!interfaces__msg__SideObstacles__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
interfaces__msg__SideObstacles__Sequence__copy(
  const interfaces__msg__SideObstacles__Sequence * input,
  interfaces__msg__SideObstacles__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(interfaces__msg__SideObstacles);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    interfaces__msg__SideObstacles * data =
      (interfaces__msg__SideObstacles *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!interfaces__msg__SideObstacles__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          interfaces__msg__SideObstacles__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!interfaces__msg__SideObstacles__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
