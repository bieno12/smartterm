#include "application.h"
#include "main_page.h"
#include "create_page.h"
#include "list_page.h"

Application::Application() : mCurrentPage(std::make_shared<MainPage>(this))
{
}

void Application::doPageTransition()
{
    switch (mRequestedPage)
    {
    case ApplicationPage::Main:
        mCurrentPage = std::make_shared<MainPage>(this);
        break;
    case ApplicationPage::Display:
        mCurrentPage = std::make_shared<ListPage>(this, mEmployees);
        break;
    case ApplicationPage::Create:
        mCurrentPage = std::make_shared<CreatePage>(this, mEmployees);
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

        if (keyPressed == input::Key::Backspace)
        {
            requestPageTransition(ApplicationPage::Main);
        }
        if (keyPressed == input::Key::Esc)
        {
            requestExit();
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
