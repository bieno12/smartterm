#ifndef POINTMINA_H
#define POINTMINA_H

#include "shape.h"
#include <term/term.h>

struct Point
{
    int x;
    int y;
    Point(int x, int y) : x(x), y(y) {};
};
#endif