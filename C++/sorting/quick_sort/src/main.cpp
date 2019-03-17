#include "quick_sort.hpp"
#include "get_num.h"

int main()
{
    srand(time(NULL));
    int n = get_size();
    std::string type = " ";
    int* arr = create_array(n);
    print_array(arr, n);
    type = get_type();
    quick_sort(arr, 0, n-1, type);
    print_array(arr, n);
    destroy(arr);
}
