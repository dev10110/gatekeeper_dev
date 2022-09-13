// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from dasc_msgs:msg/QuadSetpoint.idl
// generated code does not contain a copyright notice
#include "dasc_msgs/msg/detail/quad_setpoint__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>


// Include directives for member types
// Member `header`
#include "std_msgs/msg/detail/header__functions.h"

bool
dasc_msgs__msg__QuadSetpoint__init(dasc_msgs__msg__QuadSetpoint * msg)
{
  if (!msg) {
    return false;
  }
  // header
  if (!std_msgs__msg__Header__init(&msg->header)) {
    dasc_msgs__msg__QuadSetpoint__fini(msg);
    return false;
  }
  // x
  // y
  // z
  // yaw
  return true;
}

void
dasc_msgs__msg__QuadSetpoint__fini(dasc_msgs__msg__QuadSetpoint * msg)
{
  if (!msg) {
    return;
  }
  // header
  std_msgs__msg__Header__fini(&msg->header);
  // x
  // y
  // z
  // yaw
}

dasc_msgs__msg__QuadSetpoint *
dasc_msgs__msg__QuadSetpoint__create()
{
  dasc_msgs__msg__QuadSetpoint * msg = (dasc_msgs__msg__QuadSetpoint *)malloc(sizeof(dasc_msgs__msg__QuadSetpoint));
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(dasc_msgs__msg__QuadSetpoint));
  bool success = dasc_msgs__msg__QuadSetpoint__init(msg);
  if (!success) {
    free(msg);
    return NULL;
  }
  return msg;
}

void
dasc_msgs__msg__QuadSetpoint__destroy(dasc_msgs__msg__QuadSetpoint * msg)
{
  if (msg) {
    dasc_msgs__msg__QuadSetpoint__fini(msg);
  }
  free(msg);
}


bool
dasc_msgs__msg__QuadSetpoint__Sequence__init(dasc_msgs__msg__QuadSetpoint__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  dasc_msgs__msg__QuadSetpoint * data = NULL;
  if (size) {
    data = (dasc_msgs__msg__QuadSetpoint *)calloc(size, sizeof(dasc_msgs__msg__QuadSetpoint));
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = dasc_msgs__msg__QuadSetpoint__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        dasc_msgs__msg__QuadSetpoint__fini(&data[i - 1]);
      }
      free(data);
      return false;
    }
  }
  array->data = data;
  array->size = size;
  array->capacity = size;
  return true;
}

void
dasc_msgs__msg__QuadSetpoint__Sequence__fini(dasc_msgs__msg__QuadSetpoint__Sequence * array)
{
  if (!array) {
    return;
  }
  if (array->data) {
    // ensure that data and capacity values are consistent
    assert(array->capacity > 0);
    // finalize all array elements
    for (size_t i = 0; i < array->capacity; ++i) {
      dasc_msgs__msg__QuadSetpoint__fini(&array->data[i]);
    }
    free(array->data);
    array->data = NULL;
    array->size = 0;
    array->capacity = 0;
  } else {
    // ensure that data, size, and capacity values are consistent
    assert(0 == array->size);
    assert(0 == array->capacity);
  }
}

dasc_msgs__msg__QuadSetpoint__Sequence *
dasc_msgs__msg__QuadSetpoint__Sequence__create(size_t size)
{
  dasc_msgs__msg__QuadSetpoint__Sequence * array = (dasc_msgs__msg__QuadSetpoint__Sequence *)malloc(sizeof(dasc_msgs__msg__QuadSetpoint__Sequence));
  if (!array) {
    return NULL;
  }
  bool success = dasc_msgs__msg__QuadSetpoint__Sequence__init(array, size);
  if (!success) {
    free(array);
    return NULL;
  }
  return array;
}

void
dasc_msgs__msg__QuadSetpoint__Sequence__destroy(dasc_msgs__msg__QuadSetpoint__Sequence * array)
{
  if (array) {
    dasc_msgs__msg__QuadSetpoint__Sequence__fini(array);
  }
  free(array);
}
