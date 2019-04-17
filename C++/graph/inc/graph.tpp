template <class T>
void graph<T>::add_link(edge<T> edge)
{
    m_links.push_back(edge);
    cities.insert(edge.first_town);
    cities.insert(edge.second_town);
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

template <class T>
double graph<T>::get_indirect_path (T start, T dest)
{
    double min_dist = 200000;
    double direct = get_path(start, dest);
    if (-1 != direct) {
        return direct;
    }
    cities.erase(start);
    cities.erase(dest);
    if (!cities.empty()) {
        for (auto i : cities) {
            if(get_indirect_path(start, i) != -1 && get_indirect_path (i, dest) != -1){
                double indirect = get_indirect_path(start,i) + get_indirect_path(i,dest);
                min_dist = std::min(min_dist, indirect);
            }
        }
        if (min_dist < 200000) {
            cities.insert(start);
            cities.insert(dest);
            return min_dist;
        } else {
            cities.insert(start);
            cities.insert(dest);
            return -1;
        }
    } else {
        cities.insert(start);
        cities.insert(dest);
        return -1;
    }
}
