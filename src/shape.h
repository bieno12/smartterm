#ifndef SHAPEMINA_H
#define SHAPEMINA_H
#include <term/term.h>
class Shape
{
public:
    Shape() = default;
public:
    virtual void draw() = 0;

    void setColor(term::Color color)
    {
        mColor = color;
    }
    inline term::Color getColor()
    {
        return mColor;
    }
protected:
    term::Color mColor;
};
#endif