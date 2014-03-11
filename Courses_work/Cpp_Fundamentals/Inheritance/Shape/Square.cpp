#include "Square.hpp"

Square::Square(float size)
  : Shape(), size(size) {
}

float Square::getCircum() const {
  return size*size;
}

std::string Square::getType() const {
  return "I'm a square";
}
