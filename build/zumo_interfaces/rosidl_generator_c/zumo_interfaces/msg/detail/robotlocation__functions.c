// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from zumo_interfaces:msg/Robotlocation.idl
// generated code does not contain a copyright notice
#include "zumo_interfaces/msg/detail/robotlocation__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>


// Include directives for member types
// Member `id`
#include "rosidl_runtime_c/string_functions.h"

bool
zumo_interfaces__msg__Robotlocation__init(zumo_interfaces__msg__Robotlocation * msg)
{
  if (!msg) {
    return false;
  }
  // id
  if (!rosidl_runtime_c__String__init(&msg->id)) {
    zumo_interfaces__msg__Robotlocation__fini(msg);
    return false;
  }
  // x
  // y
  return true;
}

void
zumo_interfaces__msg__Robotlocation__fini(zumo_interfaces__msg__Robotlocation * msg)
{
  if (!msg) {
    return;
  }
  // id
  rosidl_runtime_c__String__fini(&msg->id);
  // x
  // y
}

zumo_interfaces__msg__Robotlocation *
zumo_interfaces__msg__Robotlocation__create()
{
  zumo_interfaces__msg__Robotlocation * msg = (zumo_interfaces__msg__Robotlocation *)malloc(sizeof(zumo_interfaces__msg__Robotlocation));
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(zumo_interfaces__msg__Robotlocation));
  bool success = zumo_interfaces__msg__Robotlocation__init(msg);
  if (!success) {
    free(msg);
    return NULL;
  }
  return msg;
}

void
zumo_interfaces__msg__Robotlocation__destroy(zumo_interfaces__msg__Robotlocation * msg)
{
  if (msg) {
    zumo_interfaces__msg__Robotlocation__fini(msg);
  }
  free(msg);
}


bool
zumo_interfaces__msg__Robotlocation__Sequence__init(zumo_interfaces__msg__Robotlocation__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  zumo_interfaces__msg__Robotlocation * data = NULL;
  if (size) {
    data = (zumo_interfaces__msg__Robotlocation *)calloc(size, sizeof(zumo_interfaces__msg__Robotlocation));
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = zumo_interfaces__msg__Robotlocation__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        zumo_interfaces__msg__Robotlocation__fini(&data[i - 1]);
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
zumo_interfaces__msg__Robotlocation__Sequence__fini(zumo_interfaces__msg__Robotlocation__Sequence * array)
{
  if (!array) {
    return;
  }
  if (array->data) {
    // ensure that data and capacity values are consistent
    assert(array->capacity > 0);
    // finalize all array elements
    for (size_t i = 0; i < array->capacity; ++i) {
      zumo_interfaces__msg__Robotlocation__fini(&array->data[i]);
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

zumo_interfaces__msg__Robotlocation__Sequence *
zumo_interfaces__msg__Robotlocation__Sequence__create(size_t size)
{
  zumo_interfaces__msg__Robotlocation__Sequence * array = (zumo_interfaces__msg__Robotlocation__Sequence *)malloc(sizeof(zumo_interfaces__msg__Robotlocation__Sequence));
  if (!array) {
    return NULL;
  }
  bool success = zumo_interfaces__msg__Robotlocation__Sequence__init(array, size);
  if (!success) {
    free(array);
    return NULL;
  }
  return array;
}

void
zumo_interfaces__msg__Robotlocation__Sequence__destroy(zumo_interfaces__msg__Robotlocation__Sequence * array)
{
  if (array) {
    zumo_interfaces__msg__Robotlocation__Sequence__fini(array);
  }
  free(array);
}
