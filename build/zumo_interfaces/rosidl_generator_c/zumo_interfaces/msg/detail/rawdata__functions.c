// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from zumo_interfaces:msg/Rawdata.idl
// generated code does not contain a copyright notice
#include "zumo_interfaces/msg/detail/rawdata__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>


// Include directives for member types
// Member `cnt`
#include "geometry_msgs/msg/detail/polygon__functions.h"
// Member `red_list`
// Member `blue_list`
// Member `green_list`
// Member `yellow_list`
#include "geometry_msgs/msg/detail/point32__functions.h"

bool
zumo_interfaces__msg__Rawdata__init(zumo_interfaces__msg__Rawdata * msg)
{
  if (!msg) {
    return false;
  }
  // cnt
  if (!geometry_msgs__msg__Polygon__Sequence__init(&msg->cnt, 0)) {
    zumo_interfaces__msg__Rawdata__fini(msg);
    return false;
  }
  // red_list
  if (!geometry_msgs__msg__Point32__Sequence__init(&msg->red_list, 0)) {
    zumo_interfaces__msg__Rawdata__fini(msg);
    return false;
  }
  // blue_list
  if (!geometry_msgs__msg__Point32__Sequence__init(&msg->blue_list, 0)) {
    zumo_interfaces__msg__Rawdata__fini(msg);
    return false;
  }
  // green_list
  if (!geometry_msgs__msg__Point32__Sequence__init(&msg->green_list, 0)) {
    zumo_interfaces__msg__Rawdata__fini(msg);
    return false;
  }
  // yellow_list
  if (!geometry_msgs__msg__Point32__Sequence__init(&msg->yellow_list, 0)) {
    zumo_interfaces__msg__Rawdata__fini(msg);
    return false;
  }
  return true;
}

void
zumo_interfaces__msg__Rawdata__fini(zumo_interfaces__msg__Rawdata * msg)
{
  if (!msg) {
    return;
  }
  // cnt
  geometry_msgs__msg__Polygon__Sequence__fini(&msg->cnt);
  // red_list
  geometry_msgs__msg__Point32__Sequence__fini(&msg->red_list);
  // blue_list
  geometry_msgs__msg__Point32__Sequence__fini(&msg->blue_list);
  // green_list
  geometry_msgs__msg__Point32__Sequence__fini(&msg->green_list);
  // yellow_list
  geometry_msgs__msg__Point32__Sequence__fini(&msg->yellow_list);
}

zumo_interfaces__msg__Rawdata *
zumo_interfaces__msg__Rawdata__create()
{
  zumo_interfaces__msg__Rawdata * msg = (zumo_interfaces__msg__Rawdata *)malloc(sizeof(zumo_interfaces__msg__Rawdata));
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(zumo_interfaces__msg__Rawdata));
  bool success = zumo_interfaces__msg__Rawdata__init(msg);
  if (!success) {
    free(msg);
    return NULL;
  }
  return msg;
}

void
zumo_interfaces__msg__Rawdata__destroy(zumo_interfaces__msg__Rawdata * msg)
{
  if (msg) {
    zumo_interfaces__msg__Rawdata__fini(msg);
  }
  free(msg);
}


bool
zumo_interfaces__msg__Rawdata__Sequence__init(zumo_interfaces__msg__Rawdata__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  zumo_interfaces__msg__Rawdata * data = NULL;
  if (size) {
    data = (zumo_interfaces__msg__Rawdata *)calloc(size, sizeof(zumo_interfaces__msg__Rawdata));
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = zumo_interfaces__msg__Rawdata__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        zumo_interfaces__msg__Rawdata__fini(&data[i - 1]);
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
zumo_interfaces__msg__Rawdata__Sequence__fini(zumo_interfaces__msg__Rawdata__Sequence * array)
{
  if (!array) {
    return;
  }
  if (array->data) {
    // ensure that data and capacity values are consistent
    assert(array->capacity > 0);
    // finalize all array elements
    for (size_t i = 0; i < array->capacity; ++i) {
      zumo_interfaces__msg__Rawdata__fini(&array->data[i]);
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

zumo_interfaces__msg__Rawdata__Sequence *
zumo_interfaces__msg__Rawdata__Sequence__create(size_t size)
{
  zumo_interfaces__msg__Rawdata__Sequence * array = (zumo_interfaces__msg__Rawdata__Sequence *)malloc(sizeof(zumo_interfaces__msg__Rawdata__Sequence));
  if (!array) {
    return NULL;
  }
  bool success = zumo_interfaces__msg__Rawdata__Sequence__init(array, size);
  if (!success) {
    free(array);
    return NULL;
  }
  return array;
}

void
zumo_interfaces__msg__Rawdata__Sequence__destroy(zumo_interfaces__msg__Rawdata__Sequence * array)
{
  if (array) {
    zumo_interfaces__msg__Rawdata__Sequence__fini(array);
  }
  free(array);
}
