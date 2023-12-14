# include "list.h"

////////////////////////////
//        СПИСОК
////////////////////////////

// КОНСТРУКТОРЫ

template <typename T>
List<T>::List(std::initializer_list<value_type> const &items) {
    for (auto it = items.begin(); it != items.end(); it++)
    {
        push_back(*it);
    }
};

// LIST CAPACITY
template <typename T>
bool List<T>::empty() {
    return (size_ == 0) ? true : false;
}

// LIST ELEMENT ACCESS
template <typename T>
size_t List<T>::size() {
    return size_;
}

template <typename T>
const T & List<T>::front()	{
    if (!head_) {
        throw std::out_of_range("lol");
    }
    return head_->value;
}


template <typename T>
const T & List<T>::back()	{
    if (!head_) {
        throw std::out_of_range("lol");
    }
    return tail_->value;
}

// LIST MODIFIERS
template <typename T>
void List<T>::push_back(const_reference value) {
    Node *node = new Node();
    node->value = value;
    if (head_ == nullptr) {
        head_ = node;
    } else {
        tail_->next = node;
    }
    node->prev = tail_;
    tail_ = node;
    size_++;
}

template <typename T>
void List<T>::push_front(const_reference value) {
    Node *node = new Node();
    node->value = value;
    if (tail_ == nullptr) {
        tail_ = node;
    } else {
        head_->prev = node;
    }
    node->next = head_;
    head_ = node;
    size_++;
}

template <typename T>
void List<T>::pop_front() {
    if (head_ == nullptr) {
        throw std::out_of_range("fix later");
    }
    if (size_ == 1) {
        delete head_;
        head_ = nullptr;
        tail_ = nullptr;
    } else {
        struct Node* tmp = head_->next;
        delete head_;
        head_ = tmp;
        head_->prev = nullptr;
    }
    size_--;
}

template <typename T>
void List<T>::pop_back() {
    if (tail_ == nullptr) {
        throw std::out_of_range("fix later");
    }
    if (size_ == 1) {
        delete head_;
        head_ = nullptr;
        tail_ = nullptr;
    } else {
        struct Node* tmp = tail_->prev;
        delete tail_;
        tail_ = tmp;
        tail_->next = nullptr;
    }
    size_--;
}



template class List<int>;


////////////////////////////
//        ИТЕРАТОР
////////////////////////////

template <typename T>
typename List<T>::ListIterator List<T>::ListIterator::operator++() {
    if (node_->next == nullptr) {
        throw std::out_of_range("iter too much")
    } 
    return node_->next;
}

template <typename T>
typename List<T>::ListIterator List<T>::ListIterator::operator--() {
    if (node_->prev == nullptr) {
        throw std::out_of_range("iter too much")
    } 
    return node_->prev;
}

template <typename T>
const T & List<T>::ListIterator::get_value() {
    return node_->value;
}