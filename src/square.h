#ifndef SQUAREMINA_H
#define SQUAREMINA_H

#include "rect.h"

class Square : private Rect
{
public:
    Square(double length) : Rect(length, length)
    {
    }
    double getLength() { return dim1; }
    void setLength(double len) { dim1 = dim2 = len; }

    double calculateArea() override {
        return dim1 * dim1;
    }
private:
};
#endif