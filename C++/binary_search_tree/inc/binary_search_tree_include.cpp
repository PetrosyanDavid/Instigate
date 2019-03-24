/////////////////////////////Node Class ///////////////////////////////////////
template <class T>
node<T>::node ():
    m_left(nullptr),
    m_right(nullptr)
{}

template <class T>
node<T>:: node (T data):
    m_data(data),
    m_left(nullptr),
    m_right(nullptr)
{}

template <class T>
node<T>:: node (T data, node<T>* left, node<T>* right):
    m_data(data),
    m_left(left),
    m_right(right)
{}

///////////////////////////////////Tree Class///////////////////////////////////

template <class T>
tree<T>::tree ():
    m_root(nullptr)
{}

template <class T>
void tree<T>::insert (const T& data)
{
    //node<T> * tmp_ptr = m_root;
    if (m_root == nullptr) {
        m_root = new node<T>(data);
    } else {
        insert_helper(m_root, data);
    }
}

template <class T>
void tree<T>::insert_helper (node<T>* adress, const T& data)
{
    if (data < adress->m_data) {
        if (adress->m_left == nullptr) {
            adress->m_left = new node<T>(data);
        } else {
            insert_helper(adress->m_left, data);
        }
    } else {
        if (adress->m_right == nullptr) {
            adress->m_right = new node<T>(data);
        } else {
            insert_helper(adress->m_right, data);
        }
    }
}

template <class T>
void tree<T>::print ()
{
    if (m_root == nullptr) {
        std::cout << "Nothing to print" << std::endl;
        return;
    }
    print_helper(m_root);
    std::cout << std::endl;
}

template <class T>
void tree<T>::print_helper (node<T>* adress)
{
    if (adress->m_left != nullptr) {
        print_helper(adress->m_left);
    }
    std::cout << adress->m_data << " " << std::flush;
    if (adress->m_right != nullptr) {
        print_helper(adress->m_right);
    }
}

template <class T>
tree<T>::~tree ()
{
    if (m_root == nullptr) {
        return;
    } else {
        destroy (m_root);
    }
}

template <class T>
void tree<T>::destroy (node<T>* adress)
{
    if (adress->m_left) {
        destroy(adress->m_left);
    }
    if (adress->m_right) {
        destroy(adress->m_right);
    }
    delete adress;
}

template <class T>
bool tree<T>::find (const T& val)
{
    if (m_root == nullptr) {
        return false;
    } else {
        return find_helper (m_root, val);
    }
}

template <class T>
bool tree<T>::find_helper (node<T>* adress,const T& val)
{
    if (val == adress->m_data) {
        return true;
    } else if (val < adress->m_data) {
        if (adress->m_left) {
            return find_helper(adress->m_left, val);
        } else {
            return false;
        }
    } else {
        if (adress->m_right) {
            return find_helper(adress->m_right, val);
        } else {
            return false;
        }
    }
}

template <class T>
node<T>* tree<T>::find_adress_helper (node<T>* adress, const T& val, char& side)
{
    assert (val != adress->m_data);
    if (val < adress->m_data) {
        if (adress->m_left != nullptr) {
            if(adress->m_left->m_data == val) {
                side = 'l';
                return adress;
            } else {
                return find_adress_helper(adress->m_left, val, side);
            }
        } else {
            return nullptr;
        }
    } else {
        if (adress->m_right != nullptr) {
            if (adress->m_right->m_data == val) {
                side = 'r';
                return adress;
            } else {
                return find_adress_helper(adress->m_right, val, side);
            }
        } else {
            return nullptr;
        }
    }
}

template <class T>
void tree<T>::remove(const T& val)
{
    if (m_root == nullptr) {
        std::cout << "Nothing in tree" << std::endl;
    } else if (val == m_root->m_data){
        node<T>* tmp_ptr = new node<T>(val + 1, m_root, nullptr);
        remove_adress (tmp_ptr, val);
        m_root = tmp_ptr->m_left;
        delete tmp_ptr;
    } else {
        remove_adress (m_root, val);
    }
}

template <class T>
void tree<T>::remove_adress(node<T>* adress, const T& val)
{
    node<T>* rem_ptr = nullptr;
    char side = ' ';
    node<T>* current = nullptr;
    assert (adress->m_data != val);
    rem_ptr = find_adress_helper(adress, val, side);
    if  (rem_ptr == nullptr) {
        return;
    }
    if ('r' == side) {
        current = rem_ptr->m_right;
    } else if ('l' == side) {
        current = rem_ptr->m_left;
    }
    if (current->m_left == nullptr && current->m_right == nullptr) {
        delete current;
        current = nullptr;
        if ('r' == side){
            rem_ptr->m_right = nullptr;
        } else if ('l' == side) {
            rem_ptr->m_left = nullptr;
        }
    } else if (current->m_left == nullptr) {
        node<T>* tmp_r = current->m_right;
        current->m_data = tmp_r->m_data;
        current->m_right = tmp_r->m_right;
        current->m_left = tmp_r->m_left;
        delete tmp_r;
    } else if (current->m_right == nullptr) {
        node<T>* tmp_l = current->m_left;
        current->m_data = tmp_l->m_data;
        current->m_right = tmp_l->m_right;
        current->m_left = tmp_l->m_left;
        delete tmp_l;
    } else {
        node<T>* next = current->m_left;
        if (next->m_right == nullptr) {
            T tmp_val = next->m_data;
            remove_adress(current, next->m_data);
            current->m_data = tmp_val;
        } else {
            while (next->m_right->m_right != nullptr) {
                next = next->m_right;
            }
            T tmp_val = next->m_right->m_data;
            remove_adress(next, next->m_right->m_data);
            current->m_data = tmp_val;
        }
    }
}
