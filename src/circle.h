#ifndef CIRCLEMINA_H
#define CIRCLEMINA_H

#include "shape.h"
#include <term/term.h>
#include "point.h"

class Circle : public Shape
{
public:
    Circle() = default;;
    Circle(Point center, int radius);

    void draw();

    void setCenter(Point center);
    void setDoFill(bool doFill);
    void setRadius(int radius);
    Point getCenter();
    bool getDoFill();
    int getRadius();

private:
    Point mCenter;
    bool mDoFill;
    int mRadius;
};

#endif