#include <stdio.h>
#include <stdlib.h>

int isPerfect(unsigned int number) 
{
  int i=1;
  int temp=0;

  while(temp<number)
  {
    temp+=i;
    i++;
  }
  if(temp==number)
    return 1;
  
  return 0;
}


int main(int argc, char *argv[])
{
  int number_of_primes;
  int getal;

  if(argc<2)
  {
    printf("Use: ./a.out <number> <number>");
    return -1;
  }

  for(int i=1; i<argc; ++i)
  {
    getal = strtol(argv[i],NULL,10); 
    if(isPerfect(getal))
      printf("%d is perfect!\n", getal);
    else
      printf("%d is not perfect!\n", getal);
  }

  

  return 0;
}
