#include <iostream>
#include "SmartPointer.hpp"

using namespace std;

class Foo{};

int main(void){

  string delim = "----------";

  cout << delim << "First check" << endl;
  SmartPointer<Foo> fsp(new Foo()); //refcount = 1
  {
    SmartPointer<Foo> fsp2 = fsp; //refcount ++
  }//refcount--
  cout << delim << "Second check" << endl;

  fsp = SmartPointer<Foo>(new Foo()); //refcount ++
 
  cout << delim << "Third check" << endl;

  fsp = fsp;



}
