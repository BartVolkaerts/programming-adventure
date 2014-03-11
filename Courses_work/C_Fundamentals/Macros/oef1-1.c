#include <stdio.h>

#define LINE SYM_TO_STRING(__LINE__)
#define SYM_TO_STRING(SYM) STRINGIFY(SYM)
#define STRINGIFY(sym) #sym
#define STR(s) #s     //Stringification of a macro argument

int main(int argc, char *argv[])
{
  printf("%s\n",LINE);
  printf("%s\n",STR(__LINE__));
  return 0;
}
