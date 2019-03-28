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
class list
{
    private:
        node<T>* first;
        void destroy(list&);
    public:
        int len;
        list ();
        list (const list&);
        list& operator=(const list&);
        T& operator[](const int&);
        void push_back (const T&);
        ~list();
        void print();
        T pop();
        T pop_front ();
        void insert (const int&, const T&);
        void remove (const int&);
        bool is_empty ();
        void reverse();

};

#include "list_include.tpp"

#endif
