#include <iostream>

#include <term/term.h>
#include <term/input.h>
#include <term/tui.h>
using namespace std;

int main(int, char**){
    term::clearScreen();
    term::input::setInputMode(term::input::InputMode::Raw);
    term::hideCursor();
    
}
