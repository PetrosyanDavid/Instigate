#include "person.hpp"

person::person ():
    m_age(0),
    m_name(" "),
    m_last_name(" "),
    m_height(0),
    m_weight(0)
{
    std::cout << "Default constructor for person called" << std::endl;
}

person::person (int age, std::string name, std::string last_name,
        int height, int weight):
    m_age (age),
    m_name (name),
    m_last_name (last_name),
    m_height (height),
    m_weight (weight)
{
    std::cout << "Custom constructor for person called" << std::endl;
}

void person::set_person_info (int age, std::string name, std::string last_name,
        int height, int weight)
{
    m_age = age;
    m_name = name;
    m_last_name = last_name;
    m_height = height;
    m_weight = weight;
}

person::~person()
{
    std::cout << "Deconstructor for person called" << std::endl;
}

void person::get_info ()
{
    std::cout << "get_info for person called" << std::endl;
    std::cout << "Age = " << m_age << "\nName = " << m_name
        << "\nLast name = " << m_last_name << "\nHeight = "
        << m_height << "\nWeight = " << m_weight << std::endl;
}

student::student ():
    m_year (0),
    m_faculty (" "),
    m_thesis_name (" "),
    m_courses (0),
    m_gpa (0)
{
    std::cout << "Default constructor for student called" << std::endl;
}

student::student (int year, std::string faculty, std::string thesis_name,
        int courses, int gpa):
    m_year (year),
    m_faculty (faculty),
    m_thesis_name (thesis_name),
    m_courses (courses),
    m_gpa (gpa)
{
    std::cout << "Custom constructor for student called" << std::endl;
}

student::~student ()
{
    std::cout << "Deconstructor for student called" << std::endl;
}

void student::get_info ()
{
    std::cout << "get_info for student  called" << std::endl;
    std::cout << "Age = " << m_age << "\nName = " << m_name
        << "\nLast name = " << m_last_name << "\nHeight = "
        << m_height << "\nWeight = " << m_weight << "\nYear = "
        << m_year << "\nFaculty = " << m_faculty << "\nThesis = "
        << m_thesis_name << "\nNr. of courses = " << m_courses
        << "\nAverage GPA" << m_gpa << std::endl;
}
