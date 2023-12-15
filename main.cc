#include <iostream>
#include "list.h"
// #include "vector.h"

using std::cin;
using std::cout;
using std::endl;

void print_list(List<int> v) {
   List<int>::size_type size = v.size();
   List<int>::iterator iter = v.begin();
   for (int i = 0; i<size-1; i++) {
      std::cout << iter.get_value() << ' ';
      ++iter;
   }
   std::cout << iter.get_value() << '\n';
}

int main() {
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
   List<int> v;
   v.push_back(1);
   v.push_back(2);
   v.push_back(3);
   v.push_back(4);
   print_list(v);
   List<int>::iterator iter = v.begin();
   ++iter;
   ++iter;
   ++iter;
   v.erase(iter);
   // std::cout << '\n' << v.front() << '\n' << v.back();
   print_list(v);
}