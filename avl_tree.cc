#include "avl_tree.h"
#include <vector>
#include <string>

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
    std::vector<AVL_tree<T>::Node*> nodes;
    std::vector<AVL_tree<T>::Node*> new_nodes;
    nodes.push_back(root);
    while (true) {
        int heights = 0;
        for (size_type i = 0; i<nodes.size(); i++) {
            for (int k = 0; k <= (nodes[i]->height_/2-1); k++) {
                std::cout << ' ';
            }
            std::cout << ((nodes[i]->height_ == 0)?"*":std::to_string(nodes[i]->key_)) << ' ';
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

template class AVL_tree<int>;