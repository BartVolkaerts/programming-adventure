#include <stdio.h>

#define IS_UPPER_CASE(x) (x>65?(x<90?1:0):0) 

int main(int argc, char *argv[])
{
  printf("Is X uppercase? %d\n",IS_UPPER_CASE('X'));
  printf("Is x uppercase? %d\n",IS_UPPER_CASE('x'));
  return 0;
}
