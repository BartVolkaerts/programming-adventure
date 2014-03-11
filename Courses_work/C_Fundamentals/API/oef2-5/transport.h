#ifndef TRANSPORT_H
#define TRANSPORT_H

int read(char* buffer, int length);
int write(char *message, int length);

typedef struct transport_layer
{
  int (*read)(char*,int);
  int (*write)(char*,int);
} Transport;

#endif
