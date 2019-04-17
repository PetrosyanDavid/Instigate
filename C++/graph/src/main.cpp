#include <graph.hpp>

int main()
{
    graph<std::string> map;
    edge<std::string> a("Yerevan", "Armavir", 25.5);
    edge<std::string> b("Yerevan", "Abovyan", 16.2);
    edge<std::string> c("Yerevan", "Yeghegnadzor", 87);
    edge<std::string> d("Ararat", "Armavir", 12.8);
    edge<std::string> e("Kapan", "Meghri", 33.3);
    edge<std::string> f("Yeghegnadzor", "Kapan", 55);
    map.add_link(b);
    map.add_link(a);
    map.add_link(c);
    map.add_link(d);
    map.add_link(e);
    map.add_link(f);
    double dist = map.get_indirect_path ("Kapan", "Yerevan");
    std::cout << dist << std::endl;
    //std::cout << map.get_path ("Yerevan", "Kapan") << std::endl;
    //map.cities.erase("Yerevan");
    for (auto i : map.cities) {
        std::cout << i << " " << std::flush;
    }
    //std::copy(map.cities.begin(), map.cities.end(),
    //        std::ostream_iterator<const std::string>(std::cout, " "));
    std::cout << std::endl;
}
