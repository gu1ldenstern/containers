#include <iostream>
// #include "list.h"
// #include "vector.h"
// #include "avl_tree.h"
#include "stack.h"

using std::cin;
using std::cout;
using std::endl;

// void print_list(List<int> v) {
//    List<int>::size_type size = v.size();
//    List<int>::iterator iter = v.begin();
//    for (int i = 0; i<size-1; i++) {
//       std::cout << iter.get_value() << ' ';
//       ++iter;
//       // if (i == 1) {
//       //    break;
//       // } 
//    }
//    std::cout << iter.get_value() << '\n';
// }


int main() {
   Stack<int> example;
   example.push(5);
   std::cout << example.top();
   // AVL_tree<int> tree;
   // tree.insert(5, 0);
   // tree.insert(1, 0);
   // tree.insert(2, 0);
   // tree.insert(6, 0);
   // tree.insert(3, 0);
   // tree.insert(9, 0);
   // tree.insert(8, 0);
   // tree.remove(6);
   // tree.print_tree();
   // AVL_tree<int>::iterator iter = tree.begin();
   // std::cout << iter.get_key() << ' ';
   // ++iter;
   // std::cout << iter.get_key()<< ' ';
   // ++iter;
   // std::cout << iter.get_key()<< ' ';
   // ++iter;
   // std::cout << iter.get_key()<< ' ';
   // ++iter;
   // std::cout << iter.get_key()<< ' ';
   // ++iter;
   // std::cout << iter.get_key()<< ' ';
   // std::cout << get_height(tree.root_);
   //  Vector<int> v = {1, 2, 3, 4, 5};
   //  v.push_back(6);
   //  for (long unsigned i = 0; i < v.size(); i++) {
   //     std::cout << v.at(i); 
   //  }
   //  std::cout << '\n' << v.front() << '\n' << v.back();
   //  std::cout << '\n' << v.size() << '\n' << v.capacity();
   //  std::cout << '\n';
   //  v.pop_back();
   //  for (long unsigned i = 0; i < v.size(); i++) {
   //     std::cout << v.at(i); 
   //  }
   //  std::cout << v[2];
   // List<int> v;
   // v.push_back(1);
   // v.push_back(2);
   // v.push_back(3);
   // v.push_back(5);
   // print_list(v);
   // List<int> c;
   // c.push_back(1);
   // c.push_back(1);
   // c.push_back(1);
   // c.push_back(5);
   // c.push_back(6);
   // c.push_back(7);
   // c.push_back(345);
   // List<int>::iterator iter = v.end();
   // ++iter;
   // List<int>::iterator current = v.insert(iter, 5);
   // ++iter;
   // ++iter;
   // ++iter;
   // v.erase(iter);
   // std::cout << '\n' << v.front() << '\n' << v.back();
   // v.unique();
   // std::cout << current.get_value() << '\n';
   // std::cout << '\n' << v.front() << ' ' << v.back() << ' ' << v.size();
   // v.merge(c);
   // v.swap(c);
   // print_list(v);
   // print_list(c);
}