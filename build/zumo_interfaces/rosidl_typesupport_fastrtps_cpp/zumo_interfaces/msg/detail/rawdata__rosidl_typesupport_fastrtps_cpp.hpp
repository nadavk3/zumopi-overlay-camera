// generated from rosidl_typesupport_fastrtps_cpp/resource/idl__rosidl_typesupport_fastrtps_cpp.hpp.em
// with input from zumo_interfaces:msg/Rawdata.idl
// generated code does not contain a copyright notice

#ifndef ZUMO_INTERFACES__MSG__DETAIL__RAWDATA__ROSIDL_TYPESUPPORT_FASTRTPS_CPP_HPP_
#define ZUMO_INTERFACES__MSG__DETAIL__RAWDATA__ROSIDL_TYPESUPPORT_FASTRTPS_CPP_HPP_

#include "rosidl_runtime_c/message_type_support_struct.h"
#include "rosidl_typesupport_interface/macros.h"
#include "zumo_interfaces/msg/rosidl_typesupport_fastrtps_cpp__visibility_control.h"
#include "zumo_interfaces/msg/detail/rawdata__struct.hpp"

#ifndef _WIN32
# pragma GCC diagnostic push
# pragma GCC diagnostic ignored "-Wunused-parameter"
# ifdef __clang__
#  pragma clang diagnostic ignored "-Wdeprecated-register"
#  pragma clang diagnostic ignored "-Wreturn-type-c-linkage"
# endif
#endif
#ifndef _WIN32
# pragma GCC diagnostic pop
#endif

#include "fastcdr/Cdr.h"

namespace zumo_interfaces
{

namespace msg
{

namespace typesupport_fastrtps_cpp
{

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_zumo_interfaces
cdr_serialize(
  const zumo_interfaces::msg::Rawdata & ros_message,
  eprosima::fastcdr::Cdr & cdr);

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_zumo_interfaces
cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  zumo_interfaces::msg::Rawdata & ros_message);

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_zumo_interfaces
get_serialized_size(
  const zumo_interfaces::msg::Rawdata & ros_message,
  size_t current_alignment);

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_zumo_interfaces
max_serialized_size_Rawdata(
  bool & full_bounded,
  size_t current_alignment);

}  // namespace typesupport_fastrtps_cpp

}  // namespace msg

}  // namespace zumo_interfaces

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_zumo_interfaces
const rosidl_message_type_support_t *
  ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, zumo_interfaces, msg, Rawdata)();

#ifdef __cplusplus
}
#endif

#endif  // ZUMO_INTERFACES__MSG__DETAIL__RAWDATA__ROSIDL_TYPESUPPORT_FASTRTPS_CPP_HPP_
