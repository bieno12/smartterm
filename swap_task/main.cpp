#include <iostream>
using namespace std;
void swapWithXor(int *x, int *y)
{
    *x = *x ^ *y;
    *y = *x ^ *y;
    *x = *x ^ *y;
}

void swapWithSubtraction(int *x, int *y)
{
    *x = *x + *y;
    *y = *x - *y;
    *x = *x - *y;
}
void swapWithMultiplication(int *x, int *y)
{
    *x = *x * *y;
    *y = *x / *y;
    *x = *x / *y;
}

int main(int, char**){
    int x = 1, y = 2;

    cout << "x: " << x << ", y: " << y << endl;

    swapWithSubtraction(&x, &y);
    cout << "After Swapping with Subtraction\n";
    cout << "x: " << x << ", y: " << y << endl;

    swapWithXor(&x, &y);
    cout << "After Swapping with Xor" << endl;
    cout << "x: " << x << ", y: " << y << endl;
    swapWithMultiplication(&x, &y);
    cout << "After Swapping with Multiplication" << endl;
    cout << "x: " << x << ", y: " << y << endl;

}
