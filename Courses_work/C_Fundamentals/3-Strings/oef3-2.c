#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[])
{
  for(int i=1;i<argc;++i)
  {
    printf("%de argument: %s\n\tlengte: %lu\n", i, argv[i], strlen(argv[i]));
  }
  return 0;
}
