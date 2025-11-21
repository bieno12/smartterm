#include "application.h"
#include "main_page.h"
#include "display_page.h"
#include "edit_page.h"
Application::Application() : mCurrentPage(std::make_shared<MainPage>(this))
{
    mLines = Buffer<Buffer<char>>(5);
    mLines.push_back(Buffer<char>());

    for (char c : std::string("Hello There from line 1"))
        mLines[0].push_back(c);
}

void Application::doPageTransition()
{
    switch (mRequestedPage)
    {
    case ApplicationPage::Main:
        mCurrentPage = std::make_shared<MainPage>(this);
        break;
    case ApplicationPage::Display:
        mCurrentPage = std::make_shared<DisplayPage>(this, mLines);
        break;
    case ApplicationPage::Edit:
        mCurrentPage = std::make_shared<EditPage>(this, mLines);
        break;
    default:
        break;
    }
    mRequestedPage = ApplicationPage::NoPage;
}


void Application::requestPageTransition(ApplicationPage page)
{
    mRequestedPage = page;
}

void Application::requestExit()
{
    mRunning = false;
}

static void toDebugSection()
{

    int rows, cols;
    term::getSize(cols, rows);

    if (rows > 0)
        term::setCursorPosition(0, rows);

}

void Application::run()
{
    namespace input = term::input;

    input::setInputMode(term::input::InputMode::Raw);
    term::clearScreen();

    mCurrentPage->draw();

    while(mRunning)
    {
        input::Key keyPressed = input::readkey();

        if (keyPressed == input::Key::Esc)
        {
            requestPageTransition(ApplicationPage::Main);
        }
        else
        {
            mCurrentPage->onKeyPressed(keyPressed);
        }


        // handle page transition requests
        if (mRequestedPage != ApplicationPage::NoPage)
            doPageTransition();

        term::clearScreen();
        mCurrentPage->draw();
    }
}
