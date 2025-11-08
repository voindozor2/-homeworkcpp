#include "triangle_tests.h"

#include <cassert>

#include "../../geometry/triangle.h"

void copy_constructor_triangle_test()
{
    triangle triag_test(1,1,2,2,3,1);
    triangle triag_test2(triag_test);

    assert(triag_test2.get_x1() == 1);
    assert(triag_test2.get_y1() == 1);
    assert(triag_test2.get_x2() == 2);
    assert(triag_test2.get_y2() == 2);
    assert(triag_test2.get_x3() == 3);
    assert(triag_test2.get_y3() == 1);
}

void constructor_triangle_test()
{
    triangle triag_test(1,1,2,2,3,1);
    assert(triag_test.get_x1() == 1);
    assert(triag_test.get_y1() == 1);
    assert(triag_test.get_x2() == 2);
    assert(triag_test.get_y2() == 2);
    assert(triag_test.get_x3() == 3);
    assert(triag_test.get_y3() == 1);
}

void operator_equal_triangle_test()
{
    triangle triag_test(1,1,2,2,3,1);
    triangle triag_test2(2,2,3,3,4,1);
    triag_test2 = triag_test;
    assert(triag_test2.get_x1() == 1);
    assert(triag_test2.get_y1() == 1);
    assert(triag_test2.get_x2() == 2);
    assert(triag_test2.get_y2() == 2);
    assert(triag_test2.get_x3() == 3);
    assert(triag_test2.get_y3() == 1);
}

void operator_equals_triangle_test()
{
    triangle triag_test(1,1,2,2,3,1);
    triangle triag_test2(1,1,2,2,3,1);

    bool equals = triag_test == triag_test2;
    bool equals_expected = true;
    assert(equals == equals_expected);
}

void operator_not_equals_triangle_test()
{
    triangle triag_test(1,2,2,3,3,2);
    triangle triag_test2(1,1,2,2,3,1);

    bool not_equals = triag_test != triag_test2;
    bool not_equals_expected = true;
    assert(not_equals == not_equals_expected);
}

void operator_more_triangle_test()
{
    triangle triag_test(1,2,2,3,3,2);
    triangle triag_test2(1,1,2,2,3,1);
    bool more = triag_test > triag_test2;
    bool more_expected = true;
    assert(more == more_expected);
}

void operator_less_triangle_test()
{
    triangle triag_test(1,1,2,2,3,1);
    triangle triag_test2(1,1,2,4,3,1);

    
    bool less = triag_test < triag_test2;
    bool less_expected = true;
    assert(less == less_expected);
}

void operator_more_equal_triangle_test()
{
    triangle triag_test(1,2,2,3,3,2);
    triangle triag_test2(1,1,2,2,3,1);

    bool more = triag_test >= triag_test2;
    bool more_expected = true;
    assert(more == more_expected);

    triangle triag_test3(1,2,2,3,3,2);
    triangle triag_test4(1,2,2,3,3,2);

    bool equals = triag_test3 >= triag_test4;
    bool equals_expected = true;
    assert(equals == equals_expected);
}

void operator_less_equal_triangle_test()
{
    triangle triag_test(1,1,2,2,3,1);
    triangle triag_test2(1,2,2,3,3,2);

    bool less = triag_test <= triag_test2;
    bool less_expected = true;
    assert(less == less_expected);
    
    triangle triag_test3(1,1,2,2,3,1);
    triangle triag_test4(1,1,2,2,3,1);

    bool equals = triag_test3 <= triag_test4;
    bool equals_expected = true;
    assert(equals == equals_expected);
}

void calculate_triangle_area_test()
{
    triangle triag_test(1,1,2,2,3,1);
    double area = triag_test.calculate_area();

    assert(area == 1);
}

void calculate_triangle_perimeter_test()
{
    triangle triag_test(1,1,2,2,3,1);
    double perimeter = triag_test.calculate_perimeter();
    assert(perimeter == 4.8284271247461898);
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
