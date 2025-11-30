#include "complex.h"

Complex::Complex(double real, double imaginary): mReal(real), mImaginary(imaginary)
{
}

double Complex::getImaginary()
{
    return mImaginary;
}
double Complex::getReal()
{
    return mReal;
}
void Complex::setImaginary(double imaginary)
{
    mImaginary = imaginary;
}

Complex Complex::operator+(const Complex &other)
{
    return Complex(mReal + other.mReal, mImaginary + other.mImaginary);
}

Complex &Complex::operator+=(const Complex &other) {
    mReal += other.mReal;
    mImaginary += other.mImaginary;
    return *this;
}

Complex Complex::operator-(const Complex &other)
{
    return Complex(mReal - other.mReal, mImaginary - other.mImaginary);
}

Complex &Complex::operator-=(const Complex &other)
{
    mReal -= other.mReal;
    mImaginary -= other.mImaginary;
    return *this;
}

Complex Complex::operator*(const Complex &other)
{
    const double& a = mReal;
    const double& b = mImaginary;
    const double& c = other.mReal;
    const double& d = other.mImaginary;

    return Complex(a*c - b*d, a*d + b*c);
}

Complex& Complex::operator*=(const Complex &other)
{
    const double& a = mReal;
    const double& b = mImaginary;
    const double& c = other.mReal;
    const double& d = other.mImaginary;

    mReal = a*c - b*d;
    mImaginary = a*d + b*c;
    return *this;
}

Complex Complex::operator/(const Complex &other)
{
    const double& a = mReal;
    const double& b = mImaginary;
    const double& c = other.mReal;
    const double& d = other.mImaginary;

    const double den = c*c + d*d;

    return Complex((a*c + b*d) / den, (b*c - a*d) / den); 
}

Complex& Complex::operator/=(const Complex &other)
{
    const double& a = mReal;
    const double& b = mImaginary;
    const double& c = other.mReal;
    const double& d = other.mImaginary;

    const double den = c*c + d*d;

    mReal = (a*c + b*d) / den;
    mImaginary = (b*c - a*d) / den;
    return *this;
}

bool Complex::operator==(const Complex &other)
{
    const double eps = 1e-9;
    double delta_a = mReal - other.mReal;
    double delta_b = mImaginary - other.mImaginary;
    if(delta_a < 0)
        delta_a *= 1;
    if(delta_b < 0)
        delta_b *= 1;
    
    return  delta_a < eps && delta_b < eps;
}
bool Complex::operator!=(const Complex &other)
{
    return  !(*this == other);
}

std::ostream &operator<<(std::ostream &ostream, const Complex &complex) {
  ostream << complex.mReal;
  if(complex.mImaginary == 0)
  {
    return ostream;
  }
  else if (complex.mImaginary < 0)
  {
    return ostream << " "<< complex.mImaginary << "i";
  }
  return ostream << " + " << complex.mImaginary << "i";
}
