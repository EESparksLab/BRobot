// generated from rosidl_typesupport_fastrtps_c/resource/idl__type_support_c.cpp.em
// with input from ros2_roboclaw_driver:msg/RoboClawStatus.idl
// generated code does not contain a copyright notice
#include "ros2_roboclaw_driver/msg/detail/robo_claw_status__rosidl_typesupport_fastrtps_c.h"


#include <cassert>
#include <limits>
#include <string>
#include "rosidl_typesupport_fastrtps_c/identifier.h"
#include "rosidl_typesupport_fastrtps_c/wstring_conversion.hpp"
#include "rosidl_typesupport_fastrtps_cpp/message_type_support.h"
#include "ros2_roboclaw_driver/msg/rosidl_typesupport_fastrtps_c__visibility_control.h"
#include "ros2_roboclaw_driver/msg/detail/robo_claw_status__struct.h"
#include "ros2_roboclaw_driver/msg/detail/robo_claw_status__functions.h"
#include "fastcdr/Cdr.h"

#ifndef _WIN32
# pragma GCC diagnostic push
# pragma GCC diagnostic ignored "-Wunused-parameter"
# ifdef __clang__
#  pragma clang diagnostic ignored "-Wdeprecated-register"
#  pragma clang diagnostic ignored "-Wreturn-type-c-linkage"
# endif
#endif
#ifndef _WIN32
# pragma GCC diagnostic pop
#endif

// includes and forward declarations of message dependencies and their conversion functions

