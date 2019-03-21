#ifndef LIST_HPP
#define LIST_HPP
#include <iostream>
#include <cassert>

template <class T>
struct node
{
    public:
        T m_data;
        node* m_node;
        node();
        node(T );
        node(T, node*);
};

template <class T>
node<T>::node ():
    m_node(nullptr)
{}

template <class T>
node<T>::node (T data):
    m_data(data),
    m_node(nullptr)
{}

template <class T>
node<T>::node (T data, node* adress):
    m_data(data),
    m_node(adress)
{}

template <class T>
class list
{
    public:
        node<T>* first;
        int len;
        list ();
        list (const list&);
        list& operator=(const list&);
        T& operator[](const int&);
        void push_back (const T&);
        ~list();
        void print();
        T pop();
        void insert (const int&, const T&);
        void remove (const int&);
        bool is_empty ();
        void reverse();

};

#include "list_include.cpp"

#endif
