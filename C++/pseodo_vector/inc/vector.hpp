#ifndef VECTOR_HPP
#define VECTOR_HPP

#include <iostream>

template <typename T>
class vector
{
    private:
        T* m_arr;
        int m_size;
        int m_cap;
    public:
        vector ();
        vector (int);
        vector (const vector&);
        vector& operator=(const vector&);
        void push_back (T );
        void print ();
        ~vector();
};

template <typename T>
vector<T>::vector () :
    m_size(0),
    m_cap(10)
{
    m_arr = nullptr;
    m_arr = new T[m_cap];
    for (int i = 0; i < m_cap; ++i) {
        m_arr[i] = 0;
    }
}

template <typename T>
vector<T>::vector (int size) :
    m_size(size)
{
    m_cap = 2*m_size;
    m_arr = nullptr;
    m_arr = new T[m_cap];
    for (int i = 0; i < m_size; ++i) {
        m_arr[i] = i;
    }
    for (int i = m_size; i < m_cap; ++i) {
        m_arr[i] = 0;
    }
}

template <typename T>
vector<T>::vector (const vector& a)
{
    m_size = a.m_size;
    m_cap = a.m_cap;
    m_arr = nullptr;
    m_arr = new T[m_cap];
    for (int i = 0; i < m_cap; ++i) {
        m_arr[i] = a.m_arr[i];
    }
}

template <typename T>
vector<T>& vector<T>::operator=(const vector& a)
{
    m_size = a.m_size;
    m_cap = a.m_cap;
    delete [] m_arr;
    m_arr = nullptr;
    m_arr = new T[m_cap];
    for (int i = 0; i < m_cap; ++i) {
        m_arr[i] = a.m_arr[i];
    }
    return *this;
}


template <typename T>
void vector<T>::push_back (T a)
{
    m_arr[m_size] = a;
    m_size ++;
}

template <typename T>
void vector<T>::print ()
{
    for (int i = 0; i < m_size; ++i) {
        std::cout << m_arr[i] << " " << std::flush;
    }
    std::cout << std::endl;
}

template <typename T>
vector<T>::~vector ()
{
    delete [] m_arr;
}
#endif
