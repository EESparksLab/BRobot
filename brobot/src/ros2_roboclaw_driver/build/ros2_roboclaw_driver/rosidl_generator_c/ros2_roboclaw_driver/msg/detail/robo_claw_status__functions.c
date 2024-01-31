// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from ros2_roboclaw_driver:msg/RoboClawStatus.idl
// generated code does not contain a copyright notice
#include "ros2_roboclaw_driver/msg/detail/robo_claw_status__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


// Include directives for member types
// Member `error_string`
#include "rosidl_runtime_c/string_functions.h"

bool
ros2_roboclaw_driver__msg__RoboClawStatus__init(ros2_roboclaw_driver__msg__RoboClawStatus * msg)
{
  if (!msg) {
    return false;
  }
  // m1_p
  // m1_i
  // m1_d
  // m1_qpps
  // m1_current_speed
  // m1_motor_current
  // m1_encoder_value
  // m1_encoder_status
  // m2_p
  // m2_i
  // m2_d
  // m2_qpps
  // m2_current_speed
  // m2_motor_current
  // m2_encoder_value
  // m2_encoder_status
  // main_battery_voltage
  // logic_battery_voltage
  // temperature
  // error_string
  if (!rosidl_runtime_c__String__init(&msg->error_string)) {
    ros2_roboclaw_driver__msg__RoboClawStatus__fini(msg);
    return false;
  }
  return true;
}

void
ros2_roboclaw_driver__msg__RoboClawStatus__fini(ros2_roboclaw_driver__msg__RoboClawStatus * msg)
{
  if (!msg) {
    return;
  }
  // m1_p
  // m1_i
  // m1_d
  // m1_qpps
  // m1_current_speed
  // m1_motor_current
  // m1_encoder_value
  // m1_encoder_status
  // m2_p
  // m2_i
  // m2_d
  // m2_qpps
  // m2_current_speed
  // m2_motor_current
  // m2_encoder_value
  // m2_encoder_status
  // main_battery_voltage
  // logic_battery_voltage
  // temperature
  // error_string
  rosidl_runtime_c__String__fini(&msg->error_string);
}

bool
ros2_roboclaw_driver__msg__RoboClawStatus__are_equal(const ros2_roboclaw_driver__msg__RoboClawStatus * lhs, const ros2_roboclaw_driver__msg__RoboClawStatus * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // m1_p
  if (lhs->m1_p != rhs->m1_p) {
    return false;
  }
  // m1_i
  if (lhs->m1_i != rhs->m1_i) {
    return false;
  }
  // m1_d
  if (lhs->m1_d != rhs->m1_d) {
    return false;
  }
  // m1_qpps
  if (lhs->m1_qpps != rhs->m1_qpps) {
    return false;
  }
  // m1_current_speed
  if (lhs->m1_current_speed != rhs->m1_current_speed) {
    return false;
  }
  // m1_motor_current
  if (lhs->m1_motor_current != rhs->m1_motor_current) {
    return false;
  }
  // m1_encoder_value
  if (lhs->m1_encoder_value != rhs->m1_encoder_value) {
    return false;
  }
  // m1_encoder_status
  if (lhs->m1_encoder_status != rhs->m1_encoder_status) {
    return false;
  }
  // m2_p
  if (lhs->m2_p != rhs->m2_p) {
    return false;
  }
  // m2_i
  if (lhs->m2_i != rhs->m2_i) {
    return false;
  }
  // m2_d
  if (lhs->m2_d != rhs->m2_d) {
    return false;
  }
  // m2_qpps
  if (lhs->m2_qpps != rhs->m2_qpps) {
    return false;
  }
  // m2_current_speed
  if (lhs->m2_current_speed != rhs->m2_current_speed) {
    return false;
  }
  // m2_motor_current
  if (lhs->m2_motor_current != rhs->m2_motor_current) {
    return false;
  }
  // m2_encoder_value
  if (lhs->m2_encoder_value != rhs->m2_encoder_value) {
    return false;
  }
  // m2_encoder_status
  if (lhs->m2_encoder_status != rhs->m2_encoder_status) {
    return false;
  }
  // main_battery_voltage
  if (lhs->main_battery_voltage != rhs->main_battery_voltage) {
    return false;
  }
  // logic_battery_voltage
  if (lhs->logic_battery_voltage != rhs->logic_battery_voltage) {
    return false;
  }
  // temperature
  if (lhs->temperature != rhs->temperature) {
    return false;
  }
  // error_string
  if (!rosidl_runtime_c__String__are_equal(
      &(lhs->error_string), &(rhs->error_string)))
  {
    return false;
  }
  return true;
}

