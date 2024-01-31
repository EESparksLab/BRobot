// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from ros2_roboclaw_driver:msg/RoboClawStatus.idl
// generated code does not contain a copyright notice

#ifndef ROS2_ROBOCLAW_DRIVER__MSG__DETAIL__ROBO_CLAW_STATUS__STRUCT_HPP_
#define ROS2_ROBOCLAW_DRIVER__MSG__DETAIL__ROBO_CLAW_STATUS__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


#ifndef _WIN32
# define DEPRECATED__ros2_roboclaw_driver__msg__RoboClawStatus __attribute__((deprecated))
#else
# define DEPRECATED__ros2_roboclaw_driver__msg__RoboClawStatus __declspec(deprecated)
#endif

namespace ros2_roboclaw_driver
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct RoboClawStatus_
{
  using Type = RoboClawStatus_<ContainerAllocator>;

  explicit RoboClawStatus_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->m1_p = 0.0f;
      this->m1_i = 0.0f;
      this->m1_d = 0.0f;
      this->m1_qpps = 0ul;
      this->m1_current_speed = 0l;
      this->m1_motor_current = 0.0f;
      this->m1_encoder_value = 0ul;
      this->m1_encoder_status = 0;
      this->m2_p = 0.0f;
      this->m2_i = 0.0f;
      this->m2_d = 0.0f;
      this->m2_qpps = 0ul;
      this->m2_current_speed = 0l;
      this->m2_motor_current = 0.0f;
      this->m2_encoder_value = 0ul;
      this->m2_encoder_status = 0;
      this->main_battery_voltage = 0.0f;
      this->logic_battery_voltage = 0.0f;
      this->temperature = 0.0f;
      this->error_string = "";
    }
  }

  explicit RoboClawStatus_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : error_string(_alloc)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->m1_p = 0.0f;
      this->m1_i = 0.0f;
      this->m1_d = 0.0f;
      this->m1_qpps = 0ul;
      this->m1_current_speed = 0l;
      this->m1_motor_current = 0.0f;
      this->m1_encoder_value = 0ul;
      this->m1_encoder_status = 0;
      this->m2_p = 0.0f;
      this->m2_i = 0.0f;
      this->m2_d = 0.0f;
      this->m2_qpps = 0ul;
      this->m2_current_speed = 0l;
      this->m2_motor_current = 0.0f;
      this->m2_encoder_value = 0ul;
      this->m2_encoder_status = 0;
      this->main_battery_voltage = 0.0f;
      this->logic_battery_voltage = 0.0f;
      this->temperature = 0.0f;
      this->error_string = "";
    }
  }

  // field types and members
  using _m1_p_type =
    float;
  _m1_p_type m1_p;
  using _m1_i_type =
    float;
  _m1_i_type m1_i;
  using _m1_d_type =
    float;
  _m1_d_type m1_d;
  using _m1_qpps_type =
    uint32_t;
  _m1_qpps_type m1_qpps;
  using _m1_current_speed_type =
    int32_t;
  _m1_current_speed_type m1_current_speed;
  using _m1_motor_current_type =
    float;
  _m1_motor_current_type m1_motor_current;
  using _m1_encoder_value_type =
    uint32_t;
  _m1_encoder_value_type m1_encoder_value;
  using _m1_encoder_status_type =
    uint8_t;
  _m1_encoder_status_type m1_encoder_status;
  using _m2_p_type =
    float;
  _m2_p_type m2_p;
  using _m2_i_type =
    float;
  _m2_i_type m2_i;
  using _m2_d_type =
    float;
  _m2_d_type m2_d;
  using _m2_qpps_type =
    uint32_t;
  _m2_qpps_type m2_qpps;
  using _m2_current_speed_type =
    int32_t;
  _m2_current_speed_type m2_current_speed;
  using _m2_motor_current_type =
    float;
  _m2_motor_current_type m2_motor_current;
  using _m2_encoder_value_type =
    uint32_t;
  _m2_encoder_value_type m2_encoder_value;
  using _m2_encoder_status_type =
    uint8_t;
  _m2_encoder_status_type m2_encoder_status;
  using _main_battery_voltage_type =
    float;
  _main_battery_voltage_type main_battery_voltage;
  using _logic_battery_voltage_type =
    float;
  _logic_battery_voltage_type logic_battery_voltage;
  using _temperature_type =
    float;
  _temperature_type temperature;
  using _error_string_type =
    std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>;
  _error_string_type error_string;

  // setters for named parameter idiom
  Type & set__m1_p(
    const float & _arg)
  {
    this->m1_p = _arg;
    return *this;
  }
  Type & set__m1_i(
    const float & _arg)
  {
    this->m1_i = _arg;
    return *this;
  }
  Type & set__m1_d(
    const float & _arg)
  {
    this->m1_d = _arg;
    return *this;
  }
  Type & set__m1_qpps(
    const uint32_t & _arg)
  {
    this->m1_qpps = _arg;
    return *this;
  }
  Type & set__m1_current_speed(
    const int32_t & _arg)
  {
    this->m1_current_speed = _arg;
    return *this;
  }
  Type & set__m1_motor_current(
    const float & _arg)
  {
    this->m1_motor_current = _arg;
    return *this;
  }
  Type & set__m1_encoder_value(
    const uint32_t & _arg)
  {
    this->m1_encoder_value = _arg;
    return *this;
  }
  Type & set__m1_encoder_status(
    const uint8_t & _arg)
  {
    this->m1_encoder_status = _arg;
    return *this;
  }
  Type & set__m2_p(
    const float & _arg)
  {
    this->m2_p = _arg;
    return *this;
  }
  Type & set__m2_i(
    const float & _arg)
  {
    this->m2_i = _arg;
    return *this;
  }
  Type & set__m2_d(
    const float & _arg)
  {
    this->m2_d = _arg;
    return *this;
  }
  Type & set__m2_qpps(
    const uint32_t & _arg)
  {
    this->m2_qpps = _arg;
    return *this;
  }
  Type & set__m2_current_speed(
    const int32_t & _arg)
  {
    this->m2_current_speed = _arg;
    return *this;
  }
  Type & set__m2_motor_current(
    const float & _arg)
  {
    this->m2_motor_current = _arg;
    return *this;
  }
  Type & set__m2_encoder_value(
    const uint32_t & _arg)
  {
    this->m2_encoder_value = _arg;
    return *this;
  }
  Type & set__m2_encoder_status(
    const uint8_t & _arg)
  {
    this->m2_encoder_status = _arg;
    return *this;
  }
  Type & set__main_battery_voltage(
    const float & _arg)
  {
    this->main_battery_voltage = _arg;
    return *this;
  }
  Type & set__logic_battery_voltage(
    const float & _arg)
  {
    this->logic_battery_voltage = _arg;
    return *this;
  }
  Type & set__temperature(
    const float & _arg)
  {
    this->temperature = _arg;
    return *this;
  }
  Type & set__error_string(
    const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> & _arg)
  {
    this->error_string = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    ros2_roboclaw_driver::msg::RoboClawStatus_<ContainerAllocator> *;
  using ConstRawPtr =
    const ros2_roboclaw_driver::msg::RoboClawStatus_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<ros2_roboclaw_driver::msg::RoboClawStatus_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<ros2_roboclaw_driver::msg::RoboClawStatus_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      ros2_roboclaw_driver::msg::RoboClawStatus_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<ros2_roboclaw_driver::msg::RoboClawStatus_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      ros2_roboclaw_driver::msg::RoboClawStatus_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<ros2_roboclaw_driver::msg::RoboClawStatus_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<ros2_roboclaw_driver::msg::RoboClawStatus_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<ros2_roboclaw_driver::msg::RoboClawStatus_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__ros2_roboclaw_driver__msg__RoboClawStatus
    std::shared_ptr<ros2_roboclaw_driver::msg::RoboClawStatus_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__ros2_roboclaw_driver__msg__RoboClawStatus
    std::shared_ptr<ros2_roboclaw_driver::msg::RoboClawStatus_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const RoboClawStatus_ & other) const
  {
    if (this->m1_p != other.m1_p) {
      return false;
    }
    if (this->m1_i != other.m1_i) {
      return false;
    }
    if (this->m1_d != other.m1_d) {
      return false;
    }
    if (this->m1_qpps != other.m1_qpps) {
      return false;
    }
    if (this->m1_current_speed != other.m1_current_speed) {
      return false;
    }
    if (this->m1_motor_current != other.m1_motor_current) {
      return false;
    }
    if (this->m1_encoder_value != other.m1_encoder_value) {
      return false;
    }
    if (this->m1_encoder_status != other.m1_encoder_status) {
      return false;
    }
    if (this->m2_p != other.m2_p) {
      return false;
    }
    if (this->m2_i != other.m2_i) {
      return false;
    }
    if (this->m2_d != other.m2_d) {
      return false;
    }
    if (this->m2_qpps != other.m2_qpps) {
      return false;
    }
    if (this->m2_current_speed != other.m2_current_speed) {
      return false;
    }
    if (this->m2_motor_current != other.m2_motor_current) {
      return false;
    }
    if (this->m2_encoder_value != other.m2_encoder_value) {
      return false;
    }
    if (this->m2_encoder_status != other.m2_encoder_status) {
      return false;
    }
    if (this->main_battery_voltage != other.main_battery_voltage) {
      return false;
    }
    if (this->logic_battery_voltage != other.logic_battery_voltage) {
      return false;
    }
    if (this->temperature != other.temperature) {
      return false;
    }
    if (this->error_string != other.error_string) {
      return false;
    }
    return true;
  }
  bool operator!=(const RoboClawStatus_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct RoboClawStatus_

// alias to use template instance with default allocator
using RoboClawStatus =
  ros2_roboclaw_driver::msg::RoboClawStatus_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace ros2_roboclaw_driver

#endif  // ROS2_ROBOCLAW_DRIVER__MSG__DETAIL__ROBO_CLAW_STATUS__STRUCT_HPP_
