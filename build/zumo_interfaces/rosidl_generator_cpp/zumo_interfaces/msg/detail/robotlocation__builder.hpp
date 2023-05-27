// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from zumo_interfaces:msg/Robotlocation.idl
// generated code does not contain a copyright notice

#ifndef ZUMO_INTERFACES__MSG__DETAIL__ROBOTLOCATION__BUILDER_HPP_
#define ZUMO_INTERFACES__MSG__DETAIL__ROBOTLOCATION__BUILDER_HPP_

#include "zumo_interfaces/msg/detail/robotlocation__struct.hpp"
#include <rosidl_runtime_cpp/message_initialization.hpp>
#include <algorithm>
#include <utility>


namespace zumo_interfaces
{

namespace msg
{

namespace builder
{

class Init_Robotlocation_y
{
public:
  explicit Init_Robotlocation_y(::zumo_interfaces::msg::Robotlocation & msg)
  : msg_(msg)
  {}
  ::zumo_interfaces::msg::Robotlocation y(::zumo_interfaces::msg::Robotlocation::_y_type arg)
  {
    msg_.y = std::move(arg);
    return std::move(msg_);
  }

private:
  ::zumo_interfaces::msg::Robotlocation msg_;
};

class Init_Robotlocation_x
{
public:
  explicit Init_Robotlocation_x(::zumo_interfaces::msg::Robotlocation & msg)
  : msg_(msg)
  {}
  Init_Robotlocation_y x(::zumo_interfaces::msg::Robotlocation::_x_type arg)
  {
    msg_.x = std::move(arg);
    return Init_Robotlocation_y(msg_);
  }

private:
  ::zumo_interfaces::msg::Robotlocation msg_;
};

class Init_Robotlocation_id
{
public:
  Init_Robotlocation_id()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_Robotlocation_x id(::zumo_interfaces::msg::Robotlocation::_id_type arg)
  {
    msg_.id = std::move(arg);
    return Init_Robotlocation_x(msg_);
  }

private:
  ::zumo_interfaces::msg::Robotlocation msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::zumo_interfaces::msg::Robotlocation>()
{
  return zumo_interfaces::msg::builder::Init_Robotlocation_id();
}

}  // namespace zumo_interfaces

#endif  // ZUMO_INTERFACES__MSG__DETAIL__ROBOTLOCATION__BUILDER_HPP_
