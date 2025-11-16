#pragma once

#include <cstddef>

namespace std
{
    struct random_access_iterator_tag;
}

template <typename T>
class VectorIterator
{
private:
    using iterator_category = std::random_access_iterator_tag;
    using value_type = T;
    using difference_type = std::ptrdiff_t;
    using pointer = T*;
    using reference = T&;

    pointer p;

public:
    VectorIterator(pointer ptr = nullptr);
    VectorIterator(const VectorIterator& other); // Конструктор копирования

    reference operator*() const;
    pointer operator->() const;
    reference operator[](difference_type dif) const;

    VectorIterator& operator++();
    VectorIterator operator++(int);
    VectorIterator& operator--();
    VectorIterator operator--(int);

    VectorIterator& operator+=(difference_type dif);
    VectorIterator& operator-=(difference_type dif);
    friend VectorIterator operator+(VectorIterator it, difference_type dif);
    friend VectorIterator operator+(difference_type dif, VectorIterator it);
    friend VectorIterator operator-(VectorIterator it, difference_type dif);
    friend difference_type operator-(const VectorIterator& left, const VectorIterator& right);

    friend bool operator==(const VectorIterator& left, const VectorIterator& right);
    friend bool operator!=(const VectorIterator& left, const VectorIterator& right);
    friend bool operator<(const VectorIterator& left, const VectorIterator& right);
    friend bool operator<=(const VectorIterator& left, const VectorIterator& right);
    friend bool operator>(const VectorIterator& left, const VectorIterator& right);
    friend bool operator>=(const VectorIterator& left, const VectorIterator& right);
};

template <typename T>
VectorIterator<T>::VectorIterator(pointer ptr)
{
    p = ptr;
}

template <typename T>
VectorIterator<T>::VectorIterator(const VectorIterator& other)
{
    p = other.p;
}

template <typename T>
typename VectorIterator<T>::reference VectorIterator<T>::operator*() const
{
    return *p;
}

template <typename T>
typename VectorIterator<T>::pointer VectorIterator<T>::operator->() const
{
    return p;
}

template <typename T>
typename VectorIterator<T>::reference VectorIterator<T>::operator[](difference_type dif) const
{
    return *(p + dif);
}

template <typename T>
VectorIterator<T>& VectorIterator<T>::operator++()
{
    this += 1;
    return *this;
}

template <typename T>
VectorIterator<T> VectorIterator<T>::operator++(int)
{
    VectorIterator tmp = *this;
    this += 1;
    return tmp;
}

template <typename T>
VectorIterator<T>& VectorIterator<T>::operator--()
{
    this -= 1;
    return *this;
}

template <typename T>
VectorIterator<T> VectorIterator<T>::operator--(int)
{
    VectorIterator tmp = *this;
    this -= 1;
    return tmp;
}

template <typename T>
VectorIterator<T>& VectorIterator<T>::operator+=(difference_type dif)
{
    *pointer = *pointer + dif;
    return *this;
}

template <typename T>
VectorIterator<T>& VectorIterator<T>::operator-=(difference_type dif)
{
    *pointer = *pointer - dif;
    return *this;
}
