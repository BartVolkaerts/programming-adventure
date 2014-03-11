#include <iostream>
#include "Class1.hpp"

using namespace std;

Class1 klasseg("GLOBAL");

int main(int argc, char **argv)
{
  Class1 klasses("STATIC");
  Class1 *klassed = new Class1("DYNAMIC");

  delete(klassed);
}
