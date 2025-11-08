#include "triangle.h"

#include <cmath>

double triangle::calculate_length_of_segment(int x1, int y1, int x2, int y2) const
{
    int dif_x = x2 - x1;
    int dif_y = y2 - y1;
    return std::sqrt(dif_x * dif_x + dif_y * dif_y);
}

triangle::triangle()
{
    x_1 = 0;
    y_1 = 0;
    x_2 = 0;
    y_2 = 0;
    x_3 = 0;
    y_3 = 0;
}

triangle::triangle(triangle& other)
{
    this->x_1 = other.x_1;
    this->y_1 = other.y_1;
    this->x_2 = other.x_2;
    this->y_2 = other.y_2;
    this->x_3 = other.x_3;
    this->y_3 = other.y_3;
}

triangle::triangle(int x_1, int y_1, int x_2, int y_2, int x_3, int y_3)
{
    this->x_1 = x_1;
    this->y_1 = y_1;
    this->x_2 = x_2;
    this->y_2 = y_2;
    this->x_3 = x_3;
    this->y_3 = y_3;
}

triangle& triangle::operator=(const triangle& other)
{
    this->x_1 = other.x_1;
    this->y_1 = other.y_1;
    this->x_2 = other.x_2;
    this->y_2 = other.y_2;
    this->x_3 = other.x_3;
    this->y_3 = other.y_3;
    return *this;
}

bool triangle::operator==(const shape& other) const
{
    if (other.get_type() != get_type())
    {
        return false;
    }
    const triangle& casted = dynamic_cast<const triangle&>(other);
    bool eq_segment1 = calculate_length_of_segment(this->x_1, this->y_1, this->x_2, this->y_2)
        == calculate_length_of_segment(casted.get_x1(), casted.get_y1(), casted.get_x2(), casted.get_y2());
    bool eq_segment2 = calculate_length_of_segment(this->x_2, this->y_2, this->x_3, this->y_3) ==
        calculate_length_of_segment(casted.get_x2(), casted.get_y2(), casted.get_x3(), casted.get_y3());
    bool eq_segment3 = calculate_length_of_segment(this->x_3, this->y_3, this->x_1, this->y_1) ==
        calculate_length_of_segment(casted.get_x3(), casted.get_y3(), casted.get_x1(), casted.get_y1());
    return eq_segment1 && eq_segment2 && eq_segment3;
}

bool triangle::operator!=(const shape& other) const
{
    return !(this == &other);
}

bool triangle::operator>(const shape& other) const
{
    if (other.get_type() != get_type())
    {
        return false;
    }
    const triangle& casted = dynamic_cast<const triangle&>(other);
    bool more_segment1 = calculate_length_of_segment(this->x_1, this->y_1, this->x_2, this->y_2)
        == calculate_length_of_segment(casted.get_x1(), casted.get_y1(), casted.get_x2(), casted.get_y2());
    bool more_segment2 = calculate_length_of_segment(this->x_2, this->y_2, this->x_3, this->y_3) ==
        calculate_length_of_segment(casted.get_x2(), casted.get_y2(), casted.get_x3(), casted.get_y3());
    bool more_segment3 = calculate_length_of_segment(this->x_3, this->y_3, this->x_1, this->y_1) ==
        calculate_length_of_segment(casted.get_x3(), casted.get_y3(), casted.get_x1(), casted.get_y1());

    return more_segment1 || more_segment2 || more_segment3;
}

bool triangle::operator<(const shape& other) const
{
    return !(this >= &other);
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
    return static_cast<double>(abs(x_1 * (y_2 - y_3) + x_2 * (y_3 - y_1) + x_3 * (y_1 - y_2)) / 2);
}

double triangle::calculate_perimeter() const
{
    return calculate_length_of_segment(x_1, y_1, x_2, y_2)
        + calculate_length_of_segment(x_2, y_2, x_3, y_3)
        + calculate_length_of_segment(x_3, y_3, x_1, y_1);
}

std::string triangle::get_type() const
{
    return "rectangle";
}

int triangle::get_x1() const
{
    return x_1;
}

int triangle::get_y1() const
{
    return y_1;
}

int triangle::get_x2() const
{
    return x_2;
}

int triangle::get_y2() const
{
    return y_2;
}

int triangle::get_x3() const
{
    return x_3;
}

int triangle::get_y3() const
{
    return y_3;
}
