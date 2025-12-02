
#ifndef TERM
#define TERM
#include <cstdint>
namespace term
{

struct Color {
     const static Color BLUE; 
     const static Color RED; 
     const static Color GREEN; 
     const static Color BLACK;   
     const static Color WHITE;   
     const static Color YELLOW;  
     const static Color MAGENTA; 
     const static Color CYAN;    

    uint8_t r;
    uint8_t g;
    uint8_t b;
    Color(uint8_t r, uint8_t g, uint8_t b): r(r), g(g), b(b) {}
    Color() : r(255), g(255), b(255) {}
};





void setForegroundColor(const Color& color);
void setBackgroundColor(const Color& color);
void resetColors();
void clearScreen();
void clearLine();
void showCursor();
void hideCursor();
void setCursorPosition(unsigned int x,unsigned int y);
void getCursorPosition(int &x,int &y);

void getSize(int &cols, int &rows);
void sleep(uint32_t milliseconds);
} // namespace term

#endif