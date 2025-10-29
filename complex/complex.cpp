#include "complex.h"

#include <cmath>
#include <ostream>
#include <string>

complex::complex()
{
    real = 0;
    imag = 0;
}

complex::complex(double realInitialize, double imagInitialize)
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
    double new_real = real * other.real - imag * other.imag;
    double new_imag = real * other.imag + imag * other.real;
    real = new_real;
    imag = new_imag;
    return *this;
}

complex complex::operator/(const complex& other)
{
    double denominator = other.real * other.real + other.imag * other.imag; // c² + d²

    double new_real = (real * other.real + imag * other.imag) / denominator;
    double new_imag = (imag * other.real - real * other.imag) / denominator;
    real = new_real;
    imag = new_imag;
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

bool complex::operator==(const complex& other) const//нагуглил
{
    const double epsilon = 1e-12;
    
    bool real_equal = std::fabs(real - other.real) < epsilon; 
    bool imag_equal = std::fabs(imag - other.imag) < epsilon;
    
    return real_equal && imag_equal;
}

bool complex::operator!=(const complex& other) const
{
    return !(*this == other);
}

bool complex::operator<(const complex& other) const
{
    const double epsilon = 1e-12;
    
    bool real_equal = std::fabs(real - other.real) < epsilon;
    if (!real_equal)
    {
        return real < other.real;
    }
    return imag < other.imag;
}

bool complex::operator>(const complex& other) const
{
    return !(*this < other);
}

bool complex::operator<=(const complex& other) const
{
    return *this < other || *this == other;
}

bool complex::operator>=(const complex& other) const
{
    return *this > other || *this == other;
}

std::string complex::toString() const
{
    return std::string(std::to_string(real) + " + " + std::to_string(imag) + " * i");
}

complex::operator int() const
{
    return static_cast<int>(real);
}

double complex::get_real() const
{
    return real;
}

double complex::get_imag() const
{
    return imag;
}


std::ostream& operator<<(std::ostream& os, const complex& other)
{
    std::string stringToOut = other.toString();
    os << stringToOut;
    return os;
}

