# generated from rosidl_generator_py/resource/_idl.py.em
# with input from interfaces:msg/State.idl
# generated code does not contain a copyright notice


# Import statements for member types

import builtins  # noqa: E402, I100

import rosidl_parser.definition  # noqa: E402, I100


class Metaclass_State(type):
    """Metaclass of message 'State'."""

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
                'interfaces.msg.State')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__msg__state
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__msg__state
            cls._CONVERT_TO_PY = module.convert_to_py_msg__msg__state
            cls._TYPE_SUPPORT = module.type_support_msg__msg__state
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__msg__state

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
            'CURRENT_STATE__DEFAULT': 0,
            'PREVIOUS_STATE__DEFAULT': -1,
            'MESSAGE_INDEX__DEFAULT': 2,
        }

    @property
    def CURRENT_STATE__DEFAULT(cls):
        """Return default value for message field 'current_state'."""
        return 0

    @property
    def PREVIOUS_STATE__DEFAULT(cls):
        """Return default value for message field 'previous_state'."""
        return -1

    @property
    def MESSAGE_INDEX__DEFAULT(cls):
        """Return default value for message field 'message_index'."""
        return 2


class State(metaclass=Metaclass_State):
    """Message class 'State'."""

    __slots__ = [
        '_current_state',
        '_previous_state',
        '_state_name',
        '_message_index',
    ]

    _fields_and_field_types = {
        'current_state': 'int8',
        'previous_state': 'int8',
        'state_name': 'string',
        'message_index': 'int8',
    }

    SLOT_TYPES = (
        rosidl_parser.definition.BasicType('int8'),  # noqa: E501
        rosidl_parser.definition.BasicType('int8'),  # noqa: E501
        rosidl_parser.definition.UnboundedString(),  # noqa: E501
        rosidl_parser.definition.BasicType('int8'),  # noqa: E501
    )

    def __init__(self, **kwargs):
        assert all('_' + key in self.__slots__ for key in kwargs.keys()), \
            'Invalid arguments passed to constructor: %s' % \
            ', '.join(sorted(k for k in kwargs.keys() if '_' + k not in self.__slots__))
        self.current_state = kwargs.get(
            'current_state', State.CURRENT_STATE__DEFAULT)
        self.previous_state = kwargs.get(
            'previous_state', State.PREVIOUS_STATE__DEFAULT)
        self.state_name = kwargs.get('state_name', str())
        self.message_index = kwargs.get(
            'message_index', State.MESSAGE_INDEX__DEFAULT)

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
        if self.current_state != other.current_state:
            return False
        if self.previous_state != other.previous_state:
            return False
        if self.state_name != other.state_name:
            return False
        if self.message_index != other.message_index:
            return False
        return True

    @classmethod
    def get_fields_and_field_types(cls):
        from copy import copy
        return copy(cls._fields_and_field_types)

    @builtins.property
    def current_state(self):
        """Message field 'current_state'."""
        return self._current_state

    @current_state.setter
    def current_state(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'current_state' field must be of type 'int'"
            assert value >= -128 and value < 128, \
                "The 'current_state' field must be an integer in [-128, 127]"
        self._current_state = value

    @builtins.property
    def previous_state(self):
        """Message field 'previous_state'."""
        return self._previous_state

    @previous_state.setter
    def previous_state(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'previous_state' field must be of type 'int'"
            assert value >= -128 and value < 128, \
                "The 'previous_state' field must be an integer in [-128, 127]"
        self._previous_state = value

    @builtins.property
    def state_name(self):
        """Message field 'state_name'."""
        return self._state_name

    @state_name.setter
    def state_name(self, value):
        if __debug__:
            assert \
                isinstance(value, str), \
                "The 'state_name' field must be of type 'str'"
        self._state_name = value

    @builtins.property
    def message_index(self):
        """Message field 'message_index'."""
        return self._message_index

    @message_index.setter
    def message_index(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'message_index' field must be of type 'int'"
            assert value >= -128 and value < 128, \
                "The 'message_index' field must be an integer in [-128, 127]"
        self._message_index = value
