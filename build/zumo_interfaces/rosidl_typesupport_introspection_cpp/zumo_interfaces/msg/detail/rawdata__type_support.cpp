// generated from rosidl_typesupport_introspection_cpp/resource/idl__type_support.cpp.em
// with input from zumo_interfaces:msg/Rawdata.idl
// generated code does not contain a copyright notice

#include "array"
#include "cstddef"
#include "string"
#include "vector"
#include "rosidl_runtime_c/message_type_support_struct.h"
#include "rosidl_typesupport_cpp/message_type_support.hpp"
#include "rosidl_typesupport_interface/macros.h"
#include "zumo_interfaces/msg/detail/rawdata__struct.hpp"
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

void Rawdata_init_function(
  void * message_memory, rosidl_runtime_cpp::MessageInitialization _init)
{
  new (message_memory) zumo_interfaces::msg::Rawdata(_init);
}

void Rawdata_fini_function(void * message_memory)
{
  auto typed_message = static_cast<zumo_interfaces::msg::Rawdata *>(message_memory);
  typed_message->~Rawdata();
}

size_t size_function__Rawdata__cnt(const void * untyped_member)
{
  const auto * member = reinterpret_cast<const std::vector<geometry_msgs::msg::Polygon> *>(untyped_member);
  return member->size();
}

const void * get_const_function__Rawdata__cnt(const void * untyped_member, size_t index)
{
  const auto & member =
    *reinterpret_cast<const std::vector<geometry_msgs::msg::Polygon> *>(untyped_member);
  return &member[index];
}

void * get_function__Rawdata__cnt(void * untyped_member, size_t index)
{
  auto & member =
    *reinterpret_cast<std::vector<geometry_msgs::msg::Polygon> *>(untyped_member);
  return &member[index];
}

void resize_function__Rawdata__cnt(void * untyped_member, size_t size)
{
  auto * member =
    reinterpret_cast<std::vector<geometry_msgs::msg::Polygon> *>(untyped_member);
  member->resize(size);
}

size_t size_function__Rawdata__red_list(const void * untyped_member)
{
  const auto * member = reinterpret_cast<const std::vector<geometry_msgs::msg::Point32> *>(untyped_member);
  return member->size();
}

const void * get_const_function__Rawdata__red_list(const void * untyped_member, size_t index)
{
  const auto & member =
    *reinterpret_cast<const std::vector<geometry_msgs::msg::Point32> *>(untyped_member);
  return &member[index];
}

void * get_function__Rawdata__red_list(void * untyped_member, size_t index)
{
  auto & member =
    *reinterpret_cast<std::vector<geometry_msgs::msg::Point32> *>(untyped_member);
  return &member[index];
}

void resize_function__Rawdata__red_list(void * untyped_member, size_t size)
{
  auto * member =
    reinterpret_cast<std::vector<geometry_msgs::msg::Point32> *>(untyped_member);
  member->resize(size);
}

size_t size_function__Rawdata__blue_list(const void * untyped_member)
{
  const auto * member = reinterpret_cast<const std::vector<geometry_msgs::msg::Point32> *>(untyped_member);
  return member->size();
}

const void * get_const_function__Rawdata__blue_list(const void * untyped_member, size_t index)
{
  const auto & member =
    *reinterpret_cast<const std::vector<geometry_msgs::msg::Point32> *>(untyped_member);
  return &member[index];
}

void * get_function__Rawdata__blue_list(void * untyped_member, size_t index)
{
  auto & member =
    *reinterpret_cast<std::vector<geometry_msgs::msg::Point32> *>(untyped_member);
  return &member[index];
}

void resize_function__Rawdata__blue_list(void * untyped_member, size_t size)
{
  auto * member =
    reinterpret_cast<std::vector<geometry_msgs::msg::Point32> *>(untyped_member);
  member->resize(size);
}

size_t size_function__Rawdata__green_list(const void * untyped_member)
{
  const auto * member = reinterpret_cast<const std::vector<geometry_msgs::msg::Point32> *>(untyped_member);
  return member->size();
}

const void * get_const_function__Rawdata__green_list(const void * untyped_member, size_t index)
{
  const auto & member =
    *reinterpret_cast<const std::vector<geometry_msgs::msg::Point32> *>(untyped_member);
  return &member[index];
}

void * get_function__Rawdata__green_list(void * untyped_member, size_t index)
{
  auto & member =
    *reinterpret_cast<std::vector<geometry_msgs::msg::Point32> *>(untyped_member);
  return &member[index];
}

void resize_function__Rawdata__green_list(void * untyped_member, size_t size)
{
  auto * member =
    reinterpret_cast<std::vector<geometry_msgs::msg::Point32> *>(untyped_member);
  member->resize(size);
}

size_t size_function__Rawdata__yellow_list(const void * untyped_member)
{
  const auto * member = reinterpret_cast<const std::vector<geometry_msgs::msg::Point32> *>(untyped_member);
  return member->size();
}

