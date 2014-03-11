#include <stdio.h>

int main(int argc, char *argv[])
{
  int a[] = {1,2,3,4,5};
  float b[] = {1.0,2.0,3.0,4.0,5.0};
  double c[] = {1.0,2.0,3.0,4.0,5.0};

  int* pa = a;

  printf("a[3] is: %d\n", pa[3]);
  for(int i=0;i<5;i++)
  {
    printf("%d at location %p\n",*pa,pa);
    pa++;
  }

  float* pb = b;
  for(int i=0;i<5;i++)
  {
    printf("%f at location %p\n",*pb,pb);
    pb++;
  }
 
  return 0;
}
