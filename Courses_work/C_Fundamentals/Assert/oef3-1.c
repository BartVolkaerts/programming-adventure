#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <assert.h>

void *safe_malloc(size_t size);

int main(int argc, char *argv[])
{
  int *intp = (int*)safe_malloc(ULONG_MAX);
  printf("Gelukt!\n");

  return 0;
}


void *safe_malloc(size_t size)
{
  void *p = malloc(size);
  assert(p);
  
  return p;
}
