#ifndef AVL_TREE_H
#define AVL_TREE_H

#include <iostream>
#include <initializer_list>
#include <utility>

template <class T>
class AVL_tree {
    public:
        using value_type = T;
        using reference = T&;
        using const_reference = const T &;
        using size_type = size_t;
    private:
        struct Node {
            value_type key_ = 0;
            value_type value_ = 0;
            struct Node *left_ = nullptr;
            struct Node *right_ = nullptr;
            struct Node *prev_ = nullptr;
            int height_ = 1;
        };
        struct Node* root = nullptr;
    public:
        class TreeIterator {
            friend class AVL_tree<T>;
            private:
                typename AVL_tree<T>::Node* node_;
            public:
                TreeIterator(){};
                TreeIterator(typename AVL_tree<T>::Node *node):node_(node){};
                TreeIterator& operator++();
                TreeIterator& operator--();
                const_reference get_key();
                const_reference get_value();
        };
        using iterator = TreeIterator;
        AVL_tree() : root(nullptr) {};
        void dummy();
        void print_tree();
        void insert(value_type key, value_type value);
        void remove(value_type key);
        iterator begin();
        iterator end();

        // почему друзья записаны так -- https://en.wikibooks.org/wiki/More_C%2B%2B_Idioms/Making_New_Friends
        // грубо говоря, есть другие варианты, но они выглядят стремно
        friend int get_height(Node* current) {
            return current?current->height_:0;
        }
        friend int get_bfactor(Node* current) {
            return get_height(current->right_)-get_height(current->left_);
        }
        friend void fix_height(Node* current) {
            current->height_ = std::max(get_height(current->right_), get_height(current->left_)) +1;
        }
        friend Node* insert_node(Node* p, value_type key, value_type value) {
            if(!p) {
                Node* curr = new Node();
                curr->key_ = key;
                curr->value_ = value;
                return curr;
            } 
            if (key < p->key_) {
                p->left_ = insert_node(p->left_, key, value);
                if ( p->left_) {
                    p->left_->prev_ = p;
                }
            } else {
                p->right_ = insert_node(p->right_, key, value);
                if ( p->right_) {
                    p->right_->prev_ = p;
                }
            }
            return balance(p);
        }

        friend Node* rotate_right(Node* p) {
            Node* q = p->left_;
            p->left_ = q->right_;
            q->right_ = p;
            q->prev_ = p->prev_;
            p->prev_ = q;
            if (p->left_) {
                p->left_->prev_ = p;
            }
            fix_height(p);
            fix_height(q);
            return q;
        }

        friend Node* rotate_left(Node* q) {
            Node* p = q->right_;
            q->right_ = p->left_;
            p->left_ = q;
            p->prev_ = q->prev_;
            q->prev_ = p;
            if (q->right_) {
                q->right_->prev_ = q;
            }
            fix_height(q);
            fix_height(p);
            return p;
        }

        friend Node* balance (Node* p) {
            fix_height(p);
            if (get_bfactor(p) == 2) {
                if (get_bfactor(p->right_) < 0) {
                    p->right_ = rotate_right(p->right_);
                }
                return rotate_left(p);
            }
            if (get_bfactor(p) == -2) {
                if (get_bfactor(p->left_) > 0) {
                    p->left_ = rotate_left(p->left_);
                }
                return rotate_right(p);
            }
            return p;
        }
        friend Node* remove_node (Node* p, int k) {
            if (!p) {
                return 0;
            }
            if (k > p->key_) {
                p->right_ = remove_node(p->right_, k);
            } else if (k < p->key_) {
                p->left_ = remove_node(p->left_, k);
            } else {
                Node* right = p->right_;
                Node* left = p->left_;
                Node* prev = p->prev_;
                delete p;
                if (!right) {
                    return left;
                }
                Node* change = find_min(right);
                change->prev_ = prev;
                change->right_ = remove_min(right);
                if (change->right_) {
                    change->right_->prev_ = change;
                }
                change->left_ = left;
                if (change->left_) {
                    change->left_->prev_ = change;
                }
                return balance(change);
            }
            return balance(p);
        }
        friend Node* find_min(Node* p) {
            return p->left_?find_min(p->left_):p;
        }

        friend Node* find_max(Node* p) {
            return p->right_?find_max(p->right_):p;
        }

        friend Node* remove_min(Node* p) {
            if (!p->left_) {
                return p->right_;
            }
            p->left_ = remove_min(p->left_);
            return balance(p);
        }
};


#endif