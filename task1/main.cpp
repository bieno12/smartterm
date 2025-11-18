#include <iostream>

#include <term/term.h>
using namespace std;
int main(int, char**){
    term::clearScreen();
    term::setCursorPosition(5, 5);
    term::setBackgroundColor(term::Color(100, 100, 100));
    term::setForegroundColor(term::Color::RED);
    cout << "Hello, Smart Term!" << endl;
    term::resetColors();
    term::sleep(2000);
    term::clearScreen();
    term::setCursorPosition(1, 1);
    cout << "Goodbye!" << endl;

    return 0;
}
