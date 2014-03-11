#include <iostream>
#include "LexicalCast.hpp"

using namespace std;

int main (int argc, char** argv) {
  int a = tass::lexical_cast<int>(argv[1]);
  cout << a << endl;

  short b = tass::lexical_cast<short>(argv[1]);
  cout << b << endl;

  string c = tass::lexical_cast<string>(argv[1]);
  cout << c << endl;

}
