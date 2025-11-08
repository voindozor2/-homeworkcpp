#pragma once
#include "shape.h"

class rectangle : public shape
{
private:
    int x_1;
    int y_1;
    int x_2;
    int y_2;
    int x_3;
    int y_3;
    int x_4;
    int y_4;

    int calculate_length_of_segment(int x1, int y1, int x2, int y2) const;
public:
    rectangle();
    rectangle(rectangle& other);
    rectangle(int x_1, int y_1, int x_2, int y_2,int x_3,int y_3,int x_4,int y_4);
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

    int get_x1() const;
    int get_y1() const;
    int get_x2() const;
    int get_y2() const;
    int get_x3() const;
    int get_y3() const;
    int get_x4() const;
    int get_y4() const;
};
