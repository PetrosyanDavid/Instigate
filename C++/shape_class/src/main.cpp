#include "shape.hpp"

int main ()
{
    rectangle a("red", 12,14);
    a.get_area();
    a.get_info();
    std::cout << a.get_area() << std::endl;
}
