#include <stdio.h>
#include <stdlib.h>
#include "data_structures/array.h"

#define MAX_STACK 10000
#define MAX_STR 10

char get_item(char *str, int limit)
{
  char *w = str;
  int c;
  while((c = getchar()) == ' ');

  if (c == EOF || c == '\n')
    return EOF;

  *w++ = c;
  --limit;

  if (c == '+' || c == '*' || c == '-' || c == '/') {
    *w = '\0';
    return 1;
  }

  while(limit && (c = getchar()) >= '0' && '9' >= c) {
    *w++ = c;
    --limit;
  }

  *w = '\0';
  return 1;
}

int main()
{
  Array *array = array_init(MAX_STACK);
  char str[MAX_STR];

  while(get_item(str, MAX_STR) != EOF) {
    char c = str[0];
    int right_operand;
    switch(c) {
      case '+':
        push(array, pop(array) + pop(array));
        break;
      case '*':
        push(array, pop(array) * pop(array));
        break;
      case '-':
        right_operand = pop(array);
        push(array, pop(array) - right_operand);
        break;
      case '/':
        right_operand = pop(array);
        push(array, pop(array) / right_operand);
        break;
      default:
        push(array, atoi(str)); 
    }
  }
  printf("%d", pop(array));
  return 0;
}
