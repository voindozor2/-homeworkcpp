#include "complex_tests.h"

#include <cassert>
#include <iostream>
#include <fstream>

#include "../../complex/complex.h"

void constructor_complex_test()
{
    complex complex(100, 100);
    assert(complex.get_real() == 100.0);
    assert(complex.get_imag() == 100.0);
    std::cout << "constructor_complex_test is OK" << std::endl;
}

void constructor_copy_complex_test()
{
    complex complex1(100, 100);
    complex complex2(complex1);
    assert(complex2.get_real() == 100.0);
    assert(complex2.get_imag() == 100.0);
    std::cout << "constructor_copy_complex_test is OK" << std::endl;
}

void operator_plus_complex_test()
{
    complex complex1(100, 100);
    complex complex2(100, 100);
    complex1 = complex1 + complex2;
    assert(complex1.get_real() == 200.0);
    assert(complex1.get_imag() == 200.0);
    std::cout << "operator_plus_complex_test is OK" << std::endl;
}

void operator_minus_complex_test()
{
    complex complex1(150, 150);
    complex complex2(100, 100);
    complex1 = complex1 - complex2;
    assert(complex1.get_real() == 50.0);
    assert(complex1.get_imag() == 50.0);
    std::cout << "operator_minus_complex_test is OK" << std::endl;
}

void operator_multiply_complex_test()
{
    complex complex1(0, 2);
    complex complex2(0, 3);
    complex1 = complex1 * complex2;
    assert(complex1.get_real() == -6.0);
    assert(complex1.get_imag() == 0);

    complex complex3(2, 0);
    complex complex4(3, 0);
    complex3 = complex3 * complex4;
    assert(complex3.get_real() == 6.0);
    assert(complex3.get_imag() == 0);

    complex complex5(1, 2);
    complex complex6(3, 4);
    complex5 = complex5 * complex6;
    assert(complex5.get_real() == -5);
    assert(complex5.get_imag() == 10);
    std::cout << "operator_multiply_complex_test is OK" << std::endl;
}

void operator_division_complex_test()
{
    complex complex1(6, 0);
    complex complex2(2, 0);
    complex1 = complex1 / complex2;
    assert(complex1.get_real() == 3);
    assert(complex1.get_imag() == 0);

    complex complex3(1, 2);
    complex complex4(1, 1);
    complex3 = complex3 / complex4;
    assert(complex3.get_real() == 1.5);
    assert(complex3.get_imag() == 0.5);
    std::cout << "operator_division_complex_test is OK" << std::endl;
}

void operator_plus_equal_complex_test()
{
    complex complex1(100, 100);
    complex complex2(100, 100);
    complex1 += complex2;
    assert(complex1.get_real() == 200.0);
    assert(complex1.get_imag() == 200.0);
    std::cout << "operator_plus_equal_complex_test is OK" << std::endl;
}

void operator_minus_equal_complex_test()
{
    complex complex1(150, 150);
    complex complex2(100, 100);
    complex1 -= complex2;
    assert(complex1.get_real() == 50.0);
    assert(complex1.get_imag() == 50.0);
    std::cout << "operator_minus_equal_complex_test is OK" << std::endl;
}

void operator_multiply_equal_complex_test()
{
    complex complex1(0, 2);
    complex complex2(0, 3);
    complex1 *= complex2;
    assert(complex1.get_real() == -6.0);
    assert(complex1.get_imag() == 0);

    complex complex3(2, 0);
    complex complex4(3, 0);
    complex3 *= complex4;
    assert(complex3.get_real() == 6.0);
    assert(complex3.get_imag() == 0);

    complex complex5(1, 2);
    complex complex6(3, 4);
    complex5 *= complex6;
    assert(complex5.get_real() == -5);
    assert(complex5.get_imag() == 10);
    std::cout << "operator_multiply_equal_complex_test is OK" << std::endl;
}

void operator_division_equal_complex_test()
{
    complex complex1(6, 0);
    complex complex2(2, 0);
    complex1 /= complex2;
    assert(complex1.get_real() == 3);
    assert(complex1.get_imag() == 0);

    complex complex3(1, 2);
    complex complex4(1, 1);
    complex3 /= complex4;
    assert(complex3.get_real() == 1.5);
    assert(complex3.get_imag() == 0.5);
    std::cout << "operator_division_equal_complex_test is OK" << std::endl;
}

