#include "Triangle.hpp"

Triangle::Triangle(float size)
  : Shape(), size(size) {
}

float Triangle::getCircum() const {
  return (size*size)/2; 
}

std::string Triangle::getType() const {
  return "I'm a triangle";
}
