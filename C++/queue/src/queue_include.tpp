template <class T>
node<T>::node ():
    m_node(nullptr)
{}

template <class T>
node<T>::node (T data):
    m_data(data),
    m_node(nullptr)
{}

template <class T>
node<T>::node (T data, node* adress):
    m_data(data),
    m_node(adress)
{}


template <class T>
list<T>::list() :
    first (nullptr),
    len(0)
{}

template <class T>
void list<T>::destroy (list<T>& a)
{
    node<T>* tmp_ptr1 = a.first;
    if (a.first != nullptr) {
        node<T>* tmp_ptr2 = a.first->m_node;
        while (tmp_ptr2 != nullptr) {
            delete tmp_ptr1;
            tmp_ptr1 = tmp_ptr2;
            tmp_ptr2 = tmp_ptr1->m_node;
        }
        delete tmp_ptr1;
    }
}

template <class T>
list<T>::~list ()
{
    destroy (*this);
}


template <class T>
void list<T>::push_back (const T& data)
{
    if (first == nullptr) {
        first = new node<T>(data);
        ++len;
    } else {
        node<T>* tmp_ptr = nullptr;
        tmp_ptr = first;
        while (tmp_ptr->m_node != nullptr) {
            tmp_ptr = tmp_ptr->m_node;
        }
        tmp_ptr->m_node = new node<T>(data);
        len ++;
    }
}

template <class T>
void list<T>::print ()
{
    if (first == nullptr) {
        std::cout << "List is empty" << std::endl;
    } else {
        node<T>* tmp_ptr = first;
        while (tmp_ptr != nullptr) {
            std::cout << tmp_ptr->m_data << " " << std::flush;
            tmp_ptr = tmp_ptr->m_node;
        }
        std::cout << std::endl;
    }
}

template <class T>
T list<T>::pop ()
{
    assert(first);
    node<T>* tmp_ptr = first;
    node<T>* tmp_ptr_2 = tmp_ptr;
    while (tmp_ptr->m_node != nullptr) {
        tmp_ptr_2 =tmp_ptr;
        tmp_ptr = tmp_ptr->m_node;
    }
    T a = tmp_ptr->m_data;
    delete tmp_ptr;
    tmp_ptr_2->m_node = nullptr;
    --len;
    return a;
}

template <class T>
T list<T>::pop_front ()
{
    assert(first);
    node<T>* tmp_ptr = first;
    T a = tmp_ptr->m_data;
    first = first->m_node;
    delete tmp_ptr;
    tmp_ptr = nullptr;
    --len;
    return a;
}

template <class T>
void list<T>::insert (const int& pos, const T& data)
{
    if (len - 1 < pos) {
        std::cout << "Out of range, for insert" << std::endl;
    } else if (0 == pos) {
        node<T>* tmp_ptr = new node<T>(data,first);
        first = tmp_ptr;
    } else {
        node<T>* tmp_ptr_1 = first;
        for (int i = 0; i < pos-1; ++i) {
            tmp_ptr_1 = tmp_ptr_1->m_node;
        }
        node<T>* tmp_ptr_2 = tmp_ptr_1->m_node;
        tmp_ptr_1->m_node = new node<T>(data,tmp_ptr_2);
    }
    ++ len;
}

template <class T>
void list<T>::remove (const int& pos)
{
    if (len - 1 < pos) {
        std::cout << "Out of range for remove" << std::endl;
    } else {
        node<T>* tmp_ptr = first;
        for (int i = 0; i < pos-1; ++i) {
            tmp_ptr = tmp_ptr->m_node;
        }
        node<T>* pos_ptr = tmp_ptr->m_node;
        tmp_ptr->m_node = pos_ptr->m_node;
        delete pos_ptr;
    }
    --len;
}

template <class T>
list<T>::list(const list& a)
{
    len = a.len;
    first = nullptr;
    if (a.first != nullptr) {
        first  = new node<T>(a.first->m_data);
        node<T>* tmp_ptr_1 = first;
        node<T>* tmp_ptr_2 = a.first;
        while (tmp_ptr_2->m_node != nullptr) {
            tmp_ptr_2 = tmp_ptr_2->m_node;
            tmp_ptr_1->m_node = new node<T>(tmp_ptr_2->m_data);
            tmp_ptr_1 = tmp_ptr_1->m_node;
        }
    }
}

template <class T>
list<T>& list<T>::operator=(const list& a)
{
    destroy (*this);
    len = a.len;
    if (a.first != nullptr) {
        first  = new node<T>(a.first->m_data);
        node<T>* tmp_ptr_1 = first;
        node<T>* tmp_ptr_2 = a.first;
        while (tmp_ptr_2->m_node != nullptr) {
            tmp_ptr_2 = tmp_ptr_2->m_node;
            tmp_ptr_1->m_node = new node<T>(tmp_ptr_2->m_data);
            tmp_ptr_1 = tmp_ptr_1->m_node;
        }
    } else {
        first = nullptr;
    }
    return *this;
}

template <class T>
bool list<T>::is_empty()
{
    if (first == nullptr) {
        return true;
    } else {
        return false;
    }
}

template <class T>
T& list<T>::operator[](const int& pos)
{
    assert(pos < len);
    node<T>* tmp_ptr = first;
    for (int i = 0; i < pos; ++i) {
        tmp_ptr = tmp_ptr->m_node;
    }
    return tmp_ptr->m_data;
}

template <class T>
void list<T>::reverse()
{
    if (0 == len || 1 == len) {
        return;
    }
    node<T>* tmp_ptr_1 = first;
    node<T>* tmp_ptr_2 = first->m_node;
    node<T>* tmp_ptr_3 = tmp_ptr_2->m_node;
    first->m_node = nullptr;
    while (tmp_ptr_3 != nullptr) {
        tmp_ptr_2->m_node = tmp_ptr_1;
        tmp_ptr_1 = tmp_ptr_2;
        tmp_ptr_2 = tmp_ptr_3;
        tmp_ptr_3 = tmp_ptr_2->m_node;
    }
    tmp_ptr_2->m_node = tmp_ptr_1;
    first = tmp_ptr_2;
}

template <class T>
void queue<T>::queue_in (const T& val)
{
    this->push_back (val);
}

template <class T>
T queue<T>::queue_out ()
{
    return this->pop_front();
}
