// generated from rosidl_typesupport_introspection_c/resource/idl__type_support.c.em
// with input from zumo_interfaces:msg/Rawdata.idl
// generated code does not contain a copyright notice

#include <stddef.h>
#include "zumo_interfaces/msg/detail/rawdata__rosidl_typesupport_introspection_c.h"
#include "zumo_interfaces/msg/rosidl_typesupport_introspection_c__visibility_control.h"
#include "rosidl_typesupport_introspection_c/field_types.h"
#include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/message_introspection.h"
#include "zumo_interfaces/msg/detail/rawdata__functions.h"
#include "zumo_interfaces/msg/detail/rawdata__struct.h"


// Include directives for member types
// Member `cnt`
// Member `red_list`
// Member `blue_list`
// Member `yellow_list`
#include "geometry_msgs/msg/polygon.h"
// Member `cnt`
// Member `red_list`
// Member `blue_list`
// Member `yellow_list`
#include "geometry_msgs/msg/detail/polygon__rosidl_typesupport_introspection_c.h"

#ifdef __cplusplus
extern "C"
{
#endif

void Rawdata__rosidl_typesupport_introspection_c__Rawdata_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  zumo_interfaces__msg__Rawdata__init(message_memory);
}

void Rawdata__rosidl_typesupport_introspection_c__Rawdata_fini_function(void * message_memory)
{
  zumo_interfaces__msg__Rawdata__fini(message_memory);
}

size_t Rawdata__rosidl_typesupport_introspection_c__size_function__Polygon__cnt(
  const void * untyped_member)
{
  const geometry_msgs__msg__Polygon__Sequence * member =
    (const geometry_msgs__msg__Polygon__Sequence *)(untyped_member);
  return member->size;
}

const void * Rawdata__rosidl_typesupport_introspection_c__get_const_function__Polygon__cnt(
  const void * untyped_member, size_t index)
{
  const geometry_msgs__msg__Polygon__Sequence * member =
    (const geometry_msgs__msg__Polygon__Sequence *)(untyped_member);
  return &member->data[index];
}

void * Rawdata__rosidl_typesupport_introspection_c__get_function__Polygon__cnt(
  void * untyped_member, size_t index)
{
  geometry_msgs__msg__Polygon__Sequence * member =
    (geometry_msgs__msg__Polygon__Sequence *)(untyped_member);
  return &member->data[index];
}

bool Rawdata__rosidl_typesupport_introspection_c__resize_function__Polygon__cnt(
  void * untyped_member, size_t size)
{
  geometry_msgs__msg__Polygon__Sequence * member =
    (geometry_msgs__msg__Polygon__Sequence *)(untyped_member);
  geometry_msgs__msg__Polygon__Sequence__fini(member);
  return geometry_msgs__msg__Polygon__Sequence__init(member, size);
}

size_t Rawdata__rosidl_typesupport_introspection_c__size_function__Polygon__red_list(
  const void * untyped_member)
{
  const geometry_msgs__msg__Polygon__Sequence * member =
    (const geometry_msgs__msg__Polygon__Sequence *)(untyped_member);
  return member->size;
}

const void * Rawdata__rosidl_typesupport_introspection_c__get_const_function__Polygon__red_list(
  const void * untyped_member, size_t index)
{
  const geometry_msgs__msg__Polygon__Sequence * member =
    (const geometry_msgs__msg__Polygon__Sequence *)(untyped_member);
  return &member->data[index];
}

void * Rawdata__rosidl_typesupport_introspection_c__get_function__Polygon__red_list(
  void * untyped_member, size_t index)
{
  geometry_msgs__msg__Polygon__Sequence * member =
    (geometry_msgs__msg__Polygon__Sequence *)(untyped_member);
  return &member->data[index];
}

bool Rawdata__rosidl_typesupport_introspection_c__resize_function__Polygon__red_list(
  void * untyped_member, size_t size)
{
  geometry_msgs__msg__Polygon__Sequence * member =
    (geometry_msgs__msg__Polygon__Sequence *)(untyped_member);
  geometry_msgs__msg__Polygon__Sequence__fini(member);
  return geometry_msgs__msg__Polygon__Sequence__init(member, size);
}

size_t Rawdata__rosidl_typesupport_introspection_c__size_function__Polygon__blue_list(
  const void * untyped_member)
{
  const geometry_msgs__msg__Polygon__Sequence * member =
    (const geometry_msgs__msg__Polygon__Sequence *)(untyped_member);
  return member->size;
}

const void * Rawdata__rosidl_typesupport_introspection_c__get_const_function__Polygon__blue_list(
  const void * untyped_member, size_t index)
{
  const geometry_msgs__msg__Polygon__Sequence * member =
    (const geometry_msgs__msg__Polygon__Sequence *)(untyped_member);
  return &member->data[index];
}

void * Rawdata__rosidl_typesupport_introspection_c__get_function__Polygon__blue_list(
  void * untyped_member, size_t index)
{
  geometry_msgs__msg__Polygon__Sequence * member =
    (geometry_msgs__msg__Polygon__Sequence *)(untyped_member);
  return &member->data[index];
}

bool Rawdata__rosidl_typesupport_introspection_c__resize_function__Polygon__blue_list(
  void * untyped_member, size_t size)
{
  geometry_msgs__msg__Polygon__Sequence * member =
    (geometry_msgs__msg__Polygon__Sequence *)(untyped_member);
  geometry_msgs__msg__Polygon__Sequence__fini(member);
  return geometry_msgs__msg__Polygon__Sequence__init(member, size);
}

