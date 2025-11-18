#include "term/input.h"


#include <iostream>

#ifndef _WIN32
#include <termios.h>
#include <unistd.h>

static struct termios originalTermios;

#else
#include <windows.h>
#include <conio.h>
#endif

void term::input::setInputMode(InputMode mode) {
#ifndef _WIN32
    if (mode == InputMode::Raw) {
        struct termios rawTermios;
        tcgetattr(STDIN_FILENO, &originalTermios);
        rawTermios = originalTermios;
        rawTermios.c_lflag &= ~(ECHO | ICANON);
        tcsetattr(STDIN_FILENO, TCSANOW, &rawTermios);
    } else if (mode == InputMode::Cooked) {
        tcsetattr(STDIN_FILENO, TCSANOW, &originalTermios);
    }
#else
    static DWORD originalConsoleMode = 0;
    HANDLE hStdin = GetStdHandle(STD_INPUT_HANDLE);
    
    if (mode == InputMode::Raw) {
        GetConsoleMode(hStdin, &originalConsoleMode);
        DWORD rawMode = originalConsoleMode & ~(ENABLE_ECHO_INPUT | ENABLE_LINE_INPUT);
        SetConsoleMode(hStdin, rawMode);
    } else if (mode == InputMode::Cooked) {
        SetConsoleMode(hStdin, originalConsoleMode);
    }
#endif
}

term::input::Key term::input::readkey()
{
#ifdef _WIN32
    int ch = _getch();

    // Special keys in Windows console: first byte is 0 or 0xE0,
    // second byte indicates the actual key.
    if (ch == 0 || ch == 0xE0) {
        int ch2 = _getch();
        switch (ch2) {
            case 72: return Key::ArrowUp;    // Up
            case 80: return Key::ArrowDown;  // Down
            case 75: return Key::ArrowLeft;  // Left
            case 77: return Key::ArrowRight; // Right
            case 71: return Key::Home;       // Home
            case 79: return Key::End;        // End
            default: return Key::NoKey;
        }
    }

    // Normal keys
    if (ch == 27) {
        return Key::Esc;
    }
    if (ch == 13) {
        return Key::Enter;
    }
    if (ch == 8) {
        return Key::Backspace;
    }

    return static_cast<Key>(static_cast<unsigned char>(ch));

#else
    // POSIX / ANSI terminals (your original logic, slightly guarded)
    char ch;
    if (!std::cin.get(ch)) {
        return Key::NoKey;
    }

    if (ch == 27) {
        // Possible special key sequence: ESC [ X
        if (std::cin.peek() == '[') {
            std::cin.get(); // consume '['
            char nextChar;
            if (!std::cin.get(nextChar)) {
                return Key::NoKey;
            }

            switch (nextChar) {
                case 'A': return Key::ArrowUp;
                case 'B': return Key::ArrowDown;
                case 'C': return Key::ArrowRight;
                case 'D': return Key::ArrowLeft;
                case 'H': return Key::Home;
                case 'F': return Key::End;
                default:  return Key::NoKey;
            }
        } else {
            return Key::Esc;
        }
    }

    if (ch == 10 || ch == 13) {
        return Key::Enter;
    }
    if (ch == 8 || ch == 127) {
        return Key::Backspace;
    }

    return static_cast<Key>(static_cast<unsigned char>(ch));
#endif
}
