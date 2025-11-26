#include "input_field.h"

using namespace tui;

InputField::InputField(std::string prompt, tui::Position position) : Widget(position) {
    mPrompt = prompt;
}

void InputField::onKeyPressed(term::input::Key keyPressed)
{
    if (keyPressed == term::input::Key::Enter)
    {

        readInput();
    }
}

void InputField::draw()
{
    term::setCursorPosition(mPosition.x, mPosition.y);
    std::cout << mPrompt << mValue;
}

std::string InputField::getValue()
 {
    return mValue;
}

void InputField::resetValue()
 {
    term::setCursorPosition(mPosition.x, mPosition.y);
    term::clearLine();
    mValue = "";
    draw();
}

void InputField::readInput()
{

    auto originalMode = term::input::getInputMode();
    term::input::setInputMode(term::input::InputMode::Cooked);
    term::setCursorPosition(mPosition.x + mPrompt.size() + 1, mPosition.y);
    term::showCursor();
    std::getline(std::cin, mValue);

    term::input::setInputMode(originalMode);
    term::hideCursor();

}
