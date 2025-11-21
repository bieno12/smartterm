#pragma once

#include "widget.h"
#include <vector>
#include <string>
#include <memory>

namespace tui
{

class Page : public tui::Widget
{

protected:
    std::string mTitle;
    std::vector<tui::Widget *> mWidgets;
    int32_t mFocusedWidgetIndex = -1;
    
public:

    Page() = default;
    Page(const std::string& title);
    void addWidget(tui::Widget *widget);
    void removeWidget(tui::Widget *widget);
    
    void draw() override;
    void onKeyPressed(term::input::Key keyPressed) override;
    void focusNext();

};

} // namespace tui