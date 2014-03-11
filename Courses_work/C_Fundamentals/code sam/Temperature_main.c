#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Temperature.h"

int main(int argc, char const *argv[])
{
	if(argc < 3 ) {
		printf("Usage: %s <c2k | c2f> <degrees>\n", argv[0]);
		return 0;
	}

	double degrees = StringToDouble(argv[2]);

	if(strncmp(argv[1], "c2f", 3) == 0 ) {
		printf("Result = %g\n", CtoF(degrees));
	}
	else if(strncmp(argv[1], "c2k", 3) == 0 ) {
		printf("Result = %g\n", CtoK(degrees));
	} 
	else if(strncmp(argv[1], "k2c", 3) == 0 ) {
		printf("Result = %g\n", KtoC(degrees));
	}
	return 0;
}