#include <iostream>

#include <term/term.h>
#include <term/input.h>
#include "rect.h"
#include "circle.h"
#include "square.h"
#include "triangle.h"

using namespace std;

int main(int, char**){
    Triangle triangle(3, 4); // base = 3, height = 4
    Rect rect(5, 6);        // width = 5, height = 6
    Square square(4);       // side = 4
    Circle circle(7);       // radius = 7

    cout << "Triangle Area: " << triangle.calculateArea() << endl;
    cout << "Rectangle Area: " << rect.calculateArea() << endl;
    cout << "Square Area: " << square.calculateArea() << endl;
    cout << "Circle Area: " << circle.calculateArea() << endl;
}
