#include "vector.h"

template <typename T>
void Vector<T>::reserve_more_capacity(size_t size)
{
    if (size > m_capacity)
    {
        value_type *buff = new value_type[size];
        for (size_t i = 0; i < m_size; ++i)
            buff[i] = std::move(arr[i]);
        delete[] arr;
        arr = buff;
        m_capacity = size;
    }
}

template <typename T>
Vector<T>::Vector(std::initializer_list<value_type> const &items)
{
    arr = new value_type[items.size()];
    int i = 0;
    for (auto it = items.begin(); it != items.end(); it++)
    {
        arr[i] = *it;
        i++;
    }
    m_size = items.size();
    m_capacity = items.size();
};

// ELEMENT ACCESS
template <typename T>
T Vector<T>::at(size_type i)
{
    if (i > m_size) { 
        throw std::out_of_range("Vector index is out of range");
    } 
    return arr[i];
}

template <typename T>
T& Vector<T>::operator[](size_type pos)
{
    if (pos > m_size) { 
        throw std::out_of_range("Vector index is out of range");
    } 
    return arr[pos];
}

template <typename T>
const T& Vector<T>::front()
{
    if (m_size == 0) {
        throw std::out_of_range("Zero-size vector");
    }
    return arr[0];
}

template <typename T>
const T& Vector<T>::back()
{
    if (m_size == 0) {
        throw std::out_of_range("Zero-size vector");
    }
    return arr[m_size-1];
}

// CAPACITY
template <typename T>
size_t Vector<T>::size()
{
    return m_size;
}

template <typename T>
size_t Vector<T>::capacity()
{
    return m_capacity;
}

template <typename T>
bool Vector<T>::empty()
{
    return (m_size == 0) ?  true : false;
}

template <typename T>
iterator Vector<T>::begin() {
    ListIterator a(head_);
    return a;
}

// MODIFIERS

template <typename T>
void Vector<T>::push_back(T v)
{
    if (m_size == m_capacity)
    {
        reserve_more_capacity(m_size * 2);
    }
    arr[m_size++] = v;
}

template <typename T>
void Vector<T>::pop_back()
{
    m_size--;
}

template class Vector<int>;