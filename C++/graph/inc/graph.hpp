#ifndef GRAPH_HPP
#define GRAPH_HPP

#include <iostream>
#include <vector>
#include <set>
#include <iterator>
#include <cstring>


template <class T>
struct edge
{
    public:
        T first_town;
        T second_town;
        double distance;
        edge () :
            first_town(" "),
            second_town(""),
            distance (0) {};
        edge (T first_town, T second_town, double distance) :
            first_town(first_town),
            second_town(second_town),
            distance(distance) {};
};


template <class T>
class graph
{
    public:
        std::set<std::string> cities;
        std::vector<edge<T>> m_links;
        void add_link (edge<T> );
        double get_path (T start, T dest);
        double get_indirect_path (T start, T dest);
};



#include "graph.tpp"
#endif
