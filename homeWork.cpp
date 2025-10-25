#include "tests/vector/tests.h"
#include "tests/string/string_tests.h"
#include "tests/big_integer/big_integer_tests.h"
#include "tests/complex/complex_tests.h"

int main(int argc, char* argv[])
{
    run_vector_tests();
    run_string_tests();
    run_big_integer_tests();
    run_complex_tests();
    return 0;
}
