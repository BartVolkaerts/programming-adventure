#include <stdio.h>

#define AMOUNT 10

int main(int argc, char *argv[])
{
  int max=0;
  int temp;

  for(int i = 0; i < AMOUNT; ++i)
  {
    printf("Enter nr %d: ", i+1);
    scanf("%d", &temp);
    if (temp > max)
      max = temp;
  }

  printf("Biggest number was %d\n", max);

  return 0;
}
