# generated from rosidl_generator_py/resource/_idl.py.em
# with input from dasc_msgs:msg/QuadTrajectory.idl
# generated code does not contain a copyright notice


# Import statements for member types

# Member 'ts'
# Member 'xs'
# Member 'ys'
# Member 'zs'
# Member 'yaws'
# Member 'vxs'
# Member 'vys'
# Member 'vzs'
import array  # noqa: E402, I100

import rosidl_parser.definition  # noqa: E402, I100


class Metaclass_QuadTrajectory(type):
    """Metaclass of message 'QuadTrajectory'."""

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
            module = import_type_support('dasc_msgs')
        except ImportError:
            import logging
            import traceback
            logger = logging.getLogger(
                'dasc_msgs.msg.QuadTrajectory')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__msg__quad_trajectory
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__msg__quad_trajectory
            cls._CONVERT_TO_PY = module.convert_to_py_msg__msg__quad_trajectory
            cls._TYPE_SUPPORT = module.type_support_msg__msg__quad_trajectory
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__msg__quad_trajectory

            from std_msgs.msg import Header
            if Header.__class__._TYPE_SUPPORT is None:
                Header.__class__.__import_type_support__()

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
        }


class QuadTrajectory(metaclass=Metaclass_QuadTrajectory):
    """Message class 'QuadTrajectory'."""

    __slots__ = [
        '_header',
        '_ts',
        '_xs',
        '_ys',
        '_zs',
        '_yaws',
        '_vxs',
        '_vys',
        '_vzs',
    ]

    _fields_and_field_types = {
        'header': 'std_msgs/Header',
        'ts': 'sequence<double>',
        'xs': 'sequence<double>',
        'ys': 'sequence<double>',
        'zs': 'sequence<double>',
        'yaws': 'sequence<double>',
        'vxs': 'sequence<double>',
        'vys': 'sequence<double>',
        'vzs': 'sequence<double>',
    }

    SLOT_TYPES = (
        rosidl_parser.definition.NamespacedType(['std_msgs', 'msg'], 'Header'),  # noqa: E501
        rosidl_parser.definition.UnboundedSequence(rosidl_parser.definition.BasicType('double')),  # noqa: E501
        rosidl_parser.definition.UnboundedSequence(rosidl_parser.definition.BasicType('double')),  # noqa: E501
        rosidl_parser.definition.UnboundedSequence(rosidl_parser.definition.BasicType('double')),  # noqa: E501
        rosidl_parser.definition.UnboundedSequence(rosidl_parser.definition.BasicType('double')),  # noqa: E501
        rosidl_parser.definition.UnboundedSequence(rosidl_parser.definition.BasicType('double')),  # noqa: E501
        rosidl_parser.definition.UnboundedSequence(rosidl_parser.definition.BasicType('double')),  # noqa: E501
        rosidl_parser.definition.UnboundedSequence(rosidl_parser.definition.BasicType('double')),  # noqa: E501
        rosidl_parser.definition.UnboundedSequence(rosidl_parser.definition.BasicType('double')),  # noqa: E501
    )

    def __init__(self, **kwargs):
        assert all('_' + key in self.__slots__ for key in kwargs.keys()), \
            'Invalid arguments passed to constructor: %s' % \
            ', '.join(sorted(k for k in kwargs.keys() if '_' + k not in self.__slots__))
        from std_msgs.msg import Header
        self.header = kwargs.get('header', Header())
        self.ts = array.array('d', kwargs.get('ts', []))
        self.xs = array.array('d', kwargs.get('xs', []))
        self.ys = array.array('d', kwargs.get('ys', []))
        self.zs = array.array('d', kwargs.get('zs', []))
        self.yaws = array.array('d', kwargs.get('yaws', []))
        self.vxs = array.array('d', kwargs.get('vxs', []))
        self.vys = array.array('d', kwargs.get('vys', []))
        self.vzs = array.array('d', kwargs.get('vzs', []))

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
        if self.header != other.header:
            return False
        if self.ts != other.ts:
            return False
        if self.xs != other.xs:
            return False
        if self.ys != other.ys:
            return False
        if self.zs != other.zs:
            return False
        if self.yaws != other.yaws:
            return False
        if self.vxs != other.vxs:
            return False
        if self.vys != other.vys:
            return False
        if self.vzs != other.vzs:
            return False
        return True

    @classmethod
    def get_fields_and_field_types(cls):
        from copy import copy
        return copy(cls._fields_and_field_types)

    @property
    def header(self):
        """Message field 'header'."""
        return self._header

    @header.setter
    def header(self, value):
        if __debug__:
            from std_msgs.msg import Header
            assert \
                isinstance(value, Header), \
                "The 'header' field must be a sub message of type 'Header'"
        self._header = value

    @property
    def ts(self):
        """Message field 'ts'."""
        return self._ts

    @ts.setter
    def ts(self, value):
        if isinstance(value, array.array):
            assert value.typecode == 'd', \
                "The 'ts' array.array() must have the type code of 'd'"
            self._ts = value
            return
        if __debug__:
            from collections.abc import Sequence
            from collections.abc import Set
            from collections import UserList
            from collections import UserString
            assert \
                ((isinstance(value, Sequence) or
                  isinstance(value, Set) or
                  isinstance(value, UserList)) and
                 not isinstance(value, str) and
                 not isinstance(value, UserString) and
                 all(isinstance(v, float) for v in value) and
                 True), \
                "The 'ts' field must be a set or sequence and each value of type 'float'"
        self._ts = array.array('d', value)

    @property
    def xs(self):
        """Message field 'xs'."""
        return self._xs

    @xs.setter
    def xs(self, value):
        if isinstance(value, array.array):
            assert value.typecode == 'd', \
                "The 'xs' array.array() must have the type code of 'd'"
            self._xs = value
            return
        if __debug__:
            from collections.abc import Sequence
            from collections.abc import Set
            from collections import UserList
            from collections import UserString
            assert \
                ((isinstance(value, Sequence) or
                  isinstance(value, Set) or
                  isinstance(value, UserList)) and
                 not isinstance(value, str) and
                 not isinstance(value, UserString) and
                 all(isinstance(v, float) for v in value) and
                 True), \
                "The 'xs' field must be a set or sequence and each value of type 'float'"
        self._xs = array.array('d', value)

    @property
    def ys(self):
        """Message field 'ys'."""
        return self._ys

    @ys.setter
    def ys(self, value):
        if isinstance(value, array.array):
            assert value.typecode == 'd', \
                "The 'ys' array.array() must have the type code of 'd'"
            self._ys = value
            return
        if __debug__:
            from collections.abc import Sequence
            from collections.abc import Set
            from collections import UserList
            from collections import UserString
            assert \
                ((isinstance(value, Sequence) or
                  isinstance(value, Set) or
                  isinstance(value, UserList)) and
                 not isinstance(value, str) and
                 not isinstance(value, UserString) and
                 all(isinstance(v, float) for v in value) and
                 True), \
                "The 'ys' field must be a set or sequence and each value of type 'float'"
        self._ys = array.array('d', value)

    @property
    def zs(self):
        """Message field 'zs'."""
        return self._zs

    @zs.setter
    def zs(self, value):
        if isinstance(value, array.array):
            assert value.typecode == 'd', \
                "The 'zs' array.array() must have the type code of 'd'"
            self._zs = value
            return
        if __debug__:
            from collections.abc import Sequence
            from collections.abc import Set
            from collections import UserList
            from collections import UserString
            assert \
                ((isinstance(value, Sequence) or
                  isinstance(value, Set) or
                  isinstance(value, UserList)) and
                 not isinstance(value, str) and
                 not isinstance(value, UserString) and
                 all(isinstance(v, float) for v in value) and
                 True), \
                "The 'zs' field must be a set or sequence and each value of type 'float'"
        self._zs = array.array('d', value)

    @property
    def yaws(self):
        """Message field 'yaws'."""
        return self._yaws

    @yaws.setter
    def yaws(self, value):
        if isinstance(value, array.array):
            assert value.typecode == 'd', \
                "The 'yaws' array.array() must have the type code of 'd'"
            self._yaws = value
            return
        if __debug__:
            from collections.abc import Sequence
            from collections.abc import Set
            from collections import UserList
            from collections import UserString
            assert \
                ((isinstance(value, Sequence) or
                  isinstance(value, Set) or
                  isinstance(value, UserList)) and
                 not isinstance(value, str) and
                 not isinstance(value, UserString) and
                 all(isinstance(v, float) for v in value) and
                 True), \
                "The 'yaws' field must be a set or sequence and each value of type 'float'"
        self._yaws = array.array('d', value)

    @property
    def vxs(self):
        """Message field 'vxs'."""
        return self._vxs

    @vxs.setter
    def vxs(self, value):
        if isinstance(value, array.array):
            assert value.typecode == 'd', \
                "The 'vxs' array.array() must have the type code of 'd'"
            self._vxs = value
            return
        if __debug__:
            from collections.abc import Sequence
            from collections.abc import Set
            from collections import UserList
            from collections import UserString
            assert \
                ((isinstance(value, Sequence) or
                  isinstance(value, Set) or
                  isinstance(value, UserList)) and
                 not isinstance(value, str) and
                 not isinstance(value, UserString) and
                 all(isinstance(v, float) for v in value) and
                 True), \
                "The 'vxs' field must be a set or sequence and each value of type 'float'"
        self._vxs = array.array('d', value)

    @property
    def vys(self):
        """Message field 'vys'."""
        return self._vys

    @vys.setter
    def vys(self, value):
        if isinstance(value, array.array):
            assert value.typecode == 'd', \
                "The 'vys' array.array() must have the type code of 'd'"
            self._vys = value
            return
        if __debug__:
            from collections.abc import Sequence
            from collections.abc import Set
            from collections import UserList
            from collections import UserString
            assert \
                ((isinstance(value, Sequence) or
                  isinstance(value, Set) or
                  isinstance(value, UserList)) and
                 not isinstance(value, str) and
                 not isinstance(value, UserString) and
                 all(isinstance(v, float) for v in value) and
                 True), \
                "The 'vys' field must be a set or sequence and each value of type 'float'"
        self._vys = array.array('d', value)

    @property
    def vzs(self):
        """Message field 'vzs'."""
        return self._vzs

    @vzs.setter
    def vzs(self, value):
        if isinstance(value, array.array):
            assert value.typecode == 'd', \
                "The 'vzs' array.array() must have the type code of 'd'"
            self._vzs = value
            return
        if __debug__:
            from collections.abc import Sequence
            from collections.abc import Set
            from collections import UserList
            from collections import UserString
            assert \
                ((isinstance(value, Sequence) or
                  isinstance(value, Set) or
                  isinstance(value, UserList)) and
                 not isinstance(value, str) and
                 not isinstance(value, UserString) and
                 all(isinstance(v, float) for v in value) and
                 True), \
                "The 'vzs' field must be a set or sequence and each value of type 'float'"
        self._vzs = array.array('d', value)
