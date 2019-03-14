#include "smart_array.hpp"

int main()
{
    smart_array a(7,2);
    a[3] = 12;
    std::cout << "array_element is " << a[3] <<std::endl;
    smart_array b;
    b = a;
    std::cout << "array_element of copy is " << b[2] <<std::endl;
    std::cout << "array_element of copy is " << b[3] <<std::endl;
}
