# generated from rosidl_generator_py/resource/_idl.py.em
# with input from interfaces:msg/Obstacles.idl
# generated code does not contain a copyright notice


# Import statements for member types

import builtins  # noqa: E402, I100

import rosidl_parser.definition  # noqa: E402, I100


class Metaclass_Obstacles(type):
    """Metaclass of message 'Obstacles'."""

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
                'interfaces.msg.Obstacles')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__msg__obstacles
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__msg__obstacles
            cls._CONVERT_TO_PY = module.convert_to_py_msg__msg__obstacles
            cls._TYPE_SUPPORT = module.type_support_msg__msg__obstacles
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__msg__obstacles

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
            'FRONT__DEFAULT': 0,
            'REAR__DEFAULT': 0,
            'US_ERROR__DEFAULT': 0,
            'LIDAR_ERROR__DEFAULT': 0,
        }

    @property
    def FRONT__DEFAULT(cls):
        """Return default value for message field 'front'."""
        return 0

    @property
    def REAR__DEFAULT(cls):
        """Return default value for message field 'rear'."""
        return 0

    @property
    def US_ERROR__DEFAULT(cls):
        """Return default value for message field 'us_error'."""
        return 0

    @property
    def LIDAR_ERROR__DEFAULT(cls):
        """Return default value for message field 'lidar_error'."""
        return 0


class Obstacles(metaclass=Metaclass_Obstacles):
    """Message class 'Obstacles'."""

    __slots__ = [
        '_front',
        '_rear',
        '_us_error',
        '_lidar_error',
    ]

    _fields_and_field_types = {
        'front': 'int8',
        'rear': 'int8',
        'us_error': 'int8',
        'lidar_error': 'int8',
    }

    SLOT_TYPES = (
        rosidl_parser.definition.BasicType('int8'),  # noqa: E501
        rosidl_parser.definition.BasicType('int8'),  # noqa: E501
        rosidl_parser.definition.BasicType('int8'),  # noqa: E501
        rosidl_parser.definition.BasicType('int8'),  # noqa: E501
    )

    def __init__(self, **kwargs):
        assert all('_' + key in self.__slots__ for key in kwargs.keys()), \
            'Invalid arguments passed to constructor: %s' % \
            ', '.join(sorted(k for k in kwargs.keys() if '_' + k not in self.__slots__))
        self.front = kwargs.get(
            'front', Obstacles.FRONT__DEFAULT)
        self.rear = kwargs.get(
            'rear', Obstacles.REAR__DEFAULT)
        self.us_error = kwargs.get(
            'us_error', Obstacles.US_ERROR__DEFAULT)
        self.lidar_error = kwargs.get(
            'lidar_error', Obstacles.LIDAR_ERROR__DEFAULT)

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
        if self.front != other.front:
            return False
        if self.rear != other.rear:
            return False
        if self.us_error != other.us_error:
            return False
        if self.lidar_error != other.lidar_error:
            return False
        return True

    @classmethod
    def get_fields_and_field_types(cls):
        from copy import copy
        return copy(cls._fields_and_field_types)

    @builtins.property
    def front(self):
        """Message field 'front'."""
        return self._front

    @front.setter
    def front(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'front' field must be of type 'int'"
            assert value >= -128 and value < 128, \
                "The 'front' field must be an integer in [-128, 127]"
        self._front = value

    @builtins.property
    def rear(self):
        """Message field 'rear'."""
        return self._rear

    @rear.setter
    def rear(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'rear' field must be of type 'int'"
            assert value >= -128 and value < 128, \
                "The 'rear' field must be an integer in [-128, 127]"
        self._rear = value

    @builtins.property
    def us_error(self):
        """Message field 'us_error'."""
        return self._us_error

    @us_error.setter
    def us_error(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'us_error' field must be of type 'int'"
            assert value >= -128 and value < 128, \
                "The 'us_error' field must be an integer in [-128, 127]"
        self._us_error = value

    @builtins.property
    def lidar_error(self):
        """Message field 'lidar_error'."""
        return self._lidar_error

    @lidar_error.setter
    def lidar_error(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'lidar_error' field must be of type 'int'"
            assert value >= -128 and value < 128, \
                "The 'lidar_error' field must be an integer in [-128, 127]"
        self._lidar_error = value
