// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from ros2_roboclaw_driver:msg/RoboClawStatus.idl
// generated code does not contain a copyright notice

#ifndef ROS2_ROBOCLAW_DRIVER__MSG__DETAIL__ROBO_CLAW_STATUS__BUILDER_HPP_
#define ROS2_ROBOCLAW_DRIVER__MSG__DETAIL__ROBO_CLAW_STATUS__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "ros2_roboclaw_driver/msg/detail/robo_claw_status__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace ros2_roboclaw_driver
{

namespace msg
{

namespace builder
{

class Init_RoboClawStatus_error_string
{
public:
  explicit Init_RoboClawStatus_error_string(::ros2_roboclaw_driver::msg::RoboClawStatus & msg)
  : msg_(msg)
  {}
  ::ros2_roboclaw_driver::msg::RoboClawStatus error_string(::ros2_roboclaw_driver::msg::RoboClawStatus::_error_string_type arg)
  {
    msg_.error_string = std::move(arg);
    return std::move(msg_);
  }

private:
  ::ros2_roboclaw_driver::msg::RoboClawStatus msg_;
};

class Init_RoboClawStatus_temperature
{
public:
  explicit Init_RoboClawStatus_temperature(::ros2_roboclaw_driver::msg::RoboClawStatus & msg)
  : msg_(msg)
  {}
  Init_RoboClawStatus_error_string temperature(::ros2_roboclaw_driver::msg::RoboClawStatus::_temperature_type arg)
  {
    msg_.temperature = std::move(arg);
    return Init_RoboClawStatus_error_string(msg_);
  }

private:
  ::ros2_roboclaw_driver::msg::RoboClawStatus msg_;
};

class Init_RoboClawStatus_logic_battery_voltage
{
public:
  explicit Init_RoboClawStatus_logic_battery_voltage(::ros2_roboclaw_driver::msg::RoboClawStatus & msg)
  : msg_(msg)
  {}
  Init_RoboClawStatus_temperature logic_battery_voltage(::ros2_roboclaw_driver::msg::RoboClawStatus::_logic_battery_voltage_type arg)
  {
    msg_.logic_battery_voltage = std::move(arg);
    return Init_RoboClawStatus_temperature(msg_);
  }

private:
  ::ros2_roboclaw_driver::msg::RoboClawStatus msg_;
};

class Init_RoboClawStatus_main_battery_voltage
{
public:
  explicit Init_RoboClawStatus_main_battery_voltage(::ros2_roboclaw_driver::msg::RoboClawStatus & msg)
  : msg_(msg)
  {}
  Init_RoboClawStatus_logic_battery_voltage main_battery_voltage(::ros2_roboclaw_driver::msg::RoboClawStatus::_main_battery_voltage_type arg)
  {
    msg_.main_battery_voltage = std::move(arg);
    return Init_RoboClawStatus_logic_battery_voltage(msg_);
  }

private:
  ::ros2_roboclaw_driver::msg::RoboClawStatus msg_;
};

class Init_RoboClawStatus_m2_encoder_status
{
public:
  explicit Init_RoboClawStatus_m2_encoder_status(::ros2_roboclaw_driver::msg::RoboClawStatus & msg)
  : msg_(msg)
  {}
  Init_RoboClawStatus_main_battery_voltage m2_encoder_status(::ros2_roboclaw_driver::msg::RoboClawStatus::_m2_encoder_status_type arg)
  {
    msg_.m2_encoder_status = std::move(arg);
    return Init_RoboClawStatus_main_battery_voltage(msg_);
  }

private:
  ::ros2_roboclaw_driver::msg::RoboClawStatus msg_;
};

class Init_RoboClawStatus_m2_encoder_value
{
public:
  explicit Init_RoboClawStatus_m2_encoder_value(::ros2_roboclaw_driver::msg::RoboClawStatus & msg)
  : msg_(msg)
  {}
  Init_RoboClawStatus_m2_encoder_status m2_encoder_value(::ros2_roboclaw_driver::msg::RoboClawStatus::_m2_encoder_value_type arg)
  {
    msg_.m2_encoder_value = std::move(arg);
    return Init_RoboClawStatus_m2_encoder_status(msg_);
  }

private:
  ::ros2_roboclaw_driver::msg::RoboClawStatus msg_;
};

class Init_RoboClawStatus_m2_motor_current
{
public:
  explicit Init_RoboClawStatus_m2_motor_current(::ros2_roboclaw_driver::msg::RoboClawStatus & msg)
  : msg_(msg)
  {}
  Init_RoboClawStatus_m2_encoder_value m2_motor_current(::ros2_roboclaw_driver::msg::RoboClawStatus::_m2_motor_current_type arg)
  {
    msg_.m2_motor_current = std::move(arg);
    return Init_RoboClawStatus_m2_encoder_value(msg_);
  }

private:
  ::ros2_roboclaw_driver::msg::RoboClawStatus msg_;
};

class Init_RoboClawStatus_m2_current_speed
{
public:
  explicit Init_RoboClawStatus_m2_current_speed(::ros2_roboclaw_driver::msg::RoboClawStatus & msg)
  : msg_(msg)
  {}
  Init_RoboClawStatus_m2_motor_current m2_current_speed(::ros2_roboclaw_driver::msg::RoboClawStatus::_m2_current_speed_type arg)
  {
    msg_.m2_current_speed = std::move(arg);
    return Init_RoboClawStatus_m2_motor_current(msg_);
  }

private:
  ::ros2_roboclaw_driver::msg::RoboClawStatus msg_;
};

class Init_RoboClawStatus_m2_qpps
{
public:
  explicit Init_RoboClawStatus_m2_qpps(::ros2_roboclaw_driver::msg::RoboClawStatus & msg)
  : msg_(msg)
  {}
  Init_RoboClawStatus_m2_current_speed m2_qpps(::ros2_roboclaw_driver::msg::RoboClawStatus::_m2_qpps_type arg)
  {
    msg_.m2_qpps = std::move(arg);
    return Init_RoboClawStatus_m2_current_speed(msg_);
  }

private:
  ::ros2_roboclaw_driver::msg::RoboClawStatus msg_;
};

class Init_RoboClawStatus_m2_d
{
public:
  explicit Init_RoboClawStatus_m2_d(::ros2_roboclaw_driver::msg::RoboClawStatus & msg)
  : msg_(msg)
  {}
  Init_RoboClawStatus_m2_qpps m2_d(::ros2_roboclaw_driver::msg::RoboClawStatus::_m2_d_type arg)
  {
    msg_.m2_d = std::move(arg);
    return Init_RoboClawStatus_m2_qpps(msg_);
  }

private:
  ::ros2_roboclaw_driver::msg::RoboClawStatus msg_;
};

class Init_RoboClawStatus_m2_i
{
public:
  explicit Init_RoboClawStatus_m2_i(::ros2_roboclaw_driver::msg::RoboClawStatus & msg)
  : msg_(msg)
  {}
  Init_RoboClawStatus_m2_d m2_i(::ros2_roboclaw_driver::msg::RoboClawStatus::_m2_i_type arg)
  {
    msg_.m2_i = std::move(arg);
    return Init_RoboClawStatus_m2_d(msg_);
  }

private:
  ::ros2_roboclaw_driver::msg::RoboClawStatus msg_;
};

class Init_RoboClawStatus_m2_p
{
public:
  explicit Init_RoboClawStatus_m2_p(::ros2_roboclaw_driver::msg::RoboClawStatus & msg)
  : msg_(msg)
  {}
  Init_RoboClawStatus_m2_i m2_p(::ros2_roboclaw_driver::msg::RoboClawStatus::_m2_p_type arg)
  {
    msg_.m2_p = std::move(arg);
    return Init_RoboClawStatus_m2_i(msg_);
  }

private:
  ::ros2_roboclaw_driver::msg::RoboClawStatus msg_;
};

class Init_RoboClawStatus_m1_encoder_status
{
public:
  explicit Init_RoboClawStatus_m1_encoder_status(::ros2_roboclaw_driver::msg::RoboClawStatus & msg)
  : msg_(msg)
  {}
  Init_RoboClawStatus_m2_p m1_encoder_status(::ros2_roboclaw_driver::msg::RoboClawStatus::_m1_encoder_status_type arg)
  {
    msg_.m1_encoder_status = std::move(arg);
    return Init_RoboClawStatus_m2_p(msg_);
  }

private:
  ::ros2_roboclaw_driver::msg::RoboClawStatus msg_;
};

class Init_RoboClawStatus_m1_encoder_value
{
public:
  explicit Init_RoboClawStatus_m1_encoder_value(::ros2_roboclaw_driver::msg::RoboClawStatus & msg)
  : msg_(msg)
  {}
  Init_RoboClawStatus_m1_encoder_status m1_encoder_value(::ros2_roboclaw_driver::msg::RoboClawStatus::_m1_encoder_value_type arg)
  {
    msg_.m1_encoder_value = std::move(arg);
    return Init_RoboClawStatus_m1_encoder_status(msg_);
  }

private:
  ::ros2_roboclaw_driver::msg::RoboClawStatus msg_;
};

class Init_RoboClawStatus_m1_motor_current
{
public:
  explicit Init_RoboClawStatus_m1_motor_current(::ros2_roboclaw_driver::msg::RoboClawStatus & msg)
  : msg_(msg)
  {}
  Init_RoboClawStatus_m1_encoder_value m1_motor_current(::ros2_roboclaw_driver::msg::RoboClawStatus::_m1_motor_current_type arg)
  {
    msg_.m1_motor_current = std::move(arg);
    return Init_RoboClawStatus_m1_encoder_value(msg_);
  }

private:
  ::ros2_roboclaw_driver::msg::RoboClawStatus msg_;
};

class Init_RoboClawStatus_m1_current_speed
{
public:
  explicit Init_RoboClawStatus_m1_current_speed(::ros2_roboclaw_driver::msg::RoboClawStatus & msg)
  : msg_(msg)
  {}
  Init_RoboClawStatus_m1_motor_current m1_current_speed(::ros2_roboclaw_driver::msg::RoboClawStatus::_m1_current_speed_type arg)
  {
    msg_.m1_current_speed = std::move(arg);
    return Init_RoboClawStatus_m1_motor_current(msg_);
  }

private:
  ::ros2_roboclaw_driver::msg::RoboClawStatus msg_;
};

class Init_RoboClawStatus_m1_qpps
{
public:
  explicit Init_RoboClawStatus_m1_qpps(::ros2_roboclaw_driver::msg::RoboClawStatus & msg)
  : msg_(msg)
  {}
  Init_RoboClawStatus_m1_current_speed m1_qpps(::ros2_roboclaw_driver::msg::RoboClawStatus::_m1_qpps_type arg)
  {
    msg_.m1_qpps = std::move(arg);
    return Init_RoboClawStatus_m1_current_speed(msg_);
  }

private:
  ::ros2_roboclaw_driver::msg::RoboClawStatus msg_;
};

class Init_RoboClawStatus_m1_d
{
public:
  explicit Init_RoboClawStatus_m1_d(::ros2_roboclaw_driver::msg::RoboClawStatus & msg)
  : msg_(msg)
  {}
  Init_RoboClawStatus_m1_qpps m1_d(::ros2_roboclaw_driver::msg::RoboClawStatus::_m1_d_type arg)
  {
    msg_.m1_d = std::move(arg);
    return Init_RoboClawStatus_m1_qpps(msg_);
  }

private:
  ::ros2_roboclaw_driver::msg::RoboClawStatus msg_;
};

class Init_RoboClawStatus_m1_i
{
public:
  explicit Init_RoboClawStatus_m1_i(::ros2_roboclaw_driver::msg::RoboClawStatus & msg)
  : msg_(msg)
  {}
  Init_RoboClawStatus_m1_d m1_i(::ros2_roboclaw_driver::msg::RoboClawStatus::_m1_i_type arg)
  {
    msg_.m1_i = std::move(arg);
    return Init_RoboClawStatus_m1_d(msg_);
  }

private:
  ::ros2_roboclaw_driver::msg::RoboClawStatus msg_;
};

class Init_RoboClawStatus_m1_p
{
public:
  Init_RoboClawStatus_m1_p()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_RoboClawStatus_m1_i m1_p(::ros2_roboclaw_driver::msg::RoboClawStatus::_m1_p_type arg)
  {
    msg_.m1_p = std::move(arg);
    return Init_RoboClawStatus_m1_i(msg_);
  }

private:
  ::ros2_roboclaw_driver::msg::RoboClawStatus msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::ros2_roboclaw_driver::msg::RoboClawStatus>()
{
  return ros2_roboclaw_driver::msg::builder::Init_RoboClawStatus_m1_p();
}

}  // namespace ros2_roboclaw_driver

#endif  // ROS2_ROBOCLAW_DRIVER__MSG__DETAIL__ROBO_CLAW_STATUS__BUILDER_HPP_
