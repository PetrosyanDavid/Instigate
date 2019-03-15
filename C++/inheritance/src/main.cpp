#include "person.hpp"

int main()
{

    student b(4, "Physiscs", "Theory", 16, 4);
    b.set_person_info(29, "David", "Petrosyan", 183, 125);
    std::cout << std::endl;
    std::cout << "Info for sudent" << std::endl;
    std::cout << std::endl;
    b.get_info();
    std::cout << std::endl;
    person* c = new student;
    std::cout << std::endl;
    c -> get_info();
    delete c;
}
