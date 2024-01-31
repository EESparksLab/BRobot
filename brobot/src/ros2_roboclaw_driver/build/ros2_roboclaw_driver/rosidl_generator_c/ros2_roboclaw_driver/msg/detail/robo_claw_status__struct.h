// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from ros2_roboclaw_driver:msg/RoboClawStatus.idl
// generated code does not contain a copyright notice

#ifndef ROS2_ROBOCLAW_DRIVER__MSG__DETAIL__ROBO_CLAW_STATUS__STRUCT_H_
#define ROS2_ROBOCLAW_DRIVER__MSG__DETAIL__ROBO_CLAW_STATUS__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Include directives for member types
// Member 'error_string'
#include "rosidl_runtime_c/string.h"

/// Struct defined in msg/RoboClawStatus in the package ros2_roboclaw_driver.
typedef struct ros2_roboclaw_driver__msg__RoboClawStatus
{
  float m1_p;
  float m1_i;
  float m1_d;
  uint32_t m1_qpps;
  int32_t m1_current_speed;
  float m1_motor_current;
  uint32_t m1_encoder_value;
  uint8_t m1_encoder_status;
  float m2_p;
  float m2_i;
  float m2_d;
  uint32_t m2_qpps;
  int32_t m2_current_speed;
  float m2_motor_current;
  uint32_t m2_encoder_value;
  uint8_t m2_encoder_status;
  float main_battery_voltage;
  float logic_battery_voltage;
  float temperature;
  rosidl_runtime_c__String error_string;
} ros2_roboclaw_driver__msg__RoboClawStatus;

// Struct for a sequence of ros2_roboclaw_driver__msg__RoboClawStatus.
typedef struct ros2_roboclaw_driver__msg__RoboClawStatus__Sequence
{
  ros2_roboclaw_driver__msg__RoboClawStatus * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} ros2_roboclaw_driver__msg__RoboClawStatus__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // ROS2_ROBOCLAW_DRIVER__MSG__DETAIL__ROBO_CLAW_STATUS__STRUCT_H_
