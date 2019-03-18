#include "shape.hpp"
#include <cstdlib>
#include <ctime>

shape* get_random ()
{
    if (rand()%2 == 0) {
        return new rectangle ( "red", rand()%10, rand()%10);
    } else {
        return new circle ("blue", rand()%10);
    }
}

int main ()
{
    int nrec = 0;
    int ncir = 0;
    srand(time(NULL));
    rectangle a("red", 12,14);
    //a.get_area();
    a.get_info();
    std::cout << "Rectangle area = " << a.get_area() << std::endl;
    circle b("green", 15);
    b.get_info();
    std::cout << "Circle area = " << b.get_area() << std::endl;
    shape* arr[10];
    for (int i = 0; i < 10; ++i) {
        arr[i] = get_random();
    }
    int m_arr[10];
    for (int i = 0; i < 10; ++i) {
        rectangle* rec = dynamic_cast<rectangle*>(arr[i]);
        circle* cir = dynamic_cast<circle*>(arr[i]);
        if (rec) {
            nrec++;
            m_arr[i] = 1;
        } else if (cir) {
            ncir++;
            m_arr[i] = 0;
        }
    }
    std::cout << "Nr of rectangles = " << nrec << "\nNr of circles = " << ncir << std::endl;
    for (int i = 0; i < 10; ++i) {
        std::cout << m_arr[i] << " " << std::flush;
    }
    std::cout << std::endl;
    for (int i = 0; i < 10; ++i) {
        arr[i]->get_info();
    }
    std::cout << std::endl;
    std::cout << std::endl;
    std::cout << std::endl;
    std::cout << std::endl;

    circle b1(b);

}
