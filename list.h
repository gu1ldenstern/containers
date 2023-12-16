#ifndef LIST_H
#define LIST_H

#include <iostream>
#include <initializer_list>
#include <utility>

template <class T>
class List {

    public:
        using value_type = T;
        using reference = T&;
        using const_reference = const T &;
        using size_type = size_t;
    protected:
        struct Node {
            struct Node *next = nullptr;
            struct Node *prev = nullptr;
            value_type value = 0;
        };
    public:
        class ListIterator {
            friend class List<T>;
            private:
                typename List<T>::Node *node_;
            public:
                ListIterator(){};
                ListIterator(typename List<T>::Node *node):node_(node){};
                ListIterator &operator++();
                ListIterator &operator--();
                const_reference get_value();
        };
        using iterator = ListIterator;
    private:
        size_t size_;
        Node *head_;
        Node *tail_;
    public:
        List() : size_(0), head_(nullptr), tail_(nullptr) {};
        // list(size_type n);
        List(std::initializer_list<value_type> const &items);
        // list(const list &l);
        // list(list &&l);
        // ~List();
        // operator=(list &&l)	
        // LIST ELEMENT ACCESS
        const_reference front();
        const_reference back();
        iterator begin();
        iterator end();
        // LIST CAPACITY
        size_type size();
        bool empty();
        // LIST MODIFIERS
        void clear();
        void swap(List& other);
        void push_back(const_reference value);
        void push_front(const_reference value);
        void pop_front();
        void pop_back();
        void reverse();
        void unique();
        void merge(List& other);
        iterator insert(iterator pos, const_reference value);
        void erase(iterator pos);
        void splice(iterator i, List& spliced);
};

#endif