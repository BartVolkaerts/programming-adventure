#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int isArmstr(char *arg)
{
  int power = strlen(arg);
  int value = strtol(arg,NULL,10);
  int temp = 0;
  char test;

  for(int i=0; i<power; ++i)
  {
    test = arg[i];
    temp += (int)(pow(atoi(&test), power));
  }

  if(temp == value)
    return 1;

  return 0;
}

int main(int argc, char *argv[])
{
  for(int i=1;i<argc;++i)
  {
    if(isArmstr(argv[i]))
      printf("%ld is an Armstrong number\n", strtol(argv[i], NULL,10));
  }
  return 0;
}
