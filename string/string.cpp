#include "string.h"

#include <iostream>
#include <istream>
#include <ostream>

void string::allocate(int indexes)
{
    try
    {
        max_size = indexes * coef > max_size * coef ? indexes * coef : max_size * coef;
        char* new_head = new char[max_size]();
        for (size_t i = 0; i < size(); i++)
        {
            new_head[i] = head[i];
        }
        delete[] head;
        head = new_head;
    }
    catch (std::bad_alloc& ex)
    {
        std::cout << ex.what() << std::endl;
    }
}

string::string()
{
    try
    {
        int initial_size = 5;
        max_size = (initial_size == 0) ? 1 : initial_size * coef;
        head = new char[max_size](); //Инициализация нулями!
        length = 0;
    }
    catch (std::bad_alloc& ex)
    {
        std::cout << ex.what() << std::endl;
    }
}

string::string(int initial_size)
{
    try
    {
        max_size = (initial_size == 0) ? 1 : initial_size * coef;
        head = new char[max_size](); //Инициализация нулями!
        length = 0;
    }
    catch (std::bad_alloc& ex)
    {
        std::cout << ex.what() << std::endl;
    }
}

string::string(const string& other)
{
    try
    {
        max_size = other.max_size;
        head = new char[max_size](); //Инициализация нулями!
        length = other.length;
        for (int i = 0; i < size(); i++)
        {
            head[i] = other.head[i];
        }
    }
    catch (std::bad_alloc& ex)
    {
        std::cout << ex.what() << std::endl;
    }
}

string::string(const char* chars, int initial_size)
{
    try
    {
        head = new char[initial_size](); //Инициализация нулями!
        max_size = (initial_size == 0) ? 1 : initial_size * coef;
        length = initial_size;
        for (size_t i = 0; i < length; i++)
        {
            head[i] = chars[i];
        }
    }
    catch (std::bad_alloc& ex)
    {
        std::cout << ex.what() << std::endl;
    }
}

string::~string()
{
    delete[] head;
}

const size_t string::size() const
{
    return length;
}

string string::operator+(const string& other)
{
    string temp(*this);
    temp += other;
    return temp;
}

string string::operator+(const char& ch)
{
    string temp(*this);
    return temp += ch;
}

string& string::operator+=(const string& other)
{
    if (size() + other.size() > max_size)
    {
        allocate(size() + other.size());
    }
    for (int i = 0; i < other.size(); i++)
    {
        head[length] = other[i];
        length++;
    }
    return *this;
}

string& string::operator+=(const char& ch)
{
    if (length + 1 == max_size)
    {
        allocate(size() + 5);
    }
    head[length] = ch;
    length++;
    return *this;
}

string& string::operator=(const string& other)
{
    try
    {
        if (this == &other)
        {
            return *this;
        }
        delete [] head;
        max_size = other.max_size;
        head = new char[max_size]();
        length = other.size();
        for (size_t i = 0; i < other.size(); i++)
        {
            head[i] = other.head[i];
        }
    }
    catch (std::bad_alloc& ex)
    {
        std::cout << ex.what() << std::endl;
    }
    return *this;
}

bool string::operator==(const string& other) const
{
    bool equal = true;
    if (size() != other.size())
    {
        return false;
    }

    for (size_t i = 0; i < size(); i++)
    {
        if (head[i] != other.head[i])
        {
            equal = false;
        }
    }
    return equal;
}

bool string::operator!=(const string& other) const
{
    return !(*this == other);
}

char string::operator[](int index) const
{
    if (index < 0 || index >= size())
    {
        throw std::out_of_range("vector index out of range");
    }
    return head[index];
}

char& string::operator[](int index)
{
    return head[index];
}

std::ostream& operator<<(std::ostream& out, const string& str)
{
    for (char* i = str.head; i < str.head + str.size(); i++)
        // По индексу выводило только положение в ASCII таблице
        out << *i;
    return out;
}

std::istream& operator>>(std::istream& in, string& str)
{
    char ch;
    while (in.get(ch))
    {
        str = str + ch;
    }
    return in;
}

const int string::get_max_size() const
{
    return max_size;
}

const int string::get_coef() const
{
    return coef;
}

const int string::get_size() const
{
    return size();
}
