#include <stdio.h>
#include "transport.h"
#include <assert.h>

Transport transport = {&read, &write};

int write(char *message, int length)
{
  assert(message);
  assert(length>0);

  printf("BEGIN_OF_WRITE\n");
  for(int i = 0; i < length; i++)
  {
    printf("%c ", message[i]);
  }

  printf("\nEND_OF_WRITE\n");
  return 0;
}

int read(char* buffer, int length)
{
  printf("BEGIN_OF_READ\n");

  printf("END_OF_READ\n");
  return 0;
}
