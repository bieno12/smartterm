#include "internal.h"
#include <iostream>
#include <thread>
#include "term/term.h"
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

void term::clearLine()
{
    cout << "\x1b[2K";
}
void term::showCursor()
{
    cout << "\x1b[?25h";
}

void term::hideCursor()
{
    cout << "\x1b[?25l";
}

void term::getCursorPosition(int &x, int &y)
{
    // Ask terminal for cursor position
    std::cout << "\x1b[6n" << std::flush;

    char ch;
    std::string response;

    // Read until we get 'R'
    while (std::cin.get(ch)) {
        response += ch;
        if (ch == 'R')
            break;
    }

    // Expected: ESC [ rows ; cols R
    int r, c;
    if (std::sscanf(response.c_str(), "\x1b[%d;%dR", &r, &c) == 2) {
        y = r;
        x = c;
    } else {
        y = x = -1; // error
    }
}
void term::getSize(int &cols, int &rows)
{
    // Move cursor far bottom-right
    setCursorPosition(999, 999);
    getCursorPosition(cols, rows);

}

void term::setCursorPosition(unsigned int x,unsigned int y)
{
    cout << "\x1b[" << y << ";" << x << "H";
}

void term::sleep(uint32_t milliseconds)
{
    this_thread::sleep_for(chrono::milliseconds(milliseconds));
}