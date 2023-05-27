// generated from rosidl_typesupport_introspection_c/resource/idl__type_support.c.em
// with input from zumo_interfaces:msg/Robotlocation.idl
// generated code does not contain a copyright notice

#include <stddef.h>
#include "zumo_interfaces/msg/detail/robotlocation__rosidl_typesupport_introspection_c.h"
#include "zumo_interfaces/msg/rosidl_typesupport_introspection_c__visibility_control.h"
#include "rosidl_typesupport_introspection_c/field_types.h"
#include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/message_introspection.h"
#include "zumo_interfaces/msg/detail/robotlocation__functions.h"
#include "zumo_interfaces/msg/detail/robotlocation__struct.h"


// Include directives for member types
// Member `id`
#include "rosidl_runtime_c/string_functions.h"

#ifdef __cplusplus
extern "C"
{
#endif

void Robotlocation__rosidl_typesupport_introspection_c__Robotlocation_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  zumo_interfaces__msg__Robotlocation__init(message_memory);
}

void Robotlocation__rosidl_typesupport_introspection_c__Robotlocation_fini_function(void * message_memory)
{
  zumo_interfaces__msg__Robotlocation__fini(message_memory);
}

static rosidl_typesupport_introspection_c__MessageMember Robotlocation__rosidl_typesupport_introspection_c__Robotlocation_message_member_array[3] = {
  {
    "id",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_STRING,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(zumo_interfaces__msg__Robotlocation, id),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "x",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_INT32,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(zumo_interfaces__msg__Robotlocation, x),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "y",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_INT32,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(zumo_interfaces__msg__Robotlocation, y),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers Robotlocation__rosidl_typesupport_introspection_c__Robotlocation_message_members = {
  "zumo_interfaces__msg",  // message namespace
  "Robotlocation",  // message name
  3,  // number of fields
  sizeof(zumo_interfaces__msg__Robotlocation),
  Robotlocation__rosidl_typesupport_introspection_c__Robotlocation_message_member_array,  // message members
  Robotlocation__rosidl_typesupport_introspection_c__Robotlocation_init_function,  // function to initialize message memory (memory has to be allocated)
  Robotlocation__rosidl_typesupport_introspection_c__Robotlocation_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t Robotlocation__rosidl_typesupport_introspection_c__Robotlocation_message_type_support_handle = {
  0,
  &Robotlocation__rosidl_typesupport_introspection_c__Robotlocation_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_zumo_interfaces
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, zumo_interfaces, msg, Robotlocation)() {
  if (!Robotlocation__rosidl_typesupport_introspection_c__Robotlocation_message_type_support_handle.typesupport_identifier) {
    Robotlocation__rosidl_typesupport_introspection_c__Robotlocation_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &Robotlocation__rosidl_typesupport_introspection_c__Robotlocation_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif
