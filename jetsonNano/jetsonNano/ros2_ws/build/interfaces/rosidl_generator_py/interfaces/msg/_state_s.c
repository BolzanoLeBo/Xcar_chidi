// generated from rosidl_generator_py/resource/_idl_support.c.em
// with input from interfaces:msg/State.idl
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
#include "interfaces/msg/detail/state__struct.h"
#include "interfaces/msg/detail/state__functions.h"

#include "rosidl_runtime_c/string.h"
#include "rosidl_runtime_c/string_functions.h"


ROSIDL_GENERATOR_C_EXPORT
bool interfaces__msg__state__convert_from_py(PyObject * _pymsg, void * _ros_message)
{
  // check that the passed message is of the expected Python class
  {
    char full_classname_dest[28];
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
    assert(strncmp("interfaces.msg._state.State", full_classname_dest, 27) == 0);
  }
  interfaces__msg__State * ros_message = _ros_message;
  {  // current_state
    PyObject * field = PyObject_GetAttrString(_pymsg, "current_state");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->current_state = (int8_t)PyLong_AsLong(field);
    Py_DECREF(field);
  }
  {  // previous_state
    PyObject * field = PyObject_GetAttrString(_pymsg, "previous_state");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->previous_state = (int8_t)PyLong_AsLong(field);
    Py_DECREF(field);
  }
  {  // state_name
    PyObject * field = PyObject_GetAttrString(_pymsg, "state_name");
    if (!field) {
      return false;
    }
    assert(PyUnicode_Check(field));
    PyObject * encoded_field = PyUnicode_AsUTF8String(field);
    if (!encoded_field) {
      Py_DECREF(field);
      return false;
    }
    rosidl_runtime_c__String__assign(&ros_message->state_name, PyBytes_AS_STRING(encoded_field));
    Py_DECREF(encoded_field);
    Py_DECREF(field);
  }
  {  // message_index
    PyObject * field = PyObject_GetAttrString(_pymsg, "message_index");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->message_index = (int8_t)PyLong_AsLong(field);
    Py_DECREF(field);
  }

  return true;
}

ROSIDL_GENERATOR_C_EXPORT
PyObject * interfaces__msg__state__convert_to_py(void * raw_ros_message)
{
  /* NOTE(esteve): Call constructor of State */
  PyObject * _pymessage = NULL;
  {
    PyObject * pymessage_module = PyImport_ImportModule("interfaces.msg._state");
    assert(pymessage_module);
    PyObject * pymessage_class = PyObject_GetAttrString(pymessage_module, "State");
    assert(pymessage_class);
    Py_DECREF(pymessage_module);
    _pymessage = PyObject_CallObject(pymessage_class, NULL);
    Py_DECREF(pymessage_class);
    if (!_pymessage) {
      return NULL;
    }
  }
  interfaces__msg__State * ros_message = (interfaces__msg__State *)raw_ros_message;
  {  // current_state
    PyObject * field = NULL;
    field = PyLong_FromLong(ros_message->current_state);
    {
      int rc = PyObject_SetAttrString(_pymessage, "current_state", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // previous_state
    PyObject * field = NULL;
    field = PyLong_FromLong(ros_message->previous_state);
    {
      int rc = PyObject_SetAttrString(_pymessage, "previous_state", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // state_name
    PyObject * field = NULL;
    field = PyUnicode_DecodeUTF8(
      ros_message->state_name.data,
      strlen(ros_message->state_name.data),
      "replace");
    if (!field) {
      return NULL;
    }
    {
      int rc = PyObject_SetAttrString(_pymessage, "state_name", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // message_index
    PyObject * field = NULL;
    field = PyLong_FromLong(ros_message->message_index);
    {
      int rc = PyObject_SetAttrString(_pymessage, "message_index", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }

  // ownership of _pymessage is transferred to the caller
  return _pymessage;
}
