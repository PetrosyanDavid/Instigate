#include <vector.hpp>

int main()
{
    vector <int> a(10);
    a.print();
    a.push_back(18);
    a.print();
    a.insert(3,1153);
    a.print();
    std::cout << a.pop() << std::endl;
    a.print();
    a.swap(0,6);
    a.print();
    a.insert(888,123);
    a.print();
    std::cout << a[4] << std::endl;
    a[4] = 777;
    a.print();
    vector <int> b(3);
    b.push_back(12);
    b.push_back(13);
    b.push_back(14);
    b.print();
    b.push_back(15);
    std::cout << a;

}
