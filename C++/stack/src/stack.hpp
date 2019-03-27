#ifndef VECTOR_HPP
#define VECTOR_HPP

#include <iostream>
#include <cassert>
template <typename T> class vector;
template <typename T> std::ostream& operator<< (std::ostream& , const vector<T>&);

template <typename T>
class vector
{
    private:
        T* m_arr;
        int m_size;
        int m_cap;
        void resize();
    public:
        vector ();
        vector (int);
        vector (const vector&);
        vector& operator=(const vector&);
        void insert (const int&, const T&);
        T pop();
        void erase (int);
        T& operator[] (const int&);
        bool operator== (const vector&);
        void push_back (const T&);
        void print ();
        void swap (int, int);
        ~vector();
        friend std::ostream& operator<< <T> (std::ostream&, const vector<T>&);
};

template <class T>
class stack : public vector<T>
{
    public:
        void stack_push (const T&);
        T stack_pop ();
};

#include "stack_include.tpp"
#endif
