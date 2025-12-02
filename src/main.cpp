#include <iostream>

#include <term/term.h>
#include <term/input.h>
#include "picture.h"
#include "line.h"
#include "rect.h"
#include "circle.h"
#include "point.h"
using namespace std;

//implmeneted with AI
int main(int, char**){
    // Create a Picture object
    Picture picture;

    // Create and add a rectangle to the picture
    Rect rect(Point(10, 10), Point(50, 30)); // Top-left corner at (10, 10), width 50, height 30
    rect.setColor(term::Color::CYAN);
    picture.addShape(&rect);

    // Create and add a line to the picture
    Line line(Point(10, 10), Point(40, 40)); // Line from (20, 20) to (70, 70)
    line.setColor(term::Color::RED);
    picture.addShape(&line);

    // Create and add a circle to the picture
    Circle circle(Point(20, 20), 10); // Center at (40, 40), radius 20
    circle.setColor(term::Color::BLACK);
    picture.addShape(&circle);
    
    // Draw the picture
    picture.draw();
    term::input::setInputMode(term::input::InputMode::Raw);
    term::input::readkey();
    return 0;
}
