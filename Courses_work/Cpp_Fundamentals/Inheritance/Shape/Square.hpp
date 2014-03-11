#ifndef SQUARE_H
#define SQUARE_H

#include "Shape.hpp"

class Square : public Shape {
  public:
    Square(float);
    virtual float getCircum() const;
    virtual std::string getType() const;

  private:
    int size;
};

#endif
