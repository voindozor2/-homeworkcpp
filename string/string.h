#pragma once
#include <iosfwd>

class string
{
private:
    char* head;
    size_t max_size;
    const int coef = 2;
    size_t length;

    void allocate(int indexes);

public:
    string();
    string(int initial_size);
    string(const string& other);
    string(const char* chars, int size);
    ~string();
    const size_t size() const;
    string& operator+(const string& other);
    string& operator+(const char&);
    string& operator=(const string& other);
    bool operator==(const string& other) const;
    bool operator!=(const string& other) const;
    char operator[](int index) const;
    char& operator[](int index);
    friend std::istream& operator>>(std::istream& in, string& str);
    friend std::ostream& operator<<(std::ostream& os, const string& str);
    const int get_max_size() const;
    const int get_coef() const;
    const int get_size() const;
};
