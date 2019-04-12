#include "thread.hpp"
#include <iostream>
#include <cassert>

////////////////////thread class////////////////////

threads::thread::thread() : m_thread()
{}

threads::thread::~thread()
{}

void threads::thread::create_thread()
{
    pthread_attr_t attr;
    int r = pthread_attr_init(&attr);
    r = pthread_attr_setdetachstate(&attr, PTHREAD_CREATE_DETACHED);
    assert(0 == r);
    r = pthread_create(&m_thread, &attr, entry_point, (void*)this);
    assert(0 == r);
    r = pthread_attr_destroy(&attr);
    assert(0 == r);
    (void)r;
}

void threads::thread::detach_thread()
{
    std::cout <<"\nstart detach thread\n";
    int r = pthread_detach(m_thread);
    assert(0 == r);
    (void)r;
    std::cout <<"\nend detach thread\n";
}


void threads::thread::join_thread()
{
    std::cout <<"\nstart join thread\n";
    int r = pthread_join(m_thread, 0);
    assert(0 == r);
    (void)r;
    std::cout <<"\nend join thread\n";
}

void* threads::thread::entry_point(void* p)
{
    assert(0 != p);
    threads::thread* t = reinterpret_cast<threads::thread*>(p);
    assert(0 != t);
    t->run();
    return 0;
}
