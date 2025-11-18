#include <iostream>
#include <string>
#include <term/term.h>
#include <term/input.h>
#include <term/tui.h>



std::string promptForInput(const std::string& prompt, const std::string& status=""){
    term::setBackgroundColor(term::Color::BLUE);
    term::setForegroundColor(term::Color::WHITE);

    term::setCursorPosition(3,0);
    term::clearLine();
    std::cout << status << std::endl;
    term::clearLine();
    std::cout << prompt;

    auto originalMode = term::input::getInputMode();

    term::input::setInputMode(term::input::InputMode::Cooked);
    std::string inputString;

    std::cin >> inputString;

    term::input::setInputMode(originalMode);
    term::resetColors();
    return inputString;
}

int inputInteger(const std::string& prompt, std::string status="")
{
    while(true)
    {
        try {
            return std::stoi(promptForInput(prompt, status));
        }
        catch (...)
        {
            status = "Enter a valid Integer";
        }
    }
    return 0;
}


void solveMagicMox(int n)
{
    term::clearScreen();
    
    const int cellSize =  n;
    const int gridOffset = 10;
    const uint32_t waitMilliSeconds = 500;

    int row= 0, col=0;

    int number = 1;
    while (number <= n*n)
    {
        term::setCursorPosition(gridOffset + col * cellSize, gridOffset + row * cellSize);
        std::cout << number << std::flush;

        if(number % n == 0)
        {
            row =  row + 1;
        }
        else
        {
            row = (row - 1 + n) % n;
            col = (col + 1) % n;
        }

        number++;
        term::sleep(waitMilliSeconds);
    }
    
    term::setCursorPosition(0, n*cellSize+ 1 + gridOffset);
}
int main(int, char**){
    term::clearScreen();
    // std::string input = promptForInput("d");
    int n = inputInteger("Enter an odd grid size: ");
    while (n%2 == 0 || n < 3 || n >15)
        n = inputInteger("Enter an odd grid size: ", "make sure to enter odd number between 3 and 15");
    solveMagicMox(n);
}
