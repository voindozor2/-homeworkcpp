#include "big_integer.h"

unsigned char* big_integer::plus(unsigned char* one, unsigned char* two, size_t bits_sizeFirst, size_t bits_sizeSecond)
{
    unsigned char perenos = 0;
    int sizeSecond = bits_sizeSecond;
    for (size_t i = bits_sizeFirst; i > 0; i--)
    {
        if (perenos == 1)
        {
            one[i - 1] = one[i - 1] + perenos;
            perenos = 0;
        }
        if (sizeSecond > 0)
        {
            unsigned char temp = one[i - 1] + two[sizeSecond - 1];
            if (temp > divider)
            {
                perenos = 1;
                temp -= divider;
            }
            one[i - 1] = temp;
            sizeSecond--;
        }
    }
    return one;
}

unsigned char* big_integer::minus(unsigned char* one, unsigned char* two, size_t bits_sizeFirst, size_t bits_sizeSecond,
                                  bool sigFirst, bool sigSecond)
{
    size_t raznica = bits_sizeFirst - bits_sizeSecond;
    size_t sizeSecond = 0;
    bool resultSig = true;
    for (size_t i = 0; i < bits_sizeFirst; i++)
    {
        if (i >= raznica)
        {
            if (sigFirst == true && sigSecond == true || sigFirst == false && sigSecond == false)
            {
                if (one[i] > two[sizeSecond])
                {
                    one[i] = one[i] - two[sizeSecond];
                }
                else if (two[sizeSecond] > one[i])
                {
                    resultSig = false;
                    if (i != 0)
                    {
                        if (one[i - 1] != 0)
                        {
                            one[i] = one[i] + one[i - 1] * divider;
                            one[i - 1] = one[i - 1] - 1;
                        }
                        else
                        {
                            for (size_t j = i; j > 0; j--)
                            {
                                if (one[j - 1] != 0)
                                {
                                    one[i] = one[j - 1] * divider - one[i];
                                    one[j - 1] = one[j - 1] - 1;
                                    break;
                                }
                                else
                                {
                                    one[j - 1] = divider - 1;
                                }
                            }
                        }
                    }
                    else
                    {
                        resultSig = false;
                        one[i] = two[sizeSecond] - one[i];
                    }
                    one[i] = one[i] - two[sizeSecond];
                }
                else
                {
                    one[i] = one[i] - two[sizeSecond];
                }
            }
            else
            {
                resultSig = false;
                return plus(one, two, bits_sizeFirst, bits_sizeSecond);
            }
            sizeSecond++;
        }
    }
    return one;
}

big_integer::big_integer()
{
    sig = true;
    bits_size = 0;
    bytes = new unsigned char[bits_size]();
}

big_integer::big_integer(int value)
{
    if (value < 0)
    {
        sig = false;
    }
    else
    {
        sig = true;
    }
    value = abs(value);
    bits_size = log10(value) + 1;
    bytes = new unsigned char[bits_size]();

    for (size_t i = bits_size; i > 0; i--)
    {
        bytes[i - 1] = static_cast<unsigned char>(value % divider);
        value /= divider;
    }
}

big_integer::~big_integer()
{
    delete[] bytes;
}

big_integer::big_integer(const big_integer& other)
{
    if (this == &other)
    {
        return;
    }
    sig = other.sig;
    bits_size = other.bits_size;

    bytes = new unsigned char[bits_size]();
    for (size_t i = 0; i < bits_size; i++)
    {
        bytes[i] = other.bytes[i];
    }
}

big_integer& big_integer::operator=(const big_integer& other)
{
    if (this == &other)
    {
        return *this;
    }
    sig = other.sig;
    bits_size = other.bits_size;
    bytes = new unsigned char[bits_size]();
    for (size_t i = 0; i < bits_size; i++)
    {
        bytes[i] = other.bytes[i];
    }
    return *this;
}

big_integer& big_integer::operator+=(const big_integer& other)
{
    *this = *this + other;
    return *this;
}

big_integer& big_integer::operator+=(const int other)
{
    big_integer integer(other);
    *this = *this + integer;
    return *this;
}

big_integer& big_integer::operator-=(const big_integer& other)
{
    *this =*this - other;
    return *this;
}


big_integer& big_integer::operator++() //++a
{
    *this += 1;
    return *this;
}

big_integer big_integer::operator++(int) //a++
{
    big_integer temp = *this;
    *this += 1;
    return temp;
}

big_integer& big_integer::operator--() // --a
{
    *this -= 1;
    return *this;
}

big_integer big_integer::operator--(int) // a--            
{
    big_integer temp = *this;
    *this -= 1;
    return temp;
}

big_integer big_integer::operator+(const big_integer& other)
{
    if (bits_size > other.bits_size)
    {
        bytes = plus(bytes, other.bytes, bits_size, other.bits_size);
    }
    else
    {
        bytes = plus(other.bytes, bytes, other.bits_size, bits_size);
    }
    return *this;
}

big_integer big_integer::operator+(const int other)
{
    big_integer other_big_int(other);
    *this = *this + other_big_int;
    return *this;
}

big_integer big_integer::operator-(const big_integer& other)
{
    bytes = minus(bytes, other.bytes, bits_size, other.bits_size, sig, other.sig);
    sig = sig || other.sig;
    return *this;
}

big_integer big_integer::operator-(const int other)
{
    big_integer other_big_int(other);
    *this = *this - other_big_int;
    return *this;
}

bool big_integer::operator==(const big_integer& other)
{
    if (bits_size != other.bits_size)
    {
        return false;
    }

    for (size_t i = 0; i < bits_size; i++)
    {
        if (bytes[i] != other.bytes[i])
        {
            return false;
        }
    }
    return true;
}

bool big_integer::operator!=(const big_integer& other)
{
    if (bits_size != other.bits_size)
    {
        return true;
    }

    for (size_t i = 0; i < bits_size; i++)
    {
        if (bytes[i] != other.bytes[i])
        {
            return true;
        }
    }
    return false;
}

std::string big_integer::get() const
{
    std::string string;

    for (size_t i = 0; i < bits_size; i++)
    {
        string += static_cast<unsigned char>(bytes[i]) + '0';
    }
    string.erase(0, string.find_first_not_of('0'));
    if (sig == false)
    {
        string = '-' + string;
    }
    return string;
}
