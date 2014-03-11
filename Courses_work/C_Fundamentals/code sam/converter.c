#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Temperature.h"



double StringToDouble(const char *str) {
	char *p = NULL;
	double getal = strtod(str, &p);
	if(p == str) {
		printf("Conversion failed! Please enter a valid number!\n");
		exit(1);
	}
	return getal;
}

double CtoK(double celcius) {
	return celcius + 273.15;
}

double CtoF(double celcius) {
	return (celcius * 9 / 5) + 32;
}

double KtoC(double kelvin) {
	return (kelvin - 273.15);
}
