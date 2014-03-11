#include <stdio.h>
#include <string.h>

#define LOWER_CASE_BEGIN 97
#define LOWER_CASE_END 122
#define OFFSET 32

void toUpper(char *arg)
{
  int lengte = strlen(arg);
  for(int i=0;i<lengte;++i)
  {
    if(arg[i]>= LOWER_CASE_BEGIN && arg[i]<=LOWER_CASE_END)
      arg[i] = (char)((int)arg[i] - OFFSET);
  }
}

int main(int argc, char *argv[])
{
  for(int i=1;i<argc;++i)
  {
    toUpper(argv[i]);
    printf("%s ", argv[i]);
  }
  printf("\n");
  return 0;
}
