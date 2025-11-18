#pragma once
#include <cstdint>
#include <term/input.h>
namespace tui
{
struct Position
{
    uint32_t x;
    uint32_t y;
};


class Widget {
public:
    Position mPosition{};

public:
    Widget() = default;
    Widget(Position pos) : mPosition(pos) {}
    virtual void draw() = 0;
    virtual ~Widget() = default;

    //input handling
    virtual void onKeyPressed(term::input::Key keyPressed) {}
};

} // namespace tui