#include "smart_array.hpp"

int main()
{
    smart_array a(10,2);
    a.print();
    a[3] = 12;
    a.print();
    a.resize(12);
    a.print();
    std::cout << "Before pushback" << std::endl;
    a.psh_back(16);
    a.print();
    a.resize(12);
    a.print();
    a.resize(14,111);
    a.print();
}
