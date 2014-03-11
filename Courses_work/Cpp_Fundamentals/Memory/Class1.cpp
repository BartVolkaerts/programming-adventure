#include "Class1.hpp"

Class1::Class1(std::string name) : name(name) {
  std::cout << "Constructor Class1  " << name << std::endl;
}
Class1::~Class1() {
  std::cout << "Destructor Class1  " << name << std::endl;
}
