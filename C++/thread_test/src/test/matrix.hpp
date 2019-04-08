/**
 * @file matrix.hpp
 * @brief Contains prototype for my_thread class and adder class
 */
#ifndef MATRIX_H
#define MATRIX_H
#include <thread>
#define SIZE 4

extern int a[SIZE][SIZE];
extern int b[SIZE][SIZE];
extern int c[SIZE][SIZE];

/**
  @class my_thread
  @brief abstract class
 */
class my_thread
{
// maybe protected?
    public:
     /**
       * @fn my_thread
       * @brief Constructor
       */
      my_thread();
      /**
       * @fn ~my_thread
       * @brief Destructor
       */
      virtual ~my_thread();
      /**
       * @fn run
       *@brief pure virtual function
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
      /**
       * @fn entry_point
       * @brief for thread
       * @param obj
       * @brief connecting function to thread
       * */
      static void* entry_point(void* obj);
      pthread_t m_thread;
};

// custom program

/**
 * @class adder
 * @brief is inharitanced my_thread class and added two matrixs.
 * */
class adder : public my_thread
{
    public:
      /**
       * @fn run
       * @brief virtual function's overloading.
       * */
      virtual void run();
      /**
       *@fn adder       
       *@brief  two matrics addition.
       @param i
       @brief first index
       @param j
       @brief second index
       */
      adder(int i, int j);
    private:
      /**
       * @param m_i
       * @brief for matrix first index
       * */
      int m_i;
      /**
       * @param m_j;
       * @brief for matric second index
       * */
      int m_j;
};

#endif

