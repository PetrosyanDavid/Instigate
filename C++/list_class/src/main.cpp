#include "list.hpp"

int main()
{
    list<int> a;
    a.push_back(12);
    a.push_back(8383);
    a.push_back(954);
    a.print();
    a.pop();
    a.print();
    a.push_back(777);
    a.push_back(1224);
    a.push_back(56);
    a.print();
    a.insert(3, 111);
    a.print();
    a.remove(4);
    a.print();
    std::cout << a[2] << std::endl;
    a[2] = 888;
    a.print();
    list<int> b = a;
    b.print();
    list<int> c;
    c = a;
    c.print();
    a.insert(0,555);
    a.print();
    a.reverse();
    a.print();
    std::cout << a.pop_front() << std::endl;
    a.print();
}
