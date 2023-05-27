// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from zumo_interfaces:msg/Rawdata.idl
// generated code does not contain a copyright notice

#ifndef ZUMO_INTERFACES__MSG__DETAIL__RAWDATA__STRUCT_HPP_
#define ZUMO_INTERFACES__MSG__DETAIL__RAWDATA__STRUCT_HPP_

#include <rosidl_runtime_cpp/bounded_vector.hpp>
#include <rosidl_runtime_cpp/message_initialization.hpp>
#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>


// Include directives for member types
// Member 'cnt'
#include "geometry_msgs/msg/detail/polygon__struct.hpp"
// Member 'red_list'
// Member 'blue_list'
// Member 'green_list'
// Member 'yellow_list'
#include "geometry_msgs/msg/detail/point32__struct.hpp"

#ifndef _WIN32
# define DEPRECATED__zumo_interfaces__msg__Rawdata __attribute__((deprecated))
#else
# define DEPRECATED__zumo_interfaces__msg__Rawdata __declspec(deprecated)
#endif

namespace zumo_interfaces
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct Rawdata_
{
  using Type = Rawdata_<ContainerAllocator>;

  explicit Rawdata_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_init;
  }

  explicit Rawdata_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_init;
    (void)_alloc;
  }

  // field types and members
  using _cnt_type =
    std::vector<geometry_msgs::msg::Polygon_<ContainerAllocator>, typename ContainerAllocator::template rebind<geometry_msgs::msg::Polygon_<ContainerAllocator>>::other>;
  _cnt_type cnt;
  using _red_list_type =
    std::vector<geometry_msgs::msg::Point32_<ContainerAllocator>, typename ContainerAllocator::template rebind<geometry_msgs::msg::Point32_<ContainerAllocator>>::other>;
  _red_list_type red_list;
  using _blue_list_type =
    std::vector<geometry_msgs::msg::Point32_<ContainerAllocator>, typename ContainerAllocator::template rebind<geometry_msgs::msg::Point32_<ContainerAllocator>>::other>;
  _blue_list_type blue_list;
  using _green_list_type =
    std::vector<geometry_msgs::msg::Point32_<ContainerAllocator>, typename ContainerAllocator::template rebind<geometry_msgs::msg::Point32_<ContainerAllocator>>::other>;
  _green_list_type green_list;
  using _yellow_list_type =
    std::vector<geometry_msgs::msg::Point32_<ContainerAllocator>, typename ContainerAllocator::template rebind<geometry_msgs::msg::Point32_<ContainerAllocator>>::other>;
  _yellow_list_type yellow_list;

  // setters for named parameter idiom
  Type & set__cnt(
    const std::vector<geometry_msgs::msg::Polygon_<ContainerAllocator>, typename ContainerAllocator::template rebind<geometry_msgs::msg::Polygon_<ContainerAllocator>>::other> & _arg)
  {
    this->cnt = _arg;
    return *this;
  }
  Type & set__red_list(
    const std::vector<geometry_msgs::msg::Point32_<ContainerAllocator>, typename ContainerAllocator::template rebind<geometry_msgs::msg::Point32_<ContainerAllocator>>::other> & _arg)
  {
    this->red_list = _arg;
    return *this;
  }
  Type & set__blue_list(
    const std::vector<geometry_msgs::msg::Point32_<ContainerAllocator>, typename ContainerAllocator::template rebind<geometry_msgs::msg::Point32_<ContainerAllocator>>::other> & _arg)
  {
    this->blue_list = _arg;
    return *this;
  }
  Type & set__green_list(
    const std::vector<geometry_msgs::msg::Point32_<ContainerAllocator>, typename ContainerAllocator::template rebind<geometry_msgs::msg::Point32_<ContainerAllocator>>::other> & _arg)
  {
    this->green_list = _arg;
    return *this;
  }
  Type & set__yellow_list(
    const std::vector<geometry_msgs::msg::Point32_<ContainerAllocator>, typename ContainerAllocator::template rebind<geometry_msgs::msg::Point32_<ContainerAllocator>>::other> & _arg)
  {
    this->yellow_list = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    zumo_interfaces::msg::Rawdata_<ContainerAllocator> *;
  using ConstRawPtr =
    const zumo_interfaces::msg::Rawdata_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<zumo_interfaces::msg::Rawdata_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<zumo_interfaces::msg::Rawdata_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      zumo_interfaces::msg::Rawdata_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<zumo_interfaces::msg::Rawdata_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      zumo_interfaces::msg::Rawdata_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<zumo_interfaces::msg::Rawdata_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<zumo_interfaces::msg::Rawdata_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<zumo_interfaces::msg::Rawdata_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__zumo_interfaces__msg__Rawdata
    std::shared_ptr<zumo_interfaces::msg::Rawdata_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__zumo_interfaces__msg__Rawdata
    std::shared_ptr<zumo_interfaces::msg::Rawdata_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const Rawdata_ & other) const
  {
    if (this->cnt != other.cnt) {
      return false;
    }
    if (this->red_list != other.red_list) {
      return false;
    }
    if (this->blue_list != other.blue_list) {
      return false;
    }
    if (this->green_list != other.green_list) {
      return false;
    }
    if (this->yellow_list != other.yellow_list) {
      return false;
    }
    return true;
  }
  bool operator!=(const Rawdata_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct Rawdata_

// alias to use template instance with default allocator
using Rawdata =
  zumo_interfaces::msg::Rawdata_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace zumo_interfaces

#endif  // ZUMO_INTERFACES__MSG__DETAIL__RAWDATA__STRUCT_HPP_
