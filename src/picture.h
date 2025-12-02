#ifndef PICTUREMINA_H
#define PICTUREMINA_H
#include <myutils/vector.h>
#include "shape.h"
class Picture
{
public:
    Picture() = default;

    void draw();
    void addShape(Shape* shape);
private:
    myutils::Vector<Shape*> mShapes;
};
#endif