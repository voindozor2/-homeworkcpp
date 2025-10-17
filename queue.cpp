#include <iostream>

class queue
{
private:
    int* head;
    int* tail;
    const int coef = 2;
    int max_size;
    int* start_array_mem;
    int* end_array_mem;

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

    queue(int initialSize)
    {
        max_size = initialSize * coef;
        start_array_mem = new int[max_size];
        end_array_mem = start_array_mem + max_size;
        head = start_array_mem;
        tail = head;
    }

    ~queue()
    {
        delete[] start_array_mem;
    }

    queue& operator=(const queue& from)
    {
        for (int i = 0; i < from.tail - from.head; i++)
        {
            push_to_tail(from.head[i]);
        }
        return *this;
    }

    void allocate_new_array()
    {
        int* new_start_array_mem = new int[max_size * coef];
        int* new_head;
        int* new_tail;

        if (tail - start_array_mem < head - start_array_mem)
        {
            for (int i = end_array_mem - head; i < max_size; i++)
            {
                new_start_array_mem[i + max_size * coef - max_size] = start_array_mem[i];
            }
            new_head = new_start_array_mem + max_size * coef - (head - end_array_mem);

            for (int i = 0; i < tail - start_array_mem; i++)
            {
                new_start_array_mem[i] = start_array_mem[i];
            }

            new_tail = new_start_array_mem + (tail - start_array_mem);
        }
        else
        {
            for (int i = 0; i < end_array_mem - start_array_mem; i++)
            {
                new_start_array_mem[i] = start_array_mem[i];
            }
            new_head = head;
            new_tail = new_start_array_mem + (tail - start_array_mem);
        }

        max_size = max_size * coef;
        delete[] start_array_mem;
        start_array_mem = new_start_array_mem;
        end_array_mem = start_array_mem + max_size;
        head = new_head;
        tail = new_tail;
    }

    void push_to_head(int value)
    {
        if (head - 1 == tail)
        {
            allocate_new_array();
        }
        head--;
        if (start_array_mem - head > 0)
        {
            head = end_array_mem - (start_array_mem - head);
        }

        *head = value;
    }

    void push_to_tail(int value)
    {
        if (tail + 1 == head || tail + 1 > end_array_mem && start_array_mem != head)
        {
            allocate_new_array();
        }
        else
        {
            tail = start_array_mem + (tail - start_array_mem);
        }
        head[tail - head] = value;
        tail += 1;
    }

    void print_array_with_capacity()
    {
        std::cout << "Array Elements: ";
        for (int* i = start_array_mem; i < end_array_mem; i++)
            std::cout << *i << " ";
        std::cout << std::endl;
    }

    int pop_from_head()
    {
        int result = head[0];
        head++;
        if (head - end_array_mem > 0)
        {
            head = start_array_mem + (head - end_array_mem);
        }
        return result;
    }

    int pop_from_tail()
    {
        int result = head[tail - head];
        tail--;
        return result;
    }
};
