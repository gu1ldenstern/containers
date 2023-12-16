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
void List<T>::clear() {
    while (this->size() != 0) {
        this->pop_back();
    }
}

template <typename T>
void List<T>::swap(List& other)	{
    std::swap(this->head_, other.head_);
    std::swap(this->tail_, other.tail_);
    std::swap(this->size_, other.size_);
}


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

template <typename T>
typename List<T>::ListIterator List<T>::begin() {
    iterator iter(head_);
    return iter;
}

template <typename T>
typename List<T>::ListIterator List<T>::end() {
    iterator iter(tail_);
    return iter;
}


template <typename T>
void List<T>::reverse() {
    iterator start(head_);
    iterator finish(tail_);
    for (size_type x = 0; x < size_/2; x++) {
        if (x != 0) {
            ++start;
            ++finish;
        }
        std::swap(start.node_->value, finish.node_->value);
    }
}

template <typename T>
void List<T>::splice(iterator pos, List& other) {	 // NB! ЗАМЕНИТЬ НА CONST
    while (true) {
        other.push_back(pos.get_value());
        if (pos.node_->next == nullptr) {
            break;
        }
        ++pos;
    }
}

template <typename T>
void List<T>::unique() {
    if (!this->empty()) {
        iterator iter = this->begin();
        while (iter.node_->next != nullptr) {
            iterator possibly_delete(iter.node_);
            ++iter;
            if (possibly_delete.node_->value == iter.node_->value) {
                this->erase(possibly_delete);
            }
        }
    } 
}

template <typename T>
void List<T>:: merge(List& other) {
    iterator first(this->head_);
    while (first.node_->next != nullptr) {
        if (other.size() == 0) {
            break;
        }
        if (other.front() <= first.node_->value) {
            this->insert(first, other.front());
            other.pop_front();
        } else {
            if (first.node_->next != nullptr) {
                ++first;
            }
        }
    }
    while (other.size() != 0) {
        this->push_back(other.front());
        other.pop_front();
    }
}

template <typename T>
void List<T>::erase(ListIterator pos) {
    if (pos.node_->prev != nullptr) {
        pos.node_->prev->next = pos.node_->next;
    } else {
        head_ = pos.node_->next;
    }
    if (pos.node_->next != nullptr) {
        pos.node_->next->prev = pos.node_->prev;

    } else {
        tail_ = pos.node_->prev;
    }
    size_--;
}

template <typename T>
typename List<T>::ListIterator List<T>::insert(ListIterator pos, const T & value) {
    Node* node = new Node();
    node->value = value;
    node->prev = pos.node_->prev;
    node->next = pos.node_;
    if (pos.node_->prev != nullptr){
        pos.node_->prev->next = node;
    } else {
        head_ = node;
    }
    pos.node_->prev = node;
    iterator current(node);
    size_++;
    return current;
}

template class List<int>;


////////////////////////////
//        ИТЕРАТОР
////////////////////////////

template <class T>
typename List<T>::ListIterator& List<T>::ListIterator::operator++() {
    if (node_->next == nullptr) {
        throw std::out_of_range("iter too much");
    } 
    node_ = node_->next;
    return *this;
}

template <class T>
typename List<T>::ListIterator& List<T>::ListIterator::operator--() {
    if (node_->prev == nullptr) {
        throw std::out_of_range("iter too much");
    } 
    node_ = node_->prev;
    return *this;
}

template <typename T>
const T & List<T>::ListIterator::get_value() {
    return node_->value;
}