#include <cstdio>
#include <immintrin.h>
#include <iostream>

class Vector
{
private:
    int* head;
    int* tail;
    const int coef = 2;
    int maxSize;
    int* startArray;
    int* endArray;

public:
    Vector(int initialSize)
    {
        maxSize = initialSize * coef;
        startArray = new int[maxSize];
        endArray = startArray + maxSize;
        head = startArray;
        tail = head;
    }

    ~Vector()
    {
        delete[] startArray; //Чтобы освободить память от массива, здесь нужно указать указатель на первый элемент массива
    }

    Vector& operator=(const Vector& to)
    {
        for (int i = 0; i < to.tail - to.head; i++)
        {
            head[i] = to.head[i];
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

    void push_to_head_v2(int value)
    {
        head--;
        int naskolkomenshechemstartarray = startArray - head;
        if (naskolkomenshechemstartarray > 0)
        {
            head = endArray - naskolkomenshechemstartarray;
        }
        *head = value;
    }

    void push_to_tail(int value)
    {
        head[tail - head] = value;
        tail += 1;
    }

    void delete_back()
    {
        tail -= 1;
    }

    void printArray()
    {
        std::cout << "Array Elements: ";
        for (int* i = head; i < tail; i++)
            std::cout << *i << " ";
        std::cout << std::endl;
    }

    void printArrayWithCapacity()
    {
        std::cout << "Array Elements: ";
        std::cout <<  std::endl;
        for (int* i = startArray; i < endArray; i++)
            std::cout << *i << std::endl;
        std::cout << std::endl;
    }
};

int main(int argc, char* argv[])
{
    Vector test1(10);
    test1.push_to_tail(1);
    test1.printArray();
    test1.push_to_tail(2);
    test1.printArray();
    test1.push_to_tail(3);
    test1.printArray();

    test1.pop_back();
    test1.push_to_tail(333);
    test1.printArray();

    test1.push_to_head_v2(222);
    test1.printArrayWithCapacity();


    return 0;
}
