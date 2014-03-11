#ifndef transport_H
#define transport_H

struct transport_layer {
	int (*write)(char *data, int length);
	int (*read)(char *buffer, int length);
};

int write(char *data, int length);
int read(char *buffer, int length);

#endif