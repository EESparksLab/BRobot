# generated from rosidl_generator_py/resource/_idl.py.em
# with input from ros2_roboclaw_driver:msg/RoboClawStatus.idl
# generated code does not contain a copyright notice


# Import statements for member types

import builtins  # noqa: E402, I100

import math  # noqa: E402, I100

import rosidl_parser.definition  # noqa: E402, I100


class Metaclass_RoboClawStatus(type):
    """Metaclass of message 'RoboClawStatus'."""

    _CREATE_ROS_MESSAGE = None
    _CONVERT_FROM_PY = None
    _CONVERT_TO_PY = None
    _DESTROY_ROS_MESSAGE = None
    _TYPE_SUPPORT = None

    __constants = {
    }

    @classmethod
    def __import_type_support__(cls):
        try:
            from rosidl_generator_py import import_type_support
            module = import_type_support('ros2_roboclaw_driver')
        except ImportError:
            import logging
            import traceback
            logger = logging.getLogger(
                'ros2_roboclaw_driver.msg.RoboClawStatus')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__msg__robo_claw_status
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__msg__robo_claw_status
            cls._CONVERT_TO_PY = module.convert_to_py_msg__msg__robo_claw_status
            cls._TYPE_SUPPORT = module.type_support_msg__msg__robo_claw_status
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__msg__robo_claw_status

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
        }


