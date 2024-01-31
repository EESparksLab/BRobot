// generated from rosidl_generator_py/resource/_idl_support.c.em
// with input from ros2_roboclaw_driver:msg/RoboClawStatus.idl
// generated code does not contain a copyright notice
#define NPY_NO_DEPRECATED_API NPY_1_7_API_VERSION
#include <Python.h>
#include <stdbool.h>
#ifndef _WIN32
# pragma GCC diagnostic push
# pragma GCC diagnostic ignored "-Wunused-function"
#endif
#include "numpy/ndarrayobject.h"
#ifndef _WIN32
# pragma GCC diagnostic pop
#endif
#include "rosidl_runtime_c/visibility_control.h"
#include "ros2_roboclaw_driver/msg/detail/robo_claw_status__struct.h"
#include "ros2_roboclaw_driver/msg/detail/robo_claw_status__functions.h"

#include "rosidl_runtime_c/string.h"
#include "rosidl_runtime_c/string_functions.h"


ROSIDL_GENERATOR_C_EXPORT
bool ros2_roboclaw_driver__msg__robo_claw_status__convert_from_py(PyObject * _pymsg, void * _ros_message)
{
  // check that the passed message is of the expected Python class
  {
    char full_classname_dest[58];
    {
      char * class_name = NULL;
      char * module_name = NULL;
      {
        PyObject * class_attr = PyObject_GetAttrString(_pymsg, "__class__");
        if (class_attr) {
          PyObject * name_attr = PyObject_GetAttrString(class_attr, "__name__");
          if (name_attr) {
            class_name = (char *)PyUnicode_1BYTE_DATA(name_attr);
            Py_DECREF(name_attr);
          }
          PyObject * module_attr = PyObject_GetAttrString(class_attr, "__module__");
          if (module_attr) {
            module_name = (char *)PyUnicode_1BYTE_DATA(module_attr);
            Py_DECREF(module_attr);
          }
          Py_DECREF(class_attr);
        }
      }
      if (!class_name || !module_name) {
        return false;
      }
      snprintf(full_classname_dest, sizeof(full_classname_dest), "%s.%s", module_name, class_name);
    }
    assert(strncmp("ros2_roboclaw_driver.msg._robo_claw_status.RoboClawStatus", full_classname_dest, 57) == 0);
  }
  ros2_roboclaw_driver__msg__RoboClawStatus * ros_message = _ros_message;
  {  // m1_p
    PyObject * field = PyObject_GetAttrString(_pymsg, "m1_p");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->m1_p = (float)PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // m1_i
    PyObject * field = PyObject_GetAttrString(_pymsg, "m1_i");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->m1_i = (float)PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // m1_d
    PyObject * field = PyObject_GetAttrString(_pymsg, "m1_d");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->m1_d = (float)PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // m1_qpps
    PyObject * field = PyObject_GetAttrString(_pymsg, "m1_qpps");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->m1_qpps = PyLong_AsUnsignedLong(field);
    Py_DECREF(field);
  }
  {  // m1_current_speed
    PyObject * field = PyObject_GetAttrString(_pymsg, "m1_current_speed");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->m1_current_speed = (int32_t)PyLong_AsLong(field);
    Py_DECREF(field);
  }
  {  // m1_motor_current
    PyObject * field = PyObject_GetAttrString(_pymsg, "m1_motor_current");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->m1_motor_current = (float)PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // m1_encoder_value
    PyObject * field = PyObject_GetAttrString(_pymsg, "m1_encoder_value");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->m1_encoder_value = PyLong_AsUnsignedLong(field);
    Py_DECREF(field);
  }
  {  // m1_encoder_status
    PyObject * field = PyObject_GetAttrString(_pymsg, "m1_encoder_status");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->m1_encoder_status = (uint8_t)PyLong_AsUnsignedLong(field);
    Py_DECREF(field);
  }
  {  // m2_p
    PyObject * field = PyObject_GetAttrString(_pymsg, "m2_p");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->m2_p = (float)PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // m2_i
    PyObject * field = PyObject_GetAttrString(_pymsg, "m2_i");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->m2_i = (float)PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // m2_d
    PyObject * field = PyObject_GetAttrString(_pymsg, "m2_d");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->m2_d = (float)PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // m2_qpps
    PyObject * field = PyObject_GetAttrString(_pymsg, "m2_qpps");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->m2_qpps = PyLong_AsUnsignedLong(field);
    Py_DECREF(field);
  }
  {  // m2_current_speed
    PyObject * field = PyObject_GetAttrString(_pymsg, "m2_current_speed");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->m2_current_speed = (int32_t)PyLong_AsLong(field);
    Py_DECREF(field);
  }
  {  // m2_motor_current
    PyObject * field = PyObject_GetAttrString(_pymsg, "m2_motor_current");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->m2_motor_current = (float)PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // m2_encoder_value
    PyObject * field = PyObject_GetAttrString(_pymsg, "m2_encoder_value");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->m2_encoder_value = PyLong_AsUnsignedLong(field);
    Py_DECREF(field);
  }
  {  // m2_encoder_status
    PyObject * field = PyObject_GetAttrString(_pymsg, "m2_encoder_status");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->m2_encoder_status = (uint8_t)PyLong_AsUnsignedLong(field);
    Py_DECREF(field);
  }
  {  // main_battery_voltage
    PyObject * field = PyObject_GetAttrString(_pymsg, "main_battery_voltage");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->main_battery_voltage = (float)PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // logic_battery_voltage
    PyObject * field = PyObject_GetAttrString(_pymsg, "logic_battery_voltage");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->logic_battery_voltage = (float)PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // temperature
    PyObject * field = PyObject_GetAttrString(_pymsg, "temperature");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->temperature = (float)PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // error_string
    PyObject * field = PyObject_GetAttrString(_pymsg, "error_string");
    if (!field) {
      return false;
    }
    assert(PyUnicode_Check(field));
    PyObject * encoded_field = PyUnicode_AsUTF8String(field);
    if (!encoded_field) {
      Py_DECREF(field);
      return false;
    }
    rosidl_runtime_c__String__assign(&ros_message->error_string, PyBytes_AS_STRING(encoded_field));
    Py_DECREF(encoded_field);
    Py_DECREF(field);
  }

  return true;
}