size_t Rawdata__rosidl_typesupport_introspection_c__size_function__Polygon__yellow_list(
  const void * untyped_member)
{
  const geometry_msgs__msg__Polygon__Sequence * member =
    (const geometry_msgs__msg__Polygon__Sequence *)(untyped_member);
  return member->size;
}

const void * Rawdata__rosidl_typesupport_introspection_c__get_const_function__Polygon__yellow_list(
  const void * untyped_member, size_t index)
{
  const geometry_msgs__msg__Polygon__Sequence * member =
    (const geometry_msgs__msg__Polygon__Sequence *)(untyped_member);
  return &member->data[index];
}

void * Rawdata__rosidl_typesupport_introspection_c__get_function__Polygon__yellow_list(
  void * untyped_member, size_t index)
{
  geometry_msgs__msg__Polygon__Sequence * member =
    (geometry_msgs__msg__Polygon__Sequence *)(untyped_member);
  return &member->data[index];
}

bool Rawdata__rosidl_typesupport_introspection_c__resize_function__Polygon__yellow_list(
  void * untyped_member, size_t size)
{
  geometry_msgs__msg__Polygon__Sequence * member =
    (geometry_msgs__msg__Polygon__Sequence *)(untyped_member);
  geometry_msgs__msg__Polygon__Sequence__fini(member);
  return geometry_msgs__msg__Polygon__Sequence__init(member, size);
}

static rosidl_typesupport_introspection_c__MessageMember Rawdata__rosidl_typesupport_introspection_c__Rawdata_message_member_array[4] = {
  {
    "cnt",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(zumo_interfaces__msg__Rawdata, cnt),  // bytes offset in struct
    NULL,  // default value
    Rawdata__rosidl_typesupport_introspection_c__size_function__Polygon__cnt,  // size() function pointer
    Rawdata__rosidl_typesupport_introspection_c__get_const_function__Polygon__cnt,  // get_const(index) function pointer
    Rawdata__rosidl_typesupport_introspection_c__get_function__Polygon__cnt,  // get(index) function pointer
    Rawdata__rosidl_typesupport_introspection_c__resize_function__Polygon__cnt  // resize(index) function pointer
  },
  {
    "red_list",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(zumo_interfaces__msg__Rawdata, red_list),  // bytes offset in struct
    NULL,  // default value
    Rawdata__rosidl_typesupport_introspection_c__size_function__Polygon__red_list,  // size() function pointer
    Rawdata__rosidl_typesupport_introspection_c__get_const_function__Polygon__red_list,  // get_const(index) function pointer
    Rawdata__rosidl_typesupport_introspection_c__get_function__Polygon__red_list,  // get(index) function pointer
    Rawdata__rosidl_typesupport_introspection_c__resize_function__Polygon__red_list  // resize(index) function pointer
  },
  {
    "blue_list",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(zumo_interfaces__msg__Rawdata, blue_list),  // bytes offset in struct
    NULL,  // default value
    Rawdata__rosidl_typesupport_introspection_c__size_function__Polygon__blue_list,  // size() function pointer
    Rawdata__rosidl_typesupport_introspection_c__get_const_function__Polygon__blue_list,  // get_const(index) function pointer
    Rawdata__rosidl_typesupport_introspection_c__get_function__Polygon__blue_list,  // get(index) function pointer
    Rawdata__rosidl_typesupport_introspection_c__resize_function__Polygon__blue_list  // resize(index) function pointer
  },
  {
    "yellow_list",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(zumo_interfaces__msg__Rawdata, yellow_list),  // bytes offset in struct
    NULL,  // default value
    Rawdata__rosidl_typesupport_introspection_c__size_function__Polygon__yellow_list,  // size() function pointer
    Rawdata__rosidl_typesupport_introspection_c__get_const_function__Polygon__yellow_list,  // get_const(index) function pointer
    Rawdata__rosidl_typesupport_introspection_c__get_function__Polygon__yellow_list,  // get(index) function pointer
    Rawdata__rosidl_typesupport_introspection_c__resize_function__Polygon__yellow_list  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers Rawdata__rosidl_typesupport_introspection_c__Rawdata_message_members = {
  "zumo_interfaces__msg",  // message namespace
  "Rawdata",  // message name
  4,  // number of fields
  sizeof(zumo_interfaces__msg__Rawdata),
  Rawdata__rosidl_typesupport_introspection_c__Rawdata_message_member_array,  // message members
  Rawdata__rosidl_typesupport_introspection_c__Rawdata_init_function,  // function to initialize message memory (memory has to be allocated)
  Rawdata__rosidl_typesupport_introspection_c__Rawdata_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t Rawdata__rosidl_typesupport_introspection_c__Rawdata_message_type_support_handle = {
  0,
  &Rawdata__rosidl_typesupport_introspection_c__Rawdata_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_zumo_interfaces
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, zumo_interfaces, msg, Rawdata)() {
  Rawdata__rosidl_typesupport_introspection_c__Rawdata_message_member_array[0].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, geometry_msgs, msg, Polygon)();
  Rawdata__rosidl_typesupport_introspection_c__Rawdata_message_member_array[1].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, geometry_msgs, msg, Polygon)();
  Rawdata__rosidl_typesupport_introspection_c__Rawdata_message_member_array[2].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, geometry_msgs, msg, Polygon)();
  Rawdata__rosidl_typesupport_introspection_c__Rawdata_message_member_array[3].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, geometry_msgs, msg, Polygon)();
  if (!Rawdata__rosidl_typesupport_introspection_c__Rawdata_message_type_support_handle.typesupport_identifier) {
    Rawdata__rosidl_typesupport_introspection_c__Rawdata_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &Rawdata__rosidl_typesupport_introspection_c__Rawdata_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif
