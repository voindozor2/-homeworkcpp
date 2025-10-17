#include "myvector.h"

int main(int argc, char* argv[])
{
    vector v1(5);
    v1.push_to_tail(1);
    v1.push_to_tail(2);
    v1.push_to_tail(3);
    v1.push_to_tail(4);
    v1.push_to_tail(5);
    vector v2(3);
    v2.push_to_tail(10);
    v2.push_to_tail(11);
    v2.push_to_tail(12);
    v1 = v2;
    v1.print_array();
    return 0;
}
