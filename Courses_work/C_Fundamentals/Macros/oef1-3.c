#include <stdio.h>

#define SELECT_LSB(num) num&0x1
#define SELECT_NB(num,n) (num>>n)&0x01

int main(int argc, char *argv[])
{
  for (int i = 0; i < 10; i++)
  {
    printf("LSB of %d : %d\n",i,SELECT_LSB(i));
    printf("2nd B of %d : %d\n",i,SELECT_NB(i,1));
  }
  return 0;
}
