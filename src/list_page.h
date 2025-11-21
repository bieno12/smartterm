#ifndef LIST_PAGE_H
#define LIST_PAGE_H
#include <term/tui.h>
#include <string>
#include <iostream>
#include <vector>
#include "application.h"
#include <iomanip>
#include <sstream>



class ListPage : public tui::Page
{

public:
    ListPage(Application *application, std::vector<Employee> &employees)
        : Page("List Employees"), mEmployees(employees),mApplication(application)
    {
        
    }

    void draw() override {
        int rows, cols;
        term::getSize(cols, rows);
        //print header
        term::setCursorPosition(2, 2);
        std::cout << padString("Number", 20) << "|";
        std::cout << padString("First Name", 20) << "|";
        std::cout << padString("Last Name", 20) << "|";
        std::cout << padString("Date of Birth", 20) << "|";
        std::cout << padString("Position", 20) << "|";

        term::setCursorPosition(2, 3);
        std::cout << padString("", 5*20 + 5, '-') << "|";

        for (int i = 0; i < mEmployees.size(); i++)
        {
            term::setCursorPosition(2, i + 4);
            std::cout << padString(mEmployees[i].firstName, 20) << "|";
            std::cout << padString(mEmployees[i].lastName, 20) << "|";
            
            std::string dateOfBirth = padString(std::to_string(mEmployees[i].dateOfBirth.day), 2 ,'0') 
                                + "-" + padString(std::to_string(mEmployees[i].dateOfBirth.month), 2 ,'0')
                                + "-" + padString(std::to_string(mEmployees[i].dateOfBirth.year), 4 ,'0');
            std::cout << padString(dateOfBirth, 20) << "|";
            std::cout << padString(mEmployees[i].position, 20) << "|";
        }


    }

    ~ListPage() {
    }

    
private:
    std::string padString(std::string str,  int width, char c = ' ')
    {
        if(str.size() < width)
            return std::string(width-str.size(), c) + str;
        else
            return str;
    }

    std::vector<Employee> &mEmployees;
    Application *mApplication;

};
#endif