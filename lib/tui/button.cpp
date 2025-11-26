#include "button.h"

tui::Button::Button(std::string label, tui::Position position) : mLabel(label), Widget(position) {}

void tui::Button::onKeyPressed(term::input::Key keyPressed) {
  if (keyPressed == term::input::Key::Enter ||
      keyPressed == term::input::Key::Space) {
    onButtonPressed.emit();
  }
}

void tui::Button::draw()
 {
    term::setBackgroundColor(term::Color::WHITE);
    term::setForegroundColor(term::Color::BLACK);
    term::setCursorPosition(mPosition.x, mPosition.y);
    std::cout << mLabel;
    term::resetColors();
}

tui::ToggleButton::ToggleButton(std::string label, tui::Position position) : mLabel(label), Widget(position) {}

void tui::ToggleButton::onKeyPressed(term::input::Key keyPressed)
 {
    if(keyPressed == term::input::Key::Enter || keyPressed == term::input::Key::Space)
    {
        mValue = !mValue;
        onButtonPressed.emit(mValue);
    }
}

void tui::ToggleButton::draw()
 {
    term::setBackgroundColor(term::Color::WHITE);
    term::setForegroundColor(term::Color::BLACK);
    term::setCursorPosition(mPosition.x, mPosition.y);
    std::cout << "|" << (mValue ? "#" : " ") << "|" << mLabel;
    term::resetColors();
}
