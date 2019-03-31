template <class T>
void graph<T>::add_link(edge<T> edge)
{
    m_links.push_back(edge);
}

template <class T>
double graph<T>::get_path (T start, T dest)
{
    for (auto it = m_links.begin(); it < m_links.end(); ++it) {
        if ((*it).first_town  == start && (*it).second_town == dest) {
            return (*it).distance;
        } else if ((*it).second_town  == start && (*it).first_town == dest) {
            return (*it).distance;
        }
    }
    std::cout << "No direct path exists" << std::endl;
    return -1;
}