class RoboClawStatus(metaclass=Metaclass_RoboClawStatus):
    """Message class 'RoboClawStatus'."""

    __slots__ = [
        '_m1_p',
        '_m1_i',
        '_m1_d',
        '_m1_qpps',
        '_m1_current_speed',
        '_m1_motor_current',
        '_m1_encoder_value',
        '_m1_encoder_status',
        '_m2_p',
        '_m2_i',
        '_m2_d',
        '_m2_qpps',
        '_m2_current_speed',
        '_m2_motor_current',
        '_m2_encoder_value',
        '_m2_encoder_status',
        '_main_battery_voltage',
        '_logic_battery_voltage',
        '_temperature',
        '_error_string',
    ]

    _fields_and_field_types = {
        'm1_p': 'float',
        'm1_i': 'float',
        'm1_d': 'float',
        'm1_qpps': 'uint32',
        'm1_current_speed': 'int32',
        'm1_motor_current': 'float',
        'm1_encoder_value': 'uint32',
        'm1_encoder_status': 'uint8',
        'm2_p': 'float',
        'm2_i': 'float',
        'm2_d': 'float',
        'm2_qpps': 'uint32',
        'm2_current_speed': 'int32',
        'm2_motor_current': 'float',
        'm2_encoder_value': 'uint32',
        'm2_encoder_status': 'uint8',
        'main_battery_voltage': 'float',
        'logic_battery_voltage': 'float',
        'temperature': 'float',
        'error_string': 'string',
    }

    SLOT_TYPES = (
        rosidl_parser.definition.BasicType('float'),  # noqa: E501
        rosidl_parser.definition.BasicType('float'),  # noqa: E501
        rosidl_parser.definition.BasicType('float'),  # noqa: E501
        rosidl_parser.definition.BasicType('uint32'),  # noqa: E501
        rosidl_parser.definition.BasicType('int32'),  # noqa: E501
        rosidl_parser.definition.BasicType('float'),  # noqa: E501
        rosidl_parser.definition.BasicType('uint32'),  # noqa: E501
        rosidl_parser.definition.BasicType('uint8'),  # noqa: E501
        rosidl_parser.definition.BasicType('float'),  # noqa: E501
        rosidl_parser.definition.BasicType('float'),  # noqa: E501
        rosidl_parser.definition.BasicType('float'),  # noqa: E501
        rosidl_parser.definition.BasicType('uint32'),  # noqa: E501
        rosidl_parser.definition.BasicType('int32'),  # noqa: E501
        rosidl_parser.definition.BasicType('float'),  # noqa: E501
        rosidl_parser.definition.BasicType('uint32'),  # noqa: E501
        rosidl_parser.definition.BasicType('uint8'),  # noqa: E501
        rosidl_parser.definition.BasicType('float'),  # noqa: E501
        rosidl_parser.definition.BasicType('float'),  # noqa: E501
        rosidl_parser.definition.BasicType('float'),  # noqa: E501
        rosidl_parser.definition.UnboundedString(),  # noqa: E501
    )

    def __init__(self, **kwargs):
        assert all('_' + key in self.__slots__ for key in kwargs.keys()), \
            'Invalid arguments passed to constructor: %s' % \
            ', '.join(sorted(k for k in kwargs.keys() if '_' + k not in self.__slots__))
        self.m1_p = kwargs.get('m1_p', float())
        self.m1_i = kwargs.get('m1_i', float())
        self.m1_d = kwargs.get('m1_d', float())
        self.m1_qpps = kwargs.get('m1_qpps', int())
        self.m1_current_speed = kwargs.get('m1_current_speed', int())
        self.m1_motor_current = kwargs.get('m1_motor_current', float())
        self.m1_encoder_value = kwargs.get('m1_encoder_value', int())
        self.m1_encoder_status = kwargs.get('m1_encoder_status', int())
        self.m2_p = kwargs.get('m2_p', float())
        self.m2_i = kwargs.get('m2_i', float())
        self.m2_d = kwargs.get('m2_d', float())
        self.m2_qpps = kwargs.get('m2_qpps', int())
        self.m2_current_speed = kwargs.get('m2_current_speed', int())
        self.m2_motor_current = kwargs.get('m2_motor_current', float())
        self.m2_encoder_value = kwargs.get('m2_encoder_value', int())
        self.m2_encoder_status = kwargs.get('m2_encoder_status', int())
        self.main_battery_voltage = kwargs.get('main_battery_voltage', float())
        self.logic_battery_voltage = kwargs.get('logic_battery_voltage', float())
        self.temperature = kwargs.get('temperature', float())
        self.error_string = kwargs.get('error_string', str())

    def __repr__(self):
        typename = self.__class__.__module__.split('.')
        typename.pop()
        typename.append(self.__class__.__name__)
        args = []
        for s, t in zip(self.__slots__, self.SLOT_TYPES):
            field = getattr(self, s)
            fieldstr = repr(field)
            # We use Python array type for fields that can be directly stored
            # in them, and "normal" sequences for everything else.  If it is
            # a type that we store in an array, strip off the 'array' portion.
            if (
                isinstance(t, rosidl_parser.definition.AbstractSequence) and
                isinstance(t.value_type, rosidl_parser.definition.BasicType) and
                t.value_type.typename in ['float', 'double', 'int8', 'uint8', 'int16', 'uint16', 'int32', 'uint32', 'int64', 'uint64']
            ):
                if len(field) == 0:
                    fieldstr = '[]'
                else:
                    assert fieldstr.startswith('array(')
                    prefix = "array('X', "
                    suffix = ')'
                    fieldstr = fieldstr[len(prefix):-len(suffix)]
            args.append(s[1:] + '=' + fieldstr)
        return '%s(%s)' % ('.'.join(typename), ', '.join(args))

    def __eq__(self, other):
        if not isinstance(other, self.__class__):
            return False
        if self.m1_p != other.m1_p:
            return False
        if self.m1_i != other.m1_i:
            return False
        if self.m1_d != other.m1_d:
            return False
        if self.m1_qpps != other.m1_qpps:
            return False
        if self.m1_current_speed != other.m1_current_speed:
            return False
        if self.m1_motor_current != other.m1_motor_current:
            return False
        if self.m1_encoder_value != other.m1_encoder_value:
            return False
        if self.m1_encoder_status != other.m1_encoder_status:
            return False
        if self.m2_p != other.m2_p:
            return False
        if self.m2_i != other.m2_i:
            return False
        if self.m2_d != other.m2_d:
            return False
        if self.m2_qpps != other.m2_qpps:
            return False
        if self.m2_current_speed != other.m2_current_speed:
            return False
        if self.m2_motor_current != other.m2_motor_current:
            return False
        if self.m2_encoder_value != other.m2_encoder_value:
            return False
        if self.m2_encoder_status != other.m2_encoder_status:
            return False
        if self.main_battery_voltage != other.main_battery_voltage:
            return False
        if self.logic_battery_voltage != other.logic_battery_voltage:
            return False
        if self.temperature != other.temperature:
            return False
        if self.error_string != other.error_string:
            return False
        return True

    @classmethod
    def get_fields_and_field_types(cls):
        from copy import copy
        return copy(cls._fields_and_field_types)

    @builtins.property
    def m1_p(self):
        """Message field 'm1_p'."""
        return self._m1_p

    @m1_p.setter
    def m1_p(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'm1_p' field must be of type 'float'"
            assert not (value < -3.402823466e+38 or value > 3.402823466e+38) or math.isinf(value), \
                "The 'm1_p' field must be a float in [-3.402823466e+38, 3.402823466e+38]"
        self._m1_p = value

    @builtins.property
    def m1_i(self):
        """Message field 'm1_i'."""
        return self._m1_i

    @m1_i.setter
    def m1_i(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'm1_i' field must be of type 'float'"
            assert not (value < -3.402823466e+38 or value > 3.402823466e+38) or math.isinf(value), \
                "The 'm1_i' field must be a float in [-3.402823466e+38, 3.402823466e+38]"
        self._m1_i = value

    @builtins.property
    def m1_d(self):
        """Message field 'm1_d'."""
        return self._m1_d

    @m1_d.setter
    def m1_d(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'm1_d' field must be of type 'float'"
            assert not (value < -3.402823466e+38 or value > 3.402823466e+38) or math.isinf(value), \
                "The 'm1_d' field must be a float in [-3.402823466e+38, 3.402823466e+38]"
        self._m1_d = value

    @builtins.property
    def m1_qpps(self):
        """Message field 'm1_qpps'."""
        return self._m1_qpps

    @m1_qpps.setter
    def m1_qpps(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'm1_qpps' field must be of type 'int'"
            assert value >= 0 and value < 4294967296, \
                "The 'm1_qpps' field must be an unsigned integer in [0, 4294967295]"
        self._m1_qpps = value

    @builtins.property
    def m1_current_speed(self):
        """Message field 'm1_current_speed'."""
        return self._m1_current_speed

    @m1_current_speed.setter
    def m1_current_speed(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'm1_current_speed' field must be of type 'int'"
            assert value >= -2147483648 and value < 2147483648, \
                "The 'm1_current_speed' field must be an integer in [-2147483648, 2147483647]"
        self._m1_current_speed = value

    @builtins.property
    def m1_motor_current(self):
        """Message field 'm1_motor_current'."""
        return self._m1_motor_current

    @m1_motor_current.setter
    def m1_motor_current(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'm1_motor_current' field must be of type 'float'"
            assert not (value < -3.402823466e+38 or value > 3.402823466e+38) or math.isinf(value), \
                "The 'm1_motor_current' field must be a float in [-3.402823466e+38, 3.402823466e+38]"
        self._m1_motor_current = value

    @builtins.property
    def m1_encoder_value(self):
        """Message field 'm1_encoder_value'."""
        return self._m1_encoder_value

    @m1_encoder_value.setter
    def m1_encoder_value(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'm1_encoder_value' field must be of type 'int'"
            assert value >= 0 and value < 4294967296, \
                "The 'm1_encoder_value' field must be an unsigned integer in [0, 4294967295]"
        self._m1_encoder_value = value

    @builtins.property
    def m1_encoder_status(self):
        """Message field 'm1_encoder_status'."""
        return self._m1_encoder_status

    @m1_encoder_status.setter
    def m1_encoder_status(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'm1_encoder_status' field must be of type 'int'"
            assert value >= 0 and value < 256, \
                "The 'm1_encoder_status' field must be an unsigned integer in [0, 255]"
        self._m1_encoder_status = value

    @builtins.property
    def m2_p(self):
        """Message field 'm2_p'."""
        return self._m2_p

    @m2_p.setter
    def m2_p(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'm2_p' field must be of type 'float'"
            assert not (value < -3.402823466e+38 or value > 3.402823466e+38) or math.isinf(value), \
                "The 'm2_p' field must be a float in [-3.402823466e+38, 3.402823466e+38]"
        self._m2_p = value

    @builtins.property
    def m2_i(self):
        """Message field 'm2_i'."""
        return self._m2_i

    @m2_i.setter
    def m2_i(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'm2_i' field must be of type 'float'"
            assert not (value < -3.402823466e+38 or value > 3.402823466e+38) or math.isinf(value), \
                "The 'm2_i' field must be a float in [-3.402823466e+38, 3.402823466e+38]"
        self._m2_i = value

    @builtins.property
    def m2_d(self):
        """Message field 'm2_d'."""
        return self._m2_d

    @m2_d.setter
    def m2_d(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'm2_d' field must be of type 'float'"
            assert not (value < -3.402823466e+38 or value > 3.402823466e+38) or math.isinf(value), \
                "The 'm2_d' field must be a float in [-3.402823466e+38, 3.402823466e+38]"
        self._m2_d = value

    @builtins.property
    def m2_qpps(self):
        """Message field 'm2_qpps'."""
        return self._m2_qpps

    @m2_qpps.setter
    def m2_qpps(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'm2_qpps' field must be of type 'int'"
            assert value >= 0 and value < 4294967296, \
                "The 'm2_qpps' field must be an unsigned integer in [0, 4294967295]"
        self._m2_qpps = value

    @builtins.property
    def m2_current_speed(self):
        """Message field 'm2_current_speed'."""
        return self._m2_current_speed

    @m2_current_speed.setter
    def m2_current_speed(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'm2_current_speed' field must be of type 'int'"
            assert value >= -2147483648 and value < 2147483648, \
                "The 'm2_current_speed' field must be an integer in [-2147483648, 2147483647]"
        self._m2_current_speed = value

    @builtins.property
    def m2_motor_current(self):
        """Message field 'm2_motor_current'."""
        return self._m2_motor_current

    @m2_motor_current.setter
    def m2_motor_current(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'm2_motor_current' field must be of type 'float'"
            assert not (value < -3.402823466e+38 or value > 3.402823466e+38) or math.isinf(value), \
                "The 'm2_motor_current' field must be a float in [-3.402823466e+38, 3.402823466e+38]"
        self._m2_motor_current = value

    @builtins.property
    def m2_encoder_value(self):
        """Message field 'm2_encoder_value'."""
        return self._m2_encoder_value

    @m2_encoder_value.setter
    def m2_encoder_value(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'm2_encoder_value' field must be of type 'int'"
            assert value >= 0 and value < 4294967296, \
                "The 'm2_encoder_value' field must be an unsigned integer in [0, 4294967295]"
        self._m2_encoder_value = value

    @builtins.property
    def m2_encoder_status(self):
        """Message field 'm2_encoder_status'."""
        return self._m2_encoder_status

    @m2_encoder_status.setter
    def m2_encoder_status(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'm2_encoder_status' field must be of type 'int'"
            assert value >= 0 and value < 256, \
                "The 'm2_encoder_status' field must be an unsigned integer in [0, 255]"
        self._m2_encoder_status = value

    @builtins.property
    def main_battery_voltage(self):
        """Message field 'main_battery_voltage'."""
        return self._main_battery_voltage

    @main_battery_voltage.setter
    def main_battery_voltage(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'main_battery_voltage' field must be of type 'float'"
            assert not (value < -3.402823466e+38 or value > 3.402823466e+38) or math.isinf(value), \
                "The 'main_battery_voltage' field must be a float in [-3.402823466e+38, 3.402823466e+38]"
        self._main_battery_voltage = value

    @builtins.property
    def logic_battery_voltage(self):
        """Message field 'logic_battery_voltage'."""
        return self._logic_battery_voltage

    @logic_battery_voltage.setter
    def logic_battery_voltage(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'logic_battery_voltage' field must be of type 'float'"
            assert not (value < -3.402823466e+38 or value > 3.402823466e+38) or math.isinf(value), \
                "The 'logic_battery_voltage' field must be a float in [-3.402823466e+38, 3.402823466e+38]"
        self._logic_battery_voltage = value

    @builtins.property
    def temperature(self):
        """Message field 'temperature'."""
        return self._temperature

    @temperature.setter
    def temperature(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'temperature' field must be of type 'float'"
            assert not (value < -3.402823466e+38 or value > 3.402823466e+38) or math.isinf(value), \
                "The 'temperature' field must be a float in [-3.402823466e+38, 3.402823466e+38]"
        self._temperature = value

    @builtins.property
    def error_string(self):
        """Message field 'error_string'."""
        return self._error_string

    @error_string.setter
    def error_string(self, value):
        if __debug__:
            assert \
                isinstance(value, str), \
                "The 'error_string' field must be of type 'str'"
        self._error_string = value
