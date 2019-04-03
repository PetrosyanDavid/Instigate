#ifndef BINARRY_SEARCH_TREE_HPP
#define BINARY_SEARCH_TREE_HPP

#include <iostream>
#include <cassert>
#include "queue.hpp"

template <class T>
struct node
{
    public:
        T m_data;
    public:
        T& get_data();

    public:
        node<T>* m_left;
    public:
        node<T>*& get_left();

    public:
        node<T>* m_right;
    public:
        node<T>*& get_right();

        //Constructors
        node ();
        node (T );
        node (T, node<T>*, node<T>*);
};


template <class T>
class tree
{
    private:
        node<T>* m_root;

    private:
        // places  data val under appropriate node below adress node
        void insert_helper (node<T>* adress, const T& val);

        void print_helper (node<T>* adress);

        // finds if node with value val exists in nodes under atress
        bool find_helper (node<T>* adress,const T& val);

        // deletes all nodes under adress including itself
        void destroy(node<T>* adress);

        // looks for node with data val in nodes under adress and
        // returns pointer to its parent node
        node<T>* find_adress_helper (node<T>* adress, const T& val);

        // searches for node with data val somewhere under adress node
        // and deletes it
        void remove_adress (node<T>* adress, const T& val);

        int get_height_helper (node<T>*, int);

        // remove node with 0 children at current
        void remove_zero (node<T>* patent, node<T>* current);
        // remove node with 1 hild at current
        void remove_one (node<T>* parent, node<T>* current);
        // remove node with 2 childern at current
        void remove_two (node<T>* current);

    public:
        //Constructors
        tree ();
        ~tree();

        // create node with data val in appropriate place in tree
        void insert (const T& val);

        // find if node with data val exists in tree
        bool find (const T& val);

        // delete node with data val from treee if it exists
        void remove (const T& val);

        int get_height ();

        // print tree inorder
        void print ();

        // print tree line by line
        void print_traverse ();
};

#include "binary_search_tree_include.tpp"
#endif
