#include <stdio.h>
#include <stdlib.h>

void memcopy(void* dst, void* src, int size)
{
  char* psrc = src;
  char* pend = src + size;
  char* pdst = dst;
  for (; psrc != pend; psrc++, pdst++)
  {
    *pdst = *psrc;
  }


}

int main()
{
  int a[] = {1,2,3,4};
  int b[4];

  memcopy((void*)b, a, sizeof a);

  char* source = (char*)&a[0];
  char* end = source + sizeof a;
  char* dst = (char*)&b[0];
  for (; source != end ; source++, dst++)
  {
    printf("%c %c\n", *source, *dst);
  }

  return 0;
}
