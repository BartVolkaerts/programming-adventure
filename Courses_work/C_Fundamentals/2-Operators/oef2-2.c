#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int add(int size, char *argv[])
{
  int temp=0.0;

  for(int i=2;i<size;++i)
    temp += (int)strtol(argv[i],NULL,10);

  return temp;
}

int sub(int size, char *argv[])
{
  int temp=(int)strtol(argv[2],NULL,10);

  for(int i=3;i<size;++i)
    temp -= (int)strtol(argv[i],NULL,10);

  return temp;
}

int mul(int size, char *argv[])
{
  int temp=(int)strtol(argv[2],NULL,10);

  for(int i=3;i<size;++i)
    temp *= (int)strtol(argv[i],NULL,10);

  return temp;
}

int divd(int size, char *argv[])
{
  int temp=(int)strtol(argv[2],NULL,10);

  for(int i=3;i<size;++i)
    temp /= (int)strtol(argv[i],NULL,10);

  return temp;
}

int modulus(int size, char *argv[])
{
  int temp=(int)strtol(argv[2],NULL,10);

  for(int i=3;i<size;++i)
    temp /= (int)strtol(argv[i],NULL,10);

  return temp;
}

int and(int size, char *argv[])
{
  int temp=(int)strtol(argv[2],NULL,10);

  for(int i=3;i<size;++i)
    temp &= (int)strtol(argv[i],NULL,10);

  return temp;
}

int or(int size, char *argv[])
{
  int temp=(int)strtol(argv[2],NULL,10);

  for(int i=3;i<size;++i)
    temp |= (int)strtol(argv[i],NULL,10);

  return temp;
}

int tild(int size, char *argv[])
{
  int temp=(int)strtol(argv[2],NULL,10);

  for(int i=3;i<size;++i)
    temp ^= (int)strtol(argv[i],NULL,10);

  return temp;
}

int main(int argc, char *argv[])
{
  int size = argc;
  int result;

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
              
    case '&': result = and(size, argv);
              break;
    case '|': result = or(size, argv);
              break;
    case '^': result = tild(size, argv);
              break;

    default: printf("Operator nut supported!\n");
  }
  
  printf("Result: %d\n", result);
  return 0;
}
