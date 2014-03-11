#include <stdio.h>

int main(int argc, char *argv[])
{
  int equal = 1;
  int i=0;

  while(equal)
  {
    equal = (argv[1][i] == argv[2][i]);
    if(argv[1][i] == '\0' || argv[2][i] == '\0')
      break;
    i++;
  }

  if (equal)
    printf("String are equal!\n");
  else
    printf("String are not equal\n");

  return 0;
}
