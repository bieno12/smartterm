#include "line.h"
#include <iostream>
Line::Line(Point start, Point end, int thickness)
    : mStart(start), mEnd(end), mThickness(thickness) {}

// Implemented via AI
#include <cmath>
#include <algorithm>

// helper: plot a point at integer (x=col, y=row)
static inline void plot_point(int x, int y) {
    // Protect against negative positions if you want:
    if (x < 0 || y < 0) return;
    term::setCursorPosition(y, x);
    std::cout << " ";
}

// integer Bresenham from (x0,y0) to (x1,y1)
static void bresenham_line(int x0, int y0, int x1, int y1) {
    int dx = std::abs(x1 - x0);
    int sx = x0 < x1 ? 1 : -1;
    int dy = -std::abs(y1 - y0);
    int sy = y0 < y1 ? 1 : -1;
    int err = dx + dy; // err = dx + dy (note dy is negative)

    while (true) {
        plot_point(x0, y0);
        if (x0 == x1 && y0 == y1) break;
        int e2 = 2 * err;
        if (e2 >= dy) { err += dy; x0 += sx; } // move in x
        if (e2 <= dx) { err += dx; y0 += sy; } // move in y
    }
}

void Line::draw() {
    int x1 = mStart.x; // column
    int y1 = mStart.y; // row
    int x2 = mEnd.x;
    int y2 = mEnd.y;
    int thickness = std::max(1, mThickness);

    term::setBackgroundColor(mColor);

    // vector from start to end
    int dx = x2 - x1;
    int dy = y2 - y1;

    double length = std::hypot((double)dx, (double)dy);

    if (length < 1e-9) {
        // Degenerate: single point -> draw a filled square of size = thickness
        int half = thickness / 2;
        for (int oy = -half; oy <= half; ++oy) {
            for (int ox = -half; ox <= half; ++ox) {
                plot_point(x1 + ox, y1 + oy);
            }
        }
        term::resetColors();
        return;
    }

    // unit perpendicular vector to the line: (-dy/len, dx/len)
    double nx = - (double)dy / length;
    double ny =   (double)dx / length;

    // We will draw multiple integer-offset parallel lines.
    // Center the offsets: if thickness is odd, include zero; if even, offsets are symmetric.
    int half = (thickness - 1) / 2;
    for (int t = -half; t <= half; ++t) {
        // offset in floating point
        double ox = nx * (double)t;
        double oy = ny * (double)t;

        // round offsets to nearest integer
        int ix = (int)std::lround(ox);
        int iy = (int)std::lround(oy);

        // Draw Bresenham on the offset line
        bresenham_line(x1 + ix, y1 + iy, x2 + ix, y2 + iy);
    }

    // If thickness was even (e.g. 2,4) we still need to cover the remaining offset
    // Example: thickness=2 -> t values above produce only one offset (t=0) when using (thickness-1)/2.
    // So handle the upper half when thickness is even:
    if ((thickness % 2) == 0) {
        // add the complement offset (half + 1)
        int t = half + 1;
        double ox = nx * (double)t;
        double oy = ny * (double)t;
        int ix = (int)std::lround(ox);
        int iy = (int)std::lround(oy);
        bresenham_line(x1 + ix, y1 + iy, x2 + ix, y2 + iy);
    }

    term::resetColors();
}

void Line::setStartPoint(Point start)
{
    mStart = start;
}

void Line::setEndPoint(Point end)
{
    mEnd = end;
}

void Line::setThickness(int thickness)
{
    mThickness = thickness;
}

Point Line::getStartPoint()
{
    return mStart;
}

Point Line::getEndPoint()
{
    return mEnd;
}

int Line::getThickness()
{
    return mThickness;
}
