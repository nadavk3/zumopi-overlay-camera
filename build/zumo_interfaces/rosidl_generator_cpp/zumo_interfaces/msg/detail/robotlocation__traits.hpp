// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from zumo_interfaces:msg/Robotlocation.idl
// generated code does not contain a copyright notice

#ifndef ZUMO_INTERFACES__MSG__DETAIL__ROBOTLOCATION__TRAITS_HPP_
#define ZUMO_INTERFACES__MSG__DETAIL__ROBOTLOCATION__TRAITS_HPP_

#include "zumo_interfaces/msg/detail/robotlocation__struct.hpp"
#include <rosidl_runtime_cpp/traits.hpp>
#include <stdint.h>
#include <type_traits>

namespace rosidl_generator_traits
{

template<>
inline const char * data_type<zumo_interfaces::msg::Robotlocation>()
{
  return "zumo_interfaces::msg::Robotlocation";
}

template<>
inline const char * name<zumo_interfaces::msg::Robotlocation>()
{
  return "zumo_interfaces/msg/Robotlocation";
}

template<>
struct has_fixed_size<zumo_interfaces::msg::Robotlocation>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<zumo_interfaces::msg::Robotlocation>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<zumo_interfaces::msg::Robotlocation>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // ZUMO_INTERFACES__MSG__DETAIL__ROBOTLOCATION__TRAITS_HPP_
