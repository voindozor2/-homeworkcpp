#pragma once
#include <iosfwd>
#include <string>

class complex
{
private:
    double real;
    double imag;
public:
    complex();
    complex(double realInitialize, double imagInitialize);
    complex(const complex& other);
    complex operator+(const complex& other);
    complex operator-(const complex& other);
    complex operator*(const complex& other);
    complex operator/(const complex& other);
    complex& operator+=(const complex& other);
    complex& operator-=(const complex& other);
    complex& operator*=(const complex& other);
    complex& operator/=(const complex& other);
    bool operator==(const complex& other) const;
    bool operator!=(const complex& other) const;
    bool operator<(const complex& other) const;
    bool operator>(const complex& other) const;
    bool operator<=(const complex& other) const;
    bool operator>=(const complex& other) const;
    std::string toString() const;
    friend std::ostream& operator<<(std::ostream& os, const complex& other);
    operator int() const;
    double get_real() const;
    double get_imag() const;
};
