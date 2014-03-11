#include <stdio.h>

#define MINIMUM2(x,y) x<y?x:y
#define MINIMUM3(x,y,z) (MINIMUM2(x,y))<z?(MINIMUM2(x,y)):z

int main(int argc, char *argv[])
{
  int x=10,y=12,z=9;
  printf("%d\n", MINIMUM2(x,y));
  printf("%d\n", MINIMUM3(x,y,z));
  return 0;
}
