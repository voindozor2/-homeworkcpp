#include "rectangle.h"

#include <cmath>

int rectangle::calculate_length_of_segment(int x1, int y1, int x2, int y2) const
{
    int dif_x = x2 - x1;
    int dif_y = y2 - y1;
    return std::sqrt(dif_x * dif_x + dif_y * dif_y);
}

rectangle::rectangle()
{
    x_1 = 0;
    y_1 = 0;
    x_2 = 0;
    y_2 = 0;
    x_3 = 0;
    y_3 = 0;
    x_4 = 0;
    y_4 = 0;
}

rectangle::rectangle(rectangle& other)
{
    this->x_1 = other.x_1;
    this->y_1 = other.y_1;
    this->x_2 = other.x_2;
    this->y_2 = other.y_2;
    this->x_3 = other.x_3;
    this->y_3 = other.y_3;
    this->x_4 = other.x_4;
    this->y_4 = other.y_4;
}

rectangle::rectangle(int x_1, int y_1, int x_2, int y_2, int x_3, int y_3, int x_4, int y_4)
{
    this->x_1 = x_1;
    this->y_1 = y_1;
    this->x_2 = x_2;
    this->y_2 = y_2;
    this->x_3 = x_3;
    this->y_3 = y_3;
    this->x_4 = x_4;
    this->y_4 = y_4;
}

rectangle& rectangle::operator=(const rectangle& other)
{
    this->x_1 = other.x_1;
    this->y_1 = other.y_1;
    this->x_2 = other.x_2;
    this->y_2 = other.y_2;
    this->x_3 = other.x_3;
    this->y_3 = other.y_3;
    this->x_4 = other.x_4;
    this->y_4 = other.y_4;
    return *this;
}

bool rectangle::operator==(const shape& other) const
{
    if (other.get_type() != get_type())
    {
        return false;
    }
    const rectangle& casted = dynamic_cast<const rectangle&>(other);
    bool eq_segment1 = calculate_length_of_segment(this->x_1, this->y_1, this->x_2, this->y_2)
        == calculate_length_of_segment(casted.get_x1(), casted.get_y1(), casted.get_x2(), casted.get_y2());
    bool eq_segment2 = calculate_length_of_segment(this->x_2, this->y_2, this->x_3, this->y_3) ==
        calculate_length_of_segment(casted.get_x2(), casted.get_y2(), casted.get_x3(), casted.get_y3());
    bool eq_segment3 = calculate_length_of_segment(this->x_3, this->y_3, this->x_4, this->y_4) ==
        calculate_length_of_segment(casted.get_x3(), casted.get_y3(), casted.get_x4(), casted.get_y4());
    bool eq_segment4 = calculate_length_of_segment(this->x_4, this->y_4, this->x_1, this->y_1) ==
        calculate_length_of_segment(casted.get_x4(), casted.get_y4(), casted.get_x1(), casted.get_y1());
    return eq_segment1 && eq_segment2 && eq_segment3 && eq_segment4;
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
    bool more_segment1 = calculate_length_of_segment(this->x_1, this->y_1, this->x_2, this->y_2)
        > calculate_length_of_segment(casted.get_x1(), casted.get_y1(), casted.get_x2(), casted.get_y2());
    bool more_segment2 = calculate_length_of_segment(this->x_2, this->y_2, this->x_3, this->y_3)
        > calculate_length_of_segment(casted.get_x2(), casted.get_y2(), casted.get_x3(), casted.get_y3());
    bool more_segment3 = calculate_length_of_segment(this->x_3, this->y_3, this->x_4, this->y_4)
        > calculate_length_of_segment(casted.get_x3(), casted.get_y3(), casted.get_x4(), casted.get_y4());
    bool more_segment4 = calculate_length_of_segment(this->x_4, this->y_4, this->x_1, this->y_1)
        > calculate_length_of_segment(casted.get_x4(), casted.get_y4(), casted.get_x1(), casted.get_y1());

    return more_segment1 || more_segment2 || more_segment3 || more_segment4;
}

bool rectangle::operator<(const shape& other) const
{
    return !(this >= &other);
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
    return calculate_length_of_segment(x_1,y_1,x_2,y_2) * calculate_length_of_segment(x_2,y_2,x_3,y_3);
}

double rectangle::calculate_perimeter() const
{
    int a = calculate_length_of_segment(x_1,y_1,x_2,y_2);
    int b = calculate_length_of_segment(x_2,y_2,x_3,y_3);
    return (a + b) * 2;
}

std::string rectangle::get_type() const
{
    return "rectangle";
}

int rectangle::get_x1() const
{
    return x_1;
}

int rectangle::get_y1() const
{
    return y_1;
}

int rectangle::get_x2() const
{
    return x_2;
}

int rectangle::get_y2() const
{
    return y_2;
}

int rectangle::get_x3() const
{
    return x_3;
}

int rectangle::get_y3() const
{
    return y_3;
}

int rectangle::get_x4() const
{
    return x_4;
}

int rectangle::get_y4() const
{
    return y_4;
}
