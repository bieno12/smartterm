#include "page.h"
#include <term/term.h>
#include <term/input.h>
#include <iostream>

tui::Page::Page(const std::string &title) : mTitle(title), Widget()
{

}

void tui::Page::addWidget(const std::shared_ptr<tui::Widget> &widget)
{
    mWidgets.insert(widget);
}
void tui::Page::removeWidget(const std::shared_ptr<tui::Widget> &widget)
{
    mWidgets.erase(widget);
}

void tui::Page::draw()
{
    term::setCursorPosition(mPosition.x, mPosition.y);
    term::setForegroundColor(term::Color::CYAN);
    term:: setBackgroundColor(term::Color::BLACK);
    std::cout << mTitle;
    term::resetColors();
    for (const auto& widget : mWidgets) {
        widget->draw();
    }
}

void tui::Page::onKeyPressed(term::input::Key keyPressed)
{
    for (const auto &w : mWidgets)
    {
        w->onKeyPressed(keyPressed);
    }
}
