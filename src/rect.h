#ifndef RECTMINA_H
#define RECTMINA_H

#include "geoshape.h"

class Rect : public GeoShape
{
public:
    Rect(double l, double w)
    {
        dim1 = l;
        dim2 = w;
    }
    double calculateArea() override {
        return dim1 * dim2;
    }
private:
};

#endif