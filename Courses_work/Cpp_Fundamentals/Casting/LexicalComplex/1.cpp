#include <iostream>
#include "Complex.hpp"
#include "LexicalComplex.hpp"
#include "Operator.hpp"

using namespace std;

int main (int argc, char** argv) {
  Complex a(5,6);
  string s = tass::lexical_cast<string>(a);
  cout << s << endl;


  Complex b = tass::lexical_cast<Complex>(argv[1]);
  cout << b.getReal() << "+" << b.getImag() << "i" << endl;
}
