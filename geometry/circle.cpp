#include "circle.h"
#include <cmath>

circle::circle()
{
    center_x = 0;
    center_y = 0;
    radius = 0;
}

circle::circle(circle& other)
{
    center_x = other.center_x;
    center_y = other.center_y;
    radius = other.radius;
}

circle::circle(double center_x, double center_y, double radius)
{
    this->center_x = center_x;
    this->center_y = center_y;
    this->radius = radius;
}

circle& circle::operator=(const circle& other)
{
    this->center_x = other.center_x;
    this->center_y = other.center_y;
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

int circle::get_center_x() const
{
    return center_x;
}

int circle::get_center_y() const
{
    return center_y;
}

int circle::get_radius() const
{
    return radius;
}
