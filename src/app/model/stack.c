#include "stack.h"
#include <stddef.h>
#include <stdlib.h>

stack_t *stack_new(size_t capacity) {
  stack_t *s = malloc(sizeof(stack_t));
  if (s == NULL) {
    return NULL;
  }

  s->count = 0;
  s->capacity = capacity;
  s->data = malloc(sizeof(void *) * capacity);
  if (s->data == NULL) {
    return NULL;
  }
  return s;
}

void stack_push(stack_t *stack, void *obj) {
  if (stack->count == stack->capacity) {
    stack->capacity *= 2;
    void **temp_data = realloc(stack->data, sizeof(void *) * stack->capacity);
    if (temp_data == NULL) {
      free(stack->data);
      exit(1);
    }
    stack->data = temp_data;
  }
  stack->data[stack->count] = obj;
  stack->count++;
}

void *stack_pop(stack_t *stack) {
  if (stack->count == 0) {
    return NULL;
  }
  stack->count--;
  return stack->data[stack->count];
}

void stack_free(stack_t *stack) {
  if (stack == NULL) {
    return;
  }
  if (stack->data != NULL) {
    free(stack->data);
  }
  free(stack);
}
