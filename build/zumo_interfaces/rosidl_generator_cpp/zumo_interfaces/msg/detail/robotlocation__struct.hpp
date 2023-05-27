// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from zumo_interfaces:msg/Robotlocation.idl
// generated code does not contain a copyright notice

#ifndef ZUMO_INTERFACES__MSG__DETAIL__ROBOTLOCATION__STRUCT_HPP_
#define ZUMO_INTERFACES__MSG__DETAIL__ROBOTLOCATION__STRUCT_HPP_

#include <rosidl_runtime_cpp/bounded_vector.hpp>
#include <rosidl_runtime_cpp/message_initialization.hpp>
#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>


#ifndef _WIN32
# define DEPRECATED__zumo_interfaces__msg__Robotlocation __attribute__((deprecated))
#else
# define DEPRECATED__zumo_interfaces__msg__Robotlocation __declspec(deprecated)
#endif

namespace zumo_interfaces
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct Robotlocation_
{
  using Type = Robotlocation_<ContainerAllocator>;

  explicit Robotlocation_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->id = "";
      this->x = 0l;
      this->y = 0l;
    }
  }

  explicit Robotlocation_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : id(_alloc)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->id = "";
      this->x = 0l;
      this->y = 0l;
    }
  }

  // field types and members
  using _id_type =
    std::basic_string<char, std::char_traits<char>, typename ContainerAllocator::template rebind<char>::other>;
  _id_type id;
  using _x_type =
    int32_t;
  _x_type x;
  using _y_type =
    int32_t;
  _y_type y;

  // setters for named parameter idiom
  Type & set__id(
    const std::basic_string<char, std::char_traits<char>, typename ContainerAllocator::template rebind<char>::other> & _arg)
  {
    this->id = _arg;
    return *this;
  }
  Type & set__x(
    const int32_t & _arg)
  {
    this->x = _arg;
    return *this;
  }
  Type & set__y(
    const int32_t & _arg)
  {
    this->y = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    zumo_interfaces::msg::Robotlocation_<ContainerAllocator> *;
  using ConstRawPtr =
    const zumo_interfaces::msg::Robotlocation_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<zumo_interfaces::msg::Robotlocation_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<zumo_interfaces::msg::Robotlocation_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      zumo_interfaces::msg::Robotlocation_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<zumo_interfaces::msg::Robotlocation_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      zumo_interfaces::msg::Robotlocation_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<zumo_interfaces::msg::Robotlocation_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<zumo_interfaces::msg::Robotlocation_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<zumo_interfaces::msg::Robotlocation_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__zumo_interfaces__msg__Robotlocation
    std::shared_ptr<zumo_interfaces::msg::Robotlocation_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__zumo_interfaces__msg__Robotlocation
    std::shared_ptr<zumo_interfaces::msg::Robotlocation_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const Robotlocation_ & other) const
  {
    if (this->id != other.id) {
      return false;
    }
    if (this->x != other.x) {
      return false;
    }
    if (this->y != other.y) {
      return false;
    }
    return true;
  }
  bool operator!=(const Robotlocation_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct Robotlocation_

// alias to use template instance with default allocator
using Robotlocation =
  zumo_interfaces::msg::Robotlocation_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace zumo_interfaces

#endif  // ZUMO_INTERFACES__MSG__DETAIL__ROBOTLOCATION__STRUCT_HPP_
