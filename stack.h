#ifndef STACK_H
#define STACK_H

#include <iostream>
#include <initializer_list>
#include <utility>
#include "list.h"

template <class T>
class Stack : private List<T> {
    public:
        using value_type = T;
        using reference = T&;
        using const_reference = const T &;
        using size_type = size_t;
        const_reference top() {
            return this->front();
        };
        // bool empty(
        //     return empty
        // );
        void push(const_reference value) {
            this->push_front(value);
        };
        void pop() {
            this->pop_front();
        }
};

#endif