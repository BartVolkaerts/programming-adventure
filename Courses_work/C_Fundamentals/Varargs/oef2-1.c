#include <stdio.h>
#include <stdarg.h>

int add(int a, ...)
{
  va_list ap;
  int sum = 0, i;
  va_start(ap,a);

  sum = a;
  i = va_arg(ap,int);
  
  while(i != -1)
  {
    sum += i;
    i = va_arg(ap,int);
  }
  va_end(ap);

  return sum;
}

int main(int argc, char *argv[])
{
  printf("%d\n", add(1,2,3,4,5,6,7,8,9,-1));

  return 0;
}
