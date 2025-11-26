#ifndef SAVE_PAGE_H
#define SAVE_PAGE_H
#include <term/tui.h>
#include <term/signal.h>
#include <string>
#include <iostream>
#include <vector>
#include "application.h"
#include <fstream>




class SavePage : public tui::Page
{

public:
    SavePage(Application *application, Buffer<Buffer<char>> &lines)
        : Page("Save buffer into file"), mLines(lines),mApplication(application)
            , mFilenameField("Filename: ", {2,2})
            , mSaveButton("Save", {2, 10})
            , mBackButton("Back", {12, 10})
            , mAppendModeToggleButton("Append Mode", {2, 8})
    {
        term::hideCursor();

        addWidget(&mFilenameField);
        addWidget(&mAppendModeToggleButton);
        addWidget(&mSaveButton);
        addWidget(&mBackButton);

        // add handler when button is pressed
        mSaveButton.onButtonPressed.connect([this](){
            HandleSaveButton();
        });

        mBackButton.onButtonPressed.connect([this](){
            mApplication->requestPageTransition(Application::ApplicationPage::Main);
        });

        focusNext();
    }

    void draw() override {
        Page::draw();
        term::setCursorPosition(1, 12);
        std::cout << mStatus;

        term::setCursorPosition(1, 14);
        std::cout << "Press tab to navigate fields, Enter to input into field";
    }
    void onKeyPressed(term::input::Key keyPressed)
    {
        mStatus = "";
        Page::onKeyPressed(keyPressed);

    }
    ~SavePage() {
    }

private:
    void HandleSaveButton()
    {
        // validate fields
        std::string filename = mFilenameField.getValue();
        if (filename == "")
        {
            mStatus = "Filename shouldn't be empty";
            return ;
        }

        std::ofstream file;
        if(mAppendModeToggleButton.getValue())
            file.open(filename, std::ios::out | std::ios::app);
        else   
            file.open(filename, std::ios::out);

        if (!file.is_open())
        {
            mStatus = "Failed to open file";
            return ;
        }
        for(int i = 0; i < mLines.getSize() - 1; i++)
        {
            for(int j = 0; j < mLines[i].getSize(); j++)
            {
                file << mLines[i][j];
            }
            file << '\n';
        }
        for(int i = 0; i < mLines[mLines.getSize() - 1].getSize(); i++)
        {
            file << mLines[mLines.getSize() - 1][i];
        }
        file.close();
        mStatus = "Saved into " + filename;
    }

    bool validateDateOfBirth(std::string date, int &day, int &month, int &year)
    {
        int parsedDay, parsedMonth, parsedYear;
        if (std::sscanf(date.c_str(), "%d-%d-%d", &parsedDay, &parsedMonth, &parsedYear) != 3) {
            return false;
        }
        if (parsedDay < 1 || parsedDay > 31 || parsedMonth < 1 || parsedMonth > 12 || parsedYear < 1900) {
            return false;
        }
        day = parsedDay;
        month = parsedMonth;
        year = parsedYear;
        return true;
    }
private:
    Application *mApplication;
    Buffer<Buffer<char>> &mLines;

    tui::InputField mFilenameField;

    tui::Button mSaveButton;
    tui::Button mBackButton;
    tui::ToggleButton mAppendModeToggleButton;
    std::string mStatus;
};
#endif