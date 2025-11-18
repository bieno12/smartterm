#include "menu.h"
#include <iostream>


tui::Menu::Menu(const std::vector<std::string> &items, const tui::Position pos) 
    : Widget(pos), mItems(items), mSelectedIndex(-1), mHoveredIndex(0)
{
}


void tui::Menu::moveUp() {
  if (mHoveredIndex > 0)
    mHoveredIndex--;
}
void tui::Menu::moveDown()
{
    if (mHoveredIndex + 1 < mItems.size())
        mHoveredIndex++;
}

std::string tui::Menu::getSelectedItem() const {
    if (mSelectedIndex >= mItems.size()) {
        return "";
    }
    return mItems[mSelectedIndex];
}

void tui::Menu::selectHovered()
{
    mSelectedIndex = mHoveredIndex;
}

void tui::Menu::deselect()
{
    mSelectedIndex = -1;
}

void tui::Menu::draw()
{
    for (int32_t i = 0; i < mItems.size(); ++i)
    {
        term::setCursorPosition(mPosition.x, mPosition.y + i);
        if (i == mSelectedIndex)
        {
            term::setForegroundColor(mSelectedColor);
        }
        else if (i == mHoveredIndex)
        {
            term::setForegroundColor(mHoverColor);
        }
        else
        {
            term::setForegroundColor(mNormalColor);
        }
        std::cout << mItems[i];
        term::resetColors();
    }
}

void tui::Menu::onKeyPressed(term::input::Key keyPressed)
{
    if(keyPressed == term::input::Key::ArrowUp
        || keyPressed == term::input::Key::ArrowLeft
        || keyPressed == term::input::Key::Home) {
        // cout << "[UP]!" ;
        this->moveUp();
    }
    else if (keyPressed == term::input::Key::ArrowDown
        || keyPressed == term::input::Key::ArrowRight
        || keyPressed == term::input::Key::End) {
        // cout << "[DOWN]!" ;
        this->moveDown();
    }
    else if (keyPressed == term::input::Key::Enter) {
        this->selectHovered();
    }
}
