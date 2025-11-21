#ifndef CREATE_PAGE_H
#define CREATE_PAGE_H
#include <term/tui.h>
#include <term/signal.h>
#include <string>
#include <iostream>
#include <vector>
#include "application.h"


class Button : public tui::Widget 
{
public:
    Button(std::string label, tui::Position position) : mLabel(label), Widget(position) {}

    void onKeyPressed(term::input::Key keyPressed) override {
        if(keyPressed == term::input::Key::Enter)
        {
            onButtonPressed.emit();
        }
    }
    
    void draw() override {
        term::setBackgroundColor(term::Color::WHITE);
        term::setForegroundColor(term::Color::BLACK);
        term::setCursorPosition(mPosition.x, mPosition.y);
        std::cout << mLabel;
        term::resetColors();
    }

public:
    tui::Signal<> onButtonPressed;
private:
    std::string mLabel;

};
class InputField : public tui::Widget 
{
public:
    InputField(std::string prompt, tui::Position position) : Widget(position)
    {
        mPrompt = prompt;
    }
    void onKeyPressed(term::input::Key keyPressed) override {
        if (keyPressed == term::input::Key::Enter)
        {

            readInput();
        }
    }
    
    void draw() override {
        term::setCursorPosition(mPosition.x, mPosition.y);
        std::cout << mPrompt << mValue;
    }
    std::string getValue() {
        return mValue;
    }
    void resetValue() {
        term::setCursorPosition(mPosition.x, mPosition.y);
        term::clearLine();
        mValue = "";
        draw();
    }
private:
        void readInput()
        {

            auto originalMode = term::input::getInputMode();
            term::input::setInputMode(term::input::InputMode::Cooked);
            term::setCursorPosition(mPosition.x + mPrompt.size() + 1, mPosition.y);
            term::showCursor();
            std::getline(std::cin, mValue);

            term::input::setInputMode(originalMode);
            term::hideCursor();

        }
private:
    std::string mPrompt;
    std::string mValue;

};
class CreatePage : public tui::Page
{

public:
    CreatePage(Application *application, std::vector<Employee> &employees)
        : Page("Create an Employee"), mEmployees(employees),mApplication(application)
            , mFirstNameField("First Name: ", {2,2})
            , mLastNameField("Last Name: ", {2,4})
            , mDOBField("Date of Birth in format dd-mm-yyyy: ", {2,6})
            , mPositionField("Position: ", {2,8})
            , mSubmitButton("Submit", {2, 10})
    {



        addWidget(&mFirstNameField);
        addWidget(&mLastNameField);
        addWidget(&mDOBField);
        addWidget(&mPositionField);

        addWidget(&mSubmitButton);

        // add handler when button is pressed
        mSubmitButton.onButtonPressed.connect([this](){
            HandleSubmitButton();
        });
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
    ~CreatePage() {
    }

private:
    void HandleSubmitButton()
    {
        // validate fields
        int day, month, year;
        if (mFirstNameField.getValue() == "")
        {
            mStatus = "First Name shouldn't be empty";
            return ;
        }
        else if (mLastNameField.getValue() == "")
        {
            mStatus = "Last Name shouldn't be empty";
            return ;
        }
        else if (!validateDateOfBirth(mDOBField.getValue(), day, month, year))
        {
            mStatus = "Date of birth should be in format dd-mm-yyyy";
            return ;
        }
        else if (mPositionField.getValue() == "")
        {
            mStatus = "Position shouldn't be empty";
            return ;
        }

        // add a new employee;
        mEmployees.push_back(Employee{
            mFirstNameField.getValue(),
            mLastNameField.getValue(),
            {day, month, year},
            mPositionField.getValue(),
        });
        mStatus = "Add new Employee";
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
    std::vector<Employee> &mEmployees;
    Application *mApplication;

    InputField mFirstNameField;
    InputField mLastNameField;
    InputField mDOBField;

    InputField mPositionField;

    Button mSubmitButton;

    std::string mStatus;
};
#endif