const void * get_const_function__Rawdata__yellow_list(const void * untyped_member, size_t index)
{
  const auto & member =
    *reinterpret_cast<const std::vector<geometry_msgs::msg::Point32> *>(untyped_member);
  return &member[index];
}

void * get_function__Rawdata__yellow_list(void * untyped_member, size_t index)
{
  auto & member =
    *reinterpret_cast<std::vector<geometry_msgs::msg::Point32> *>(untyped_member);
  return &member[index];
}

void resize_function__Rawdata__yellow_list(void * untyped_member, size_t size)
{
  auto * member =
    reinterpret_cast<std::vector<geometry_msgs::msg::Point32> *>(untyped_member);
  member->resize(size);
}

static const ::rosidl_typesupport_introspection_cpp::MessageMember Rawdata_message_member_array[5] = {
  {
    "cnt",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    ::rosidl_typesupport_introspection_cpp::get_message_type_support_handle<geometry_msgs::msg::Polygon>(),  // members of sub message
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(zumo_interfaces::msg::Rawdata, cnt),  // bytes offset in struct
    nullptr,  // default value
    size_function__Rawdata__cnt,  // size() function pointer
    get_const_function__Rawdata__cnt,  // get_const(index) function pointer
    get_function__Rawdata__cnt,  // get(index) function pointer
    resize_function__Rawdata__cnt  // resize(index) function pointer
  },
  {
    "red_list",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    ::rosidl_typesupport_introspection_cpp::get_message_type_support_handle<geometry_msgs::msg::Point32>(),  // members of sub message
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(zumo_interfaces::msg::Rawdata, red_list),  // bytes offset in struct
    nullptr,  // default value
    size_function__Rawdata__red_list,  // size() function pointer
    get_const_function__Rawdata__red_list,  // get_const(index) function pointer
    get_function__Rawdata__red_list,  // get(index) function pointer
    resize_function__Rawdata__red_list  // resize(index) function pointer
  },
  {
    "blue_list",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    ::rosidl_typesupport_introspection_cpp::get_message_type_support_handle<geometry_msgs::msg::Point32>(),  // members of sub message
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(zumo_interfaces::msg::Rawdata, blue_list),  // bytes offset in struct
    nullptr,  // default value
    size_function__Rawdata__blue_list,  // size() function pointer
    get_const_function__Rawdata__blue_list,  // get_const(index) function pointer
    get_function__Rawdata__blue_list,  // get(index) function pointer
    resize_function__Rawdata__blue_list  // resize(index) function pointer
  },
  {
    "green_list",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    ::rosidl_typesupport_introspection_cpp::get_message_type_support_handle<geometry_msgs::msg::Point32>(),  // members of sub message
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(zumo_interfaces::msg::Rawdata, green_list),  // bytes offset in struct
    nullptr,  // default value
    size_function__Rawdata__green_list,  // size() function pointer
    get_const_function__Rawdata__green_list,  // get_const(index) function pointer
    get_function__Rawdata__green_list,  // get(index) function pointer
    resize_function__Rawdata__green_list  // resize(index) function pointer
  },
  {
    "yellow_list",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    ::rosidl_typesupport_introspection_cpp::get_message_type_support_handle<geometry_msgs::msg::Point32>(),  // members of sub message
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(zumo_interfaces::msg::Rawdata, yellow_list),  // bytes offset in struct
    nullptr,  // default value
    size_function__Rawdata__yellow_list,  // size() function pointer
    get_const_function__Rawdata__yellow_list,  // get_const(index) function pointer
    get_function__Rawdata__yellow_list,  // get(index) function pointer
    resize_function__Rawdata__yellow_list  // resize(index) function pointer
  }
};

static const ::rosidl_typesupport_introspection_cpp::MessageMembers Rawdata_message_members = {
  "zumo_interfaces::msg",  // message namespace
  "Rawdata",  // message name
  5,  // number of fields
  sizeof(zumo_interfaces::msg::Rawdata),
  Rawdata_message_member_array,  // message members
  Rawdata_init_function,  // function to initialize message memory (memory has to be allocated)
  Rawdata_fini_function  // function to terminate message instance (will not free memory)
};

static const rosidl_message_type_support_t Rawdata_message_type_support_handle = {
  ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
  &Rawdata_message_members,
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
get_message_type_support_handle<zumo_interfaces::msg::Rawdata>()
{
  return &::zumo_interfaces::msg::rosidl_typesupport_introspection_cpp::Rawdata_message_type_support_handle;
}

}  // namespace rosidl_typesupport_introspection_cpp

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, zumo_interfaces, msg, Rawdata)() {
  return &::zumo_interfaces::msg::rosidl_typesupport_introspection_cpp::Rawdata_message_type_support_handle;
}

#ifdef __cplusplus
}
#endif
