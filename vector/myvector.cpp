#include "myvector.h"

vector::vector()
{
    max_size = 10;
    head = new int[max_size];
    tail = head;
}

vector::vector(int arr[], int size)
{
    max_size = size * coef;
    head = new int[max_size];
    tail = head;

    for (int i = 0; i < size; i++)
    {
        head[i] = arr[i];
        tail++;
    }
}

vector::vector(int initialSize)
{
    max_size = initialSize * coef;
    head = new int[max_size];
    tail = head;
}

vector::vector(const vector& source)
{
    max_size = source.max_size;
    head = new int[max_size];
    tail = head;

    for (int i = 0; i < source.size(); i++)
    {
        push_to_tail(source.at(i));
    }
}

vector::~vector()
{
    delete[] head;
}

vector& vector::operator=(const vector& from)
{
    if (this != &from)
    {
        tail = head;
        for (int i = 0; i < from.size(); i++)
        {
            head[i] = from.head[i];
            tail++;
        }
    }
    return *this;
}

bool vector::operator==(const vector& another) const
{
    if (size() != another.size())
    {
        return false;
    }

    for (int i = 0; i < size(); i++)
    {
        if (head[i] != another.head[i])
        {
            return false;
        }
    }
    return true;
}

int& vector::operator[](int index)
{
    return head[index];
}

size_t vector::size() const
{
    return tail - head;
}

void vector::shift_array_from_index(int numberOfElements, int index)
{
    for (int i = size() - 1; i >= index; i--)
    {
        head[i + numberOfElements] = head[i];
    }
    tail += numberOfElements;
}

void vector::shift_array_from_index_reverse(int numberOfElements, int index)
{
    for (int i = index; i < size(); i++)
    {
        head[i] = head[i + numberOfElements];
    }
    tail -= numberOfElements;
}

void vector::allocate_new_array()
{
    int* new_head = new int[max_size * coef];
    int* new_tail = new_head + size();

    for (int i = 0; i < size(); i++)
    {
        new_head[i] = head[i];
    }

    max_size = max_size * coef;
    delete[] head;
    head = new_head;
    tail = new_tail;
}


void vector::push_to_tail(int value)
{
    if (size() + 1 > max_size)
    {
        allocate_new_array();
    }
    head[size()] = value;
    tail += 1;
}

void vector::delete_back()
{
    tail -= 1;
}

void vector::print_array() const
{
    std::cout << "Array Elements: ";
    for (int i = 0; i < size(); i++)
        std::cout << head[i] << " ";
    std::cout << std::endl;
}

void vector::print_array_to_max_size() const
{
    std::cout << "Array Elements: ";
    for (int i = 0; i < max_size; i++)
        std::cout << head[i] << " ";
    std::cout << std::endl;
}

int vector::pop_from_tail()
{
    int result = head[size()];
    tail--;
    return result;
}

void vector::push_to_index(int index, int value)
{
    shift_array_from_index(1, index);
    head[index] = value;
}

int vector::pop_from_index(int index)
{
    int result = head[index];
    shift_array_from_index_reverse(1, index);
    return result;
}

const int vector::get_max_size() const
{
    return max_size;
}

int vector::at(int index) const
{
    return head[index];
}

int vector::get_coef() const
{
    return coef;
}
