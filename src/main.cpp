#include <iostream>

#include <term/term.h>
#include <term/input.h>

#include "complex.h"
using namespace std;

int main(int, char**){
    Complex a(3, 4); // 3 + 4i
    Complex b(1, 2); // 1 + 2i

    cout << "a: " << a << endl;
    cout << "b: " << b << endl;

    Complex sum = a + b;
    cout << "a + b: " << sum << endl;

    Complex diff = a - b;
    cout << "a - b: " << diff << endl;

    Complex prod = a * b;
    cout << "a * b: " << prod << endl;

    Complex quot = a / b;
    cout << "a / b: " << quot << endl;

    bool isEqual = (a == b);
    cout << "a == b: " << (isEqual ? "true" : "false") << endl;

    bool isNotEqual = (a != b);
    cout << "a != b: " << (isNotEqual ? "true" : "false") << endl;

    cout << "a + 4i: " << (a + 4.0_i) << endl;
}
