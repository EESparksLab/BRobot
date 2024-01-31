// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from ros2_roboclaw_driver:msg/RoboClawStatus.idl
// generated code does not contain a copyright notice

#ifndef ROS2_ROBOCLAW_DRIVER__MSG__DETAIL__ROBO_CLAW_STATUS__TRAITS_HPP_
#define ROS2_ROBOCLAW_DRIVER__MSG__DETAIL__ROBO_CLAW_STATUS__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "ros2_roboclaw_driver/msg/detail/robo_claw_status__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

namespace ros2_roboclaw_driver
{

namespace msg
{

inline void to_flow_style_yaml(
  const RoboClawStatus & msg,
  std::ostream & out)
{
  out << "{";
  // member: m1_p
  {
    out << "m1_p: ";
    rosidl_generator_traits::value_to_yaml(msg.m1_p, out);
    out << ", ";
  }

  // member: m1_i
  {
    out << "m1_i: ";
    rosidl_generator_traits::value_to_yaml(msg.m1_i, out);
    out << ", ";
  }

  // member: m1_d
  {
    out << "m1_d: ";
    rosidl_generator_traits::value_to_yaml(msg.m1_d, out);
    out << ", ";
  }

  // member: m1_qpps
  {
    out << "m1_qpps: ";
    rosidl_generator_traits::value_to_yaml(msg.m1_qpps, out);
    out << ", ";
  }

  // member: m1_current_speed
  {
    out << "m1_current_speed: ";
    rosidl_generator_traits::value_to_yaml(msg.m1_current_speed, out);
    out << ", ";
  }

  // member: m1_motor_current
  {
    out << "m1_motor_current: ";
    rosidl_generator_traits::value_to_yaml(msg.m1_motor_current, out);
    out << ", ";
  }

  // member: m1_encoder_value
  {
    out << "m1_encoder_value: ";
    rosidl_generator_traits::value_to_yaml(msg.m1_encoder_value, out);
    out << ", ";
  }

  // member: m1_encoder_status
  {
    out << "m1_encoder_status: ";
    rosidl_generator_traits::value_to_yaml(msg.m1_encoder_status, out);
    out << ", ";
  }

  // member: m2_p
  {
    out << "m2_p: ";
    rosidl_generator_traits::value_to_yaml(msg.m2_p, out);
    out << ", ";
  }

  // member: m2_i
  {
    out << "m2_i: ";
    rosidl_generator_traits::value_to_yaml(msg.m2_i, out);
    out << ", ";
  }

  // member: m2_d
  {
    out << "m2_d: ";
    rosidl_generator_traits::value_to_yaml(msg.m2_d, out);
    out << ", ";
  }

  // member: m2_qpps
  {
    out << "m2_qpps: ";
    rosidl_generator_traits::value_to_yaml(msg.m2_qpps, out);
    out << ", ";
  }

  // member: m2_current_speed
  {
    out << "m2_current_speed: ";
    rosidl_generator_traits::value_to_yaml(msg.m2_current_speed, out);
    out << ", ";
  }

  // member: m2_motor_current
  {
    out << "m2_motor_current: ";
    rosidl_generator_traits::value_to_yaml(msg.m2_motor_current, out);
    out << ", ";
  }

  // member: m2_encoder_value
  {
    out << "m2_encoder_value: ";
    rosidl_generator_traits::value_to_yaml(msg.m2_encoder_value, out);
    out << ", ";
  }

  // member: m2_encoder_status
  {
    out << "m2_encoder_status: ";
    rosidl_generator_traits::value_to_yaml(msg.m2_encoder_status, out);
    out << ", ";
  }

  // member: main_battery_voltage
  {
    out << "main_battery_voltage: ";
    rosidl_generator_traits::value_to_yaml(msg.main_battery_voltage, out);
    out << ", ";
  }

  // member: logic_battery_voltage
  {
    out << "logic_battery_voltage: ";
    rosidl_generator_traits::value_to_yaml(msg.logic_battery_voltage, out);
    out << ", ";
  }

  // member: temperature
  {
    out << "temperature: ";
    rosidl_generator_traits::value_to_yaml(msg.temperature, out);
    out << ", ";
  }

  // member: error_string
  {
    out << "error_string: ";
    rosidl_generator_traits::value_to_yaml(msg.error_string, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const RoboClawStatus & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: m1_p
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "m1_p: ";
    rosidl_generator_traits::value_to_yaml(msg.m1_p, out);
    out << "\n";
  }

  // member: m1_i
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "m1_i: ";
    rosidl_generator_traits::value_to_yaml(msg.m1_i, out);
    out << "\n";
  }

  // member: m1_d
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "m1_d: ";
    rosidl_generator_traits::value_to_yaml(msg.m1_d, out);
    out << "\n";
  }

