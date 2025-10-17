#include <cstdio>
#include <immintrin.h>
#include <iostream>

class Vector
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

    Vector(int initialSize)
    {
        max_size = initialSize * coef;
        head = new int[max_size];
        tail = head;
    }

    ~Vector()
    {
        delete[] head;
    }

    Vector& operator=(const Vector& from)
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

    void shift_array(int numberOfElements)
    {
        for (int i = size() - 1; i >= 0; i--)
        {
            head[i + numberOfElements] = head[i];
        }
        tail += numberOfElements;
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

int main(int argc, char* argv[])
{
    std::cout << "Проверка оператора присваивания" << std::endl;
    Vector test1(10);
    Vector test2(10);
    std::cout << "test1 ";
    test1.push_to_tail(1);
    test1.push_to_tail(2);
    test1.push_to_tail(3);
    test2.push_to_tail(5);
    test2.push_to_tail(6);
    test2.push_to_tail(7);
    test1.print_array();

    test2 = test1;

    std::cout << "test2 ";
    test2.print_array();
    std::cout << "Окончание проверки оператора присваивания" << std::endl;

    std::cout << "Проверка переполнения массива и реалокации" << std::endl;
    Vector test3(5);
    std::cout << "test3 ";
    test3.push_to_tail(1);
    test3.push_to_tail(2);
    test3.push_to_tail(3);
    test3.push_to_tail(4);
    test3.push_to_tail(5);
    test3.push_to_tail(6);
    test3.push_to_tail(7);
    test3.push_to_tail(8);
    test3.push_to_tail(9);
    test3.push_to_tail(10);
    test3.print_array_to_max_size();
    test3.push_to_tail(11);
    test3.print_array_to_max_size();
    std::cout << "Окончание проверки переполнения массива и реалокации" << std::endl;

    std::cout << "Проверка удаления из конца" << std::endl;
    test3.pop_from_tail();
    test3.pop_from_tail();
    test3.pop_from_tail();
    test3.print_array();
    std::cout << "Окончание проверки удаления из конца" << std::endl;

    std::cout << "Проверка вставки по индексу" << std::endl;
    std::cout << "test4 ";
    Vector test4(5);
    test4.push_to_tail(1);
    test4.push_to_tail(2);
    test4.push_to_tail(3);
    test4.push_to_index(1, 222);
    test4.push_to_index(3, 333);
    test4.print_array();
    std::cout << "Окончание проверки вставки по индексу" << std::endl;

    std::cout << "Проверка удаления по индексу" << std::endl;
    std::cout << "test5 ";
    Vector test5(5);
    test5.push_to_tail(1);
    test5.push_to_tail(2);
    test5.push_to_tail(3);
    test5.pop_from_index(1);
    test5.print_array();
    std::cout << "Окончание проверки удаления по индексу" << std::endl;
    return 0;
}
