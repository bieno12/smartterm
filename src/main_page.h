#ifndef MAIN_PAGE_H
#define MAIN_PAGE_H
#include <term/tui.h>
#include <string>
#include <vector>
#include "application.h"




class MainPage : public tui::Page
{
    tui::Menu mMainMenu;
    Application *mApplication;
public:
    MainPage(Application *application) : Page("Main Menu"), mApplication(application)
    {
        std::vector<std::string> menuItems = {"New", "Display", "Save", "Exit"};

        mMainMenu = tui::Menu(menuItems, tui::Position{2, 2});

        mMainMenu.onItemSelected.connect([this](std::string currentItem, std::string last){
            if(currentItem == "New")
            {
                mApplication->requestPageTransition(Application::ApplicationPage::Edit);
            }
            else if (currentItem == "Display")
            {
                mApplication->requestPageTransition(Application::ApplicationPage::Display);
            }
            else if (currentItem == "Save")
            {
                mApplication->requestPageTransition(Application::ApplicationPage::Save);
            }
            else if (currentItem == "Exit")
            {
                mApplication->requestExit();
            }
        });
        addWidget(&mMainMenu);
        focusNext();

    }
    ~MainPage() {

    }

};
#endif