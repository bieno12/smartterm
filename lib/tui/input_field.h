#ifndef INPUT_FIELDMINA_H
#define INPUT_FIELDMINA_H

#include <term/term.h>
#include <term/tui.h>
#include <iostream>
#include <string>

namespace tui
{

class InputField : public tui::Widget 
{
public:
    InputField(std::string prompt, tui::Position position);
    void onKeyPressed(term::input::Key keyPressed) override;
    
    void draw() override;
    std::string getValue();
    void resetValue();
private:
        void readInput();
private:
    std::string mPrompt;
    std::string mValue;

};

} // namespace tui
#endif