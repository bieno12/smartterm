#include "circle.h"
#include <iostream>
Circle::Circle(Point center, int radius) : mCenter(center), mRadius(radius) {}

// Implemented using AI
void Circle::draw()
{
    bool doFill = mDoFill;
    int x = mCenter.x;
    int y = mCenter.y;
    term::setBackgroundColor(mColor);
    term::setCursorPosition(y, x);
    int radius = mRadius;
    for (int i = -radius; i <= radius; ++i)
    {
        for (int j = -radius; j <= radius; ++j)
        {
            if (i * i + j * j <= radius * radius)
            {
                if (doFill || i * i + j * j >= (radius - 1) * (radius - 1))
                {
                    term::setCursorPosition(y + i, x + j);
                    std::cout << '*';
                }
            }
        }
    }
    term::resetColors();
}

void Circle::setCenter(Point center)
{
    mCenter = center;
}

void Circle::setDoFill(bool doFill)
{
    mDoFill = doFill;
}

void Circle::setRadius(int radius)
{
    mRadius = radius;
}

Point Circle::getCenter()
{
    return mCenter;
}

bool Circle::getDoFill()
{
    return mDoFill;
}

int Circle::getRadius()
{
    return mRadius;
}
