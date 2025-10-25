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
    complex(int realInitialize, int imagInitialize);
    complex(const complex& other);
    complex operator+(const complex& other);
    complex operator-(const complex& other);
    complex operator*(const complex& other);
    complex operator/(const complex& other);
    complex& operator+=(const complex& other);
    complex& operator-=(const complex& other);
    complex& operator*=(const complex& other);
    complex& operator/=(const complex& other);
    bool operator==(const complex& other);
    bool operator!=(const complex& other);
    bool operator<(const complex& other);
    bool operator>(const complex& other);
    bool operator<=(const complex& other);
    bool operator>=(const complex& other);
    std::string toString() const;
    friend std::ostream& operator<<(std::ostream& os, const complex& other);
    operator int() const;
};
