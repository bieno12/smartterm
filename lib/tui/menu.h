#pragma once

#include <term/input.h>
#include <term/term.h>
#include <vector>
#include <string>

#include "term/signal.h"
#include "widget.h"
namespace tui
{
class Menu : public Widget
{
private:
    std::vector<std::string> mItems;
    int32_t mSelectedIndex;
    int32_t mHoveredIndex;

    term::Color mNormalColor = term::Color::WHITE;
    term::Color mHoverColor = term::Color::YELLOW;
    term::Color mSelectedColor = term::Color::GREEN;
public:
    Signal<std::string, std::string> onItemSelected;

public:
    Menu();
    Menu(const std::vector<std::string>& items, Position pos = {0,0});
    void moveUp();
    void moveDown();
    std::string getSelectedItem() const;
    void selectHovered();
    void deselect();
    void draw() override;

    void onKeyPressed(term::input::Key keyPressed);

};

} // namespace tui