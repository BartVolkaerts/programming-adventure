#include <iostream>
#include "Complex.hpp"
using namespace std;

Complex::Complex() : real(), imag() {
}

Complex::Complex(const Complex& c) : real(c.real), imag(c.imag) {
}

Complex::Complex(const Complex* c) : real(c->real), imag(c->imag) {
}

Complex::Complex(int real, int imag) : real(real), imag(imag) {
}

int Complex::getReal() const {
  return real;
}

int Complex::getImag() const {
  return imag;
}

void Complex::setReal(int real) {
  this->real = real;
}

void Complex::setImag(int imag) {
  this->imag = imag;
}

Complex Complex::operator+(const Complex& c) const {
  return Complex(real + c.real, imag + c.imag);
}

Complex& Complex::operator+=(const Complex& c) {
  real += c.real;
  imag += c.imag;
  return *this;
}

Complex Complex::operator-(const Complex& c) const {
  return Complex(real - c.real, imag - c.imag);
}

Complex& Complex::operator-=(const Complex& c) {
  real -= c.real;
  imag -= c.imag;
  return *this;
}

Complex Complex::operator*(const Complex& c) const {
  return Complex((real*c.real-imag*c.imag),(imag*c.real+real*c.imag));
}

Complex& Complex::operator*=(const Complex& c) {
  real = (real*c.real-imag*c.imag);
  imag = (imag*c.real+real*c.imag);
  return *this;
}

istream& operator >> (istream& stream, Complex& a) {
  int x,y;
  char bla;
  stream >> x >> bla >> y;
  a.setReal(x);
  a.setImag(y);
  return stream;
}

ostream& operator << (ostream& stream, Complex a) {
  stream << a.getReal() << "+" << a.getImag() << "i";
  return stream;
}
