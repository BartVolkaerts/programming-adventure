#include <iostream>
#include "TassString.hpp"

using namespace std;


int main(int argc, char **argv)
{
  TassString *str = new TassString("HELLIX FOSSIL, OUR LORD AND SAVIER");
  cout << str->print() << endl;

  TassString * str2 = new TassString(*str, (size_t)15, (size_t)19);
  cout << str2->print() << endl;

  TassString *str3 = new TassString((size_t)500, 'x');
  cout << str3->print() << endl;

  TassString *str4 = new TassString(str->print(), (size_t)10);
  cout << str4->print() << endl;

  TassString *str5 = new TassString(*str);
  cout << str5->print() << endl;

  TassString plus;
  plus = ((*str)+*str3);

  cout << plus.print() << endl;

  delete(str5);
  delete(str4);
  delete(str3);
  delete(str2);
  delete(str);
}
