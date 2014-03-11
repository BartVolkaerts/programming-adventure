#ifndef SHAPE_H
#define SHAPE_H

#include <iostream>

class Shape {
  public:
    virtual float getCircum() const = 0;
    virtual std::string getType() const = 0;
};

#endif
