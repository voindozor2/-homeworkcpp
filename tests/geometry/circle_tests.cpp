#include "circle_tests.h"

#include <cassert>
#include <cmath>

#include "../../geometry/circle.h"

void copy_constructor_circle_test()
{
    circle circ_test(1,1);
    circle circ_test2(circ_test);

    assert(circ_test2.radius == 1.0);
    assert(circ_test2.center == 1.0);
}

void constructor_circle_test()
{
    circle circ_test(1,1);

    bool isCircle = circ_test.get_type() == "circle";

    assert(isCircle);
    assert(circ_test.radius == 1.0);
    assert(circ_test.center == 1.0);
}

void operator_equal_circle_test()
{
    circle circ_test(1,1);
    circle circ_test2(2,2);
    circ_test = circ_test2;
    
    assert(circ_test2.radius == 2.0);
    assert(circ_test2.center == 2.0);
}

void operator_equals_circle_test()
{
    circle circ_test(2,2);
    circle circ_test2(2,2);

    bool equal = circ_test == circ_test2;
    bool equal_expected = true;
    assert(equal_expected == equal);
}

void operator_not_equals_circle_test()
{
    circle circ_test(1,1);
    circle circ_test2(2,2);

    bool equal = circ_test != circ_test2;
    bool equal_expected = true;
    assert(equal_expected == equal);
}

void operator_more_circle_test()
{
    circle circ_test(1,1);
    circle circ_test2(2,2);
    bool more = circ_test2 > circ_test;
    bool more_expected = true;
    assert(more_expected == more);
}

void operator_less_circle_test()
{
    circle circ_test(2,2);
    circle circ_test2(1,1);
    bool less = circ_test2 < circ_test;
    bool less_expected = true;
    assert(less_expected == less);
}

void operator_more_equal_circle_test()
{
    circle circ_test(1,1);
    circle circ_test2(2,2);
    bool more = circ_test2 >= circ_test;
    bool more_expected = true;
    assert(more_expected == more);

    circle circ_test3(1,1);
    circle circ_test4(1,1);
    bool equal = circ_test2 >= circ_test;
    bool equal_expected = true;
    assert(equal_expected == equal);
}

void operator_less_equal_circle_test()
{
    circle circ_test(2,2);
    circle circ_test2(1,1);
    bool more = circ_test2 <= circ_test;
    bool more_expected = true;
    assert(more_expected == more);

    circle circ_test3(1,1);
    circle circ_test4(1,1);
    bool equal = circ_test2 <= circ_test;
    bool equal_expected = true;
    assert(equal_expected == equal);
}

void calculate_circle_area_test()
{
    double const pi = std::acos(-1.0);
    circle circ_test(2,2);
    double circle_area_expected = 4 * pi;
    double circle_area = circ_test.calculate_area();
    assert(circle_area_expected == circle_area);
}

void calculate_circle_perimeter_test()
{
    double const pi = std::acos(-1.0);
    double circle_perimeter = 4 * pi;
    circle circ_test(2,2);
    double circle_perim = circ_test.calculate_perimeter();
    assert(circle_perimeter == circle_perim);
}

void run_circle_test()
{
    copy_constructor_circle_test();
    constructor_circle_test();
    operator_equal_circle_test();
    operator_equals_circle_test();
    operator_not_equals_circle_test();
    operator_more_circle_test();
    operator_less_circle_test();
    operator_more_equal_circle_test();
    operator_less_equal_circle_test();
    calculate_circle_area_test();
    calculate_circle_perimeter_test();
}
