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
        node (T, node<T>*, node<T>*);
};


template <class T>
class tree
{
    private:
        node<T>* m_root;
        void insert_helper (node<T>*, const T&);
        void print_helper (node<T>* adress);
        bool find_helper (node<T>*,const T&);
        void destroy(node<T>*);
        node<T>* find_adress_helper (node<T>*,const T&, char&);
        void remove_adress (node<T>*, const T&);
    public:
        tree ();
        ~tree();
        void insert (const T&);
        bool find (const T&);
        void print ();
        void remove (const T&);
};

#include "binary_search_tree_include.cpp"
#endif
