#include <iostream>
#include <list>
 
std::ostream& operator<< (std::ostream& os, std::list<int> const& container)
{
    for (int val : container)
        os << val << ' ';
    return os << '\n';
}
 
int main()
{
    std::list<int> c{1, 2, 2, 3, 3, 2, 1, 1, 2};
    std::cout << "Before unique(): " << c;
    // const auto count1 = c.unique();
    std::cout << "After unique():  " << c
              << c.unique(); << " elements were removed\n";
 
//     c = {1, 2, 12, 23, 3, 2, 51, 1, 2, 2};
//     std::cout << "\nBefore unique(pred): " << c;
 
//     const auto count2 = c.unique([mod = 10](int x, int y)
//     {
//         return (x % mod) == (y % mod);
//     });
 
//     std::cout << "After unique(pred):  " << c
//               << count2 << " elements were removed\n";
// }