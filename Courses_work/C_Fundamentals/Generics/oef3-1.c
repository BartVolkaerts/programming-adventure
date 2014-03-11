#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>

#define GENERATE_SWAP_IMPL(type) void type ##_swap(type*a, type*b){ \
  type temp; temp = *a; *a = *b; *b = temp; }

typedef struct {
  uint64_t real;
  uint64_t imaginary;
} complex;

GENERATE_SWAP_IMPL(complex);

void swap(void* a, void *b, size_t size)
{
  void *temp = malloc(size);
  memcpy(temp,a,size);
  memcpy(a,b,size);
  memcpy(b,temp,size);
  free(temp);
}

int main(int argc, char **argv)
{
  complex a,b;
  a.real = 666;
  a.imaginary = 777;
  b.real = 42;
  b.imaginary = 44;

  printf("a={%ld,%ld}\n", a.real, a.imaginary);
  printf("b={%ld,%ld}\n", b.real, b.imaginary);

  swap(&a,&b,sizeof(complex));

  printf("a={%ld,%ld}\n", a.real, a.imaginary);
  printf("b={%ld,%ld}\n", b.real, b.imaginary);

  complex_swap(&a,&b);

  printf("a={%ld,%ld}\n", a.real, a.imaginary);
  printf("b={%ld,%ld}\n", b.real, b.imaginary);

  return 0;
}
