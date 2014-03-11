#include <stdio.h>
#include <stdlib.h>

int isPrime(unsigned int number) {
  if (number <= 1) return 0; 
  unsigned int i;
  for (i=2; i*i<=number; i++) {
    if (number % i == 0) return 0;
  }
  return 1;
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
    number_of_primes=0;
    getal = strtol(argv[i],NULL,10); 
    if(isPrime(getal))
      printf("%d is prime!\n", getal);
    for(int j = getal-1;j>=1;--j)
    {
      if(isPrime(j))
        ++number_of_primes;
    }
    printf(" Primes beneath %d: %d\n", getal, number_of_primes);
  }

  

  return 0;
}