#if defined(__cplusplus)
extern "C"
{
#endif

#include "rosidl_runtime_c/string.h"  // error_string
#include "rosidl_runtime_c/string_functions.h"  // error_string

// forward declare type support functions


using _RoboClawStatus__ros_msg_type = ros2_roboclaw_driver__msg__RoboClawStatus;

static bool _RoboClawStatus__cdr_serialize(
  const void * untyped_ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  const _RoboClawStatus__ros_msg_type * ros_message = static_cast<const _RoboClawStatus__ros_msg_type *>(untyped_ros_message);
  // Field name: m1_p
  {
    cdr << ros_message->m1_p;
  }

  // Field name: m1_i
  {
    cdr << ros_message->m1_i;
  }

  // Field name: m1_d
  {
    cdr << ros_message->m1_d;
  }

  // Field name: m1_qpps
  {
    cdr << ros_message->m1_qpps;
  }

  // Field name: m1_current_speed
  {
    cdr << ros_message->m1_current_speed;
  }

  // Field name: m1_motor_current
  {
    cdr << ros_message->m1_motor_current;
  }

  // Field name: m1_encoder_value
  {
    cdr << ros_message->m1_encoder_value;
  }

  // Field name: m1_encoder_status
  {
    cdr << ros_message->m1_encoder_status;
  }

  // Field name: m2_p
  {
    cdr << ros_message->m2_p;
  }

  // Field name: m2_i
  {
    cdr << ros_message->m2_i;
  }

  // Field name: m2_d
  {
    cdr << ros_message->m2_d;
  }

  // Field name: m2_qpps
  {
    cdr << ros_message->m2_qpps;
  }

  // Field name: m2_current_speed
  {
    cdr << ros_message->m2_current_speed;
  }

  // Field name: m2_motor_current
  {
    cdr << ros_message->m2_motor_current;
  }

  // Field name: m2_encoder_value
  {
    cdr << ros_message->m2_encoder_value;
  }

  // Field name: m2_encoder_status
  {
    cdr << ros_message->m2_encoder_status;
  }

  // Field name: main_battery_voltage
  {
    cdr << ros_message->main_battery_voltage;
  }

  // Field name: logic_battery_voltage
  {
    cdr << ros_message->logic_battery_voltage;
  }

  // Field name: temperature
  {
    cdr << ros_message->temperature;
  }

  // Field name: error_string
  {
    const rosidl_runtime_c__String * str = &ros_message->error_string;
    if (str->capacity == 0 || str->capacity <= str->size) {
      fprintf(stderr, "string capacity not greater than size\n");
      return false;
    }
    if (str->data[str->size] != '\0') {
      fprintf(stderr, "string not null-terminated\n");
      return false;
    }
    cdr << str->data;
  }

  return true;
}

static bool _RoboClawStatus__cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  void * untyped_ros_message)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  _RoboClawStatus__ros_msg_type * ros_message = static_cast<_RoboClawStatus__ros_msg_type *>(untyped_ros_message);
  // Field name: m1_p
  {
    cdr >> ros_message->m1_p;
  }

  // Field name: m1_i
  {
    cdr >> ros_message->m1_i;
  }

  // Field name: m1_d
  {
    cdr >> ros_message->m1_d;
  }

  // Field name: m1_qpps
  {
    cdr >> ros_message->m1_qpps;
  }

  // Field name: m1_current_speed
  {
    cdr >> ros_message->m1_current_speed;
  }

  // Field name: m1_motor_current
  {
    cdr >> ros_message->m1_motor_current;
  }

  // Field name: m1_encoder_value
  {
    cdr >> ros_message->m1_encoder_value;
  }

  // Field name: m1_encoder_status
  {
    cdr >> ros_message->m1_encoder_status;
  }

  // Field name: m2_p
  {
    cdr >> ros_message->m2_p;
  }

  // Field name: m2_i
  {
    cdr >> ros_message->m2_i;
  }

  // Field name: m2_d
  {
    cdr >> ros_message->m2_d;
  }

  // Field name: m2_qpps
  {
    cdr >> ros_message->m2_qpps;
  }

  // Field name: m2_current_speed
  {
    cdr >> ros_message->m2_current_speed;
  }

  // Field name: m2_motor_current
  {
    cdr >> ros_message->m2_motor_current;
  }

  // Field name: m2_encoder_value
  {
    cdr >> ros_message->m2_encoder_value;
  }

  // Field name: m2_encoder_status
  {
    cdr >> ros_message->m2_encoder_status;
  }

  // Field name: main_battery_voltage
  {
    cdr >> ros_message->main_battery_voltage;
  }

  // Field name: logic_battery_voltage
  {
    cdr >> ros_message->logic_battery_voltage;
  }

  // Field name: temperature
  {
    cdr >> ros_message->temperature;
  }

  // Field name: error_string
  {
    std::string tmp;
    cdr >> tmp;
    if (!ros_message->error_string.data) {
      rosidl_runtime_c__String__init(&ros_message->error_string);
    }
    bool succeeded = rosidl_runtime_c__String__assign(
      &ros_message->error_string,
      tmp.c_str());
    if (!succeeded) {
      fprintf(stderr, "failed to assign string into field 'error_string'\n");
      return false;
    }
  }

  return true;
}  // NOLINT(readability/fn_size)

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_ros2_roboclaw_driver
size_t get_serialized_size_ros2_roboclaw_driver__msg__RoboClawStatus(
  const void * untyped_ros_message,
  size_t current_alignment)
{
  const _RoboClawStatus__ros_msg_type * ros_message = static_cast<const _RoboClawStatus__ros_msg_type *>(untyped_ros_message);
  (void)ros_message;
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // field.name m1_p
  {
    size_t item_size = sizeof(ros_message->m1_p);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name m1_i
  {
    size_t item_size = sizeof(ros_message->m1_i);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name m1_d
  {
    size_t item_size = sizeof(ros_message->m1_d);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name m1_qpps
  {
    size_t item_size = sizeof(ros_message->m1_qpps);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name m1_current_speed
  {
    size_t item_size = sizeof(ros_message->m1_current_speed);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name m1_motor_current
  {
    size_t item_size = sizeof(ros_message->m1_motor_current);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name m1_encoder_value
  {
    size_t item_size = sizeof(ros_message->m1_encoder_value);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name m1_encoder_status
  {
    size_t item_size = sizeof(ros_message->m1_encoder_status);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name m2_p
  {
    size_t item_size = sizeof(ros_message->m2_p);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name m2_i
  {
    size_t item_size = sizeof(ros_message->m2_i);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name m2_d
  {
    size_t item_size = sizeof(ros_message->m2_d);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name m2_qpps
  {
    size_t item_size = sizeof(ros_message->m2_qpps);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name m2_current_speed
  {
    size_t item_size = sizeof(ros_message->m2_current_speed);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name m2_motor_current
  {
    size_t item_size = sizeof(ros_message->m2_motor_current);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name m2_encoder_value
  {
    size_t item_size = sizeof(ros_message->m2_encoder_value);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name m2_encoder_status
  {
    size_t item_size = sizeof(ros_message->m2_encoder_status);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name main_battery_voltage
  {
    size_t item_size = sizeof(ros_message->main_battery_voltage);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name logic_battery_voltage
  {
    size_t item_size = sizeof(ros_message->logic_battery_voltage);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name temperature
  {
    size_t item_size = sizeof(ros_message->temperature);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name error_string
  current_alignment += padding +
    eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
    (ros_message->error_string.size + 1);

  return current_alignment - initial_alignment;
}

static uint32_t _RoboClawStatus__get_serialized_size(const void * untyped_ros_message)
{
  return static_cast<uint32_t>(
    get_serialized_size_ros2_roboclaw_driver__msg__RoboClawStatus(
      untyped_ros_message, 0));
}

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_ros2_roboclaw_driver
size_t max_serialized_size_ros2_roboclaw_driver__msg__RoboClawStatus(
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

  // member: m1_p
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }
  // member: m1_i
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }
  // member: m1_d
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }
  // member: m1_qpps
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }
  // member: m1_current_speed
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }
  // member: m1_motor_current
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }
  // member: m1_encoder_value
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }
  // member: m1_encoder_status
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint8_t);
  }
  // member: m2_p
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }
  // member: m2_i
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }
  // member: m2_d
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }
  // member: m2_qpps
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }
  // member: m2_current_speed
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }
  // member: m2_motor_current
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }
  // member: m2_encoder_value
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }
  // member: m2_encoder_status
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint8_t);
  }
  // member: main_battery_voltage
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }
  // member: logic_battery_voltage
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }
  // member: temperature
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }
  // member: error_string
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

