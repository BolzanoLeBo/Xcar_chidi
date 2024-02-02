# generated from rosidl_generator_py/resource/_idl.py.em
# with input from interfaces:msg/ObstaclesId.idl
# generated code does not contain a copyright notice


# Import statements for member types

import builtins  # noqa: E402, I100

import rosidl_parser.definition  # noqa: E402, I100


class Metaclass_ObstaclesId(type):
    """Metaclass of message 'ObstaclesId'."""

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
                'interfaces.msg.ObstaclesId')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__msg__obstacles_id
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__msg__obstacles_id
            cls._CONVERT_TO_PY = module.convert_to_py_msg__msg__obstacles_id
            cls._TYPE_SUPPORT = module.type_support_msg__msg__obstacles_id
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__msg__obstacles_id

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
        }


class ObstaclesId(metaclass=Metaclass_ObstaclesId):
    """Message class 'ObstaclesId'."""

    __slots__ = [
        '_obstacle_left',
        '_obstacle_middle',
        '_obstacle_right',
        '_big_obstacle',
    ]

    _fields_and_field_types = {
        'obstacle_left': 'boolean',
        'obstacle_middle': 'boolean',
        'obstacle_right': 'boolean',
        'big_obstacle': 'boolean',
    }

    SLOT_TYPES = (
        rosidl_parser.definition.BasicType('boolean'),  # noqa: E501
        rosidl_parser.definition.BasicType('boolean'),  # noqa: E501
        rosidl_parser.definition.BasicType('boolean'),  # noqa: E501
        rosidl_parser.definition.BasicType('boolean'),  # noqa: E501
    )

    def __init__(self, **kwargs):
        assert all('_' + key in self.__slots__ for key in kwargs.keys()), \
            'Invalid arguments passed to constructor: %s' % \
            ', '.join(sorted(k for k in kwargs.keys() if '_' + k not in self.__slots__))
        self.obstacle_left = kwargs.get('obstacle_left', bool())
        self.obstacle_middle = kwargs.get('obstacle_middle', bool())
        self.obstacle_right = kwargs.get('obstacle_right', bool())
        self.big_obstacle = kwargs.get('big_obstacle', bool())

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
        if self.obstacle_left != other.obstacle_left:
            return False
        if self.obstacle_middle != other.obstacle_middle:
            return False
        if self.obstacle_right != other.obstacle_right:
            return False
        if self.big_obstacle != other.big_obstacle:
            return False
        return True

    @classmethod
    def get_fields_and_field_types(cls):
        from copy import copy
        return copy(cls._fields_and_field_types)

    @builtins.property
    def obstacle_left(self):
        """Message field 'obstacle_left'."""
        return self._obstacle_left

    @obstacle_left.setter
    def obstacle_left(self, value):
        if __debug__:
            assert \
                isinstance(value, bool), \
                "The 'obstacle_left' field must be of type 'bool'"
        self._obstacle_left = value

    @builtins.property
    def obstacle_middle(self):
        """Message field 'obstacle_middle'."""
        return self._obstacle_middle

    @obstacle_middle.setter
    def obstacle_middle(self, value):
        if __debug__:
            assert \
                isinstance(value, bool), \
                "The 'obstacle_middle' field must be of type 'bool'"
        self._obstacle_middle = value

    @builtins.property
    def obstacle_right(self):
        """Message field 'obstacle_right'."""
        return self._obstacle_right

    @obstacle_right.setter
    def obstacle_right(self, value):
        if __debug__:
            assert \
                isinstance(value, bool), \
                "The 'obstacle_right' field must be of type 'bool'"
        self._obstacle_right = value

    @builtins.property
    def big_obstacle(self):
        """Message field 'big_obstacle'."""
        return self._big_obstacle

    @big_obstacle.setter
    def big_obstacle(self, value):
        if __debug__:
            assert \
                isinstance(value, bool), \
                "The 'big_obstacle' field must be of type 'bool'"
        self._big_obstacle = value
