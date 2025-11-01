#pragma once
#include "shape.h"

class rectangle : public shape
{
public:
    double length;
    double width;

    rectangle();
    rectangle(rectangle& other);
    rectangle(double width, double length);
    ~rectangle() override = default;

    rectangle& operator= (const rectangle& other);
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
