

template <typename T>
std::ostream& operator<< (std::ostream& stream, const vector<T>& v)
{
    for (int i = 0; i < v.m_size; ++i) {
        stream << v.m_arr[i] << " " << std::flush;
    }
    std::cout << std::endl;
    return stream;
}

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
void vector<T>::push_back (const T& a)
{
    if (m_size == m_cap) {
        resize();
    }
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
    m_arr = nullptr;
}

template <typename T>
T vector<T>::pop ()
{
    T val = m_arr[m_size -1];
    --m_size;
    return val;
}

template <typename T>
T& vector<T>::operator[] (const int& pos)
{
    assert(pos < m_size);
    return m_arr[pos];
}

template <typename T>
void vector<T>::insert (const int& pos, const  T& val)
{
    if (pos > m_size -1) {
        std::cout << "Position is off limits" << std::endl;
    } else {
        if (m_size == m_cap) {
            resize();
        }
        for (int i = m_size; i > pos; -- i) {
            m_arr[i] = m_arr[i - 1];
        }
        m_arr[pos] = val;
        ++m_size;
    }
}

template <typename T>
void vector<T>::erase (int pos)
{
    if (pos > m_size - 1) {
        std::cout << "No element exists at position " << pos << std::endl;
    } else {
        for (int i = pos; i < m_size; ++i) {
            m_arr[i] = m_arr[i + 1];
        }
        --m_size;
    }
}

template <typename T>
bool vector<T>::operator== (const vector& a)
{
    if (m_size != a.m_size) {
        return false;
    } else {
        for (int i = 0; i < m_size; ++i) {
            if (m_arr[i] != a.m_arr[i]) {
                return false;
            } else {
                continue;
            }
        }
    }
    return true;
}

template <typename T>
void vector<T>::swap (int i, int j)
{
    if (i > m_size - 1 || j > m_size - 1) {
        std::cout << "No element exists at one ov positions" << std::endl;
    } else {
        std::swap(m_arr[i], m_arr[j]);
    }
}

template <typename T>
void vector<T>::resize ()
{
    m_cap *=2;
    T* tmp_ptr = nullptr;
    tmp_ptr = new T[m_cap];
    assert(tmp_ptr);
    for (int i = 0; i < m_cap/2; ++i) {
        tmp_ptr[i] = m_arr[i];
    }
    for (int i = m_cap/2; i < m_cap; ++i) {
        tmp_ptr[i] = 0;
    }
    delete [] m_arr;
    m_arr = nullptr;
    m_arr = tmp_ptr;
    std::cout << "resize called" << std::endl;
}


template <class T>
void stack<T>::stack_push (const T& val)
{
   this->push_back(val);
}

template <class T>
T stack<T>::stack_pop ()
{
    return this->pop();
}
