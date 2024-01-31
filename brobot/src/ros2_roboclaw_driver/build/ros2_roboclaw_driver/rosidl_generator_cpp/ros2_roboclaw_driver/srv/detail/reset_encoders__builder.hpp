// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from ros2_roboclaw_driver:srv/ResetEncoders.idl
// generated code does not contain a copyright notice

#ifndef ROS2_ROBOCLAW_DRIVER__SRV__DETAIL__RESET_ENCODERS__BUILDER_HPP_
#define ROS2_ROBOCLAW_DRIVER__SRV__DETAIL__RESET_ENCODERS__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "ros2_roboclaw_driver/srv/detail/reset_encoders__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace ros2_roboclaw_driver
{

namespace srv
{

namespace builder
{

class Init_ResetEncoders_Request_right
{
public:
  explicit Init_ResetEncoders_Request_right(::ros2_roboclaw_driver::srv::ResetEncoders_Request & msg)
  : msg_(msg)
  {}
  ::ros2_roboclaw_driver::srv::ResetEncoders_Request right(::ros2_roboclaw_driver::srv::ResetEncoders_Request::_right_type arg)
  {
    msg_.right = std::move(arg);
    return std::move(msg_);
  }

private:
  ::ros2_roboclaw_driver::srv::ResetEncoders_Request msg_;
};

class Init_ResetEncoders_Request_left
{
public:
  Init_ResetEncoders_Request_left()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_ResetEncoders_Request_right left(::ros2_roboclaw_driver::srv::ResetEncoders_Request::_left_type arg)
  {
    msg_.left = std::move(arg);
    return Init_ResetEncoders_Request_right(msg_);
  }

private:
  ::ros2_roboclaw_driver::srv::ResetEncoders_Request msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::ros2_roboclaw_driver::srv::ResetEncoders_Request>()
{
  return ros2_roboclaw_driver::srv::builder::Init_ResetEncoders_Request_left();
}

}  // namespace ros2_roboclaw_driver


namespace ros2_roboclaw_driver
{

namespace srv
{

namespace builder
{

class Init_ResetEncoders_Response_ok
{
public:
  Init_ResetEncoders_Response_ok()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::ros2_roboclaw_driver::srv::ResetEncoders_Response ok(::ros2_roboclaw_driver::srv::ResetEncoders_Response::_ok_type arg)
  {
    msg_.ok = std::move(arg);
    return std::move(msg_);
  }

private:
  ::ros2_roboclaw_driver::srv::ResetEncoders_Response msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::ros2_roboclaw_driver::srv::ResetEncoders_Response>()
{
  return ros2_roboclaw_driver::srv::builder::Init_ResetEncoders_Response_ok();
}

}  // namespace ros2_roboclaw_driver

#endif  // ROS2_ROBOCLAW_DRIVER__SRV__DETAIL__RESET_ENCODERS__BUILDER_HPP_
