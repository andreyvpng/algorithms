#ifndef ARRAY_H
#define ARRAY_H

#include <stdlib.h>

typedef struct Array {
  int *data;
  size_t size;
  size_t top;
} Array;

struct Array *array_init(size_t size);
void resize(struct Array *array, size_t size);
void push(struct Array *array, int value);
int pop(struct Array *array);
int peek(struct Array *array);
int get(struct Array *array, int index);
void set(struct Array *array, int index, int value);
int isEmpty(struct Array *array);
int isFull(struct Array *array);

#endif
