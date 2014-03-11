#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

double CtoF(double temp)
{
  return ((temp*(9/5))+32);
}

double CtoK(double temp)
{
  return (temp+273.15); 
}

double strtonum(char *arg)
{
  double temp;
  errno = 0;
  temp = strtol(arg,NULL,10);
  if (errno != 0)
  {
    exit(1);
  }
}

int main(int argc, char *argv[])
{
  if(argc != 3)
  {
    printf("Program needs 2 arguments\n");
    exit(1);
  }

  if(strcmp(argv[1],"c2f") == 0)
    printf("C2F: %lf\n", strtonum(argv[2]));

  if(strcmp(argv[1],"c2k") == 0)
    printf("C2K: %lf\n", strtonum(argv[2]));

  return 0;
}
