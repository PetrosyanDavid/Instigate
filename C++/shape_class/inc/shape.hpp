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
        shape (const shape&);
        shape& operator= (const shape&);
        virtual double get_area() = 0;
        virtual void get_info();
};

class rectangle : public shape
{
    public:
        int m_width;
        int m_height;
    public:
        rectangle ();
        rectangle (std::string, int, int);
        rectangle (const rectangle&);
        double get_area ();
        void get_info ();
};

class circle : public shape
{
    private:
        int m_radius;
    public:
        circle ();
        circle (std::string,std::string, int);
        circle (const circle&, std::string, std::string);
        circle& operator= (const circle&);
        double get_area ();
        void get_info ();
};

#endif
