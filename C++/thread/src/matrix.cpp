#include "matrix.hpp"
#include <iostream>
#include <cassert>

extern int a[SIZE][SIZE];
extern int b[SIZE][SIZE];
extern int c[SIZE][SIZE];
////////////////////my_thread class////////////////////

my_thread::my_thread() : m_thread()
{}

my_thread::~my_thread()
{}

void my_thread::create_thread()
{
    pthread_attr_t attr;
    int r = pthread_attr_init(&attr);
    assert(0 == r);
    r = pthread_create(&m_thread, &attr, entry_point, (void*)this);
    assert(0 == r);
    r = pthread_attr_destroy(&attr);
    assert(0 == r);
    (void)r;
}

void my_thread::join_thread()
{
    int r = pthread_join(m_thread, 0);
    assert(0 == r);
    (void)r;
}

void* my_thread::entry_point(void* p)
{
    assert(0 != p);
    my_thread* t = reinterpret_cast<my_thread*>(p);
    assert(0 != t);
    t->run();
}

//////////////adder class////////////////

adder::adder(int i, int j)
    : m_i(i)
    , m_j(j)
{}

void adder::run()
{
    assert(m_i >= 0);
    assert(m_j >= 0);
    assert(m_i < SIZE);
    assert(m_j < SIZE);
    c[m_i][m_j] = a[m_i][m_j] + b[m_i][m_j];
//    while(1);
}


