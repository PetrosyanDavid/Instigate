#ifndef LIST_HPP
#define LIST_HPP
#include <iostream>

template <class T>
struct node
{
    public:
        T m_data;
        node* m_node;
        node();
        node(T );
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
class list
{
    public:
        node<T>* first;
        int len;
        list ();
        void push_back (const T&);
        ~list();
        void print();
};

template <class T>
list<T>::list() :
    first (nullptr),
    len(0)
{}

template <class T>
list<T>::~list ()
{
    node<T>* tmp_ptr1 = first;
    if (first != nullptr) {
        node<T>* tmp_ptr2 = first->m_node;
        while (tmp_ptr2 != nullptr) {
            delete tmp_ptr1;
            tmp_ptr1 = tmp_ptr2;
            tmp_ptr2 = tmp_ptr1->m_node;
        }
        delete tmp_ptr1;
    }

}


template <class T>
void list<T>::push_back (const T& data)
{
    if (first == nullptr) {
        first = new node<T>(data);
        ++len;
    } else {
        node<T>* tmp_ptr = nullptr;
        tmp_ptr = first;
        while (tmp_ptr->m_node != nullptr) {
            tmp_ptr = tmp_ptr->m_node;
        }
        tmp_ptr->m_node = new node<T>(data);
        len ++;
    }
}

template <class T>
void list<T>::print ()
{
    if (first == nullptr) {
        std::cout << "List is empty" << std::endl;
    } else {
        node<T>* tmp_ptr = first;
        while (tmp_ptr != nullptr) {
            std::cout << tmp_ptr->m_data << " " << std::flush;
            tmp_ptr = tmp_ptr->m_node;
        }
        std::cout << std::endl;
    }
}
#endif
