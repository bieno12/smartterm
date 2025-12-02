#include "picture.h"

void Picture::draw()
{
    term::clearScreen();
    for (Shape * shape : mShapes)
        shape->draw();
}

void Picture::addShape(Shape *shape)
{
    mShapes.push_back(shape);
}
