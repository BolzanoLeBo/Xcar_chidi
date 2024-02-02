# generated from rosidl_generator_py/resource/_idl.py.em
# with input from interfaces:msg/WebMode.idl
# generated code does not contain a copyright notice


# Import statements for member types

import builtins  # noqa: E402, I100

import math  # noqa: E402, I100

import rosidl_parser.definition  # noqa: E402, I100


class Metaclass_WebMode(type):
    """Metaclass of message 'WebMode'."""

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
            module = import_type_support('interfaces')
        except ImportError:
            import logging
            import traceback
            logger = logging.getLogger(
                'interfaces.msg.WebMode')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__msg__web_mode
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__msg__web_mode
            cls._CONVERT_TO_PY = module.convert_to_py_msg__msg__web_mode
            cls._TYPE_SUPPORT = module.type_support_msg__msg__web_mode
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__msg__web_mode

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
            'BUTTON__DEFAULT': 0,
            'THROTTLE__DEFAULT': 0.0,
            'STEERING__DEFAULT': 0.0,
            'REVERSE__DEFAULT': False,
        }

    @property
    def BUTTON__DEFAULT(cls):
        """Return default value for message field 'button'."""
        return 0

    @property
    def THROTTLE__DEFAULT(cls):
        """Return default value for message field 'throttle'."""
        return 0.0

    @property
    def STEERING__DEFAULT(cls):
        """Return default value for message field 'steering'."""
        return 0.0

    @property
    def REVERSE__DEFAULT(cls):
        """Return default value for message field 'reverse'."""
        return False


class WebMode(metaclass=Metaclass_WebMode):
    """Message class 'WebMode'."""

    __slots__ = [
        '_button',
        '_throttle',
        '_steering',
        '_reverse',
    ]

    _fields_and_field_types = {
        'button': 'int8',
        'throttle': 'float',
        'steering': 'float',
        'reverse': 'boolean',
    }

    SLOT_TYPES = (
        rosidl_parser.definition.BasicType('int8'),  # noqa: E501
        rosidl_parser.definition.BasicType('float'),  # noqa: E501
        rosidl_parser.definition.BasicType('float'),  # noqa: E501
        rosidl_parser.definition.BasicType('boolean'),  # noqa: E501
    )

    def __init__(self, **kwargs):
        assert all('_' + key in self.__slots__ for key in kwargs.keys()), \
            'Invalid arguments passed to constructor: %s' % \
            ', '.join(sorted(k for k in kwargs.keys() if '_' + k not in self.__slots__))
        self.button = kwargs.get(
            'button', WebMode.BUTTON__DEFAULT)
        self.throttle = kwargs.get(
            'throttle', WebMode.THROTTLE__DEFAULT)
        self.steering = kwargs.get(
            'steering', WebMode.STEERING__DEFAULT)
        self.reverse = kwargs.get(
            'reverse', WebMode.REVERSE__DEFAULT)

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
        if self.button != other.button:
            return False
        if self.throttle != other.throttle:
            return False
        if self.steering != other.steering:
            return False
        if self.reverse != other.reverse:
            return False
        return True

    @classmethod
    def get_fields_and_field_types(cls):
        from copy import copy
        return copy(cls._fields_and_field_types)

    @builtins.property
    def button(self):
        """Message field 'button'."""
        return self._button

    @button.setter
    def button(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'button' field must be of type 'int'"
            assert value >= -128 and value < 128, \
                "The 'button' field must be an integer in [-128, 127]"
        self._button = value

    @builtins.property
    def throttle(self):
        """Message field 'throttle'."""
        return self._throttle

    @throttle.setter
    def throttle(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'throttle' field must be of type 'float'"
            assert not (value < -3.402823466e+38 or value > 3.402823466e+38) or math.isinf(value), \
                "The 'throttle' field must be a float in [-3.402823466e+38, 3.402823466e+38]"
        self._throttle = value

    @builtins.property
    def steering(self):
        """Message field 'steering'."""
        return self._steering

    @steering.setter
    def steering(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'steering' field must be of type 'float'"
            assert not (value < -3.402823466e+38 or value > 3.402823466e+38) or math.isinf(value), \
                "The 'steering' field must be a float in [-3.402823466e+38, 3.402823466e+38]"
        self._steering = value

    @builtins.property
    def reverse(self):
        """Message field 'reverse'."""
        return self._reverse

    @reverse.setter
    def reverse(self, value):
        if __debug__:
            assert \
                isinstance(value, bool), \
                "The 'reverse' field must be of type 'bool'"
        self._reverse = value
