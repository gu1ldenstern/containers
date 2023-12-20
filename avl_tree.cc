#include "avl_tree.h"
#include <vector>
#include <string>
#include <math.h>

template <typename T>
void AVL_tree<T>::dummy() {
    std::cout << "DEBUG! " << root->key_ << " DEBUG!\n" ;
    std::cout << "DEBUG! " << root->left_->key_ << " DEBUG!\n" ;
}


template <typename T>
void AVL_tree<T>::print_tree() {
    // int tree_h = root->height_;
    AVL_tree<T>::Node* empty = new Node();
    empty->height_ = 0;
    std::cout << "debug! " <<  root->height_ << '\n' ;
    std::vector<AVL_tree<T>::Node*> nodes;
    std::vector<AVL_tree<T>::Node*> new_nodes;
    nodes.push_back(root);
    int start_height = root->height_;
    while (true) {
        int heights = 0;
        for (size_type i = 0; i<nodes.size(); i++) {
            for (int k = 0; k < pow( 2, (start_height))*((i == 0)?1:2); k++) {
                std::cout << ' ';
            }
            std::cout << ((nodes[i]->height_ == 0)?"*":std::to_string(nodes[i]->key_));
            // std::cout << ((nodes[i]->height_ == 0)?"?":std::to_string(nodes[i]->prev_?nodes[i]->prev_->key_:-1));
            heights+=nodes[i]->height_;
            new_nodes.push_back(nodes[i]->left_?nodes[i]->left_:empty);
            new_nodes.push_back(nodes[i]->right_?nodes[i]->right_:empty);
        }
        nodes = std::move(new_nodes);
        new_nodes.clear();
        if (heights == 0) {
            break;
        }
        std::cout << '\n';
        start_height--;
    }
    std::cout << '\n';
}

template <typename T>
void AVL_tree<T>::insert(T key, T value) {
    root = insert_node(root, key, value);
}

template <typename T>
void AVL_tree<T>::remove(T key) {
    root = remove_node(root, key);
}

template <typename T>
typename AVL_tree<T>::TreeIterator AVL_tree<T>::begin() {
    iterator iter(find_min(root));
    return iter;
}

template <typename T>
typename AVL_tree<T>::TreeIterator AVL_tree<T>::end() {
    iterator iter(find_max(root));
    return iter;
}

template <typename T>
typename AVL_tree<T>::TreeIterator& AVL_tree<T>::TreeIterator::operator++() {
    if (node_->right_) {
        node_ = find_min(node_->right_);
        return *this;
    }
    while (node_->prev_) {
        if (node_->prev_->key_ > node_->key_) {
            node_ = node_->prev_;
            return *this;
        }
        node_ = node_->prev_;
    }
    throw std::out_of_range("No more elements sorry");
}

template <typename T>
typename AVL_tree<T>::TreeIterator& AVL_tree<T>::TreeIterator::operator--() {
    if (node_->left_) {
        node_ =  find_max(node_->left_);
        return *this;
    }
    while (node_->prev_) {
        if (node_->prev_->key_ < node_->key_) {
            node_ = node_->prev_;
            return *this;
        }
        node_ = node_->prev_;
    }
    throw std::out_of_range("No more elements sorry");
}

template <typename T>
const T & AVL_tree<T>::TreeIterator::get_key() {
    return node_->key_;
}

template <typename T>
const T & AVL_tree<T>::TreeIterator::get_value() {
    return node_->value_;
}

template class AVL_tree<int>;