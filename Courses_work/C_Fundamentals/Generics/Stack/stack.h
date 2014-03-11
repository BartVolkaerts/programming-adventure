#ifndef STACK_H
#define STACK_H

typedef struct stack stack;

stack *stack_create();
void stack_destroy(stack *s);
void stack_push(stack *s, void* e);
void *stack_pop(stack *s);
int stack_count(stack *s);

#endif
