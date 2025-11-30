#include <iostream>

#include <term/term.h>
#include <term/input.h>
#include <term/tui.h>
#include <any>
#include <myutils/any.h>
#include <myutils/python_list.h>

using namespace std;

bool isInteger(string str)
{
    const char * currentChar = str.c_str();
    if (*currentChar == '-' || *currentChar == '+')
        currentChar++;

    while(isdigit(*currentChar))
        currentChar++;    
    return *currentChar == '\0';
}

bool isFLoatingNumber(string str)
{
    const char * currentChar = str.c_str();
    if (*currentChar == '-' || *currentChar == '+')
        currentChar++;

    while(isdigit(*currentChar))
        currentChar++;    

    if(*currentChar == '.')
        currentChar++;
    while(isdigit(*currentChar))
        currentChar++;    

    return *currentChar == '\0';
}
myutils::Any autoConvert(string str)
{
    if(isInteger(str))
        return myutils::Any(std::stol(str));
    if(isFLoatingNumber(str))
        return myutils::Any(std::stod(str));
    return str;
}
int main(int, char**){
 
    myutils::PythonList list;
    cout << "Entering Items in list:";

    while (true)
    {
        cout << "item:";
        string input; getline(cin, input);
        if(input == "")
            break;
        myutils::Any item = autoConvert(input);
        list.append(item);
    }
    cout << "Your python list is:\n";
    for(int i = 0; i < list.size(); i++)
    {
        cout << "value: " << list[i] << ", type: " << list[i].type().name() << endl;
    }
}
