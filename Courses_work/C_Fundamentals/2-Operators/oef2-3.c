#include <stdio.h>

int firstFunc()
{
  printf("This is the first function\n");
  return 0;
}

int secondFunc()
{
  printf("This is the second function\n");
  return 0;
}

int main(int argc, char *argv[])
{
  if(firstFunc() || secondFunc());
  return 0;
}
