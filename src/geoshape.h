#ifndef GEOSHAPEMINA_H
#define GEOSHAPEMINA_H

class GeoShape
{
public:
    virtual double calculateArea() = 0;

    double getDim1() {return dim1; }
    double getDim2() {return dim2; }
    void setDim1(double v) { dim1 = v; }
    void setDim2(double v) { dim2 = v; }
protected:
    double dim1;
    double dim2;
};
#endif