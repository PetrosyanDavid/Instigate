#include "mutex.hpp"

#include <cassert>

void threads::mutex::wait()
{
        int r = pthread_cond_wait(&m_cond, &m_mutex);
        assert(0 == r);
        (void)r;
}

void threads::mutex::signal()
{
        int r = pthread_cond_signal(&m_cond);
        assert(0 == r);
        (void)r;
}

void threads::mutex::lock()
{
        int r = pthread_mutex_lock(&m_mutex);
        assert(0 == r);
        (void)r;
}

void threads::mutex::unlock()
{
        int r = pthread_mutex_unlock(&m_mutex);
        assert(0 == r);
        (void)r;
}

threads::mutex::mutex()
        : m_mutex(PTHREAD_MUTEX_INITIALIZER)
        , m_cond(PTHREAD_COND_INITIALIZER)
{
         int r = pthread_mutex_init(&m_mutex, 0);
         assert(0 == r);
         r = pthread_cond_init(&m_cond, 0);
         assert(0 == r);
         (void)r;
}

threads::mutex::~mutex()
{
        int r = pthread_mutex_destroy(&m_mutex);
        assert(0 == r);
        r = pthread_cond_destroy(&m_cond);
        assert(0 == r);
        (void)r;
}

