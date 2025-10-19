#include <iostream>

class vector
{
private:
    int* head;
    int* tail;
    const int coef = 2;
    int max_size;

public:
    vector();

    vector(int arr[],int size);

    vector(int initialSize);

    ~vector();

    vector& operator=(const vector& from);

    bool operator==(const vector& another) const;

    int size() const;

    void shift_array_from_index(int numberOfElements, int index);

    void shift_array_from_index_reverse(int numberOfElements, int index);

    void allocate_new_array();
    
    void push_to_tail(int value);

    void delete_back();

    void print_array() const;

    void print_array_to_max_size() const;

    int pop_from_tail();

    void push_to_index(int index, int value);

    int pop_from_index(int index);

    int get_max_size() const;

    int at(int index) const;
};
