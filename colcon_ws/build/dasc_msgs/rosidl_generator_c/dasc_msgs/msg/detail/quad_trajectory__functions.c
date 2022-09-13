// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from dasc_msgs:msg/QuadTrajectory.idl
// generated code does not contain a copyright notice
#include "dasc_msgs/msg/detail/quad_trajectory__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>


// Include directives for member types
// Member `header`
#include "std_msgs/msg/detail/header__functions.h"
// Member `ts`
// Member `xs`
// Member `ys`
// Member `zs`
// Member `yaws`
// Member `vxs`
// Member `vys`
// Member `vzs`
#include "rosidl_runtime_c/primitives_sequence_functions.h"

bool
dasc_msgs__msg__QuadTrajectory__init(dasc_msgs__msg__QuadTrajectory * msg)
{
  if (!msg) {
    return false;
  }
  // header
  if (!std_msgs__msg__Header__init(&msg->header)) {
    dasc_msgs__msg__QuadTrajectory__fini(msg);
    return false;
  }
  // ts
  if (!rosidl_runtime_c__double__Sequence__init(&msg->ts, 0)) {
    dasc_msgs__msg__QuadTrajectory__fini(msg);
    return false;
  }
  // xs
  if (!rosidl_runtime_c__double__Sequence__init(&msg->xs, 0)) {
    dasc_msgs__msg__QuadTrajectory__fini(msg);
    return false;
  }
  // ys
  if (!rosidl_runtime_c__double__Sequence__init(&msg->ys, 0)) {
    dasc_msgs__msg__QuadTrajectory__fini(msg);
    return false;
  }
  // zs
  if (!rosidl_runtime_c__double__Sequence__init(&msg->zs, 0)) {
    dasc_msgs__msg__QuadTrajectory__fini(msg);
    return false;
  }
  // yaws
  if (!rosidl_runtime_c__double__Sequence__init(&msg->yaws, 0)) {
    dasc_msgs__msg__QuadTrajectory__fini(msg);
    return false;
  }
  // vxs
  if (!rosidl_runtime_c__double__Sequence__init(&msg->vxs, 0)) {
    dasc_msgs__msg__QuadTrajectory__fini(msg);
    return false;
  }
  // vys
  if (!rosidl_runtime_c__double__Sequence__init(&msg->vys, 0)) {
    dasc_msgs__msg__QuadTrajectory__fini(msg);
    return false;
  }
  // vzs
  if (!rosidl_runtime_c__double__Sequence__init(&msg->vzs, 0)) {
    dasc_msgs__msg__QuadTrajectory__fini(msg);
    return false;
  }
  return true;
}

void
dasc_msgs__msg__QuadTrajectory__fini(dasc_msgs__msg__QuadTrajectory * msg)
{
  if (!msg) {
    return;
  }
  // header
  std_msgs__msg__Header__fini(&msg->header);
  // ts
  rosidl_runtime_c__double__Sequence__fini(&msg->ts);
  // xs
  rosidl_runtime_c__double__Sequence__fini(&msg->xs);
  // ys
  rosidl_runtime_c__double__Sequence__fini(&msg->ys);
  // zs
  rosidl_runtime_c__double__Sequence__fini(&msg->zs);
  // yaws
  rosidl_runtime_c__double__Sequence__fini(&msg->yaws);
  // vxs
  rosidl_runtime_c__double__Sequence__fini(&msg->vxs);
  // vys
  rosidl_runtime_c__double__Sequence__fini(&msg->vys);
  // vzs
  rosidl_runtime_c__double__Sequence__fini(&msg->vzs);
}

dasc_msgs__msg__QuadTrajectory *
dasc_msgs__msg__QuadTrajectory__create()
{
  dasc_msgs__msg__QuadTrajectory * msg = (dasc_msgs__msg__QuadTrajectory *)malloc(sizeof(dasc_msgs__msg__QuadTrajectory));
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(dasc_msgs__msg__QuadTrajectory));
  bool success = dasc_msgs__msg__QuadTrajectory__init(msg);
  if (!success) {
    free(msg);
    return NULL;
  }
  return msg;
}

void
dasc_msgs__msg__QuadTrajectory__destroy(dasc_msgs__msg__QuadTrajectory * msg)
{
  if (msg) {
    dasc_msgs__msg__QuadTrajectory__fini(msg);
  }
  free(msg);
}


bool
dasc_msgs__msg__QuadTrajectory__Sequence__init(dasc_msgs__msg__QuadTrajectory__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  dasc_msgs__msg__QuadTrajectory * data = NULL;
  if (size) {
    data = (dasc_msgs__msg__QuadTrajectory *)calloc(size, sizeof(dasc_msgs__msg__QuadTrajectory));
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = dasc_msgs__msg__QuadTrajectory__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        dasc_msgs__msg__QuadTrajectory__fini(&data[i - 1]);
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
dasc_msgs__msg__QuadTrajectory__Sequence__fini(dasc_msgs__msg__QuadTrajectory__Sequence * array)
{
  if (!array) {
    return;
  }
  if (array->data) {
    // ensure that data and capacity values are consistent
    assert(array->capacity > 0);
    // finalize all array elements
    for (size_t i = 0; i < array->capacity; ++i) {
      dasc_msgs__msg__QuadTrajectory__fini(&array->data[i]);
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

dasc_msgs__msg__QuadTrajectory__Sequence *
dasc_msgs__msg__QuadTrajectory__Sequence__create(size_t size)
{
  dasc_msgs__msg__QuadTrajectory__Sequence * array = (dasc_msgs__msg__QuadTrajectory__Sequence *)malloc(sizeof(dasc_msgs__msg__QuadTrajectory__Sequence));
  if (!array) {
    return NULL;
  }
  bool success = dasc_msgs__msg__QuadTrajectory__Sequence__init(array, size);
  if (!success) {
    free(array);
    return NULL;
  }
  return array;
}

void
dasc_msgs__msg__QuadTrajectory__Sequence__destroy(dasc_msgs__msg__QuadTrajectory__Sequence * array)
{
  if (array) {
    dasc_msgs__msg__QuadTrajectory__Sequence__fini(array);
  }
  free(array);
}
