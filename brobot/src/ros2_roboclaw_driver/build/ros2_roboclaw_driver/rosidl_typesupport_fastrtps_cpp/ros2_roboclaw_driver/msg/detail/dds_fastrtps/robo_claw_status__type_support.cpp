// generated from rosidl_typesupport_fastrtps_cpp/resource/idl__type_support.cpp.em
// with input from ros2_roboclaw_driver:msg/RoboClawStatus.idl
// generated code does not contain a copyright notice
#include "ros2_roboclaw_driver/msg/detail/robo_claw_status__rosidl_typesupport_fastrtps_cpp.hpp"
#include "ros2_roboclaw_driver/msg/detail/robo_claw_status__struct.hpp"

#include <limits>
#include <stdexcept>
#include <string>
#include "rosidl_typesupport_cpp/message_type_support.hpp"
#include "rosidl_typesupport_fastrtps_cpp/identifier.hpp"
#include "rosidl_typesupport_fastrtps_cpp/message_type_support.h"
#include "rosidl_typesupport_fastrtps_cpp/message_type_support_decl.hpp"
#include "rosidl_typesupport_fastrtps_cpp/wstring_conversion.hpp"
#include "fastcdr/Cdr.h"


// forward declaration of message dependencies and their conversion functions

namespace ros2_roboclaw_driver
{

namespace msg
{

namespace typesupport_fastrtps_cpp
{

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_ros2_roboclaw_driver
cdr_serialize(
  const ros2_roboclaw_driver::msg::RoboClawStatus & ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  // Member: m1_p
  cdr << ros_message.m1_p;
  // Member: m1_i
  cdr << ros_message.m1_i;
  // Member: m1_d
  cdr << ros_message.m1_d;
  // Member: m1_qpps
  cdr << ros_message.m1_qpps;
  // Member: m1_current_speed
  cdr << ros_message.m1_current_speed;
  // Member: m1_motor_current
  cdr << ros_message.m1_motor_current;
  // Member: m1_encoder_value
  cdr << ros_message.m1_encoder_value;
  // Member: m1_encoder_status
  cdr << ros_message.m1_encoder_status;
  // Member: m2_p
  cdr << ros_message.m2_p;
  // Member: m2_i
  cdr << ros_message.m2_i;
  // Member: m2_d
  cdr << ros_message.m2_d;
  // Member: m2_qpps
  cdr << ros_message.m2_qpps;
  // Member: m2_current_speed
  cdr << ros_message.m2_current_speed;
  // Member: m2_motor_current
  cdr << ros_message.m2_motor_current;
  // Member: m2_encoder_value
  cdr << ros_message.m2_encoder_value;
  // Member: m2_encoder_status
  cdr << ros_message.m2_encoder_status;
  // Member: main_battery_voltage
  cdr << ros_message.main_battery_voltage;
  // Member: logic_battery_voltage
  cdr << ros_message.logic_battery_voltage;
  // Member: temperature
  cdr << ros_message.temperature;
  // Member: error_string
  cdr << ros_message.error_string;
  return true;
}

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_ros2_roboclaw_driver
cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  ros2_roboclaw_driver::msg::RoboClawStatus & ros_message)
{
  // Member: m1_p
  cdr >> ros_message.m1_p;

  // Member: m1_i
  cdr >> ros_message.m1_i;

  // Member: m1_d
  cdr >> ros_message.m1_d;

  // Member: m1_qpps
  cdr >> ros_message.m1_qpps;

  // Member: m1_current_speed
  cdr >> ros_message.m1_current_speed;

  // Member: m1_motor_current
  cdr >> ros_message.m1_motor_current;

  // Member: m1_encoder_value
  cdr >> ros_message.m1_encoder_value;

  // Member: m1_encoder_status
  cdr >> ros_message.m1_encoder_status;

  // Member: m2_p
  cdr >> ros_message.m2_p;

  // Member: m2_i
  cdr >> ros_message.m2_i;

  // Member: m2_d
  cdr >> ros_message.m2_d;

  // Member: m2_qpps
  cdr >> ros_message.m2_qpps;

  // Member: m2_current_speed
  cdr >> ros_message.m2_current_speed;

  // Member: m2_motor_current
  cdr >> ros_message.m2_motor_current;

  // Member: m2_encoder_value
  cdr >> ros_message.m2_encoder_value;

  // Member: m2_encoder_status
  cdr >> ros_message.m2_encoder_status;

  // Member: main_battery_voltage
  cdr >> ros_message.main_battery_voltage;

  // Member: logic_battery_voltage
  cdr >> ros_message.logic_battery_voltage;

  // Member: temperature
  cdr >> ros_message.temperature;

  // Member: error_string
  cdr >> ros_message.error_string;

  return true;
}

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_ros2_roboclaw_driver
get_serialized_size(
  const ros2_roboclaw_driver::msg::RoboClawStatus & ros_message,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // Member: m1_p
  {
    size_t item_size = sizeof(ros_message.m1_p);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: m1_i
  {
    size_t item_size = sizeof(ros_message.m1_i);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: m1_d
  {
    size_t item_size = sizeof(ros_message.m1_d);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: m1_qpps
  {
    size_t item_size = sizeof(ros_message.m1_qpps);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: m1_current_speed
  {
    size_t item_size = sizeof(ros_message.m1_current_speed);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: m1_motor_current
  {
    size_t item_size = sizeof(ros_message.m1_motor_current);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: m1_encoder_value
  {
    size_t item_size = sizeof(ros_message.m1_encoder_value);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: m1_encoder_status
  {
    size_t item_size = sizeof(ros_message.m1_encoder_status);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: m2_p
  {
    size_t item_size = sizeof(ros_message.m2_p);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: m2_i
  {
    size_t item_size = sizeof(ros_message.m2_i);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: m2_d
  {
    size_t item_size = sizeof(ros_message.m2_d);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: m2_qpps
  {
    size_t item_size = sizeof(ros_message.m2_qpps);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: m2_current_speed
  {
    size_t item_size = sizeof(ros_message.m2_current_speed);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: m2_motor_current
  {
    size_t item_size = sizeof(ros_message.m2_motor_current);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: m2_encoder_value
  {
    size_t item_size = sizeof(ros_message.m2_encoder_value);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: m2_encoder_status
  {
    size_t item_size = sizeof(ros_message.m2_encoder_status);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: main_battery_voltage
  {
    size_t item_size = sizeof(ros_message.main_battery_voltage);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: logic_battery_voltage
  {
    size_t item_size = sizeof(ros_message.logic_battery_voltage);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: temperature
  {
    size_t item_size = sizeof(ros_message.temperature);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: error_string
  current_alignment += padding +
    eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
    (ros_message.error_string.size() + 1);

  return current_alignment - initial_alignment;
}

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_ros2_roboclaw_driver
max_serialized_size_RoboClawStatus(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  full_bounded = true;
  is_plain = true;


  // Member: m1_p
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  // Member: m1_i
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  // Member: m1_d
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  // Member: m1_qpps
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  // Member: m1_current_speed
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  // Member: m1_motor_current
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  // Member: m1_encoder_value
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  // Member: m1_encoder_status
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint8_t);
  }

  // Member: m2_p
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  // Member: m2_i
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  // Member: m2_d
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  // Member: m2_qpps
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  // Member: m2_current_speed
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  // Member: m2_motor_current
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  // Member: m2_encoder_value
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  // Member: m2_encoder_status
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint8_t);
  }

  // Member: main_battery_voltage
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  // Member: logic_battery_voltage
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  // Member: temperature
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  // Member: error_string
  {
    size_t array_size = 1;

    full_bounded = false;
    is_plain = false;
    for (size_t index = 0; index < array_size; ++index) {
      current_alignment += padding +
        eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
        1;
    }
  }

  return current_alignment - initial_alignment;
}

static bool _RoboClawStatus__cdr_serialize(
  const void * untyped_ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  auto typed_message =
    static_cast<const ros2_roboclaw_driver::msg::RoboClawStatus *>(
    untyped_ros_message);
  return cdr_serialize(*typed_message, cdr);
}

static bool _RoboClawStatus__cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  void * untyped_ros_message)
{
  auto typed_message =
    static_cast<ros2_roboclaw_driver::msg::RoboClawStatus *>(
    untyped_ros_message);
  return cdr_deserialize(cdr, *typed_message);
}

static uint32_t _RoboClawStatus__get_serialized_size(
  const void * untyped_ros_message)
{
  auto typed_message =
    static_cast<const ros2_roboclaw_driver::msg::RoboClawStatus *>(
    untyped_ros_message);
  return static_cast<uint32_t>(get_serialized_size(*typed_message, 0));
}

static size_t _RoboClawStatus__max_serialized_size(char & bounds_info)
{
  bool full_bounded;
  bool is_plain;
  size_t ret_val;

  ret_val = max_serialized_size_RoboClawStatus(full_bounded, is_plain, 0);

  bounds_info =
    is_plain ? ROSIDL_TYPESUPPORT_FASTRTPS_PLAIN_TYPE :
    full_bounded ? ROSIDL_TYPESUPPORT_FASTRTPS_BOUNDED_TYPE : ROSIDL_TYPESUPPORT_FASTRTPS_UNBOUNDED_TYPE;
  return ret_val;
}

static message_type_support_callbacks_t _RoboClawStatus__callbacks = {
  "ros2_roboclaw_driver::msg",
  "RoboClawStatus",
  _RoboClawStatus__cdr_serialize,
  _RoboClawStatus__cdr_deserialize,
  _RoboClawStatus__get_serialized_size,
  _RoboClawStatus__max_serialized_size
};

static rosidl_message_type_support_t _RoboClawStatus__handle = {
  rosidl_typesupport_fastrtps_cpp::typesupport_identifier,
  &_RoboClawStatus__callbacks,
  get_message_typesupport_handle_function,
};

}  // namespace typesupport_fastrtps_cpp

}  // namespace msg

}  // namespace ros2_roboclaw_driver

namespace rosidl_typesupport_fastrtps_cpp
{

template<>
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_EXPORT_ros2_roboclaw_driver
const rosidl_message_type_support_t *
get_message_type_support_handle<ros2_roboclaw_driver::msg::RoboClawStatus>()
{
  return &ros2_roboclaw_driver::msg::typesupport_fastrtps_cpp::_RoboClawStatus__handle;
}

}  // namespace rosidl_typesupport_fastrtps_cpp

#ifdef __cplusplus
extern "C"
{
#endif

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, ros2_roboclaw_driver, msg, RoboClawStatus)() {
  return &ros2_roboclaw_driver::msg::typesupport_fastrtps_cpp::_RoboClawStatus__handle;
}

#ifdef __cplusplus
}
#endif
