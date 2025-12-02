#ifndef CIRCLEMINA_H
#define CIRCLEMINA_H

#include "geoshape.h"

class Circle : private GeoShape
{
public:
    Circle(double radius)
    {
        dim1 = radius;
        dim2 = radius;
    }
    double getRadius() { return dim1; }
    void setRadius(double radius) { dim1 = dim2 = radius; }
    double calculateArea() override {
        return 3.14*dim1*dim1;
    }
private:
};
#endif