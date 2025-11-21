#ifndef LIST_PAGE_H
#define LIST_PAGE_H
#include <term/tui.h>
#include <string>
#include <iostream>
#include <vector>
#include "application.h"



class DisplayPage : public tui::Page
{

public:
    DisplayPage(Application *application, Buffer<Buffer<char>> &lines)
        : Page("Display "), mApplication(application), mLines(lines)
    {
        
    }

    void draw() override {
        Page::draw();
        for (int i = 0; i < mLines.getSize(); i++)
        {
            term::setCursorPosition(2, 2 + i);
            for (int j = 0; j < mLines[i].getSize(); j++)
                std::cout << mLines[i][j];
        }
    }

    ~DisplayPage() {
    }

    
private:
    Application *mApplication;

    Buffer<Buffer<char>> &mLines;
};
#endif