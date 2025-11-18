#pragma once

#include "widget.h"
#include <set>
#include <string>
#include <memory>

namespace tui
{

class Page : public tui::Widget
{
protected:
    std::string mTitle;
    std::set<std::shared_ptr<tui::Widget>> mWidgets;
public:
    Page() = default;
    Page(const std::string& title);
    void addWidget(const std::shared_ptr<tui::Widget>& widget);
    void removeWidget(const std::shared_ptr<tui::Widget>& widget);
    void draw() override;
    void onKeyPressed(term::input::Key keyPressed) override;
};

} // namespace tui