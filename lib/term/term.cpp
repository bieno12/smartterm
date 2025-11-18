#include "internal.h"
#include <iostream>
#include <thread>
using namespace std;
using namespace term;


const Color Color::BLUE = Color(0, 0, 255);
const Color Color::RED = Color(255, 0, 0);
const Color Color::GREEN = Color(0, 255, 0);
const Color Color::BLACK   = Color(0, 0, 0);
const Color Color::WHITE   = Color(255, 255, 255);
const Color Color::YELLOW  = Color(255, 255, 0);
const Color Color::MAGENTA = Color(255, 0, 255);
const Color Color::CYAN    = Color(0, 255, 255);


void term::setForegroundColor(const Color& color)
{
    cout << "\x1b[" << "38;2;" << (int)color.r << ";" << (int)color.g << ";" << (int)color.b << "m";
}

void term::setBackgroundColor(const Color& color)
{
    cout << "\x1b[" << "48;2;" << (int)color.r << ";" << (int)color.g << ";" << (int)color.b << "m";
}

void term::resetColors()
{
    cout << "\x1b[0m";
}

void term::clearScreen()
{
    cout << "\x1b[2J";
}

void term::showCursor()
{
    cout << "\x1b[?25h";
}

void term::hideCursor()
{
    cout << "\x1b[?25l";
}

void term::setCursorPosition(unsigned int x,unsigned int y)
{
    cout << "\x1b[" << y << ";" << x << "H";
}

void term::sleep(uint32_t milliseconds)
{
    this_thread::sleep_for(chrono::milliseconds(milliseconds));
}