  // member: m1_qpps
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "m1_qpps: ";
    rosidl_generator_traits::value_to_yaml(msg.m1_qpps, out);
    out << "\n";
  }

  // member: m1_current_speed
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "m1_current_speed: ";
    rosidl_generator_traits::value_to_yaml(msg.m1_current_speed, out);
    out << "\n";
  }

  // member: m1_motor_current
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "m1_motor_current: ";
    rosidl_generator_traits::value_to_yaml(msg.m1_motor_current, out);
    out << "\n";
  }

  // member: m1_encoder_value
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "m1_encoder_value: ";
    rosidl_generator_traits::value_to_yaml(msg.m1_encoder_value, out);
    out << "\n";
  }

  // member: m1_encoder_status
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "m1_encoder_status: ";
    rosidl_generator_traits::value_to_yaml(msg.m1_encoder_status, out);
    out << "\n";
  }

  // member: m2_p
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "m2_p: ";
    rosidl_generator_traits::value_to_yaml(msg.m2_p, out);
    out << "\n";
  }

  // member: m2_i
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "m2_i: ";
    rosidl_generator_traits::value_to_yaml(msg.m2_i, out);
    out << "\n";
  }

  // member: m2_d
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "m2_d: ";
    rosidl_generator_traits::value_to_yaml(msg.m2_d, out);
    out << "\n";
  }

  // member: m2_qpps
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "m2_qpps: ";
    rosidl_generator_traits::value_to_yaml(msg.m2_qpps, out);
    out << "\n";
  }

  // member: m2_current_speed
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "m2_current_speed: ";
    rosidl_generator_traits::value_to_yaml(msg.m2_current_speed, out);
    out << "\n";
  }

  // member: m2_motor_current
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "m2_motor_current: ";
    rosidl_generator_traits::value_to_yaml(msg.m2_motor_current, out);
    out << "\n";
  }

  // member: m2_encoder_value
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "m2_encoder_value: ";
    rosidl_generator_traits::value_to_yaml(msg.m2_encoder_value, out);
    out << "\n";
  }

  // member: m2_encoder_status
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "m2_encoder_status: ";
    rosidl_generator_traits::value_to_yaml(msg.m2_encoder_status, out);
    out << "\n";
  }

  // member: main_battery_voltage
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "main_battery_voltage: ";
    rosidl_generator_traits::value_to_yaml(msg.main_battery_voltage, out);
    out << "\n";
  }

  // member: logic_battery_voltage
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "logic_battery_voltage: ";
    rosidl_generator_traits::value_to_yaml(msg.logic_battery_voltage, out);
    out << "\n";
  }

  // member: temperature
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "temperature: ";
    rosidl_generator_traits::value_to_yaml(msg.temperature, out);
    out << "\n";
  }

  // member: error_string
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "error_string: ";
    rosidl_generator_traits::value_to_yaml(msg.error_string, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const RoboClawStatus & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace msg

}  // namespace ros2_roboclaw_driver

namespace rosidl_generator_traits
{

[[deprecated("use ros2_roboclaw_driver::msg::to_block_style_yaml() instead")]]
inline void to_yaml(
  const ros2_roboclaw_driver::msg::RoboClawStatus & msg,
  std::ostream & out, size_t indentation = 0)
{
  ros2_roboclaw_driver::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use ros2_roboclaw_driver::msg::to_yaml() instead")]]
inline std::string to_yaml(const ros2_roboclaw_driver::msg::RoboClawStatus & msg)
{
  return ros2_roboclaw_driver::msg::to_yaml(msg);
}

template<>
inline const char * data_type<ros2_roboclaw_driver::msg::RoboClawStatus>()
{
  return "ros2_roboclaw_driver::msg::RoboClawStatus";
}

template<>
inline const char * name<ros2_roboclaw_driver::msg::RoboClawStatus>()
{
  return "ros2_roboclaw_driver/msg/RoboClawStatus";
}

template<>
struct has_fixed_size<ros2_roboclaw_driver::msg::RoboClawStatus>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<ros2_roboclaw_driver::msg::RoboClawStatus>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<ros2_roboclaw_driver::msg::RoboClawStatus>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // ROS2_ROBOCLAW_DRIVER__MSG__DETAIL__ROBO_CLAW_STATUS__TRAITS_HPP_
