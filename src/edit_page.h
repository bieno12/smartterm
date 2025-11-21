#ifndef EDIT_PAGE_H
#define EDIT_PAGE_H
#include <term/tui.h>
#include <term/signal.h>
#include <string>
#include <iostream>
#include <vector>
#include "application.h"



class EditPage : public tui::Page
{

public:
    EditPage(Application *application, Buffer<Buffer<char>> &lines)
        : Page("Edit a file"), mApplication(application), mLines(lines)
            , mCursorCol(0), mCursorRow(0)
    {
        term::showCursor();
        term::setCursorPosition(offsetX + mCursorCol, offsetY + mCursorRow);
    }

    void draw() override {
        Page::draw();

        for (int i = 0; i < mLines.getSize(); i++)
        {
            term::setCursorPosition(offsetX, offsetY + i);

            for (int j = 0; j < mLines[i].getSize(); j++)
            {
                std::cout << mLines[i][j];
            }
            
        }
        term::setCursorPosition(offsetX + mCursorCol, offsetY + mCursorRow);

    }
    void onKeyPressed(term::input::Key keyPressed)
    {
        using term::input::Key;
        if(keyPressed == Key::ArrowLeft)
        {
            moveCursorLeft();
        }
        else if(keyPressed == Key::ArrowRight)
        {
            moveCursorRight();
        }
        else if(keyPressed == Key::ArrowDown)
        {
            moveCursorDown();
        }
        else if(keyPressed == Key::ArrowUp)
        {
            moveCursorUp();
        }
        else if(keyPressed == Key::Enter)
        {
            insertLine();
            moveCursorRight();

        }
        else if (keyPressed == Key::Backspace)
        {
            moveCursorLeft();
            deleteChar();
        }
        else
        {
            insertChar(static_cast<char>(keyPressed));
        }
        term::setCursorPosition(offsetX + mCursorCol, offsetY + mCursorRow);
    }
    ~EditPage() {
    }


    //cursor movement
    void moveCursorUp()
    {
        if(mCursorRow > 0)
            mCursorRow--;
        if(mCursorCol > mLines[mCursorRow].getSize())
            mCursorCol = mLines[mCursorRow].getSize();
    }
    void moveCursorDown()
    {
        if(mCursorRow < mLines.getSize() - 1)
            mCursorRow++;

        if(mCursorCol > mLines[mCursorRow].getSize())
            mCursorCol = mLines[mCursorRow].getSize();
    }
    void moveCursorLeft()
    {
        if(mCursorCol > 0)
            mCursorCol--;
        else
        {
            if(mCursorRow > 0)
            {
                mCursorRow--;
                mCursorCol = mLines[mCursorRow].getSize();
            }
        }
    }
    void moveCursorRight()
    {
        if(mCursorCol < mLines[mCursorRow].getSize())
            mCursorCol++;
        else
        {
            if(mCursorRow < mLines.getSize() - 1)
            {
                mCursorCol = 0;
                mCursorRow++;
            }
        }
    }

    // insertion/deletion commands
    void insertChar(char c)
    {
        //insertion is before index
        if(mCursorCol == mLines[mCursorRow].getSize())
            mLines[mCursorRow].push_back(c);
        else
            mLines[mCursorRow].insert(mCursorCol, c);
        moveCursorRight();
        drawLine(mCursorRow);
    }

    void deleteChar()
    {
        if(mCursorCol >= mLines[mCursorRow].getSize())
        {
            if (mCursorRow  >= mLines.getSize() - 1)
                return ;
            for (int i = 0; i < mLines[mCursorRow+1].getSize(); i++)
            {
                mLines[mCursorRow].push_back(mLines[mCursorRow+1][i]);
            }
            mLines.erase(mCursorRow+1);
            return;
        }

        mLines[mCursorRow].erase(mCursorCol);
        drawLine(mCursorRow);
    }
    void insertLine()
    {
        //insertion is after index
        uint32_t insertedRowNumber;
        if(mCursorRow == mLines.getSize())
        {
            mLines.push_back(Buffer<char>());
            insertedRowNumber = (mLines.getSize() - 1);
        }
        else
        {
            mLines.insert(mCursorRow + 1, Buffer<char>());
            insertedRowNumber = mCursorRow + 1;
        }
        //populate the newline with chars from right of cursor
        for (int i = mCursorCol; i < mLines[mCursorRow].getSize(); i++)
        {
            mLines[insertedRowNumber].push_back(mLines[mCursorRow][i]);
        }
        //delete the right side of the cursor
        while(mLines[mCursorRow].getSize() > mCursorCol)
            mLines[mCursorRow].pop_back();

        
    }

    void drawLine(int lineNumber)
    {   
        term::setCursorPosition(offsetX, offsetY + lineNumber);
        term::clearLine();

        for(int i = 0; i < mLines[lineNumber].getSize(); i++)
        {
            std::cout << mLines[lineNumber][i];
        }
        
        term::setCursorPosition(offsetX + mCursorCol, offsetY + mCursorRow);

    }
private:
    Application *mApplication;
    Buffer<Buffer<char>> &mLines;

    //cursor position (relative to the text, not the terminal)
    uint32_t mCursorRow;
    uint32_t mCursorCol;

    uint32_t mPersistantCol;

    //draw related
    const int offsetX = 2;
    const int offsetY = 2;
};
#endif