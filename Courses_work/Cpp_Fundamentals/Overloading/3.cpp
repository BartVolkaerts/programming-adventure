#include <iostream>

using namespace std;

struct Complex {
  int real;
  int imag;
};

struct Complex operator+(Complex val1, Complex val2)
{
  Complex result;
  result.real = val1.real + val2.real;
  result.imag = val1.imag + val2.imag;

  return result;
}

struct Complex operator-(Complex val1, Complex val2)
{
  Complex result;
  result.real = val1.real - val2.real;
  result.imag = val1.imag - val2.imag;

  return result;
}

ostream& operator<< (std::ostream& stream, const Complex& val)
{
  return stream << "Complex{real=" << val.real << ", imaginary=" << val.imag << "}";
}

int main(int argc, char **argv)
{
  Complex val1;
  Complex val2;
  val1.real = 5;
  val1.imag = 7;
  val2.real = 6;
  val2.imag = 8;

  cout << val1 << endl;
  cout << val2 << endl;

  cout << val1+val2 << endl;
  cout << val1-val2 << endl;

}

