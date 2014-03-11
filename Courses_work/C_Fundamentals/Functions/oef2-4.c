#include <stdio.h>
#include <string.h>

double CtoF(double temp)
{
  return ((temp*(9/5))+32);
}

double CtoK(double temp)
{
  return (temp+273.15); 
}

int main(int argc, char *argv[])
{
  if(argc != 3)
    printf("Program needs 2 arguments\n");

  if(strcmp(argv[1],"c2f") == 0)
    printf("C2F: %lf\n", CtoF((double)strtol(argv[2],NULL,10)));

  if(strcmp(argv[1],"c2k") == 0)
    printf("C2K: %lf\n", CtoK((double)strtol(argv[2],NULL,10)));

  return 0;
}
