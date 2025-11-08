#pragma once
#include "shape.h"

class circle : public shape
{
private:
    int center_x;
    int center_y;
    int radius;
public:
    circle();
    circle(circle& other);
    circle(double center_x, double center_y, double radius);
    ~circle() override = default;

    circle& operator=(const circle& other);
    bool operator==(const shape& other) const override;
    bool operator!=(const shape& other) const override;
    bool operator>(const shape& other) const override;
    bool operator<(const shape& other) const override;
    bool operator>=(const shape& other) const override;
    bool operator<=(const shape& other) const override;

    double calculate_area() const override;
    double calculate_perimeter() const override;
    std::string get_type() const override;
};
