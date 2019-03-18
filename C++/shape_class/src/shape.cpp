#include "shape.hpp"
#include <cmath>

shape::shape ():
    m_name("random "),
    m_color("white")
{
    std::cout << "Default constructor for shape" << std::endl;
}

shape::shape (std::string name, std::string color):
    m_name(name),
    m_color(color)
{
//    std::cout << "Parametrized constructor for shape called" << std::endl;
}

shape::shape (const shape& a)
{
    (void) a;
    std::cout << "Copy constructor for shape" << std::endl;
}

std::string shape::get_name ()
{
    return m_name;
}

std::string shape::get_color ()
{
    return m_color;
}

void shape::get_info()
{
    std::cout << "get info of shape" << std::endl;
}

rectangle::rectangle ():
    m_width(0),
    m_height(0)
{
    std::cout << "Default constructor for  rectangle" << std::endl;
}

rectangle::rectangle (std::string color, int width, int height):
    shape ("rectangle", color),
    m_width(width),
    m_height(height)
{
//    std::cout << "Parametrized constructor for rectangle" << std::endl;
}

rectangle::rectangle (const rectangle& r) : shape(r)
{
    (void) r;
    std::cout << "Copy constructor for rectangle" << std::endl;
}

double rectangle::get_area ()
{
    return m_width*m_height;
}

void rectangle::get_info ()
{
    std::cout << "Name = " << m_name << "\nColor = " << m_color
        << "\nWidth = " << m_width << "\nHeight = " << m_height << std::endl;
    std::cout << std::endl;
}


circle::circle ():
    m_radius(0)
{
    std::cout << "Default constructor for circle" << std::endl;
}

circle::circle (std::string color, int radius):
    shape ("circle", color),
    m_radius(radius)
{
//    std::cout << "Parametrized constructor for circle" << std::endl;
}

circle::circle (const circle& c) : shape()
{
    (void) c;
    std::cout << "Copy constructor for circle" << std::endl;
}

double circle::get_area()
{
    return M_PI*m_radius*m_radius;
}

void circle::get_info ()
{
    std::cout << "Name = " << m_name << "\nColor = " << m_color
        << "\nRadius = " << m_radius << std::endl;
    std::cout << std::endl;
}

