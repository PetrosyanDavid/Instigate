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
        void push_back (const T&);
        ~list();
        void print();
        T pop();
        void insert (const int&, const T&);
        void remove (const int&);
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

template <class T>
T list<T>::pop ()
{
    assert(first);
    node<T>* tmp_ptr = first;
    node<T>* tmp_ptr_2 = tmp_ptr;
    while (tmp_ptr->m_node != nullptr) {
        tmp_ptr_2 =tmp_ptr;
        tmp_ptr = tmp_ptr->m_node;
    }
    T a = tmp_ptr->m_data;
    delete tmp_ptr;
    tmp_ptr_2->m_node = nullptr;
    --len;
    return a;
}

template <class T>
void list<T>::insert (const int& pos, const T& data)
{
    if (len - 1 < pos) {
        std::cout << "Out of range, for insert" << std::endl;
    } else {
        node<T>* tmp_ptr_1 = first;
        node<T>* tmp_ptr_2 = first->m_node;
        for (int i = 0; i < pos-1; ++i) {
            tmp_ptr_1 = tmp_ptr_2;
            tmp_ptr_2 = tmp_ptr_1->m_node;
        }
        tmp_ptr_1->m_node = new node<T>(data,tmp_ptr_2);
    }
    ++ len;
}

template <class T>
void list<T>::remove (const int& pos)
{
    if (len - 1 < pos) {
        std::cout << "Out of range for remove" << std::endl;
    } else {
        node<T>* tmp_ptr = first;
        for (int i = 0; i < pos-1; ++i) {
            tmp_ptr = tmp_ptr->m_node;
        }
        node<T>* pos_ptr = tmp_ptr->m_node;
        tmp_ptr->m_node = pos_ptr->m_node;
        delete pos_ptr;
    }
    --len;
}

#endif
