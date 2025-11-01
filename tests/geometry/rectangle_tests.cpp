#include <cassert>

#include "../../geometry/rectangle.h"

void copy_constructor_rectangle_test()
{
    rectangle rec_test(1, 2);
    rectangle rec_test2(rec_test);
    assert(rec_test2.width == 1);
    assert(rec_test2.length == 2);
}

void constructor_rectangle_test()
{
    rectangle rec_test(1, 2);
    assert(rec_test.width == 1);
    assert(rec_test.length == 2);
}

void operator_equal_rectangle_test()
{
    rectangle rec_test(1, 2);
    rectangle rec_test2(2, 3);
    rec_test2 = rec_test;
    assert(rec_test2.width == 1);
    assert(rec_test2.length == 2);
}

void operator_equals_rectangle_test()
{
    rectangle rec_test(1, 2);
    rectangle rec_test2(1, 2);
    bool equals = rec_test == rec_test2;
    bool equals_expected = true;
    assert(equals == equals_expected);
}

void operator_not_equals_rectangle_test()
{
    rectangle rec_test(1, 2);
    rectangle rec_test2(2, 2);
    bool equals = rec_test != rec_test2;
    bool equals_expected = true;
    assert(equals == equals_expected);
}

void operator_more_rectangle_test()
{
    rectangle rec_test(1, 2);
    rectangle rec_test2(3, 4);
    bool equals = rec_test2 > rec_test;
    bool equals_expected = true;
    assert(equals == equals_expected);
}

void operator_less_rectangle_test()
{
    rectangle rec_test(3, 3);
    rectangle rec_test2(1, 1);
    bool less = rec_test < rec_test2;
    bool less_expected = true;
    assert(less == less_expected);
}

void operator_more_equal_rectangle_test()
{
    rectangle rec_test(1, 1);
    rectangle rec_test2(2, 2);
    bool more = rec_test2 >= rec_test;
    bool more_expected = true;
    assert(more == more_expected);

    rectangle rec_test3(1, 1);
    rectangle rec_test4(1, 1);
    bool equals = rec_test3 >= rec_test4;
    bool equals_expected = true;
    assert(equals == equals_expected);
}

void operator_less_equal_rectangle_test()
{
    rectangle rec_test(2, 2);
    rectangle rec_test2(3, 3);
    bool more = rec_test <= rec_test2;
    bool more_expected = true;
    assert(more == more_expected);

    rectangle rec_test3(1, 1);
    rectangle rec_test4(1, 1);
    bool equals = rec_test3 <= rec_test4;
    bool equals_expected = true;
    assert(equals == equals_expected);
}

void calculate_rectangle_area_test()
{
    rectangle rec_test(5, 2);
    assert(rec_test.calculate_area() == 10);
}

void calculate_rectangle_perimeter_test()
{
    rectangle rec_test(5, 2);
    double rec_area = rec_test.calculate_area();
    assert(rec_area == 10.0);
}

void run_rectangle_test()
{
    copy_constructor_rectangle_test();
    constructor_rectangle_test();
    operator_equal_rectangle_test();
    operator_equals_rectangle_test();
    operator_not_equals_rectangle_test();
    operator_more_rectangle_test();
    operator_less_rectangle_test();
    operator_more_equal_rectangle_test();
    operator_less_equal_rectangle_test();
    calculate_rectangle_area_test();
    calculate_rectangle_perimeter_test();
}
