#include <iostream>

#include <term/term.h>
#include <term/input.h>
#include <term/tui.h>

using namespace std;


int main(int, char**){
    term::clearScreen();
    term::input::setInputMode(term::input::InputMode::Raw);

    auto mainPage = make_shared<tui::Page>("Main Page");

    auto mainMenu =  make_shared<tui::Menu>(vector<string>{"Employees", "Options", "stuff", "Exit"}, tui::Position{2,5});

    mainPage->addWidget(mainMenu);

    auto employeePage = make_shared<tui::Page>("Employees Page");
    
    auto employeeMenu =  make_shared<tui::Menu>(vector<string>{"Add Employee", "back"}, tui::Position{2,5});
    employeePage->addWidget(employeeMenu);

    auto currentPage = mainPage;
    auto currentMenu = mainMenu;

    currentPage->draw();
    while(true)
    {

        term::input::Key key = term::input::readkey();

        currentPage->onKeyPressed(key);

        if (key == term::input::Key::Backspace)
        {
            currentPage = mainPage;
        }
        else if (key == term::input::Key::Esc)
            return 0;

        if(currentPage == employeePage)
        {
            term::setCursorPosition(10, 10);
            cout << employeeMenu->getSelectedItem() << endl;
            if(employeeMenu->getSelectedItem() == "back")
            {
                currentPage = mainPage;
                employeeMenu->deselect();
            }
        }
        else if (currentPage == mainPage)
        {
            term::setCursorPosition(10, 10);

            cout << mainMenu->getSelectedItem() << endl;
            
            if(mainMenu->getSelectedItem() == "Employees")
            {
                currentPage = employeePage;
                mainMenu->deselect();
            }
            else if (mainMenu->getSelectedItem() == "Exit")
                return 0;
        }

        term::clearScreen();
        currentPage->draw();

    }
    return 0;
}
