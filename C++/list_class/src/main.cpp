#include <list.hpp>

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
}
