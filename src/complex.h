#ifndef COMPLEXMINA_H
#define COMPLEXMINA_H

#include <type_traits>
#include <iostream>

class Complex
{
public:
    Complex() = default;
    Complex(double real, double Imaginary=0);

    Complex(const Complex &other)           = default;   // Copy constuctor
    Complex(Complex &&other)                = default;   // Move constructor
    Complex& operator=(const Complex&other) = default;   // Copy assignment operator
    Complex& operator=(Complex &&other)     = default;   // Move assignment operator
    ~Complex()                              = default;   // Destructor

    //getters and setters
    double getReal();
    double getImaginary();
    void setReal(double real);
    void setImaginary(double imaginary);

    // operator overloading for numeric types
    // Complex - number operator
    Complex operator+(double number);
    // Complex - number operator
    Complex operator-(double number);
    // Complex on Complex operators
    Complex operator+(const Complex& other);
    Complex& operator+=(const Complex& other);
    Complex operator-(const Complex& other);
    Complex& operator-=(const Complex& other);
    Complex operator*(const Complex& other);
    Complex& operator*=(const Complex& other);
    Complex operator/(const Complex& other);
    Complex& operator/=(const Complex& other);


    // Complex +/- number operator
    Complex& operator+=(double number);
    Complex& operator-=(double number)
    {
        mReal -= number;
        return *this;
    }
    // Complex mul/div number operators
    Complex operator*(double number);
    
    Complex operator/(double number);

    Complex& operator*=(double number);
    Complex& operator/=(double number);
    
    // Comparasion operators
    bool operator==(const Complex& other);
    bool operator!=(const Complex& other);
    // Printing
    friend std::ostream& operator<<(std::ostream& ostream, const Complex &complex);

private:
    double mReal;
    double mImaginary;
};
Complex operator""_i(long double);

#endif