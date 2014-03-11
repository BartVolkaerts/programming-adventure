#include <stdio.h>

void change(int x)
{
  x = 6;
}

int main(int argc, char *argv[])
{
  int x = 5;
  printf("Before: %d\n", x);
  change(x);
  printf("After: %d\n", x);
  return 0;
}
