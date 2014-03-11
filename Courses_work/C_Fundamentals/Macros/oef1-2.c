#include <stdio.h>

#define SWAP(t,x,y) do{t temp;temp=x;x=y;y=temp;}while(0)

int main(int argc, char *argv[])
{
  int x=5,y=6;
  printf("x=%d, y=%d\n", x, y);
  SWAP(int,x,y);
  printf("x=%d, y=%d\n", x, y);
  return 0;
}
