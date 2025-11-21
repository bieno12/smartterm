#ifndef APPLICATION_H
#define APPLICATION_H

#include <vector>
#include <string>
#include <term/tui.h>
#include <memory>

typedef struct Employee
{
    std::string firstName;
    std::string lastName;
    struct Date
    {
        int day;
        int month;
        int year;
    } dateOfBirth;
    std::string position;    
} Employee;

class Application
{
public:
    enum class ApplicationPage {
        NoPage,
        Main,
        Display,
        Create
    };

    Application();
    void requestPageTransition(ApplicationPage page);

    void requestExit();
    void run();
private:
    void doPageTransition();

    std::vector<Employee> mEmployees;
    std::shared_ptr<tui::Page> mCurrentPage;
    ApplicationPage mRequestedPage = ApplicationPage::NoPage;
    bool mRunning = true;
};
#endif
