#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int isPalindrome(char *arg)
{
  int end = strlen(arg)-1;
  int begin = 0;
  char a;
  char b;
  while(end>=begin)
  {
    a = arg[begin];
    b = arg[end];
    printf("%c == %c?\n", a,b);
    if(a<=90)
      a+=32;
    if(b<=90)
      b+=32;

    if(a == b)
    {
      begin++;
      end--;
    }
    else
      return 0;
  }
  return 1;
}

int main(int argc, char *argv[])
{
  for(int i=1;i<argc;++i)
  {
    if(isPalindrome(argv[i]))
      printf("%s is a Palindrome\n", argv[i]);
  }
  return 0;
}
