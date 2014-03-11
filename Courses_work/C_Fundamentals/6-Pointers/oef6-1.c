#include <stdio.h>

int main(int argc, char *argv[])
{
  int a = 5;
  float b = 6.0;
  double c = 7.0;
  char d = 'x';

  printf("%d @ %p\n",a,&a);
  printf("%f @ %p\n",b,&b);
  printf("%lf @ %p\n",c,&c);
  printf("%c @ %p\n",d,&d);

  
  int* pa = &a;
  float* pb = &b;
  double* pc = &c;
  char* pd = &d;

  *pa = 10;
  *pb = 11.0;
  *pc = 12.0;
  *pd = 'y';

  printf("%d @ %p\n",a,&a);
  printf("%f @ %p\n",b,&b);
  printf("%lf @ %p\n",c,&c);
  printf("%c @ %p\n",d,&d);

  return 0;
}
