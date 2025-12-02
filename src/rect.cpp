#include "rect.h"

#include <iostream>

Rect::Rect(Point start, Point end) : mStart(start), mEnd(end)
{
}
//implemented with AI
void Rect::draw()
{
    int x1 = mStart.x;
    int y1 = mStart.y;
    int x2 = mEnd.x;
    int y2 = mEnd.y;
    bool doFill = mDoFill;
    
    term::setBackgroundColor(mColor);
    for (int y = y1; y <= y2; ++y)
    {

        for (int x = x1; x <= x2; ++x)
        {
            if (doFill || y == y1 || y == y2 || x == x1 || x == x2)
            {
                term::setCursorPosition(x, y);
                std::cout << "*";
            }
        }
    }
    term::resetColors();
}


void Rect::setStartPoint(Point start)
{
    mStart = start;
}

void Rect::setEndPoint(Point end)
{
    mEnd = end;
}

void Rect::setDoFill(bool doFill)
{
    mDoFill = doFill;
}

Point Rect::getStartPoint()
{
    return mStart;
}

Point Rect::getEndPoint()
{
    return mEnd;
}

bool Rect::getDoFill()
{
    return mDoFill;
}
