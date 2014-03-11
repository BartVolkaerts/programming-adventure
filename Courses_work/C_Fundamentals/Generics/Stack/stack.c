#include <stdlib.h>
#include "stack.h"
#include "llist.h"

struct stack {
  Node *top;
};

stack* stack_create()
{
  stack *s = (stack*)malloc(sizeof(stack));
  s->top = NULL;
  return s;
}

void stack_destroy(stack *s)
{
  list_lfree(s->top);
  free(s);
}

void stack_push(stack *s, void* e)
{
  s->top = list_insert_after(s->top,e);
}

void *stack_pop(stack *s)
{
  Node* prev = s->top->prev;
  void *value = s->top->value; 
  list_remove(s->top);
  s->top = prev;
  return value;
}

int stack_count(stack *s)
{
  return list_count(s->top);
}
