#include "myobject.h"
#include <stdlib.h>
#include <string.h>
object_t *new_obj_integer(int value) {
  object_t *obj = malloc(sizeof(object_t));
  if (obj == NULL) {
    return NULL;
  }
  obj->kind = INETEGR;
  obj->data.v_int = value;
  return obj;
}
object_t *new_obj_float(float value) {
  object_t *obj = malloc(sizeof(object_t));
  if (obj == NULL) {
    return NULL;
  }
  obj->kind = FLOAT;
  obj->data.v_float = value;
  return obj;
}
object_t *new_obj_string(char *value) {

  object_t *obj = malloc(sizeof(object_t));
  if (obj == NULL) {
    return NULL;
  }

  obj->kind = STRING;
  obj->data.v_string = malloc(strlen(value) + 1);
  if (obj->data.v_string == NULL) {
    free(obj);
    return NULL;
  }
  strcpy(obj->data.v_string, value);
  return obj;
}
object_t *new_obj_vector3(object_t *x, object_t *y, object_t *z) {
  if (x == NULL || y == NULL || z == NULL) {
    return NULL;
  }
  object_t *obj = malloc(sizeof(object_t));
  if (obj == NULL) {
    return NULL;
  }
  obj->kind = VECTOR3;
  obj->data.v_vector3.x = x;
  obj->data.v_vector3.y = y;
  obj->data.v_vector3.z = z;
  return obj;
}
object_t *new_obj_array(size_t size) {

  object_t *obj = malloc(sizeof(object_t));
  if (obj == NULL) {
    return NULL;
  }
  object_t **elements = calloc(size, sizeof(object_t *));
  if (elements == NULL) {
    free(obj);
    return NULL;
  }
  obj_array_t array = {.size = size, .elements = elements};
  obj->kind = ARRAY;
  obj->data.v_array = array;
  return obj;
}
