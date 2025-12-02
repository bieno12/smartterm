#ifndef RECTMINA_H
#define RECTMINA_H
#include "shape.h"
#include <term/term.h>
#include "point.h"

class Rect : public Shape
{
public:
    Rect() = default;
    Rect(Point start, Point end);

    void draw() override;

    void setStartPoint(Point start);
    void setEndPoint(Point end);
    void setDoFill(bool doFill);
    Point getStartPoint();
    Point getEndPoint();
    bool getDoFill();

private:
    Point mStart;
    Point mEnd;
    bool mDoFill;
};
#endif