#ifndef LINEMINA_H
#define LINEMINA_H

#include "shape.h"
#include <term/term.h>
#include "point.h"

class Line : public Shape
{
public:
    Line() = default;
    Line(Point start, Point end, int thickness = 1);

    void draw() override;

    void setStartPoint(Point start);
    void setEndPoint(Point end);
    void setThickness(int thickness);

    Point getStartPoint();
    Point getEndPoint();
    int getThickness();

private:
    Point mStart;
    Point mEnd;
    int mThickness;
};
#endif