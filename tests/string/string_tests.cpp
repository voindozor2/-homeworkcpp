#include "string_tests.h"

#include <cassert>

#include "../../string/string.h"
#include <iostream>
#include <fstream>
#include <string>

void constructor_initial_size_test()
{
    int initial_size = 10;
    string str(initial_size);
    int coef = str.get_coef();
    int size = str.get_size();
    int max_size = str.get_max_size();
    int expected_max_size = 10 * (int)coef;

    assert(max_size == expected_max_size);
    assert(size == 0);

    std::cout << "constructor_initial_size_test is OK" << std::endl;
}

void constructor_string_copy_test()
{
    string test_str2("asdfe", 5);
    string test_str(test_str2);
    assert(test_str.size() == test_str2.size());
    assert(test_str[0] == 'a');
    assert(test_str[1] == 's');
    assert(test_str[2] == 'd');
    assert(test_str[3] == 'f');
    assert(test_str[4] == 'e');

    std::cout << "constructor_string_copy_test is OK" << std::endl;
}

void constructor_from_sequence_test()
{
    string test_str("asdfe", 5);
    assert(test_str.get_size() == 5);
    assert(test_str[0] == 'a');
    assert(test_str[1] == 's');
    assert(test_str[2] == 'd');
    assert(test_str[3] == 'f');
    assert(test_str[4] == 'e');
    std::cout << "constructor_from_sequence_test is OK" << std::endl;
}

void operator_plus_test()
{
    string test_str("b", 1);
    string test_str2("cd", 2);
    assert(test_str.get_size() == 1);
    assert(test_str[0] == 'b');
    test_str = test_str + test_str2;
    assert(static_cast<signed char>(test_str[1]) == 'c');
    assert(static_cast<signed char>(test_str[2]) == 'd');
    std::cout << "operator_plus_test is OK" << std::endl;
}

void operator_plus_char_test()
{
    string test_str("b", 1);
    test_str = test_str + 'a';
    //assert(test_str.get_size() == 2);
    assert(test_str[0] == 'b');
    assert(test_str[1] == 'a');
    std::cout << "operator_plus_char_test is OK" << std::endl;
}

void operator_equating_test()
{
    string test_str("b", 1);
    string test_str2("ab", 2);

    test_str = test_str2;
    assert(test_str == test_str2);
    std::cout << "operator_equating_test is OK" << std::endl;
}

void operator_equals_test()
{
    string test_str2("as", 2);
    assert(test_str2[0] == 'a');
    assert(test_str2[1] == 's');

    string test_str("as", 2);
    assert(test_str[0] == 'a');
    assert(test_str[1] == 's');

    bool equals_expected = true;
    bool equals_actual = test_str == test_str2;

    assert(equals_actual == equals_expected);

    std::cout << "operator_equals_test is OK" << std::endl;
}

void operator_not_equals_test()
{
    string test_str2("as", 2);
    assert(test_str2[0] == 'a');
    assert(test_str2[1] == 's');

    string test_str("asd", 3);
    assert(test_str[0] == 'a');
    assert(test_str[1] == 's');
    assert(test_str[2] == 'd');

    bool equals_expected = false;
    bool equals_actual = test_str == test_str2;

    assert(equals_actual == equals_expected);
    std::cout << "operator_not_equals_test is OK" << std::endl;
}

void operator_brackets_string_test()
{
    string test_str2("as", 2);
    assert(test_str2[0] == 'a');
    assert(test_str2[1] == 's');
    std::cout << "operator_brackets_string_test is OK" << std::endl;
}

void operator_output_test()
{
    string string1("Asdasd", 6);
    // Создаем временный файл
    std::ofstream out("temp.txt");
    out << string1;
    out.close();

    std::ifstream in("temp.txt"); // окрываем файл для чтения
    // Читаем из файла и проверяем
    assert(in.is_open());

    string line;
    char ch;
    while (in.get(ch))
    {
        line = line + ch;
    }

    assert(line == string1);
    std::cout << "operator_output_test is OK" << std::endl;
}

void operator_input_test()
{
    string string1("Asdasd", 6);
    
    // Создаем временный файл
    std::ofstream out("temp2.txt");
    out << string1;
    out.close();

    std::ifstream in("temp2.txt");
    assert(in.is_open());

    string line;
    in >> line;  // Теперь используем корректный оператор >>
    
    assert(line == string1);
    
    in.close();
    remove("temp2.txt");

    
    std::cout << "operator_input_test is OK" << std::endl;
}

void run_string_tests()
{
    constructor_initial_size_test();
    constructor_string_copy_test();
    constructor_from_sequence_test();
    operator_plus_test();
    operator_plus_char_test();
    operator_equating_test();
    operator_equals_test();
    operator_not_equals_test();
    operator_brackets_string_test();
    operator_output_test();
    operator_input_test();
}
