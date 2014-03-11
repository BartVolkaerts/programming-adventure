#include <iostream>
#include "Complex.hpp"

using namespace std;

ostream& operator<< (ostream& stream, const Complex& val) {
  return stream << "Complex{Real=" << val.getReal() << ", Imag={" << val.getImag() << "}";
}

int main(int argc, char **argv)
{
  Complex val;
  Complex val2;

  val.setReal(5);
  val.setImag(8);
  val2.setReal(1);
  val2.setImag(2);

  cout << val << endl;
  cout << (val+val2) << endl;
  cout << val << endl;
  cout << (val+=val2) << endl;
  cout << val << endl;
}
