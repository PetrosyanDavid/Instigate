#ifndef THREADS_THREAD_HPP
#define THREADS_THREAD_HPP

#include <pthread.h>

/**
 * @file thread.hpp
 * @brief Contains threads::thread class declaration
 */

/// TODO
namespace threads
{
        /**
          @class thread
          @brief abstract class incapsulating POSIX thread functionality
          */
        class thread;
}

class threads::thread
{
public:
        /**
         * @fn thread
         * @brief Constructor
         */
        thread();
        /**
         * @fn ~thread
         * @brief Destructor
         */
        virtual ~thread();
        /**
         * @fn run
         * @brief 
         */
        virtual void run() = 0;
        /**
         * @fn create_thread
         * @brief creating thread
         */
        void create_thread();
        /** 
         * @fn join_thread
         * @brief joining thread
         */
        void join_thread();
private:
        static void* entry_point(void* obj);
        pthread_t m_thread;
};

#endif // THREADS_THREAD_HPP