void operator_equals_complex_test()
{
    complex complex1(100, 200);
    complex complex2(100, 200);
    bool realEquals = static_cast<int>(complex1.get_real()) == static_cast<int>(complex2.get_real());
    bool imagEquals = static_cast<int>(complex1.get_imag()) == static_cast<int>(complex2.get_imag());
    bool complexEquals = complex1 == complex2;
    assert(realEquals && imagEquals == complexEquals);
    std::cout << "operator_equals_complex_test is OK" << std::endl;
}

void operator_not_equals_complex_test()
{
    complex complex1(200, 400);
    complex complex2(100, 200);
    bool realEquals = static_cast<int>(complex1.get_real()) != static_cast<int>(complex2.get_real());
    bool imagEquals = static_cast<int>(complex1.get_imag()) != static_cast<int>(complex2.get_imag());
    bool complexNotEquals = complex1 != complex2;
    assert(realEquals && imagEquals == complexNotEquals);
    std::cout << "operator_not_equals_complex_test is OK" << std::endl;
}

void operator_less_complex_test()
{
    complex complex1(200, 400);
    complex complex2(100, 200);
    bool realLess = static_cast<int>(complex2.get_real()) < static_cast<int>(complex1.get_real());
    bool imagLess = static_cast<int>(complex2.get_imag()) < static_cast<int>(complex1.get_imag());
    bool complexLess = complex2 < complex1;
    assert(realLess && imagLess == complexLess);
    std::cout << "operator_less_complex_test is OK" << std::endl;
}

void operator_more_complex_test()
{
    complex complex1(200, 400);
    complex complex2(100, 200);
    bool realLess = static_cast<int>(complex1.get_real()) > static_cast<int>(complex2.get_real());
    bool imagLess = static_cast<int>(complex1.get_imag()) > static_cast<int>(complex2.get_imag());
    bool complexMore = complex1 > complex2;
    assert(realLess && imagLess == complexMore);
    std::cout << "operator_more_complex_test is OK" << std::endl;
}

void operator_less_equal_complex_test()
{
    complex complex1(100, 100);
    complex complex2(100, 100);
    bool complexLessEqual = complex1 <= complex2;
    assert(true == complexLessEqual);

    complex complex3(200, 200);
    complex complex4(100, 100);
    bool complex3LessEqual = complex4 <= complex3;
    assert(true == complex3LessEqual);
    std::cout << "operator_less_equal_complex_test is OK" << std::endl;
}

void to_string_complex_test()
{
    complex complex2(100, 100);
    std::string str = complex2.toString();
    assert(str == "100.000000 + 100.000000 * i");
    std::cout << "to_string_complex_test is OK" << std::endl;
}

void operator_int_complex_test()
{
    complex complex2(100, 100);
    int complex2Int = complex2;
    assert(complex2Int == 100);
    std::cout << "operator_int_complex_test is OK" << std::endl;
}

void operator_out_complex_test()
{
    complex complex2(100, 100);
    // Создаем временный файл
    std::ofstream out("temp.txt");
    out << complex2;
    out.close();

    std::ifstream in("temp.txt"); // окрываем файл для чтения
    // Читаем из файла и проверяем
    assert(in.is_open());

    std::string line;
    char ch;
    while (in.get(ch))
    {
        line = line + ch;
    }

    assert(line == "100.000000 + 100.000000 * i");
    std::cout << "operator_out_complex_test is OK" << std::endl;
}

void run_complex_tests()
{
    constructor_complex_test();
    constructor_copy_complex_test();
    operator_plus_complex_test();
    operator_minus_complex_test();
    operator_multiply_complex_test();
    operator_division_complex_test();
    operator_plus_equal_complex_test();
    operator_minus_equal_complex_test();
    operator_multiply_equal_complex_test();
    operator_division_equal_complex_test();
    operator_equals_complex_test();
    operator_not_equals_complex_test();
    operator_less_complex_test();
    operator_more_complex_test();
    operator_less_equal_complex_test();
    to_string_complex_test();
    operator_int_complex_test();
    operator_out_complex_test();
}