static size_t _RoboClawStatus__max_serialized_size(char & bounds_info)
{
  bool full_bounded;
  bool is_plain;
  size_t ret_val;

  ret_val = max_serialized_size_ros2_roboclaw_driver__msg__RoboClawStatus(
    full_bounded, is_plain, 0);

  bounds_info =
    is_plain ? ROSIDL_TYPESUPPORT_FASTRTPS_PLAIN_TYPE :
    full_bounded ? ROSIDL_TYPESUPPORT_FASTRTPS_BOUNDED_TYPE : ROSIDL_TYPESUPPORT_FASTRTPS_UNBOUNDED_TYPE;
  return ret_val;
}


static message_type_support_callbacks_t __callbacks_RoboClawStatus = {
  "ros2_roboclaw_driver::msg",
  "RoboClawStatus",
  _RoboClawStatus__cdr_serialize,
  _RoboClawStatus__cdr_deserialize,
  _RoboClawStatus__get_serialized_size,
  _RoboClawStatus__max_serialized_size
};

static rosidl_message_type_support_t _RoboClawStatus__type_support = {
  rosidl_typesupport_fastrtps_c__identifier,
  &__callbacks_RoboClawStatus,
  get_message_typesupport_handle_function,
};

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, ros2_roboclaw_driver, msg, RoboClawStatus)() {
  return &_RoboClawStatus__type_support;
}

#if defined(__cplusplus)
}
#endif
