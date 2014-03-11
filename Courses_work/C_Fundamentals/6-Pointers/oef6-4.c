#include <stdio.h>

int main(int argc, char *argv[])
{
  int counter;
  char *temp;
  for(int i=1; i < argc; i++)
  { 
    counter = 0;
    temp = argv[i];
    while(1)
    {
      if (*temp != '\0')
      {
        temp++;
        counter++;
      }
      else
        break;
    }
    printf("Argument %d has a length of %d\n", i, counter);
  }
  

  return 0;
}
