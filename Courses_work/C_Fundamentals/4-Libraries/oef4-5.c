#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <getopt.h>

int main(int argc, char *argv[])
{
  char *hvalue = NULL;
  char *dvalue = NULL;
  int c;
  int value;

  opterr = 0;

  while (( c=getopt(argc, argv, "id:h:")) != -1 )
  {
    switch(c)
    {
      case 'd': value = atoi(optarg);
                printf("%dd = %xh\n", value, value);
        break;
      case 'h':
                value = strtol(optarg,NULL,10);
                printf("%sh = %dd\n", optarg, value);
        break;
      default:  
        break;
    }
  }
  return 0;
}
