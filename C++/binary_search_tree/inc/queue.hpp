#ifndef QUEUE_HPP
#define QUEUE_HPP
#include <iostream>
#include <cassert>

template <class T>
struct q_node
{
    public:
        T m_data;
        q_node* m_q_node;
        q_node();
        q_node(T );
        q_node(T, q_node*);
};

template <class T>
class list
{
    private:
        q_node<T>* first;
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

template <class T>
class queue : public list<T>
{
    public:
        T queue_out ();
        void queue_in (const T&);
        //void print();
};
#include "queue_include.cpp"
#endif
