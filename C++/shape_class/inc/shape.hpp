#ifndef SHAPE_H
#define SHAPE_H
#include <iostream>

class shape
{
    public:
        std::string m_name;
        std::string m_color;
    public:
        shape ();
        shape (std::string name , std::string color);
        std::string get_color();
        std::string get_name();
       // void set_color(std::string);
       // void set_name(std::string);
        virtual int get_area() = 0;
};

class rectangle : public shape
{
    public:
        int m_width;
        int m_height;
    public:
        rectangle ();
        rectangle (std::string, int, int);
        int get_area ();
        void get_info();
};
#endif
