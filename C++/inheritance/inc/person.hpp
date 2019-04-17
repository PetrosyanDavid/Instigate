#ifndef PERSON_H
#define PERSON_H

#include <iostream>

class person
{
    public:
        int m_age;
        std::string m_name;
        std::string m_last_name;
        int m_height;
        int m_weight;
        person ();
        person (int, std::string, std::string, int, int);
        void set_person_info (int, std::string, std::string, int, int);
        ~person();
        virtual void get_info () = 0;
};

class student : public person
{
    public:
        int m_year;
        std::string m_faculty;
        std::string m_thesis_name;
        int m_courses;
        int m_gpa;
        student ();
        student (int, std::string, std::string, int, int);
        ~student ();
        //void get_info ();
};

#endif
