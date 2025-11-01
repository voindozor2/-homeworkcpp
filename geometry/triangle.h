#pragma once
#include "shape.h"

class triangle : public shape
{
public:
    double first;
    double second;
    double third;
    
    triangle();
    triangle(triangle& other);
    triangle(double first, double second, double third);
    ~triangle() override = default;

    triangle& operator= (const triangle& other);
    bool operator== (const shape& other) const override;
    bool operator!= (const shape& other) const override;
    bool operator> (const shape& other) const override;
    bool operator< (const shape& other) const override;
    bool operator>= (const shape& other) const override;
    bool operator<= (const shape& other) const override;
    
    double calculate_area() const override;
    double calculate_perimeter() const override;
    std::string get_type() const override;
};
