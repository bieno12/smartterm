#include <iostream>

#include <term/term.h>
#include <term/input.h>
#include <term/tui.h>
#include <any>
#include <myutils/any.h>
#include <myutils/python_list.h>

using namespace std;

int main(int, char**){
    std::any stdAny = std::string("hello");
    myutils::Any myAny = std::string("hello");
    // cout << "stdAny is " << stdAny.type().name() << endl;
    // cout << "myAny is " << myAny.type().name() << endl;
    // stdAny = std::string("hello there");
    // myAny = std::string("hello there");
    // cout << "stdAny is " << stdAny.type().name() << endl;
    // cout << "myAny is " << myAny.type().name() << endl;
    // cout << "clearing\n";
    // stdAny.reset();
    // myAny.reset();
    // cout << "stdAny has value:" << stdAny.has_value() << endl;
    // cout << "myAny has value:" << myAny.hasValue() << endl;
    // cout << "stdAny type after reset: " << stdAny.type().name() << endl;
    // cout << "myAny type after reset: " << myAny.type().name() << endl;

    cout << "Testing copy constructors\n";
    std::any copiedStdAny = stdAny;
    myutils::Any copiedMyAny = myAny;

    cout << "copiedStdAny has value: " << copiedStdAny.has_value() << endl;
    cout << "copiedMyAny has value: " << copiedMyAny.hasValue() << endl;
    cout << "copiedStdAny type: " << copiedStdAny.type().name() << endl;
    cout << "copiedMyAny type: " << copiedMyAny.type().name() << endl;
    std::string &value = std::any_cast<std::string&>(stdAny);
    std::string &myValue = myAny.get<std::string>();
    cout << "copiedStdAny type: " << value << endl;
    cout << "copiedMyAny type: " << myValue << endl;

    value += "hello";
    myValue += "hello";
    cout << "After modification" << endl;
    cout << "copiedStdAny type: " << std::any_cast<std::string&>(stdAny) << endl;
    cout << "copiedMyAny type: " << myAny.get<std::string>() << endl;
    cout << "myAny :" << myAny << endl;
    myutils::PythonList list;

    list.append(12);
    list.append(std::string("hello world"));
    cout << "Size of Python List:" << list.size() << endl;
    cout << std::string("hello") << endl;

    list.print();
}
