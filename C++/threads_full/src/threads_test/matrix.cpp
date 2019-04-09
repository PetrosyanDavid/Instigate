#include "matrix.hpp"
#include <iostream>
#include <cassert>

data::data()
        : m_ready(false)
{
        for (int i = 0; i < SIZE; ++i) {
            for (int j = 0; j < SIZE; ++j) {
                m_matrix[i][j] = 0;
            }
        }
        m_ready = false;
}

data::~data()
{
}

void data::set_ready(bool b)
{
	m_ready = b;
        m_mutex.signal();
}

bool data::is_ready() const
{
	return m_ready;
}

void data::wait()
{
        if (m_ready) {
                return;
        }
        m_mutex.wait();
}

void data::lock()
{
        m_mutex.lock();
}

void data::unlock()
{
        m_mutex.unlock();
}

void data::init_identity()
{
        for (int i = 0; i < SIZE; ++i) {
            for (int j = 0; j < SIZE; ++j) {
                if (j == i) {
		    m_matrix[i][j] = 1;
		}
            }
        }
       set_ready(true);
}

void data::print(const char* name) const
{
        assert(0 != name);
        std::cout << name << " = " << std::endl;
        for (int i = 0; i < SIZE; ++i) {
                for (int j = 0; j < SIZE; ++j) {
                        std::cout << m_matrix[i][j] << " ";
                }
                std::cout << std::endl;
        }
}

////////////// adder ////////////////

adder::adder(data* a, data* b, data* c)
	: in1(a)
	, in2(b)
	, out(c)
{}


////////////// multiplier ///////////////
void multiplier::run()
{
        std::cout << "start mult" << std::endl;
        assert(0 != in1);
        assert(0 != in2);
        assert(0 != out);
        if (! in1->is_ready()) {
                std::cout << "mult is waiting in1" << std::endl;
                in1->wait();
        }
        if (! in2->is_ready()) {
                std::cout << "mult is waiting in2" << std::endl;
                in2->wait();
        }
        assert(in1->is_ready());
        assert(in2->is_ready());
        std::cout << "mult inputs are ready" << std::endl;
        in1->lock();
        in2->lock();
        out->lock();
        for (int i = 0; i < SIZE; ++i) {
                for (int j = 0; j < SIZE; ++j) {
                        for (int k = 0; k < SIZE; ++k) {
                                out->m_matrix[i][j] += in1->m_matrix[i][k] *
                                        in2->m_matrix[k][j];
                        }
                }
        }
        in1->unlock();
        in2->unlock();
        std::cout << "mult output is ready" << std::endl;
        out->set_ready(true);
        out->unlock();
}

multiplier::multiplier(data* a, data* b, data* c)
	: in1(a)
	, in2(b)
	, out(c)
{}

