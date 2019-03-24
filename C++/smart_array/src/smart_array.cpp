#include "smart_array.hpp"

smart_array::smart_array ()
{
    m_arr = NULL;
    m_size = 0;
    m_def = 0;
}

smart_array::smart_array (int size, int def)
{
    m_arr = NULL;
    m_size = size;
    m_def = def;
    m_arr = new int[m_size];
    for (int i = 0; i < m_size; ++i) {
        m_arr[i] = m_def;
    }
}

smart_array::smart_array (const smart_array& a)
{
    m_arr = NULL;
    m_size = a.m_size;
    m_def = a.m_def;
    m_arr = new int[m_size];
    for (int i = 0; i < m_size; ++i) {
        m_arr[i] = *(a.m_arr + i);
    }
}

smart_array& smart_array::operator= (const smart_array& a)
{
    delete [] m_arr;
    m_arr = NULL;
    m_size = a.m_size;
    m_def = a.m_def;
    m_arr = new int[m_size];
    for (int i = 0; i < m_size; ++i) {
        m_arr[i] = *(a.m_arr + i);
    }
    return *this;
}

int& smart_array::operator[](int index)
{
    return *(m_arr + index);
}

void smart_array::resize (int size,const int& def)
{
    int* tmp_ptr = NULL;
    tmp_ptr = new int[size];
    if (m_size > size) {
        for (int i = 0; i < size; ++i) {
            tmp_ptr[i] = m_arr[i];
        }
        delete [] m_arr;
        m_arr = NULL;
        m_arr = new int[size];
        for (int i = 0; i < size; ++i) {
            m_arr[i] = tmp_ptr[i];
        }
        delete [] tmp_ptr;
        tmp_ptr = NULL;
    } else {
        for (int i = 0; i < m_size; ++i) {
            tmp_ptr[i] = m_arr[i];
        }
        for (int i = m_size; i < size; ++i) {
            tmp_ptr[i] = def;
        }
        delete [] m_arr;
        m_arr = NULL;
        m_arr = new int[size];
        for (int i = 0; i < size; ++i) {
            m_arr[i] = tmp_ptr[i];
        }
        delete [] tmp_ptr;
        tmp_ptr = NULL;
    }
    m_size = size;
}

smart_array::~smart_array ()
{
    delete [] m_arr;
}

void smart_array::pop ()
{
    resize(--m_size,0);
}

void smart_array::psh_back (int val)
{
    resize(m_size + 1, val);
}

void smart_array::insert (int pos, int val)
{
    resize(++m_size,0);
    for (int i = m_size-1; i > pos; --i) {
        m_arr[i] = m_arr[i -  1];
    }
    m_arr [pos] = val;
}

void smart_array::erase (int pos)
{
    for (int i = pos; i < m_size; ++i) {
        m_arr[i] = m_arr[i + 1];
    }
    resize(--m_size,0);
}

void smart_array::print ()
{
    for (int i = 0; i < m_size; ++i) {
        std::cout << m_arr[i] << " " << std::flush;
    }
    std::cout << std::endl;
}
