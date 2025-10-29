#pragma once
#include "../vector/myvector.h"


class big_integer
{
private:
    unsigned char* bytes;
    size_t bits_size = 0;
    bool sig; // true - плюс , false - минус
    unsigned char divider = 10;
    unsigned char* plus(unsigned char* one, unsigned char* two, size_t bits_sizeFirst, size_t bits_sizeSecond);
    unsigned char* minus(unsigned char* one, unsigned char* two, size_t bits_sizeFirst, size_t bits_sizeSecond,bool sigFirst,bool sigSecond);

public:
    big_integer();
    big_integer(int value);
    ~big_integer();
    big_integer(const big_integer& other);
    big_integer& operator=(const big_integer& other);
    big_integer& operator+=(const big_integer& other);
    big_integer& operator+=(const int other);
    big_integer& operator-=(const big_integer& other);
    big_integer& operator++();
    big_integer operator++(int); 
    big_integer& operator--();
    big_integer operator--(int); 
    big_integer operator+(const big_integer& other);
    big_integer operator+(const int other_big_int);
    big_integer operator-(const big_integer& other);
    big_integer operator-(const int other);
    bool operator==(const big_integer& other) const;
    bool operator!=(const big_integer& other) const;
    friend big_integer operator+(int left, const big_integer& right);
    friend big_integer operator-(int left, const big_integer& right);
    std::string get() const;
};
