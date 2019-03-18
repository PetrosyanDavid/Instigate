#include "shape.hpp"

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
    std::cout << "Parametrized constructor for shape called" << std::endl;
}

std::string shape::get_name ()
{
    return m_name;
}

std::string shape::get_color ()
{
    return m_color;
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
    std::cout << "Parametrized constructor for rectangle" << std::endl;
}

int rectangle::get_area ()
{
    return m_width*m_height;
}

void rectangle::get_info ()
{
    std::cout << "Name = " << m_name << "\nColor = " << m_color << std::endl;
}
