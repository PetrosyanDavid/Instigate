#ifndef BINARRY_SEARCH_TREE_HPP
#define BINARY_SEARCH_TREE_HPP

#include <iostream>
#include <cassert>

template <class T>
struct node
{
    public:
        T m_data;
        node* m_left;
        node* m_right;
        node ();
        node (T );
};

template <class T>
node<T>::node ():
    m_left(nullptr),
    m_right(nullptr)
{}

template <class T>
node<T>:: node (T data):
    m_data(data),
    m_left(nullptr),
    m_right(nullptr)
{}

template <class T>
class tree
{
    public:
        node<T>* m_root;
        tree ();
        ~tree();
        void insert (const T&);
        void insert_helper (node<T>*, const T&);
        bool find (const T&);
        void print ();
        void print_helper (node<T>* adress);
        void destroy(node<T>*);
        bool find_helper (node<T>*,const T&);
};

template <class T>
tree<T>::tree ():
    m_root(nullptr)
{}

template <class T>
void tree<T>::insert (const T& data)
{
    //node<T> * tmp_ptr = m_root;
    if (m_root == nullptr) {
        m_root = new node<T>(data);
    } else {
        insert_helper(m_root, data);
    }
}

template <class T>
void tree<T>::insert_helper (node<T>* adress, const T& data)
{
    if (data < adress->m_data) {
        if (adress->m_left == nullptr) {
            adress->m_left = new node<T>(data);
        } else {
            insert_helper(adress->m_left, data);
        }
    } else {
        if (adress->m_right == nullptr) {
            adress->m_right = new node<T>(data);
        } else {
            insert_helper(adress->m_right, data);
        }
    }
}

template <class T>
void tree<T>::print ()
{
    if (m_root == nullptr) {
        std::cout << "Nothing to print" << std::endl;
        return;
    }
    print_helper(m_root);
    std::cout << std::endl;
}

template <class T>
void tree<T>::print_helper (node<T>* adress)
{
    if (adress->m_left != nullptr) {
        print_helper(adress->m_left);
    }
    std::cout << adress->m_data << " " << std::flush;
    if (adress->m_right != nullptr) {
        print_helper(adress->m_right);
    }
}

template <class T>
tree<T>::~tree ()
{
    if (m_root == nullptr) {
        return;
    } else {
        destroy (m_root);
    }
}

template <class T>
void tree<T>::destroy (node<T>* adress)
{
    if (adress->m_left) {
        destroy(adress->m_left);
    }
    if (adress->m_right) {
        destroy(adress->m_right);
    }
    delete adress;
}

template <class T>
bool tree<T>::find (const T& val)
{
    if (m_root == nullptr) {
        return false;
    } else {
        return find_helper (m_root, val);
    }
}

template <class T>
bool tree<T>::find_helper (node<T>* adress,const T& val)
{
    if (val == adress->m_data) {
        return true;
    } else if (val < adress->m_data) {
        if (adress->m_left) {
            return find_helper(adress->m_left, val);
        } else {
            return false;
        }
    } else {
        if (adress->m_right) {
            return find_helper(adress->m_right, val);
        } else {
            return false;
        }
    }
}
#endif
