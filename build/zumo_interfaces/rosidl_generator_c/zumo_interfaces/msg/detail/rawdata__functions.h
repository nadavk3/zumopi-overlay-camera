// generated from rosidl_generator_c/resource/idl__functions.h.em
// with input from zumo_interfaces:msg/Rawdata.idl
// generated code does not contain a copyright notice

#ifndef ZUMO_INTERFACES__MSG__DETAIL__RAWDATA__FUNCTIONS_H_
#define ZUMO_INTERFACES__MSG__DETAIL__RAWDATA__FUNCTIONS_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stdlib.h>

#include "rosidl_runtime_c/visibility_control.h"
#include "zumo_interfaces/msg/rosidl_generator_c__visibility_control.h"

#include "zumo_interfaces/msg/detail/rawdata__struct.h"

/// Initialize msg/Rawdata message.
/**
 * If the init function is called twice for the same message without
 * calling fini inbetween previously allocated memory will be leaked.
 * \param[in,out] msg The previously allocated message pointer.
 * Fields without a default value will not be initialized by this function.
 * You might want to call memset(msg, 0, sizeof(
 * zumo_interfaces__msg__Rawdata
 * )) before or use
 * zumo_interfaces__msg__Rawdata__create()
 * to allocate and initialize the message.
 * \return true if initialization was successful, otherwise false
 */
ROSIDL_GENERATOR_C_PUBLIC_zumo_interfaces
bool
zumo_interfaces__msg__Rawdata__init(zumo_interfaces__msg__Rawdata * msg);

/// Finalize msg/Rawdata message.
/**
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_zumo_interfaces
void
zumo_interfaces__msg__Rawdata__fini(zumo_interfaces__msg__Rawdata * msg);

/// Create msg/Rawdata message.
/**
 * It allocates the memory for the message, sets the memory to zero, and
 * calls
 * zumo_interfaces__msg__Rawdata__init().
 * \return The pointer to the initialized message if successful,
 * otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_zumo_interfaces
zumo_interfaces__msg__Rawdata *
zumo_interfaces__msg__Rawdata__create();

/// Destroy msg/Rawdata message.
/**
 * It calls
 * zumo_interfaces__msg__Rawdata__fini()
 * and frees the memory of the message.
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_zumo_interfaces
void
zumo_interfaces__msg__Rawdata__destroy(zumo_interfaces__msg__Rawdata * msg);


/// Initialize array of msg/Rawdata messages.
/**
 * It allocates the memory for the number of elements and calls
 * zumo_interfaces__msg__Rawdata__init()
 * for each element of the array.
 * \param[in,out] array The allocated array pointer.
 * \param[in] size The size / capacity of the array.
 * \return true if initialization was successful, otherwise false
 * If the array pointer is valid and the size is zero it is guaranteed
 # to return true.
 */
ROSIDL_GENERATOR_C_PUBLIC_zumo_interfaces
bool
zumo_interfaces__msg__Rawdata__Sequence__init(zumo_interfaces__msg__Rawdata__Sequence * array, size_t size);

/// Finalize array of msg/Rawdata messages.
/**
 * It calls
 * zumo_interfaces__msg__Rawdata__fini()
 * for each element of the array and frees the memory for the number of
 * elements.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_zumo_interfaces
void
zumo_interfaces__msg__Rawdata__Sequence__fini(zumo_interfaces__msg__Rawdata__Sequence * array);

/// Create array of msg/Rawdata messages.
/**
 * It allocates the memory for the array and calls
 * zumo_interfaces__msg__Rawdata__Sequence__init().
 * \param[in] size The size / capacity of the array.
 * \return The pointer to the initialized array if successful, otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_zumo_interfaces
zumo_interfaces__msg__Rawdata__Sequence *
zumo_interfaces__msg__Rawdata__Sequence__create(size_t size);

/// Destroy array of msg/Rawdata messages.
/**
 * It calls
 * zumo_interfaces__msg__Rawdata__Sequence__fini()
 * on the array,
 * and frees the memory of the array.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_zumo_interfaces
void
zumo_interfaces__msg__Rawdata__Sequence__destroy(zumo_interfaces__msg__Rawdata__Sequence * array);

#ifdef __cplusplus
}
#endif

#endif  // ZUMO_INTERFACES__MSG__DETAIL__RAWDATA__FUNCTIONS_H_
