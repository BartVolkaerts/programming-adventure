#include <stdio.h>

int rec_func(int n)
{
  if(n==0)
    return 0;

  printf(" %d\n", n);
  return n + rec_func(n-1);
}

int main(int argc, char *argv[])
{
  int n;
  printf("Pls give a number: ");
  scanf("%d", &n);
  printf("Result: %d\n", rec_func(n));
  return 0;
}
