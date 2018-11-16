#include <stdlib.h>
#include "array.h"

struct Array *array_init(size_t size)
{
  struct Array *array = (struct Array *) malloc(sizeof(struct Array *));

  array->data = (int *) malloc(sizeof(int) * size);
  array->top = 0;
  array->size = size;

  if (array->data == NULL)
    return NULL;

  return array;
}

void resize(struct Array *array, size_t size)
{
  array->data = (int *) realloc(array->data, sizeof(int) * size);
  array->size = size;
}

void push(struct Array *array, int value)
{
  array->data[array->top++] = value;
}

int pop(struct Array *array)
{
  return array->data[--array->top];
}

int peek(struct Array *array)
{
  return array->data[array->top - 1];
}

int get(struct Array *array, int index)
{
  return array->data[index];
}

void set(struct Array *array, int index, int value)
{
  array->data[index] = value;
}

int isEmpty(struct Array *array)
{
  return array->top == 0;
}

int isFull(struct Array *array)
{
  return array->size == array->top;
}
