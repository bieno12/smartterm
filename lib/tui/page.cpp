#include "page.h"
#include <term/term.h>
#include <term/input.h>
#include <iostream>

void tui::Page::focusNext()
{
    if(!mWidgets.empty())
    {
        mFocusedWidgetIndex = (mFocusedWidgetIndex+1) % mWidgets.size();
    }
    else
        mFocusedWidgetIndex = -1;
}


tui::Page::Page(const std::string &title)\
    : mTitle(title), mFocusedWidgetIndex(-1), Widget()
{

}

void tui::Page::addWidget(tui::Widget *widget)
{
    mWidgets.push_back(widget);
}
void tui::Page::removeWidget(tui::Widget *widget)
{
    int removeIndex = -1;

    for(int i = 0; i < mWidgets.size(); i++)
    {
        if(mWidgets[i] == widget)
        {
            removeIndex;
            break;
        }

    }
    if (removeIndex >= 0)
        mWidgets.erase(mWidgets.begin() + removeIndex);
    mFocusedWidgetIndex = -1;
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

    // Highlight focused
    if (mFocusedWidgetIndex >= 0)
    {
        auto pos = mWidgets[mFocusedWidgetIndex]->mPosition;
        term::setBackgroundColor(term::Color::WHITE);
        term::setForegroundColor(term::Color::BLACK);
        term::setCursorPosition(pos.x - 1, pos.y);
        std::cout << ">";
        term::resetColors();
    }


}

void tui::Page::onKeyPressed(term::input::Key keyPressed)
{
    if (keyPressed == term::input::Key::Tab)
    {
        focusNext();
    }
    else if(mFocusedWidgetIndex >= 0)
        mWidgets[mFocusedWidgetIndex]->onKeyPressed(keyPressed);


}
