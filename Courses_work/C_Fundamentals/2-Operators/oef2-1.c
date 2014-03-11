#include <stdio.h>
#include <stdlib.h>
#include <string.h>

double add(int size, char *argv[])
{
  double temp=0.0;

  for(int i=2;i<size;++i)
    temp += (double)strtol(argv[i],NULL,10);

  return temp;
}

double sub(int size, char *argv[])
{
  double temp=(double)strtol(argv[2],NULL,10);

  for(int i=3;i<size;++i)
    temp -= (double)strtol(argv[i],NULL,10);

  return temp;

}

double mul(int size, char *argv[])
{
  double temp=(double)strtol(argv[2],NULL,10);

  for(int i=3;i<size;++i)
    temp *= (double)strtol(argv[i],NULL,10);

  return temp;

}

double divd(int size, char *argv[])
{
  double temp=(double)strtol(argv[2],NULL,10);

  for(int i=3;i<size;++i)
    temp /= (double)strtol(argv[i],NULL,10);

  return temp;

}

double modulus(int size, char *argv[])
{
  double temp=(double)strtol(argv[2],NULL,10);

  for(int i=3;i<size;++i)
    temp /= (double)strtol(argv[i],NULL,10);

  return temp;

}

int main(int argc, char *argv[])
{
  int size = argc;
  double result;

  // Test the arguments
  if(strlen(argv[1])>1 || argc<4)
    return -1;
  
  char op = *argv[1];

  switch(op)
  {
    case '+': result = add(size, argv);
              break;
    case '-': result = sub(size, argv);
              break;
    case '*': result = mul(size, argv);
              break;
    case '/': result = divd(size, argv);
              break;
    case '%': result = modulus(size, argv);
              break;
    default: printf("Operator nut supported!\n");
  }
  
  printf("Result: %lf\n", result);
  return 0;
}
