#include <iostream>

#include "Circle.hpp"
#include "Square.hpp"
#include "Triangle.hpp"

using namespace std;

int main(int argc, char **argv) {
  
  Shape *shape[3];
  shape[0] = new Circle(5);
  shape[1] = new Square(6);
  shape[2] = new Triangle(7);

  for(int i = 0; i < 3; i++) {
    cout << shape[i]->getType() << endl;
    cout << shape[i]->getCircum() << endl;
    delete(shape[i]);
  }
}
