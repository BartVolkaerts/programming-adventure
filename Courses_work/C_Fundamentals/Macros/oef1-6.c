#include <stdio.h>
#include <time.h>

#if LOG_LEVEL>=1
#define PRINTTIME do{time_t rtime;struct tm *tmi;time(&rtime);tmi=localtime(&rtime);printf("%d:%d:%d ",tmi->tm_hour,tmi->tm_min,tmi->tm_sec);}while(0)
#define PRINTFL printf("%s:%d ",__FILE__, __LINE__)
#define LogError(s) PRINTTIME; printf("ERROR "); PRINTFL; printf("%s\n",s)
#else
#define LogError(s)
#endif

#if LOG_LEVEL>=2
#define LogTrace(s) PRINTTIME; printf("TRACE "); PRINTFL; printf("%s\n",s)
#else
#define LogTrace(s)
#endif

#if LOG_LEVEL>=3
#define LogDebug(s) PRINTTIME; printf("DEBUG "); PRINTFL; printf("%s\n",s)
#else
#define LogDebug(s)
#endif

int main(int argc, char *argv[])
{
  LogError("Hola");
  LogTrace("Ai");
  LogDebug("Oei");

  return 0;
}
