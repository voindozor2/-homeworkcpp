#include "rectangle.h"

rectangle::rectangle()
{
    width = 0;
    length = 0;
}

rectangle::rectangle(rectangle& other)
{
    width = other.width;
    length = other.length;
}

rectangle::rectangle(double width, double length)
{
    this->width = width;
    this->length = length;
}

rectangle& rectangle::operator=(const rectangle& other)
{
    width = other.width;
    length = other.length;
    return *this;
}

bool rectangle::operator==(const shape& other) const
{
    if (other.get_type() != get_type())
    {
        return false;
    }
    const rectangle& casted = dynamic_cast<const rectangle&>(other);
    return width == casted.width && length == casted.length;
}

bool rectangle::operator!=(const shape& other) const
{
    return !(this == &other);
}

bool rectangle::operator>(const shape& other) const
{
    if (other.get_type() != get_type())
    {
        return false;
    }

    const rectangle& casted = dynamic_cast<const rectangle&>(other);
    return width > casted.width && length > casted.length;
}

bool rectangle::operator<(const shape& other) const
{
    return !(this > &other);
}

bool rectangle::operator>=(const shape& other) const
{
    return *this > other || *this == other;
}

bool rectangle::operator<=(const shape& other) const
{
    return *this < other || *this == other;
}

double rectangle::calculate_area() const
{
    return width * length;
}

double rectangle::calculate_perimeter() const
{
    return 2 * (width + length);
}

std::string rectangle::get_type() const
{
    return "rectangle";
}
