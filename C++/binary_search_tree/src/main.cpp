#include "binary_search_tree.hpp"

int main()
{
    tree<int> a;
    a.insert(12);
    a.insert(222);
    a.insert(123);
    a.insert(235345);
    a.insert(986);
    a.insert(1);
    a.insert(77);
    a.print();
    std::cout << a.find(144) << std::endl;
    std::cout << a.find(123) << std::endl;
    //a.remove(235345);
    a.print();
    std::cout << a.get_height() << std::endl;
    a.print_traverse();
}
