// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from zumo_interfaces:msg/Rawdata.idl
// generated code does not contain a copyright notice

#ifndef ZUMO_INTERFACES__MSG__DETAIL__RAWDATA__STRUCT_H_
#define ZUMO_INTERFACES__MSG__DETAIL__RAWDATA__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Include directives for member types
// Member 'cnt'
#include "geometry_msgs/msg/detail/polygon__struct.h"
// Member 'red_list'
// Member 'blue_list'
// Member 'green_list'
// Member 'yellow_list'
#include "geometry_msgs/msg/detail/point32__struct.h"

// Struct defined in msg/Rawdata in the package zumo_interfaces.
typedef struct zumo_interfaces__msg__Rawdata
{
  geometry_msgs__msg__Polygon__Sequence cnt;
  geometry_msgs__msg__Point32__Sequence red_list;
  geometry_msgs__msg__Point32__Sequence blue_list;
  geometry_msgs__msg__Point32__Sequence green_list;
  geometry_msgs__msg__Point32__Sequence yellow_list;
} zumo_interfaces__msg__Rawdata;

// Struct for a sequence of zumo_interfaces__msg__Rawdata.
typedef struct zumo_interfaces__msg__Rawdata__Sequence
{
  zumo_interfaces__msg__Rawdata * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} zumo_interfaces__msg__Rawdata__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // ZUMO_INTERFACES__MSG__DETAIL__RAWDATA__STRUCT_H_
