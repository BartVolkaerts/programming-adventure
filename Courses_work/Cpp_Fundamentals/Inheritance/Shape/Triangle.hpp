#ifndef TRIANGLE_H
#define TRIANGLE_H

#include "Shape.hpp"

class Triangle : public Shape {
  public:
    Triangle(float);
    virtual float getCircum() const;
    virtual std::string getType() const;

  private:
    int size;
};

#endif
