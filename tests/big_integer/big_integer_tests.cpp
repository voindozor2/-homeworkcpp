#include "big_integer_tests.h"

#include <cassert>

#include "../../big_integer/big_integer.h"

void constructor_with_value_big_integer_test()
{
    big_integer big_integer(1233345);
    std::string str = big_integer.get();
    assert(str == "1233345");
    std::cout << "constructor_with_value_big_integer_test is OK" << std::endl;
}

void constructor_copy_big_integer_test()
{
    big_integer biginteger(111);
    big_integer biginteger2(biginteger);

    assert(biginteger.get() == biginteger2.get());

    std::cout << "constructor_copy_big_integer_test is OK" << std::endl;
}

void operator_equal_big_integer_test()
{
    big_integer biginteger(111);
    big_integer biginteger2(555);

    biginteger = biginteger2;
    assert(biginteger.get() == biginteger2.get());
    std::cout << "operator_equal_big_integer_test is OK" << std::endl;
}

void operator_plus_equal_big_integer_test()
{
    big_integer biginteger(100);
    big_integer biginteger2(100);
    biginteger += biginteger2;
    assert(biginteger.get() == "200");
    std::cout << "operator_plus_equal_big_integer_test is OK" << std::endl;
}

void operator_plus_equal_int_big_integer_test()
{
    big_integer biginteger(100);
    biginteger += 100;
    assert(biginteger.get() == "200");
    std::cout << "operator_plus_equal_big_integer_test is OK" << std::endl;
}

void operator_minus_equal_big_integer_test()
{
    big_integer biginteger(100);
    biginteger -= 50;
    assert(biginteger.get() == "50");
    std::cout << "operator_minus_equal_big_integer_test is OK" << std::endl;
}

void operator_increment_prefix_big_integer_test()
{
    big_integer biginteger(100);
    biginteger = ++biginteger;
    assert(biginteger.get() == "101");
    std::cout << "operator_increment_big_integer_test is OK" << std::endl;
}

void operator_increment_postfix_big_integer_test()
{
    big_integer biginteger(100);
    assert(biginteger++.get() == "100");
    assert(biginteger.get() == "101");
    std::cout << "operator_increment_big_integer_test is OK" << std::endl;
}

void operator_decrement_big_integer_test()
{
    big_integer biginteger(100);
    biginteger = --biginteger;
    assert(biginteger.get() == "99");
    std::cout << "operator_decrement_big_integer_test is OK" << std::endl;
}

void operator_plus_big_integer_big_integer_test()
{
    big_integer biginteger(120);
    big_integer biginteger2(50);
    biginteger = biginteger + biginteger2;
    assert(biginteger.get() == "170");
    std::cout << "operator_plus_big_integer_big_integer_test is OK" << std::endl;
}


void operator_plus_big_integer_more_than_one_millionbig_integer_test()
{
    big_integer biginteger(1230000);
    big_integer biginteger2(1500);
    biginteger = biginteger + biginteger2;
    assert(biginteger.get() == "1231500");
    std::cout << "operator_plus_big_integer_more_than_one_millionbig_integer_test is OK" << std::endl;
}

void operator_plus_int_big_integer_test()
{
    big_integer biginteger(120);
    biginteger = biginteger + 50;
    assert(biginteger.get() == "170");
    std::cout << "operator_plus_int_big_integer_test is OK" << std::endl;
}

void operator_minus_int_big_integer_test()
{
    big_integer biginteger(120);
    biginteger = biginteger - 50;
    assert(biginteger.get() == "70");
    std::cout << "operator_minus_int_big_integer_test is OK" << std::endl;
}

void operator_minus_big_integer_big_integer_test()
{
    big_integer biginteger(120);
    big_integer biginteger2(50);
    biginteger = biginteger - biginteger2;
    assert(biginteger.get() == "70");
    std::cout << "operator_minus_int_big_integer_test is OK" << std::endl;
}

void operator_minus_big_integer_case_2_big_integer_test()
{
    big_integer biginteger(120);
    big_integer biginteger2(-50);
    biginteger = biginteger - biginteger2;
    assert(biginteger.get() == "170");
    std::cout << "operator_minus_int_big_integer_test is OK" << std::endl;
}

void operator_minus_big_integer_case_3_big_integer_test()
{
    big_integer biginteger(-120);
    big_integer biginteger2(-50);
    biginteger = biginteger - biginteger2;
    assert(biginteger.get() == "-70");
    std::cout << "operator_minus_int_big_integer_test is OK" << std::endl;
}


void operator_equals_big_integer_test()
{
    big_integer biginteger(100);
    biginteger += 100;
    assert(biginteger.get() == "200");
    std::cout << "operator_equals_big_integer_test is OK" << std::endl;
}

void operator_not_equals_big_integer_test()
{
    big_integer biginteger(111);
    big_integer biginteger2(biginteger);

    bool equalExpected = biginteger.get() == biginteger2.get();
    bool equal = biginteger == biginteger2;

    assert(equalExpected == equal);
    std::cout << "operator_not_equals_big_integer_test is OK" << std::endl;
}

void run_big_integer_tests()
{
    constructor_with_value_big_integer_test();
    constructor_copy_big_integer_test();
    operator_equal_big_integer_test();
    operator_plus_equal_big_integer_test();
    operator_minus_equal_big_integer_test();
    operator_increment_prefix_big_integer_test();
    operator_increment_postfix_big_integer_test();
    operator_decrement_big_integer_test();
    operator_plus_big_integer_big_integer_test();
    operator_plus_big_integer_more_than_one_millionbig_integer_test();
    operator_plus_equal_int_big_integer_test();
    operator_plus_int_big_integer_test();
    operator_minus_int_big_integer_test();
    operator_minus_big_integer_big_integer_test();
    operator_minus_big_integer_case_2_big_integer_test();
    operator_minus_big_integer_case_3_big_integer_test();
    operator_equals_big_integer_test();
    operator_not_equals_big_integer_test();
}
