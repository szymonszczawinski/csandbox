#include <stddef.h>
typedef struct Object object_t;

typedef enum ObjectKind {
  INETEGR,
  FLOAT,
  STRING,
  VECTOR3,
  ARRAY
} object_kind_t;

typedef struct {
  object_t *x;
  object_t *y;
  object_t *z;
} obj_vector_t;

typedef struct {
  size_t size;
  object_t **elements;
} obj_array_t;

typedef union ObjectData {
  int v_int;
  float v_float;
  char *v_string;
  obj_vector_t v_vector3;
  obj_array_t v_array;
} object_data_t;

typedef struct Object {
  object_kind_t kind;
  object_data_t data;
} object_t;

object_t *new_obj_integer(int value);
object_t *new_obj_float(float value);
object_t *new_obj_string(char *value);
object_t *new_obj_vector3(object_t *x, object_t *y, object_t *z);
object_t *new_obj_array(size_t size);
