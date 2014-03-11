#ifndef CIRCLE_H
#define CIRCLE_H

#include "Shape.hpp"

class Circle : public Shape {
  public:
    Circle(float);
    virtual float getCircum() const;
    virtual std::string getType() const;

  private:
    int size;
};

#endif
