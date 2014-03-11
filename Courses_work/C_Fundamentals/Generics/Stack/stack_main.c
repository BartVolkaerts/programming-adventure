#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

int main(int argc, char **argv)
{
  stack *s = stack_create();
  printf("Stack size is %d\n", stack_count(s));
  

  for(int i=1;i<=10;i++)
  {
    int *val = (int*)malloc(sizeof(int));
    *val = i;
    printf("Pushing %d to stack\n", *val);
    stack_push(s,val);
    printf("\tStack size is %d\n", stack_count(s));
  }
  printf("Begin poppin'...\n");

  while(0 != stack_count(s))
  {
    int *val = stack_pop(s);
    printf("Popped %d\nFreeing...\n",*(int*)val);
    free(val);
    printf("\tStack size is %d\n", stack_count(s));
  }

  stack_destroy(s);
  return 0;
}
