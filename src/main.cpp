#include <iostream>

#include <term/term.h>
#include <term/input.h>
#include "stack.h"
using namespace std;

void printPrompt()
{
    cout << "push <num>: to add number to stack\n";
    cout << "pop:  to pop number to stack\n";
    cout << "print: to print stack\n";
}

int main(int, char**){
    Stack<int> mystack;

    mystack.push(1);
    mystack.push(2);
    mystack.push(3);
    mystack.push(4);
    mystack.push(5);
    for(int x : mystack)
    {
        cout << x << " ";
    }
    cout << endl;
    mystack.pop();
    for(int x : mystack)
    {
        cout << x << " ";
    }
    
}
