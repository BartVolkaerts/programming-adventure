#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <string.h>

char *concatenate_realloc(char* first, ...)
{
  va_list ap;
  char *tmp, *result;
  int len;
  
  len = strlen(first);
  result = (char*)malloc(len+1);
  if(result == NULL)
    exit(1);
  memcpy(result,first,len);

  va_start(ap,first);
  tmp = va_arg(ap,char *);
  while(strcmp(tmp,"end") != 0)
  {
    int tmplen = strlen(tmp);
    result = (char*)realloc(result, len+tmplen+1);
    memcpy(&result[len], tmp, tmplen);
    len += tmplen;
    tmp = va_arg(ap,char*);
  }
  va_end(ap);

  return result;
}

char *concatenate_bigchunck(char* first, ...)
{
  va_list ap;
  char *tmp, *result;
  int len;

  len = strlen(first);
  va_start(ap,first);
  tmp = va_arg(ap,char*);
  while(strcmp(tmp,"end") != 0)
  {
    len += strlen(tmp);
    tmp = va_arg(ap,char*);
  }
  va_end(ap);

  len++;
  result = (char*)malloc(len);

  len = strlen(first);
  memcpy(result,first,len);
  
  va_start(ap,first);
  tmp = va_arg(ap,char *);
  while(strcmp(tmp,"end") != 0)
  {
    int tmplen = strlen(tmp);
    memcpy(&result[len], tmp, tmplen);
    len += tmplen;
    tmp = va_arg(ap,char*);
  }
  va_end(ap);

  return result;
}

int main(int argc, char *argv[])
{
  char *result;
  result = concatenate_realloc("Hallo, ","Ik ","ben " ,"Bart!","  abcdefghijklmnopqrstuvwxyz ","end");
  printf("Result of concat realloc:\t%s\n", result);
  free(result);

  result = concatenate_bigchunck("Hallo, ","Ik ","ben " ,"Bart!","  abcdefghijklmnopqrstuvwxyz","end");
  printf("Result of concat bigchunck:\t%s\n", result);
  free(result);
  return 0;
}
