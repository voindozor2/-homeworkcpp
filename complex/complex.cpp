#include "complex.h"

#include <cmath>

complex::complex()
{
    real = 0;
    imag = 0;
}

complex::complex(int realInitialize, int imagInitialize)
{
    real = realInitialize;
    imag = imagInitialize;
}

complex::complex(const complex& other)
{
    real = other.real;
    imag = other.imag;
}

complex complex::operator+(const complex& other)
{
    real = real + other.real;
    imag = imag + other.imag;
    return *this;
}

complex complex::operator-(const complex& other)
{
    real = real - other.real;
    imag = imag - other.imag;
    return *this;
}

complex complex::operator*(const complex& other)
{
    real = real * other.real - imag * other.imag;
    imag = real * other.imag + imag * other.real;
    return *this;
}

complex complex::operator/(const complex& other)
{
    double denominator = other.real * other.real + other.imag * other.imag; // c² + d²

    real = (real * other.real + imag * other.imag) / denominator;
    imag = (imag * other.real - real * other.imag) / denominator;
    return *this;
}

complex& complex::operator+=(const complex& other)
{
    *this = *this + other;
    return *this;
}

complex& complex::operator-=(const complex& other)
{
    *this = *this - other;
    return *this;
}

complex& complex::operator*=(const complex& other)
{
    *this = *this * other;
    return *this;
}

complex& complex::operator/=(const complex& other)
{
    *this = *this / other;
    return *this;
}

bool complex::operator==(const complex& other) //нагуглил
{
    const double epsilon = 1e-12;
    
    bool real_equal = std::fabs(real - other.real) < epsilon; 
    bool imag_equal = std::fabs(imag - other.imag) < epsilon;
    
    return real_equal && imag_equal;
}

bool complex::operator!=(const complex& other)
{
    const double epsilon = 1e-12;
    
    bool real_equal = std::fabs(real - other.real) >= epsilon; 
    bool imag_equal = std::fabs(imag - other.imag) >= epsilon;
    
    return real_equal && imag_equal;
}

bool complex::operator<(const complex& other)
{
    const double epsilon = 1e-12;
    
    bool real_equal = std::fabs(real - other.real) < epsilon;
    if (!real_equal)
    {
        return real < other.real;
    }
    return imag < other.imag;
}

bool complex::operator>(const complex& other)
{
    const double epsilon = 1e-12;
    
    bool real_equal = std::fabs(real - other.real) < epsilon;
    if (!real_equal)
    {
        return real > other.real;
    }
    return imag > other.imag;
}

bool complex::operator<=(const complex& other)
{
    const double epsilon = 1e-12;
    
    bool real_equal = std::fabs(real - other.real) < epsilon;
    if (!real_equal)
    {
        return real < other.real;
    }
    else
    {
        return true;
    }
}

bool complex::operator>=(const complex& other)
{
    const double epsilon = 1e-12;
    
    bool real_equal = std::fabs(real - other.real) >= epsilon;
    if (!real_equal)
    {
        return real > other.real;
    }
    else
    {
        return true;
    }
}

std::string complex::toString() const
{
    std::string str;
    str += real;
    str += " + ";
    str += imag;
    str += " * i";
    return str;
}

complex::operator int() const
{
    return static_cast<int>(real);
}


std::ostream& operator<<(std::ostream& os, const complex& other)
{
    os << other.toString();
}