bool
ros2_roboclaw_driver__msg__RoboClawStatus__copy(
  const ros2_roboclaw_driver__msg__RoboClawStatus * input,
  ros2_roboclaw_driver__msg__RoboClawStatus * output)
{
  if (!input || !output) {
    return false;
  }
  // m1_p
  output->m1_p = input->m1_p;
  // m1_i
  output->m1_i = input->m1_i;
  // m1_d
  output->m1_d = input->m1_d;
  // m1_qpps
  output->m1_qpps = input->m1_qpps;
  // m1_current_speed
  output->m1_current_speed = input->m1_current_speed;
  // m1_motor_current
  output->m1_motor_current = input->m1_motor_current;
  // m1_encoder_value
  output->m1_encoder_value = input->m1_encoder_value;
  // m1_encoder_status
  output->m1_encoder_status = input->m1_encoder_status;
  // m2_p
  output->m2_p = input->m2_p;
  // m2_i
  output->m2_i = input->m2_i;
  // m2_d
  output->m2_d = input->m2_d;
  // m2_qpps
  output->m2_qpps = input->m2_qpps;
  // m2_current_speed
  output->m2_current_speed = input->m2_current_speed;
  // m2_motor_current
  output->m2_motor_current = input->m2_motor_current;
  // m2_encoder_value
  output->m2_encoder_value = input->m2_encoder_value;
  // m2_encoder_status
  output->m2_encoder_status = input->m2_encoder_status;
  // main_battery_voltage
  output->main_battery_voltage = input->main_battery_voltage;
  // logic_battery_voltage
  output->logic_battery_voltage = input->logic_battery_voltage;
  // temperature
  output->temperature = input->temperature;
  // error_string
  if (!rosidl_runtime_c__String__copy(
      &(input->error_string), &(output->error_string)))
  {
    return false;
  }
  return true;
}

ros2_roboclaw_driver__msg__RoboClawStatus *
ros2_roboclaw_driver__msg__RoboClawStatus__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  ros2_roboclaw_driver__msg__RoboClawStatus * msg = (ros2_roboclaw_driver__msg__RoboClawStatus *)allocator.allocate(sizeof(ros2_roboclaw_driver__msg__RoboClawStatus), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(ros2_roboclaw_driver__msg__RoboClawStatus));
  bool success = ros2_roboclaw_driver__msg__RoboClawStatus__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
ros2_roboclaw_driver__msg__RoboClawStatus__destroy(ros2_roboclaw_driver__msg__RoboClawStatus * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    ros2_roboclaw_driver__msg__RoboClawStatus__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
ros2_roboclaw_driver__msg__RoboClawStatus__Sequence__init(ros2_roboclaw_driver__msg__RoboClawStatus__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  ros2_roboclaw_driver__msg__RoboClawStatus * data = NULL;

  if (size) {
    data = (ros2_roboclaw_driver__msg__RoboClawStatus *)allocator.zero_allocate(size, sizeof(ros2_roboclaw_driver__msg__RoboClawStatus), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = ros2_roboclaw_driver__msg__RoboClawStatus__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        ros2_roboclaw_driver__msg__RoboClawStatus__fini(&data[i - 1]);
      }
      allocator.deallocate(data, allocator.state);
      return false;
    }
  }
  array->data = data;
  array->size = size;
  array->capacity = size;
  return true;
}

void
ros2_roboclaw_driver__msg__RoboClawStatus__Sequence__fini(ros2_roboclaw_driver__msg__RoboClawStatus__Sequence * array)
{
  if (!array) {
    return;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();

  if (array->data) {
    // ensure that data and capacity values are consistent
    assert(array->capacity > 0);
    // finalize all array elements
    for (size_t i = 0; i < array->capacity; ++i) {
      ros2_roboclaw_driver__msg__RoboClawStatus__fini(&array->data[i]);
    }
    allocator.deallocate(array->data, allocator.state);
    array->data = NULL;
    array->size = 0;
    array->capacity = 0;
  } else {
    // ensure that data, size, and capacity values are consistent
    assert(0 == array->size);
    assert(0 == array->capacity);
  }
}

ros2_roboclaw_driver__msg__RoboClawStatus__Sequence *
ros2_roboclaw_driver__msg__RoboClawStatus__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  ros2_roboclaw_driver__msg__RoboClawStatus__Sequence * array = (ros2_roboclaw_driver__msg__RoboClawStatus__Sequence *)allocator.allocate(sizeof(ros2_roboclaw_driver__msg__RoboClawStatus__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = ros2_roboclaw_driver__msg__RoboClawStatus__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
ros2_roboclaw_driver__msg__RoboClawStatus__Sequence__destroy(ros2_roboclaw_driver__msg__RoboClawStatus__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    ros2_roboclaw_driver__msg__RoboClawStatus__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
ros2_roboclaw_driver__msg__RoboClawStatus__Sequence__are_equal(const ros2_roboclaw_driver__msg__RoboClawStatus__Sequence * lhs, const ros2_roboclaw_driver__msg__RoboClawStatus__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!ros2_roboclaw_driver__msg__RoboClawStatus__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
ros2_roboclaw_driver__msg__RoboClawStatus__Sequence__copy(
  const ros2_roboclaw_driver__msg__RoboClawStatus__Sequence * input,
  ros2_roboclaw_driver__msg__RoboClawStatus__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(ros2_roboclaw_driver__msg__RoboClawStatus);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    ros2_roboclaw_driver__msg__RoboClawStatus * data =
      (ros2_roboclaw_driver__msg__RoboClawStatus *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!ros2_roboclaw_driver__msg__RoboClawStatus__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          ros2_roboclaw_driver__msg__RoboClawStatus__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!ros2_roboclaw_driver__msg__RoboClawStatus__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
