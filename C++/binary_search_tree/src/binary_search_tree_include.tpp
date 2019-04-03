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

template <class T>
T& node<T>::get_data ()
{
    return m_data;
}

template <class T>
node<T>*& node<T>::get_left ()
{
    return m_left;
}

template <class T>
node<T>*& node<T>::get_right ()
{
    return m_right;
}

///////////////////////////////////Tree Class///////////////////////////////////

template <class T>
tree<T>::tree ():
    m_root(nullptr)
{}

template <class T>
void tree<T>::insert (const T& data)
{
    if (m_root == nullptr) {
        m_root = new node<T>(data);
    } else {
        insert_helper(m_root, data);
    }
}

template <class T>
void tree<T>::insert_helper (node<T>* adress, const T& data)
{
    if (data < (*adress).get_data()) {
        if (nullptr == (*adress).get_left()) {
            (*adress).get_left() = new node<T>(data);
        } else {
            insert_helper((*adress).get_left(), data);
        }
    } else {
        if (nullptr == adress->m_right) {
            (*adress).get_right() = new node<T>(data);
        } else {
            insert_helper((*adress).get_right(), data);
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
        //if (NULL != adress->m_left) {
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
node<T>* tree<T>::find_adress_helper (node<T>* adress, const T& val)
{
    assert (val != adress->m_data);
    if (val < adress->m_data) {
        if (adress->m_left != nullptr) {
            if(adress->m_left->m_data == val) {
                return adress;
            } else {
                return find_adress_helper(adress->m_left, val);
            }
        } else {
            return nullptr;
        }
    } else {
        if (adress->m_right != nullptr) {
            if (adress->m_right->m_data == val) {
                return adress;
            } else {
                return find_adress_helper(adress->m_right, val);
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
    node<T>* current = nullptr;
    assert (adress->m_data != val);
    rem_ptr = find_adress_helper(adress, val);
    if  (rem_ptr == nullptr) {
        return;
    }
    if (rem_ptr->m_right != nullptr && val == rem_ptr->m_right->m_data) {
        current = rem_ptr->m_right;
    } else if (rem_ptr->m_left != nullptr && val == rem_ptr->m_left->m_data) {
        current = rem_ptr->m_left;
    }
    if (current->m_left == nullptr && current->m_right == nullptr) {
        remove_zero(rem_ptr, current);
    } else if (current->m_left == nullptr || current->m_right == nullptr) {
        remove_one (rem_ptr, current);
    } else {
        remove_two(current);
    }
}

template <class T>
void tree<T>::remove_zero(node<T>* parent, node<T>* current) {
    if (current == parent->m_right){
        parent->m_right = nullptr;
    } else if (current == parent->m_left) {
        parent->m_left = nullptr;
    }
    delete current;
    current = nullptr;
}

template <class T>
void tree<T>::remove_one (node<T>* parent, node<T>* current)
{
    if (current->m_left == nullptr) {
        if (current == parent->m_right){
            parent->m_right = current->m_right;
        } else if (current == parent->m_left) {
            parent->m_left = current->m_right;
        }
        delete current;
        current = nullptr;
    } else if (current->m_right == nullptr) {
        if (current == parent->m_right){
            parent->m_right = current->m_left;
        } else if (current == parent->m_left) {
            parent->m_left = current->m_left;
        }
        delete current;
        current = nullptr;
    }
}

template <class T>
void tree<T>::remove_two (node<T>* current)
{
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

template <class T>
int tree<T>::get_height ()
{
    int height = 0;
    return get_height_helper (m_root, height);
}

template <class T>
int tree<T>::get_height_helper (node<T>* adress, int height)
{
    if (adress == nullptr) {
        return height;
    } else {
        height = std::max (get_height_helper (adress->m_left, height + 1),
                get_height_helper(adress->m_right, height + 1));
        return height;
    }
}

template <class T>
void tree<T>::print_traverse ()
{
    if (m_root == nullptr) {
        return;
    }
    queue<node<T>*> q;
    node<T> * current = nullptr;
    q.queue_in (m_root);
    do {
        current = q.queue_out();
        std::cout << current->m_data << " " << std::flush;
        if (current->m_left != nullptr) {
            q.queue_in(current->m_left);
        }
        if (current->m_right != nullptr) {
            q.queue_in(current->m_right);
        }
    } while (!q.is_empty());
    std::cout << std::endl;
}
