// generated from rosidl_generator_py/resource/_idl_support.c.em
// with input from interfaces:msg/TrackingPosAngle.idl
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
#include "interfaces/msg/detail/tracking_pos_angle__struct.h"
#include "interfaces/msg/detail/tracking_pos_angle__functions.h"


ROSIDL_GENERATOR_C_EXPORT
bool interfaces__msg__tracking_pos_angle__convert_from_py(PyObject * _pymsg, void * _ros_message)
{
  // check that the passed message is of the expected Python class
  {
    char full_classname_dest[52];
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
    assert(strncmp("interfaces.msg._tracking_pos_angle.TrackingPosAngle", full_classname_dest, 51) == 0);
  }
  interfaces__msg__TrackingPosAngle * ros_message = _ros_message;
  {  // min_angle
    PyObject * field = PyObject_GetAttrString(_pymsg, "min_angle");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->min_angle = (float)PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // max_angle
    PyObject * field = PyObject_GetAttrString(_pymsg, "max_angle");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->max_angle = (float)PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // cam_angle
    PyObject * field = PyObject_GetAttrString(_pymsg, "cam_angle");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->cam_angle = (float)PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // person_detected
    PyObject * field = PyObject_GetAttrString(_pymsg, "person_detected");
    if (!field) {
      return false;
    }
    assert(PyBool_Check(field));
    ros_message->person_detected = (Py_True == field);
    Py_DECREF(field);
  }

  return true;
}

ROSIDL_GENERATOR_C_EXPORT
PyObject * interfaces__msg__tracking_pos_angle__convert_to_py(void * raw_ros_message)
{
  /* NOTE(esteve): Call constructor of TrackingPosAngle */
  PyObject * _pymessage = NULL;
  {
    PyObject * pymessage_module = PyImport_ImportModule("interfaces.msg._tracking_pos_angle");
    assert(pymessage_module);
    PyObject * pymessage_class = PyObject_GetAttrString(pymessage_module, "TrackingPosAngle");
    assert(pymessage_class);
    Py_DECREF(pymessage_module);
    _pymessage = PyObject_CallObject(pymessage_class, NULL);
    Py_DECREF(pymessage_class);
    if (!_pymessage) {
      return NULL;
    }
  }
  interfaces__msg__TrackingPosAngle * ros_message = (interfaces__msg__TrackingPosAngle *)raw_ros_message;
  {  // min_angle
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->min_angle);
    {
      int rc = PyObject_SetAttrString(_pymessage, "min_angle", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // max_angle
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->max_angle);
    {
      int rc = PyObject_SetAttrString(_pymessage, "max_angle", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // cam_angle
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->cam_angle);
    {
      int rc = PyObject_SetAttrString(_pymessage, "cam_angle", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // person_detected
    PyObject * field = NULL;
    field = PyBool_FromLong(ros_message->person_detected ? 1 : 0);
    {
      int rc = PyObject_SetAttrString(_pymessage, "person_detected", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }

  // ownership of _pymessage is transferred to the caller
  return _pymessage;
}
