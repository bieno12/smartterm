#include <iostream>

#include <term/term.h>
#include <term/input.h>
#include <term/tui.h>
#include <myutils/vector.h>
#include <myutils/string.h>
using namespace std;

int main(int, char**){
    myutils::String str1("Hello");
    myutils::String str2("World");

    cout << "String 1:" << str1 << endl;
    cout << "String 2:" << str2 << endl;
    myutils::String result = str1 + " " + str2;
    cout << "Concatenated String: " << result << endl;
    cout << "Length of result: " << result.getSize() << endl;
    // Demonstrate copy constructor
    myutils::String copyConstructed(result);
    cout << "Copy Constructed String: " << copyConstructed << endl;

    // Demonstrate move constructor
    myutils::String moveConstructed(std::move(copyConstructed));
    cout << "Move Constructed String: " << moveConstructed << endl;

    // Demonstrate copy assignment operator
    myutils::String copyAssigned;
    copyAssigned = result;
    cout << "Copy Assigned String: " << copyAssigned << endl;

    // Demonstrate move assignment operator
    myutils::String moveAssigned;
    moveAssigned = std::move(copyAssigned);
    cout << "Move Assigned String: " << moveAssigned << endl;

    // Demonstrate subscript operator
    cout << "First character of result: " << result[0] << endl;

    // Demonstrate push_back and pop_back
    result.push_back('!');
    cout << "After push_back: " << result << endl;
    result.pop_back();
    cout << "After pop_back: " << result << endl;

    // Demonstrate clear and isEmpty
    result.clear();
    cout << "After clear, isEmpty: " << result.isEmpty() << endl;

    // Demonstrate equality and inequality operators
    myutils::String str3("Hello World");
    cout << "str3 == moveAssigned: " << (str3 == moveAssigned) << endl;
    cout << "str3 != moveAssigned: " << (str3 != moveAssigned) << endl;

}
