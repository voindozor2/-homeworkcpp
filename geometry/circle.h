#pragma once
#include "shape.h"

class circle : public shape
{
public:
    double center;
    double radius;

    circle();
    circle(circle& other);
    circle(double center, double radius);
    ~circle() override = default;

    circle& operator= (const circle& other);
    bool operator== (const shape& other) const override;
    bool operator!= (const shape& other) const;
    bool operator> (const shape& other) const;
    bool operator< (const shape& other) const;
    bool operator>= (const shape& other) const;
    bool operator<= (const shape& other) const;
    
    double calculate_area() const override;
    double calculate_perimeter() const override;
    std::string get_type() const override;
};
