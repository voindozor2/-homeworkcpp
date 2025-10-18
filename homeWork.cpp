#include "myvector.h"
#include <cassert>

void test_vector_initilize_with_five_indexes_when_push_ten_elements_max_size_is_not_twenty()
{
    vector test_vector(5);
    for (int i = 0; i < 10; i++)
    {
        test_vector.push_to_tail(i);
    }
    assert(test_vector.size() == 10);
    assert(test_vector.get_max_size() != 20);
    std::cout << "test_vector_initilize_with_five_indexes_when_push_ten_elements_max_size_is_not_twenty is OK" <<
        std::endl;
}

void test_vector_initilize_with_five_indexes_when_push_eleven_elements_max_size_is_twenty()
{
    vector test_vector(5);
    for (int i = 0; i < 11; i++)
    {
        test_vector.push_to_tail(i);
    }
    assert(test_vector.size() == 11);
    assert(test_vector.get_max_size() == 20);
    std::cout << "test_vector_initilize_with_five_indexes_when_push_eleven_elements_max_size_is_twenty is OK" <<
        std::endl;
}

void test_vector_initilize_with_five_indexes_when_push_to_tail_int_sequence_is_equals_to_expected()
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
    std::cout << "test_vector_initilize_with_five_indexes_when_push_to_tail_int_sequence_is_equals_to_expected is OK" <<
        std::endl;
}

void
test_vector_initilize_with_five_indexes_when_push_int_sequence_and_delete_three_elements_from_back_is_equals_to_expected()
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
        "test_vector_initilize_with_five_indexes_when_push_int_sequence_and_delete_three_elements_from_back_is_equals_to_expected is OK"
        << std::endl;
}

void test_vector_initilize_with_five_indexes_when_operator_is_equal_to_another_container()
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
    std::cout << "test_vector_initilize_with_five_indexes_when_operator_is_equal_to_another_container is OK" <<
        std::endl;
}

void test_vector_initilize_with_five_indexes_when_push_to_index_equal_to_expected()
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
    std::cout << "test_vector_initilize_with_five_indexes_when_push_to_index_equal_to_expected is OK" << std::endl;
}

void test_vector_initilize_with_five_indexes_when_delete_from_index_equal_to_expected(){
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
    std::cout << "test_vector_initilize_with_five_indexes_when_delete_from_index_equal_to_expected is OK" << std::endl;
}

int main(int argc, char* argv[])
{
    test_vector_initilize_with_five_indexes_when_push_ten_elements_max_size_is_not_twenty();
    test_vector_initilize_with_five_indexes_when_push_eleven_elements_max_size_is_twenty();
    test_vector_initilize_with_five_indexes_when_push_to_tail_int_sequence_is_equals_to_expected();
    test_vector_initilize_with_five_indexes_when_push_int_sequence_and_delete_three_elements_from_back_is_equals_to_expected();
    test_vector_initilize_with_five_indexes_when_operator_is_equal_to_another_container();
    test_vector_initilize_with_five_indexes_when_push_to_index_equal_to_expected();
    test_vector_initilize_with_five_indexes_when_delete_from_index_equal_to_expected();
    return 0;
}
