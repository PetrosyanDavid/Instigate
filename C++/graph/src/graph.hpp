#ifndef GRAPH_HPP
#define GRAPH_HPP

#include <iostream>
#include <map>

template <class T>
struct edge
{
    public:
        T first_town;
        T second_town;
        double distance;
};

struct str_compare
{
    bool operator (const char* s1, const char* s2) const
    {
        return strcmp(s1,s2) < 0;
    }
};

template <class T>
class graph
{
    public:
        std::map <T, std::map <T, double, comp>, comp> connections;

        graph (std::vector<edge<T>>& edges)
        {
            int n = edges.size();
            for (auto &edge : edges) {
                T src = edge.first_town;
                T dest = edge.second_town;
                double distance = edge.distance;
            }
        }
};

#endif
