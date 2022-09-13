// generated from rosidl_generator_c/resource/idl__functions.h.em
// with input from dasc_msgs:msg/QuadSetpoint.idl
// generated code does not contain a copyright notice

#ifndef DASC_MSGS__MSG__DETAIL__QUAD_SETPOINT__FUNCTIONS_H_
#define DASC_MSGS__MSG__DETAIL__QUAD_SETPOINT__FUNCTIONS_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stdlib.h>

#include "rosidl_runtime_c/visibility_control.h"
#include "dasc_msgs/msg/rosidl_generator_c__visibility_control.h"

#include "dasc_msgs/msg/detail/quad_setpoint__struct.h"

/// Initialize msg/QuadSetpoint message.
/**
 * If the init function is called twice for the same message without
 * calling fini inbetween previously allocated memory will be leaked.
 * \param[in,out] msg The previously allocated message pointer.
 * Fields without a default value will not be initialized by this function.
 * You might want to call memset(msg, 0, sizeof(
 * dasc_msgs__msg__QuadSetpoint
 * )) before or use
 * dasc_msgs__msg__QuadSetpoint__create()
 * to allocate and initialize the message.
 * \return true if initialization was successful, otherwise false
 */
ROSIDL_GENERATOR_C_PUBLIC_dasc_msgs
bool
dasc_msgs__msg__QuadSetpoint__init(dasc_msgs__msg__QuadSetpoint * msg);

/// Finalize msg/QuadSetpoint message.
/**
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_dasc_msgs
void
dasc_msgs__msg__QuadSetpoint__fini(dasc_msgs__msg__QuadSetpoint * msg);

/// Create msg/QuadSetpoint message.
/**
 * It allocates the memory for the message, sets the memory to zero, and
 * calls
 * dasc_msgs__msg__QuadSetpoint__init().
 * \return The pointer to the initialized message if successful,
 * otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_dasc_msgs
dasc_msgs__msg__QuadSetpoint *
dasc_msgs__msg__QuadSetpoint__create();

/// Destroy msg/QuadSetpoint message.
/**
 * It calls
 * dasc_msgs__msg__QuadSetpoint__fini()
 * and frees the memory of the message.
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_dasc_msgs
void
dasc_msgs__msg__QuadSetpoint__destroy(dasc_msgs__msg__QuadSetpoint * msg);


/// Initialize array of msg/QuadSetpoint messages.
/**
 * It allocates the memory for the number of elements and calls
 * dasc_msgs__msg__QuadSetpoint__init()
 * for each element of the array.
 * \param[in,out] array The allocated array pointer.
 * \param[in] size The size / capacity of the array.
 * \return true if initialization was successful, otherwise false
 * If the array pointer is valid and the size is zero it is guaranteed
 # to return true.
 */
ROSIDL_GENERATOR_C_PUBLIC_dasc_msgs
bool
dasc_msgs__msg__QuadSetpoint__Sequence__init(dasc_msgs__msg__QuadSetpoint__Sequence * array, size_t size);

/// Finalize array of msg/QuadSetpoint messages.
/**
 * It calls
 * dasc_msgs__msg__QuadSetpoint__fini()
 * for each element of the array and frees the memory for the number of
 * elements.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_dasc_msgs
void
dasc_msgs__msg__QuadSetpoint__Sequence__fini(dasc_msgs__msg__QuadSetpoint__Sequence * array);

/// Create array of msg/QuadSetpoint messages.
/**
 * It allocates the memory for the array and calls
 * dasc_msgs__msg__QuadSetpoint__Sequence__init().
 * \param[in] size The size / capacity of the array.
 * \return The pointer to the initialized array if successful, otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_dasc_msgs
dasc_msgs__msg__QuadSetpoint__Sequence *
dasc_msgs__msg__QuadSetpoint__Sequence__create(size_t size);

/// Destroy array of msg/QuadSetpoint messages.
/**
 * It calls
 * dasc_msgs__msg__QuadSetpoint__Sequence__fini()
 * on the array,
 * and frees the memory of the array.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_dasc_msgs
void
dasc_msgs__msg__QuadSetpoint__Sequence__destroy(dasc_msgs__msg__QuadSetpoint__Sequence * array);

#ifdef __cplusplus
}
#endif

#endif  // DASC_MSGS__MSG__DETAIL__QUAD_SETPOINT__FUNCTIONS_H_