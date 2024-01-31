// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from ros2_roboclaw_driver:srv/ResetEncoders.idl
// generated code does not contain a copyright notice

#ifndef ROS2_ROBOCLAW_DRIVER__SRV__DETAIL__RESET_ENCODERS__TRAITS_HPP_
#define ROS2_ROBOCLAW_DRIVER__SRV__DETAIL__RESET_ENCODERS__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "ros2_roboclaw_driver/srv/detail/reset_encoders__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

namespace ros2_roboclaw_driver
{

namespace srv
{

inline void to_flow_style_yaml(
  const ResetEncoders_Request & msg,
  std::ostream & out)
{
  out << "{";
  // member: left
  {
    out << "left: ";
    rosidl_generator_traits::value_to_yaml(msg.left, out);
    out << ", ";
  }

  // member: right
  {
    out << "right: ";
    rosidl_generator_traits::value_to_yaml(msg.right, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const ResetEncoders_Request & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: left
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "left: ";
    rosidl_generator_traits::value_to_yaml(msg.left, out);
    out << "\n";
  }

  // member: right
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "right: ";
    rosidl_generator_traits::value_to_yaml(msg.right, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const ResetEncoders_Request & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace srv

}  // namespace ros2_roboclaw_driver

namespace rosidl_generator_traits
{

[[deprecated("use ros2_roboclaw_driver::srv::to_block_style_yaml() instead")]]
inline void to_yaml(
  const ros2_roboclaw_driver::srv::ResetEncoders_Request & msg,
  std::ostream & out, size_t indentation = 0)
{
  ros2_roboclaw_driver::srv::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use ros2_roboclaw_driver::srv::to_yaml() instead")]]
inline std::string to_yaml(const ros2_roboclaw_driver::srv::ResetEncoders_Request & msg)
{
  return ros2_roboclaw_driver::srv::to_yaml(msg);
}

template<>
inline const char * data_type<ros2_roboclaw_driver::srv::ResetEncoders_Request>()
{
  return "ros2_roboclaw_driver::srv::ResetEncoders_Request";
}

template<>
inline const char * name<ros2_roboclaw_driver::srv::ResetEncoders_Request>()
{
  return "ros2_roboclaw_driver/srv/ResetEncoders_Request";
}

template<>
struct has_fixed_size<ros2_roboclaw_driver::srv::ResetEncoders_Request>
  : std::integral_constant<bool, true> {};

template<>
struct has_bounded_size<ros2_roboclaw_driver::srv::ResetEncoders_Request>
  : std::integral_constant<bool, true> {};

template<>
struct is_message<ros2_roboclaw_driver::srv::ResetEncoders_Request>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace ros2_roboclaw_driver
{

namespace srv
{

inline void to_flow_style_yaml(
  const ResetEncoders_Response & msg,
  std::ostream & out)
{
  out << "{";
  // member: ok
  {
    out << "ok: ";
    rosidl_generator_traits::value_to_yaml(msg.ok, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const ResetEncoders_Response & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: ok
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "ok: ";
    rosidl_generator_traits::value_to_yaml(msg.ok, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const ResetEncoders_Response & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace srv

}  // namespace ros2_roboclaw_driver

namespace rosidl_generator_traits
{

[[deprecated("use ros2_roboclaw_driver::srv::to_block_style_yaml() instead")]]
inline void to_yaml(
  const ros2_roboclaw_driver::srv::ResetEncoders_Response & msg,
  std::ostream & out, size_t indentation = 0)
{
  ros2_roboclaw_driver::srv::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use ros2_roboclaw_driver::srv::to_yaml() instead")]]
inline std::string to_yaml(const ros2_roboclaw_driver::srv::ResetEncoders_Response & msg)
{
  return ros2_roboclaw_driver::srv::to_yaml(msg);
}

template<>
inline const char * data_type<ros2_roboclaw_driver::srv::ResetEncoders_Response>()
{
  return "ros2_roboclaw_driver::srv::ResetEncoders_Response";
}

template<>
inline const char * name<ros2_roboclaw_driver::srv::ResetEncoders_Response>()
{
  return "ros2_roboclaw_driver/srv/ResetEncoders_Response";
}

template<>
struct has_fixed_size<ros2_roboclaw_driver::srv::ResetEncoders_Response>
  : std::integral_constant<bool, true> {};

template<>
struct has_bounded_size<ros2_roboclaw_driver::srv::ResetEncoders_Response>
  : std::integral_constant<bool, true> {};

template<>
struct is_message<ros2_roboclaw_driver::srv::ResetEncoders_Response>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace rosidl_generator_traits
{

template<>
inline const char * data_type<ros2_roboclaw_driver::srv::ResetEncoders>()
{
  return "ros2_roboclaw_driver::srv::ResetEncoders";
}

template<>
inline const char * name<ros2_roboclaw_driver::srv::ResetEncoders>()
{
  return "ros2_roboclaw_driver/srv/ResetEncoders";
}

template<>
struct has_fixed_size<ros2_roboclaw_driver::srv::ResetEncoders>
  : std::integral_constant<
    bool,
    has_fixed_size<ros2_roboclaw_driver::srv::ResetEncoders_Request>::value &&
    has_fixed_size<ros2_roboclaw_driver::srv::ResetEncoders_Response>::value
  >
{
};

template<>
struct has_bounded_size<ros2_roboclaw_driver::srv::ResetEncoders>
  : std::integral_constant<
    bool,
    has_bounded_size<ros2_roboclaw_driver::srv::ResetEncoders_Request>::value &&
    has_bounded_size<ros2_roboclaw_driver::srv::ResetEncoders_Response>::value
  >
{
};

template<>
struct is_service<ros2_roboclaw_driver::srv::ResetEncoders>
  : std::true_type
{
};

template<>
struct is_service_request<ros2_roboclaw_driver::srv::ResetEncoders_Request>
  : std::true_type
{
};

template<>
struct is_service_response<ros2_roboclaw_driver::srv::ResetEncoders_Response>
  : std::true_type
{
};

}  // namespace rosidl_generator_traits

#endif  // ROS2_ROBOCLAW_DRIVER__SRV__DETAIL__RESET_ENCODERS__TRAITS_HPP_
