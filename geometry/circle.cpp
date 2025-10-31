#include "circle.h"
#include <cmath>

circle::circle()
{
    center = 0;
    radius = 0;
}

circle::circle(circle& other)
{
    center = other.center;
    radius = other.radius;
}

circle::circle(double center, double radius)
{
    this->center = center;
    this->radius = radius;
}

circle& circle::operator=(const circle& other)
{
    this->center = other.center;
    this->radius = other.radius;
    return *this;
}

bool circle::operator==(const shape& other) const
{
    if (other.get_type() != get_type())
    {
        return false;
    }
    
    return std::fabs(radius - dynamic_cast<const circle&>(other).radius) < std::numeric_limits<double>::epsilon();
}

bool circle::operator!=(const shape& other) const
{
    return !(this == &other);
}

bool circle::operator>(const shape& other) const
{
    if (other.get_type() != get_type())
    {
        return false;
    }

    return radius > dynamic_cast<const circle&>(other).radius;
}

bool circle::operator<(const shape& other) const
{
    if (other.get_type() != get_type())
    {
        return false;
    }

    return radius < dynamic_cast<const circle&>(other).radius;
}

bool circle::operator>=(const shape& other) const
{
    return *this > other || *this == other;
}

bool circle::operator<=(const shape& other) const
{
    return *this < other || *this == other;
}

double circle::calculate_area() const
{
    double const pi = std::acos(-1.0);
    return pi * (radius * radius);
}

double circle::calculate_perimeter() const
{
    double const pi = std::acos(-1.0);
    return 2 * pi * radius;
}

std::string circle::get_type() const
{
    return "circle";
}
