#include <stdio.h>
#include <assert.h>

int addHour(int a, int b)
{
  assert(a < 24 && a >= 0);
  assert(b < 24 && b >= 0);
  int sum;
  sum = a+b;
  if(sum>23)
    sum-=24;

  assert(sum < 24 && sum >= 0);
  return sum;
}

int main(int argc, char *argv[])
{
  printf("%sh + %sh = %dh\n", argv[1], argv[2], addHour((int)strtol(argv[1],NULL,10), (int)strtol(argv[2], NULL, 10)));
  return 0;
}
