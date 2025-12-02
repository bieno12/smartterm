#ifndef TRIANGLEMINA_H
#define TRIANGLEMINA_H

#include "geoshape.h"

class Triangle : public GeoShape
{
public:
    Triangle(double b, double h)
    {
        dim1 = b;
        dim2 = h;
    }
    double calculateArea() override {
        return 0.5 * dim1 * dim2;
    }

    
};
#endif