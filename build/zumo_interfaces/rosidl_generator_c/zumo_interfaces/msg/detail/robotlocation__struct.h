// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from zumo_interfaces:msg/Robotlocation.idl
// generated code does not contain a copyright notice

#ifndef ZUMO_INTERFACES__MSG__DETAIL__ROBOTLOCATION__STRUCT_H_
#define ZUMO_INTERFACES__MSG__DETAIL__ROBOTLOCATION__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Include directives for member types
// Member 'id'
#include "rosidl_runtime_c/string.h"

// Struct defined in msg/Robotlocation in the package zumo_interfaces.
typedef struct zumo_interfaces__msg__Robotlocation
{
  rosidl_runtime_c__String id;
  int32_t x;
  int32_t y;
} zumo_interfaces__msg__Robotlocation;

// Struct for a sequence of zumo_interfaces__msg__Robotlocation.
typedef struct zumo_interfaces__msg__Robotlocation__Sequence
{
  zumo_interfaces__msg__Robotlocation * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} zumo_interfaces__msg__Robotlocation__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // ZUMO_INTERFACES__MSG__DETAIL__ROBOTLOCATION__STRUCT_H_
