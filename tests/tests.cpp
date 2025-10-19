#include "tests.h"
#include "../vector/myvector.h"
#include <cassert>

void push_ten_elements_max_size_is_not_twenty_test()
{
    vector test_vector(5);
    for (int i = 0; i < 10; i++)
    {
        test_vector.push_to_tail(i);
    }
    assert(test_vector.size() == 10);
    assert(test_vector.get_max_size() != 20);
    std::cout << "push_ten_elements_max_size_is_not_twenty_test is OK" <<
        std::endl;
}

void push_eleven_elements_max_size_is_twenty_test()
{
    vector test_vector(5);
    for (int i = 0; i < 11; i++)
    {
        test_vector.push_to_tail(i);
    }
    assert(test_vector.size() == 11);
    assert(test_vector.get_max_size() == 20);
    std::cout << "push_eleven_elements_max_size_is_twenty_test is OK" <<
        std::endl;
}

void push_to_tail_int_sequence_is_equals_to_expected_test()
{
    vector test_vector(5);
    test_vector.push_to_tail(1);
    test_vector.push_to_tail(2);
    test_vector.push_to_tail(3);
    test_vector.push_to_tail(4);
    test_vector.push_to_tail(5);

    int expectedArray[] = {1, 2, 3, 4, 5};
    int size = std::size(expectedArray);
    vector expected(expectedArray, size);
    assert(test_vector == expected);
    std::cout << "push_to_tail_int_sequence_is_equals_to_expected_test is OK" <<
        std::endl;
}

void push_int_sequence_and_delete_three_elements_from_back_is_equals_to_expected_test()
{
    vector test_vector(5);
    test_vector.push_to_tail(1);
    test_vector.push_to_tail(2);
    test_vector.push_to_tail(3);
    test_vector.push_to_tail(4);
    test_vector.push_to_tail(5);

    test_vector.pop_from_tail();
    test_vector.pop_from_tail();
    test_vector.pop_from_tail();

    int expectedArray[] = {1, 2};
    int size = std::size(expectedArray);
    vector expected(expectedArray, size);
    assert(test_vector == expected);
    std::cout <<
        "push_int_sequence_and_delete_three_elements_from_back_is_equals_to_expected_test is OK"
        << std::endl;
}

void operator_is_equal_to_another_container_test()
{
    vector test_vector(5);
    test_vector.push_to_tail(1);
    test_vector.push_to_tail(2);
    test_vector.push_to_tail(3);
    test_vector.push_to_tail(4);
    test_vector.push_to_tail(5);

    vector test_vector2(5);

    test_vector2 = test_vector;
    assert(test_vector == test_vector2);
    std::cout << "operator_is_equal_to_another_container_test is OK" <<
        std::endl;
}

void when_push_to_index_equal_to_expected_test()
{
    vector test_vector(5);
    test_vector.push_to_tail(1);
    test_vector.push_to_tail(2);
    test_vector.push_to_tail(3);
    test_vector.push_to_tail(4);
    test_vector.push_to_tail(5);

    test_vector.push_to_index(1, 222);
    test_vector.push_to_index(3, 333);

    int expectedArray[] = {1, 222, 2, 333, 3, 4, 5};
    int size = std::size(expectedArray);
    vector expected(expectedArray, size);
    assert(test_vector == expected);
    std::cout << "when_push_to_index_equal_to_expected_test is OK" << std::endl;
}

void delete_from_index_equal_to_expected_test()
{
    vector test_vector(5);
    test_vector.push_to_tail(1);
    test_vector.push_to_tail(2);
    test_vector.push_to_tail(3);
    test_vector.push_to_tail(4);
    test_vector.push_to_tail(5);

    test_vector.pop_from_index(1);
    test_vector.pop_from_index(3);

    int expectedArray[] = {1, 3, 4};
    int size = std::size(expectedArray);
    vector expected(expectedArray, size);
    assert(test_vector == expected);
    std::cout << "delete_from_index_equal_to_expected_test is OK" << std::endl;
}

void constructor_initialize_test()
{
    int init_size = 5;
    vector test_vector(init_size);
    assert(init_size * test_vector.get_coef() == test_vector.get_max_size());
    std::cout << "constructor_initialize_test is OK" << std::endl;
}

void operator_compare_test()
{
    int init_array[] = {1, 2, 3, 4, 5};
    vector test_vector(init_array, 5);
    vector test_vector2(init_array, 5);
    
    bool equals_expected = false;

    for (int i = 0; i < test_vector.size(); ++i)
    {
        if (test_vector.at(i) == test_vector2.at(i))
        {
            equals_expected = true;
        }
    }

    bool equals = test_vector == test_vector2;

    assert(equals_expected == equals);
    
    std::cout << "operator_compare_test is OK" << std::endl;
}

void constructor_copy_test()
{
    int init_array[] = {1, 2, 3, 4, 5};
    vector test_vector(init_array, 5);
    vector test_vector2(test_vector);
    assert(test_vector == test_vector2);
    std::cout << "constructor_copy_test is OK" << std::endl;
}

void constructor_with_sequence_test()
{
    int init_array[] = {1, 2, 3, 4, 5};
    int size = 5;
    vector test_vector(init_array, size);
    const int coef = test_vector.get_coef();
    assert(size * coef == test_vector.get_max_size());

    for (int i = 0; i < size; i++)
    {
        assert(init_array[i] == test_vector.at(i));
    }
    std::cout << "constructor_with_sequence_test is OK" << std::endl;
}

void operator_brackets_test()
{
    int init_array[] = {1, 2, 3, 4, 5};
    vector test_vector(init_array, 5);

    assert(test_vector[1] == init_array[1]);

    test_vector[3] = 555;

    assert(test_vector[3] == 555);

    
    std::cout << "operator_brackets_test is OK" << std::endl;
}

void run_vector_tests()
{
    constructor_initialize_test();
    operator_compare_test();
    constructor_copy_test();
    constructor_with_sequence_test();
    operator_brackets_test();
    push_ten_elements_max_size_is_not_twenty_test();
    push_eleven_elements_max_size_is_twenty_test();
    push_to_tail_int_sequence_is_equals_to_expected_test();
    push_int_sequence_and_delete_three_elements_from_back_is_equals_to_expected_test();
    operator_is_equal_to_another_container_test();
    when_push_to_index_equal_to_expected_test();
    delete_from_index_equal_to_expected_test();
}