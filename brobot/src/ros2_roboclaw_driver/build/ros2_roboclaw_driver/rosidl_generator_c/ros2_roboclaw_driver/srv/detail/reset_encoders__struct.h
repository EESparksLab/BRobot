// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from ros2_roboclaw_driver:srv/ResetEncoders.idl
// generated code does not contain a copyright notice

#ifndef ROS2_ROBOCLAW_DRIVER__SRV__DETAIL__RESET_ENCODERS__STRUCT_H_
#define ROS2_ROBOCLAW_DRIVER__SRV__DETAIL__RESET_ENCODERS__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

/// Struct defined in srv/ResetEncoders in the package ros2_roboclaw_driver.
typedef struct ros2_roboclaw_driver__srv__ResetEncoders_Request
{
  int64_t left;
  int64_t right;
} ros2_roboclaw_driver__srv__ResetEncoders_Request;

// Struct for a sequence of ros2_roboclaw_driver__srv__ResetEncoders_Request.
typedef struct ros2_roboclaw_driver__srv__ResetEncoders_Request__Sequence
{
  ros2_roboclaw_driver__srv__ResetEncoders_Request * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} ros2_roboclaw_driver__srv__ResetEncoders_Request__Sequence;


// Constants defined in the message

/// Struct defined in srv/ResetEncoders in the package ros2_roboclaw_driver.
typedef struct ros2_roboclaw_driver__srv__ResetEncoders_Response
{
  bool ok;
} ros2_roboclaw_driver__srv__ResetEncoders_Response;

// Struct for a sequence of ros2_roboclaw_driver__srv__ResetEncoders_Response.
typedef struct ros2_roboclaw_driver__srv__ResetEncoders_Response__Sequence
{
  ros2_roboclaw_driver__srv__ResetEncoders_Response * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} ros2_roboclaw_driver__srv__ResetEncoders_Response__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // ROS2_ROBOCLAW_DRIVER__SRV__DETAIL__RESET_ENCODERS__STRUCT_H_
