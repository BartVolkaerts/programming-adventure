#include "Circle.hpp"

Circle::Circle(float radius)
  : Shape(), size(radius) {
}

float Circle::getCircum() const {
  return 3.14*size*size;
}

std::string Circle::getType() const {
  return "I'm a circle";
}
