#include <iostream>
#include "MyException.hpp"

using namespace std;

int main(int argc, char **argv) {
  try {
    throw MyException("Hola, een error");
  }
  catch(exception &e) {
    cerr << e.what() << endl;
  }
}
