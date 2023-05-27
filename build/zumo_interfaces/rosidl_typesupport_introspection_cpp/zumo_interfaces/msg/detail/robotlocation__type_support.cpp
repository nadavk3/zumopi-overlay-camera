// generated from rosidl_typesupport_introspection_cpp/resource/idl__type_support.cpp.em
// with input from zumo_interfaces:msg/Robotlocation.idl
// generated code does not contain a copyright notice

#include "array"
#include "cstddef"
#include "string"
#include "vector"
#include "rosidl_runtime_c/message_type_support_struct.h"
#include "rosidl_typesupport_cpp/message_type_support.hpp"
#include "rosidl_typesupport_interface/macros.h"
#include "zumo_interfaces/msg/detail/robotlocation__struct.hpp"
#include "rosidl_typesupport_introspection_cpp/field_types.hpp"
#include "rosidl_typesupport_introspection_cpp/identifier.hpp"
#include "rosidl_typesupport_introspection_cpp/message_introspection.hpp"
#include "rosidl_typesupport_introspection_cpp/message_type_support_decl.hpp"
#include "rosidl_typesupport_introspection_cpp/visibility_control.h"

namespace zumo_interfaces
{

namespace msg
{

namespace rosidl_typesupport_introspection_cpp
{

void Robotlocation_init_function(
  void * message_memory, rosidl_runtime_cpp::MessageInitialization _init)
{
  new (message_memory) zumo_interfaces::msg::Robotlocation(_init);
}

void Robotlocation_fini_function(void * message_memory)
{
  auto typed_message = static_cast<zumo_interfaces::msg::Robotlocation *>(message_memory);
  typed_message->~Robotlocation();
}

static const ::rosidl_typesupport_introspection_cpp::MessageMember Robotlocation_message_member_array[3] = {
  {
    "id",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_STRING,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(zumo_interfaces::msg::Robotlocation, id),  // bytes offset in struct
    nullptr,  // default value
    nullptr,  // size() function pointer
    nullptr,  // get_const(index) function pointer
    nullptr,  // get(index) function pointer
    nullptr  // resize(index) function pointer
  },
  {
    "x",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_INT32,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(zumo_interfaces::msg::Robotlocation, x),  // bytes offset in struct
    nullptr,  // default value
    nullptr,  // size() function pointer
    nullptr,  // get_const(index) function pointer
    nullptr,  // get(index) function pointer
    nullptr  // resize(index) function pointer
  },
  {
    "y",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_INT32,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(zumo_interfaces::msg::Robotlocation, y),  // bytes offset in struct
    nullptr,  // default value
    nullptr,  // size() function pointer
    nullptr,  // get_const(index) function pointer
    nullptr,  // get(index) function pointer
    nullptr  // resize(index) function pointer
  }
};

static const ::rosidl_typesupport_introspection_cpp::MessageMembers Robotlocation_message_members = {
  "zumo_interfaces::msg",  // message namespace
  "Robotlocation",  // message name
  3,  // number of fields
  sizeof(zumo_interfaces::msg::Robotlocation),
  Robotlocation_message_member_array,  // message members
  Robotlocation_init_function,  // function to initialize message memory (memory has to be allocated)
  Robotlocation_fini_function  // function to terminate message instance (will not free memory)
};

static const rosidl_message_type_support_t Robotlocation_message_type_support_handle = {
  ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
  &Robotlocation_message_members,
  get_message_typesupport_handle_function,
};

}  // namespace rosidl_typesupport_introspection_cpp

}  // namespace msg

}  // namespace zumo_interfaces


namespace rosidl_typesupport_introspection_cpp
{

template<>
ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_message_type_support_t *
get_message_type_support_handle<zumo_interfaces::msg::Robotlocation>()
{
  return &::zumo_interfaces::msg::rosidl_typesupport_introspection_cpp::Robotlocation_message_type_support_handle;
}

}  // namespace rosidl_typesupport_introspection_cpp

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, zumo_interfaces, msg, Robotlocation)() {
  return &::zumo_interfaces::msg::rosidl_typesupport_introspection_cpp::Robotlocation_message_type_support_handle;
}

#ifdef __cplusplus
}
#endif
