#include "triangle.h"

triangle::triangle()
{
    first = 0;
    second = 0;
    third = 0;
}

triangle::triangle(triangle& other)
{
    first = other.first;
    second = other.second;
    third = other.third;
}

triangle::triangle(double first, double second, double third)
{
    this->first = first;
    this->second = second;
    this->third = third;
}

triangle& triangle::operator=(const triangle& other)
{
    first = other.first;
    second = other.second;
    third = other.third;
    return *this;
}

bool triangle::operator==(const shape& other) const
{
    if (get_type() != other.get_type())
    {
        return false;
    }

    return first == dynamic_cast<const triangle&>(other).first
        && second == dynamic_cast<const triangle&>(other).second
        && third == dynamic_cast<const triangle&>(other).third;
}

bool triangle::operator!=(const shape& other) const
{
    return !(*this == other);
}

bool triangle::operator>(const shape& other) const
{
    if (get_type() != other.get_type())
    {
        return false;
    }

    return first > dynamic_cast<const triangle&>(other).first
        && second > dynamic_cast<const triangle&>(other).second
        && third > dynamic_cast<const triangle&>(other).third;
}

bool triangle::operator<(const shape& other) const
{
    return !(*this > other);
}

bool triangle::operator>=(const shape& other) const
{
    return *this > other || *this == other;
}

bool triangle::operator<=(const shape& other) const
{
    return *this < other || *this == other;
}

double triangle::calculate_area() const
{
    double p = (first + second + third) / 2;
    return sqrt(p * (p - first) * (p - second) * (p - third));
}

double triangle::calculate_perimeter() const
{
    return first + second + third;
}

std::string triangle::get_type() const
{
    return "triangle";
}
