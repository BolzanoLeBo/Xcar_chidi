# generated from rosidl_generator_py/resource/_idl.py.em
# with input from interfaces:msg/SideObstacles.idl
# generated code does not contain a copyright notice


# Import statements for member types

import builtins  # noqa: E402, I100

import math  # noqa: E402, I100

import rosidl_parser.definition  # noqa: E402, I100


class Metaclass_SideObstacles(type):
    """Metaclass of message 'SideObstacles'."""

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
                'interfaces.msg.SideObstacles')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__msg__side_obstacles
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__msg__side_obstacles
            cls._CONVERT_TO_PY = module.convert_to_py_msg__msg__side_obstacles
            cls._TYPE_SUPPORT = module.type_support_msg__msg__side_obstacles
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__msg__side_obstacles

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
            'LEFT_LIDAR__DEFAULT': False,
            'RIGHT_LIDAR__DEFAULT': False,
        }

    @property
    def LEFT_LIDAR__DEFAULT(cls):
        """Return default value for message field 'left_lidar'."""
        return False

    @property
    def RIGHT_LIDAR__DEFAULT(cls):
        """Return default value for message field 'right_lidar'."""
        return False


class SideObstacles(metaclass=Metaclass_SideObstacles):
    """Message class 'SideObstacles'."""

    __slots__ = [
        '_left_lidar',
        '_right_lidar',
        '_left_min',
        '_right_min',
    ]

    _fields_and_field_types = {
        'left_lidar': 'boolean',
        'right_lidar': 'boolean',
        'left_min': 'float',
        'right_min': 'float',
    }

    SLOT_TYPES = (
        rosidl_parser.definition.BasicType('boolean'),  # noqa: E501
        rosidl_parser.definition.BasicType('boolean'),  # noqa: E501
        rosidl_parser.definition.BasicType('float'),  # noqa: E501
        rosidl_parser.definition.BasicType('float'),  # noqa: E501
    )

    def __init__(self, **kwargs):
        assert all('_' + key in self.__slots__ for key in kwargs.keys()), \
            'Invalid arguments passed to constructor: %s' % \
            ', '.join(sorted(k for k in kwargs.keys() if '_' + k not in self.__slots__))
        self.left_lidar = kwargs.get(
            'left_lidar', SideObstacles.LEFT_LIDAR__DEFAULT)
        self.right_lidar = kwargs.get(
            'right_lidar', SideObstacles.RIGHT_LIDAR__DEFAULT)
        self.left_min = kwargs.get('left_min', float())
        self.right_min = kwargs.get('right_min', float())

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
        if self.left_lidar != other.left_lidar:
            return False
        if self.right_lidar != other.right_lidar:
            return False
        if self.left_min != other.left_min:
            return False
        if self.right_min != other.right_min:
            return False
        return True

    @classmethod
    def get_fields_and_field_types(cls):
        from copy import copy
        return copy(cls._fields_and_field_types)

    @builtins.property
    def left_lidar(self):
        """Message field 'left_lidar'."""
        return self._left_lidar

    @left_lidar.setter
    def left_lidar(self, value):
        if __debug__:
            assert \
                isinstance(value, bool), \
                "The 'left_lidar' field must be of type 'bool'"
        self._left_lidar = value

    @builtins.property
    def right_lidar(self):
        """Message field 'right_lidar'."""
        return self._right_lidar

    @right_lidar.setter
    def right_lidar(self, value):
        if __debug__:
            assert \
                isinstance(value, bool), \
                "The 'right_lidar' field must be of type 'bool'"
        self._right_lidar = value

    @builtins.property
    def left_min(self):
        """Message field 'left_min'."""
        return self._left_min

    @left_min.setter
    def left_min(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'left_min' field must be of type 'float'"
            assert not (value < -3.402823466e+38 or value > 3.402823466e+38) or math.isinf(value), \
                "The 'left_min' field must be a float in [-3.402823466e+38, 3.402823466e+38]"
        self._left_min = value

    @builtins.property
    def right_min(self):
        """Message field 'right_min'."""
        return self._right_min

    @right_min.setter
    def right_min(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'right_min' field must be of type 'float'"
            assert not (value < -3.402823466e+38 or value > 3.402823466e+38) or math.isinf(value), \
                "The 'right_min' field must be a float in [-3.402823466e+38, 3.402823466e+38]"
        self._right_min = value
