#ifndef VECTOR_H
#define VECTOR_H

#include <iostream>
#include <initializer_list>
#include <utility>


template <class T>
class Vector
{
    private:
        size_t m_size;
        size_t m_capacity;
        T *arr;
    public:
        using value_type = T;
        using reference = T &;
        using const_reference = const T &;
        using iterator = T *;
        using const_iterator = const T *;
        using size_type = size_t;
    private:
        void reserve_more_capacity(size_type size);
    public:
        // member functions
        Vector() : m_size(0U), m_capacity(0U), arr(nullptr) {}
        explicit Vector(size_type n) : m_size(n), m_capacity(n), arr(n ? new T[n] : nullptr) {}
        Vector(std::initializer_list<value_type> const &items);
        Vector(const Vector &v) : m_size(v.m_size), m_capacity(v.m_capacity), arr(v.arr) {};
        Vector(Vector &&v) : m_size(v.m_size), m_capacity(v.m_capacity), arr(v.arr)
        {
            v.arr = nullptr;
            v.m_size = 0;
        }
        ~Vector() { delete[] arr; }


        // element access
        value_type at(size_type i);
        reference operator[](size_type pos);
        const_reference front();
        const_reference back();

        // iterators

        // capacity
        bool empty();
        size_type size();
        // size_type max_size();
        // void reserve(size_type size);
        size_type capacity();
        // void shrink_to_fit();

        // modifiers
        void push_back(value_type v);
        void pop_back();
};

#endif