ROSIDL_GENERATOR_C_EXPORT
PyObject * ros2_roboclaw_driver__msg__robo_claw_status__convert_to_py(void * raw_ros_message)
{
  /* NOTE(esteve): Call constructor of RoboClawStatus */
  PyObject * _pymessage = NULL;
  {
    PyObject * pymessage_module = PyImport_ImportModule("ros2_roboclaw_driver.msg._robo_claw_status");
    assert(pymessage_module);
    PyObject * pymessage_class = PyObject_GetAttrString(pymessage_module, "RoboClawStatus");
    assert(pymessage_class);
    Py_DECREF(pymessage_module);
    _pymessage = PyObject_CallObject(pymessage_class, NULL);
    Py_DECREF(pymessage_class);
    if (!_pymessage) {
      return NULL;
    }
  }
  ros2_roboclaw_driver__msg__RoboClawStatus * ros_message = (ros2_roboclaw_driver__msg__RoboClawStatus *)raw_ros_message;
  {  // m1_p
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->m1_p);
    {
      int rc = PyObject_SetAttrString(_pymessage, "m1_p", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // m1_i
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->m1_i);
    {
      int rc = PyObject_SetAttrString(_pymessage, "m1_i", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // m1_d
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->m1_d);
    {
      int rc = PyObject_SetAttrString(_pymessage, "m1_d", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // m1_qpps
    PyObject * field = NULL;
    field = PyLong_FromUnsignedLong(ros_message->m1_qpps);
    {
      int rc = PyObject_SetAttrString(_pymessage, "m1_qpps", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // m1_current_speed
    PyObject * field = NULL;
    field = PyLong_FromLong(ros_message->m1_current_speed);
    {
      int rc = PyObject_SetAttrString(_pymessage, "m1_current_speed", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // m1_motor_current
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->m1_motor_current);
    {
      int rc = PyObject_SetAttrString(_pymessage, "m1_motor_current", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // m1_encoder_value
    PyObject * field = NULL;
    field = PyLong_FromUnsignedLong(ros_message->m1_encoder_value);
    {
      int rc = PyObject_SetAttrString(_pymessage, "m1_encoder_value", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // m1_encoder_status
    PyObject * field = NULL;
    field = PyLong_FromUnsignedLong(ros_message->m1_encoder_status);
    {
      int rc = PyObject_SetAttrString(_pymessage, "m1_encoder_status", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // m2_p
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->m2_p);
    {
      int rc = PyObject_SetAttrString(_pymessage, "m2_p", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // m2_i
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->m2_i);
    {
      int rc = PyObject_SetAttrString(_pymessage, "m2_i", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // m2_d
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->m2_d);
    {
      int rc = PyObject_SetAttrString(_pymessage, "m2_d", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // m2_qpps
    PyObject * field = NULL;
    field = PyLong_FromUnsignedLong(ros_message->m2_qpps);
    {
      int rc = PyObject_SetAttrString(_pymessage, "m2_qpps", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // m2_current_speed
    PyObject * field = NULL;
    field = PyLong_FromLong(ros_message->m2_current_speed);
    {
      int rc = PyObject_SetAttrString(_pymessage, "m2_current_speed", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // m2_motor_current
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->m2_motor_current);
    {
      int rc = PyObject_SetAttrString(_pymessage, "m2_motor_current", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // m2_encoder_value
    PyObject * field = NULL;
    field = PyLong_FromUnsignedLong(ros_message->m2_encoder_value);
    {
      int rc = PyObject_SetAttrString(_pymessage, "m2_encoder_value", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // m2_encoder_status
    PyObject * field = NULL;
    field = PyLong_FromUnsignedLong(ros_message->m2_encoder_status);
    {
      int rc = PyObject_SetAttrString(_pymessage, "m2_encoder_status", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // main_battery_voltage
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->main_battery_voltage);
    {
      int rc = PyObject_SetAttrString(_pymessage, "main_battery_voltage", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // logic_battery_voltage
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->logic_battery_voltage);
    {
      int rc = PyObject_SetAttrString(_pymessage, "logic_battery_voltage", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // temperature
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->temperature);
    {
      int rc = PyObject_SetAttrString(_pymessage, "temperature", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // error_string
    PyObject * field = NULL;
    field = PyUnicode_DecodeUTF8(
      ros_message->error_string.data,
      strlen(ros_message->error_string.data),
      "replace");
    if (!field) {
      return NULL;
    }
    {
      int rc = PyObject_SetAttrString(_pymessage, "error_string", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }

  // ownership of _pymessage is transferred to the caller
  return _pymessage;
}
