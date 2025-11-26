#ifndef BUTTONMINA_H
#define BUTTONMINA_H

#include <term/term.h>
#include <term/tui.h>
#include <iostream>
#include <string>
namespace tui
{

class Button : public tui::Widget 
{
public:
    Button(std::string label, tui::Position position);

    void onKeyPressed(term::input::Key keyPressed) override;
    
    void draw() override;

public:
    tui::Signal<> onButtonPressed;
private:
    std::string mLabel;

};


class ToggleButton : public tui::Widget
{
public:
    ToggleButton(std::string label, tui::Position position);

    void onKeyPressed(term::input::Key keyPressed) override;
    
    void draw() override;

    inline bool getValue()
    {
        return mValue;
    }
public:
    tui::Signal<bool> onButtonPressed;
private:
    std::string mLabel;
    bool mValue;
};


} //namespace tui
#endif
