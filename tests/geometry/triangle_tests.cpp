#include "triangle_tests.h"

#include <cassert>

#include "../../geometry/triangle.h"

void copy_constructor_triangle_test()
{
    triangle triag_test(1,2,3);
    triangle triag_test2(triag_test);

    assert(triag_test2.first == 1.0);
    assert(triag_test2.second == 2.0);
    assert(triag_test2.third == 3.0);
}

void constructor_triangle_test()
{
    triangle triag_test(1,2,3);
    assert(triag_test.first == 1.0);
    assert(triag_test.second == 2.0);
    assert(triag_test.third == 3.0);
}

void operator_equal_triangle_test()
{
    triangle triag_test(1,2,3);
    triangle triag_test2(33,44,55);
    triag_test2 = triag_test;
    assert(triag_test2.first == 1.0);
    assert(triag_test2.second == 2.0);
    assert(triag_test2.third == 3.0);
}

void operator_equals_triangle_test()
{
    triangle triag_test(1,2,3);
    triangle triag_test2(1,2,3);

    bool equals = triag_test == triag_test2;
    bool equals_expected = true;
    assert(equals == equals_expected);
}

void operator_not_equals_triangle_test()
{
    triangle triag_test(1,2,3);
    triangle triag_test2(33,44,55);

    bool not_equals = triag_test != triag_test2;
    bool not_equals_expected = true;
    assert(not_equals == not_equals_expected);
}

void operator_more_triangle_test()
{
    triangle triag_test(33,44,55);
    triangle triag_test2(1,2,3);

    bool more = triag_test > triag_test2;
    bool more_expected = true;
    assert(more == more_expected);
}

void operator_less_triangle_test()
{
    triangle triag_test(1,2,3);
    triangle triag_test2(33,44,55);

    bool less = triag_test < triag_test2;
    bool less_expected = true;
    assert(less == less_expected);
}

void operator_more_equal_triangle_test()
{
    triangle triag_test(33,44,55);
    triangle triag_test2(1,2,3);

    bool more = triag_test >= triag_test2;
    bool more_expected = true;
    assert(more == more_expected);

    triangle triag_test3(1,2,3);
    triangle triag_test4(1,2,3);

    bool equals = triag_test3 >= triag_test4;
    bool equals_expected = true;
    assert(equals == equals_expected);
}

void operator_less_equal_triangle_test()
{
    triangle triag_test(1,2,3);
    triangle triag_test2(33,44,55);

    bool less = triag_test <= triag_test2;
    bool less_expected = true;
    assert(less == less_expected);
    
    triangle triag_test3(1,2,3);
    triangle triag_test4(1,2,3);

    bool equals = triag_test3 <= triag_test4;
    bool equals_expected = true;
    assert(equals == equals_expected);
}

void calculate_triangle_area_test()
{
    triangle triag_test(3,3,3);
    double area = triag_test.calculate_area();

    assert(area == 3.897114317029974);
}

void calculate_triangle_perimeter_test()
{
    triangle triag_test(3,3,3);
    double perimeter = triag_test.calculate_perimeter();
    assert(perimeter == 9.0);
}

void run_triangle_test()
{
    copy_constructor_triangle_test();
    constructor_triangle_test();
    operator_equal_triangle_test();
    operator_equals_triangle_test();
    operator_not_equals_triangle_test();
    operator_more_triangle_test();
    operator_less_triangle_test();
    operator_more_equal_triangle_test();
    operator_less_equal_triangle_test();
    calculate_triangle_area_test();
    calculate_triangle_perimeter_test();
}
