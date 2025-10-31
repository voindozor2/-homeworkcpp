#pragma once
#include <string>

class shape
{
public:
    virtual ~shape() = default;
    virtual double calculate_area() const = 0;
    virtual double calculate_perimeter() const = 0;
    virtual std::string get_type()  const = 0;

    shape& operator= (const shape& other) = default;
    virtual bool operator== (const shape& other) const = 0;
    virtual bool operator!= (const shape& other) const = 0;
    virtual bool operator> (const shape& other) const = 0;
    virtual bool operator< (const shape& other) const = 0;
    virtual bool operator>= (const shape& other) const = 0;
    virtual bool operator<= (const shape& other) const = 0;
};
