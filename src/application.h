#ifndef APPLICATION_H
#define APPLICATION_H

#include <vector>
#include <string>
#include <term/tui.h>
#include "buffer.h"


class Application
{
public:
    enum class ApplicationPage {
        NoPage,
        Main,
        Edit,
        Display
    };

    Application();
    void requestPageTransition(ApplicationPage page);

    void requestExit();
    void run();
private:
    void doPageTransition();


private:
    std::shared_ptr<tui::Page> mCurrentPage;
    ApplicationPage mRequestedPage = ApplicationPage::NoPage;
    bool mRunning = true;

    //buffer manipulation
    Buffer<Buffer<char>> mLines;
};
#endif
