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
    
    Vector(int initialSize)
    {
        max_size = initialSize * coef;
        start_array_mem = new int[max_size];
        end_array_mem = start_array_mem + max_size;
        head = start_array_mem;
        tail = head;
    }

    ~Vector()
    {
        delete[] start_array_mem;
        //Чтобы освободить память от массива, здесь нужно указать указатель на первый элемент массива
    }

    Vector& operator=(const Vector& from)
    {
        for (int i = 0; i < from.tail - from.head; i++)
        {
            push_to_tail(from.head[i]);
            //Тут есть вопрос - почему нет доступа до методов объекта куда копируем
        }
        return *this;
    }

    int size()
    {
        return tail - head;
    }

    void push_to_head_v1(int value)
    {
        shift_array(1);
        head[0] = value;
    }

    void shift_array(int numberOfElements)
    {
        for (int i = size() - 1; i >= 0; i--)
        {
            head[i + numberOfElements] = head[i];
        }
        tail += numberOfElements;
    }

    void allocate_new_array()
    {
        max_size = max_size * coef;
        int* new_start_array_mem = new int[max_size];
        int* new_head = new_start_array_mem + (head - start_array_mem);
        int* new_tail = new_start_array_mem + (tail - start_array_mem);
        for (int i = 0; i < start_array_mem - end_array_mem; i++)
        {
            new_start_array_mem[i] = start_array_mem[i];
        }

        delete[] start_array_mem;
        start_array_mem = new_start_array_mem;
        end_array_mem = start_array_mem;
        head = new_head;
        tail = new_tail;
    }

    void push_to_head_v2(int value)
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

    void delete_back()
    {
        tail -= 1;
    }

    void print_array()
    {
        std::cout << "Array Elements: ";
        for (int* i = head; i < tail; i++)
            std::cout << *i << " ";
        std::cout << std::endl;
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
    //Проверка оператора присваивания
    Vector test1(10);
    Vector test2(10);
    test1.push_to_tail(1);
    test1.push_to_tail(2);
    test1.push_to_tail(3);
    test2.push_to_tail(5);
    test2.push_to_tail(6);
    test2.push_to_tail(7);
    std::cout << "test1 ";
    test1.print_array();

    test2 = test1;

    std::cout << "test2 ";
    test2.print_array();
    //Окончание проверки оператора присваивания
    //Начало проверки переполнения массива методов push_to_head_v2
    Vector test3(5);
    test3.push_to_head_v2(1);
    test3.push_to_head_v2(2);
    test3.push_to_head_v2(3);
    test3.push_to_head_v2(4);
    test3.push_to_head_v2(5);
    test3.print_array_with_capacity();
    //Начало проверки переполнения массива методов push_to_tail
    Vector test4(5);
    test4.push_to_tail(6);
    test4.push_to_tail(7);
    test4.push_to_tail(8);
    test4.push_to_tail(9);
    test4.push_to_tail(10);
    test4.print_array_with_capacity();


    
    return 0;
}
