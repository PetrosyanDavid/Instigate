#include "get_num.h"
#include <cstring>

int main()
{
    int n = 0;
    int m = 0;
    std::cout << "Input width" << std::endl;
    n = get_int();

    std::cout << "Input height" << std::endl;
    m = get_int();

    char top[n+1] = "";
    char side[n+1] = "";
    for (int i=0; i < n; i++) {
        top[i] = '*';
        side[i] = ' ';
    }
    side[0] = '*';
    side[n-1] = '*';

    std::cout << top << std::endl;
    for (int i = 0; i < m-2; i++) {
        std::cout << side << std::endl;
    }
    std::cout << top << std::endl;
    return 0;
}

