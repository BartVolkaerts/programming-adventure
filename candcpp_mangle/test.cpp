#include <iostream>

using namespace std;
#include "test.h"

void Test::print(char * test)
{
  cout << "Print from c++" << endl << test << endl;
}

void printje(char *test)
{
  Test::print(test);
}
