#ifndef OPERATOR_H
#define OPERATOR_H

#include <iostream>

istream& operator >> (istream& stream, Complex& a);
ostream& operator << (ostream& stream, Complex a);

#endif
