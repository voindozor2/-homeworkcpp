#include <iostream>

class vector
{
private:
    int* head;
    int* tail;
    const int coef = 2;
    int max_size;

public:
    int* get_head()
    {
        return head;
    }

    int* get_tail()
    {
        return tail;
    }

    int get_max_size()
    {
        return max_size;
    }

    vector(int initialSize)
    {
        max_size = initialSize * coef;
        head = new int[max_size];
        tail = head;
    }

    ~vector()
    {
        delete[] head;
    }

    vector& operator=(const vector& from)
    {
        for (int i = 0; i < from.tail - from.head; i++)
        {
            push_to_tail(from.head[i]);
        }
        return *this;
    }

    int size()
    {
        return tail - head;
    }

    void shift_array_from_index(int numberOfElements, int index)
    {
        for (int i = size() - 1; i >= index; i--)
        {
            head[i + numberOfElements] = head[i];
        }
        tail += numberOfElements;
    }

    void shift_array_from_index_reverse(int numberOfElements, int index)
    {
        for (int i = index; i < size(); i++)
        {
            head[i] = head[i + numberOfElements];
        }
        tail -= numberOfElements;
    }

    void allocate_new_array()
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


    void push_to_tail(int value)
    {
        if (size() + 1 > max_size)
        {
            allocate_new_array();
        }
        head[size()] = value;
        tail += 1;
    }

    void delete_back()
    {
        tail -= 1;
    }

    void print_array()
    {
        std::cout << "Array Elements: ";
        for (int i = 0; i < size(); i++)
            std::cout << head[i] << " ";
        std::cout << std::endl;
    }

    void print_array_to_max_size()
    {
        std::cout << "Array Elements: ";
        for (int i = 0; i < max_size; i++)
            std::cout << head[i] << " ";
        std::cout << std::endl;
    }

    int pop_from_tail()
    {
        int result = head[tail - head];
        tail--;
        return result;
    }

    void push_to_index(int index, int value)
    {
        shift_array_from_index(1, index);
        head[index] = value;
    }

    int pop_from_index(int index)
    {
        int result = head[index];
        shift_array_from_index_reverse(1, index);
        return result;
    }
};
