#include <iostream>

template <typename T>
class vector
{
private:
    T* head;
    T* tail;
    const int coef = 2;
    int max_size;

public:
    vector();

    vector(T arr[], int size);

    vector(int initialSize);

    vector(const vector& source);

    ~vector();

    vector& operator=(const vector& from);

    bool operator==(const vector& another) const;

    int& operator[](int index);

    size_t size() const;

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

    const int get_max_size() const;

    int at(int index) const;

    int get_coef() const;
};

template <typename T>
vector<T>::vector()
{
    try
    {
        max_size = 10;
        head = new T[max_size];
        tail = head;
    }
    catch (std::bad_alloc& ex)
    {
        std::cout << ex.what() << std::endl;
    }
}

template <typename T>
vector<T>::vector(T arr[], int size)
{
    try
    {
        max_size = size * coef;
        head = new T[max_size];
        tail = head;

        for (int i = 0; i < size; i++)
        {
            head[i] = arr[i];
            tail++;
        }
    }
    catch (std::bad_alloc& ex)
    {
        std::cout << ex.what() << std::endl;
    }
}

template <typename T>
vector<T>::vector(int initialSize)
{
    try
    {
        max_size = initialSize * coef;
        head = new T[max_size];
        tail = head;
    }
    catch (std::bad_alloc& ex)
    {
        std::cout << ex.what() << std::endl;
    }
}

template <typename T>
vector<T>::vector(const vector& source)
{
    try
    {
        max_size = source.max_size;
        head = new T[max_size];
        tail = head;

        for (int i = 0; i < source.size(); i++)
        {
            push_to_tail(source.at(i));
        }
    }
    catch (std::bad_alloc& ex)
    {
        std::cout << ex.what() << std::endl;
    }
}

template <typename T>
vector<T>::~vector()
{
    delete[] head;
}

template <typename T>
vector<T>& vector<T>::operator=(const vector& from)
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

template <typename T>
bool vector<T>::operator==(const vector& another) const
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

template <typename T>
int& vector<T>::operator[](int index)
{
    return head[index];
}

template <typename T>
size_t vector<T>::size() const
{
    return tail - head;
}

template <typename T>
void vector<T>::shift_array_from_index(int numberOfElements, int index)
{
    for (int i = size() - 1; i >= index; i--)
    {
        head[i + numberOfElements] = head[i];
    }
    tail += numberOfElements;
}

template <typename T>
void vector<T>::shift_array_from_index_reverse(int numberOfElements, int index)
{
    for (int i = index; i < size(); i++)
    {
        head[i] = head[i + numberOfElements];
    }
    tail -= numberOfElements;
}

template <typename T>
void vector<T>::allocate_new_array()
{
    try
    {
        T* new_head = new T[max_size * coef];
        T* new_tail = new_head + size();

        for (int i = 0; i < size(); i++)
        {
            new_head[i] = head[i];
        }

        max_size = max_size * coef;
        delete[] head;
        head = new_head;
        tail = new_tail;
    }
    catch (std::bad_alloc& ex)
    {
        std::cout << ex.what() << std::endl;
    }
}

template <typename T>
void vector<T>::push_to_tail(int value)
{
    if (size() + 1 > max_size)
    {
        allocate_new_array();
    }
    head[size()] = value;
    tail += 1;
}

template <typename T>
void vector<T>::delete_back()
{
    tail -= 1;
}

template <typename T>
void vector<T>::print_array() const
{
    std::cout << "Array Elements: ";
    for (int i = 0; i < size(); i++)
        std::cout << head[i] << " ";
    std::cout << std::endl;
}

template <typename T>
void vector<T>::print_array_to_max_size() const
{
    std::cout << "Array Elements: ";
    for (int i = 0; i < max_size; i++)
        std::cout << head[i] << " ";
    std::cout << std::endl;
}

template <typename T>
int vector<T>::pop_from_tail()
{
    T result = head[size()];
    tail--;
    return result;
}

template <typename T>
void vector<T>::push_to_index(int index, int value)
{
    if (index < 0 || index > size())
    {
        throw std::out_of_range("vector index out of range");
    }
    shift_array_from_index(1, index);
    head[index] = value;
}

template <typename T>
int vector<T>::pop_from_index(int index)
{
    if (index < 0 || index >= size())
    {
        throw std::out_of_range("vector index out of range");
    }
    int result = head[index];
    shift_array_from_index_reverse(1, index);
    return result;
}

template <typename T>
const int vector<T>::get_max_size() const
{
    return max_size;
}

template <typename T>
int vector<T>::at(int index) const
{
    if (index < 0 || index >= size())
    {
        throw std::out_of_range("vector index out of range");
    }
    return head[index];
}

template <typename T>
int vector<T>::get_coef() const
{
    return coef;
}
