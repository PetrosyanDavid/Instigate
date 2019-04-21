#ifndef DATA_H
#define DATA_H

#define SIZE 5

/**
 * @file matrix.hpp
 * @brief Contains prototype for data, multiplier and adder class
 */

#include "thread.hpp"
#include "mutex.hpp"

#include <cassert>
#include <iostream>

///////////// Data //////////////
class data
{
public:
        data();
        ~data();
        void print(const char* name) const;
        void init_identity();
        void set_ready(bool r);
        bool is_ready() const;
        void wait();
        void lock();
        void unlock();
        // TODO
        int m_matrix[SIZE][SIZE];

private:
        threads::mutex m_mutex;
        bool m_ready;
};

////////////// Adder //////////////

/**
 * @class adder
 * @brief is inharitanced thread class and added two matrixs.
 * */
class adder : public threads::thread
{
private:
	data* in1;
	data* in2;
	data* out;
public:

	/**
	*@fn adder       
	*@brief  two matrics addition.
	@param i 
	@brief first index
	@param j 
	@brief second index
	*/
	adder(data*, data*, data*);

	/**
	* @fn run
	* @brief virtual function's overloading.
	* */
        virtual void run()
	{
                std::cout << "adder starts" << std::endl;
                assert(0 != in1);
                assert(0 != in2);
                assert(0 != out);
		if (! in1->is_ready()) {
                        std::cout << "adder is waiting in1" << std::endl;
			in1->wait();
		}
		if (! in2->is_ready()) {
                        std::cout << "adder is waiting in2" << std::endl;
			in2->wait();
		}
                assert(in1->is_ready());
                assert(in2->is_ready());
                std::cout << "adder starts calc" << std::endl;
                in1->lock();
                in2->lock();
                out->lock();
                for (int i = 0; i < SIZE; ++i) {
                    for (int j = 0; j < SIZE; ++j) {
                        out->m_matrix[i][j] = in1->m_matrix[i][j] +
                                in2->m_matrix[i][j];
                        }
                }
                in1->unlock();
                in2->unlock();
                std::cout << "adder set ready" << std::endl;
		out->set_ready(true);
                out->unlock();
	}
};


////////////// Multiplay ///////////////

class multiplier : public threads::thread
{
private:
	data* in1;
	data* in2;
	data* out;
public:
	/**
	* @fn multiplier
	* @brief consturcot
	**/
        multiplier(data*, data*, data*);
	/**
	* @fn run
	* @brief virtual function's overloading.
	* */
        void run();
};

#endif
