// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from zumo_interfaces:msg/Rawdata.idl
// generated code does not contain a copyright notice

#ifndef ZUMO_INTERFACES__MSG__DETAIL__RAWDATA__BUILDER_HPP_
#define ZUMO_INTERFACES__MSG__DETAIL__RAWDATA__BUILDER_HPP_

#include "zumo_interfaces/msg/detail/rawdata__struct.hpp"
#include <rosidl_runtime_cpp/message_initialization.hpp>
#include <algorithm>
#include <utility>


namespace zumo_interfaces
{

namespace msg
{

namespace builder
{

class Init_Rawdata_yellow_list
{
public:
  explicit Init_Rawdata_yellow_list(::zumo_interfaces::msg::Rawdata & msg)
  : msg_(msg)
  {}
  ::zumo_interfaces::msg::Rawdata yellow_list(::zumo_interfaces::msg::Rawdata::_yellow_list_type arg)
  {
    msg_.yellow_list = std::move(arg);
    return std::move(msg_);
  }

private:
  ::zumo_interfaces::msg::Rawdata msg_;
};

class Init_Rawdata_green_list
{
public:
  explicit Init_Rawdata_green_list(::zumo_interfaces::msg::Rawdata & msg)
  : msg_(msg)
  {}
  Init_Rawdata_yellow_list green_list(::zumo_interfaces::msg::Rawdata::_green_list_type arg)
  {
    msg_.green_list = std::move(arg);
    return Init_Rawdata_yellow_list(msg_);
  }

private:
  ::zumo_interfaces::msg::Rawdata msg_;
};

class Init_Rawdata_blue_list
{
public:
  explicit Init_Rawdata_blue_list(::zumo_interfaces::msg::Rawdata & msg)
  : msg_(msg)
  {}
  Init_Rawdata_green_list blue_list(::zumo_interfaces::msg::Rawdata::_blue_list_type arg)
  {
    msg_.blue_list = std::move(arg);
    return Init_Rawdata_green_list(msg_);
  }

private:
  ::zumo_interfaces::msg::Rawdata msg_;
};

class Init_Rawdata_red_list
{
public:
  explicit Init_Rawdata_red_list(::zumo_interfaces::msg::Rawdata & msg)
  : msg_(msg)
  {}
  Init_Rawdata_blue_list red_list(::zumo_interfaces::msg::Rawdata::_red_list_type arg)
  {
    msg_.red_list = std::move(arg);
    return Init_Rawdata_blue_list(msg_);
  }

private:
  ::zumo_interfaces::msg::Rawdata msg_;
};

class Init_Rawdata_cnt
{
public:
  Init_Rawdata_cnt()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_Rawdata_red_list cnt(::zumo_interfaces::msg::Rawdata::_cnt_type arg)
  {
    msg_.cnt = std::move(arg);
    return Init_Rawdata_red_list(msg_);
  }

private:
  ::zumo_interfaces::msg::Rawdata msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::zumo_interfaces::msg::Rawdata>()
{
  return zumo_interfaces::msg::builder::Init_Rawdata_cnt();
}

}  // namespace zumo_interfaces

#endif  // ZUMO_INTERFACES__MSG__DETAIL__RAWDATA__BUILDER_HPP_
