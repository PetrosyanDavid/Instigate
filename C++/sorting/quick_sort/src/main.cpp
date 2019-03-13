#include "quick_sort.hpp"
#include "get_num.h"

int main()
{
    srand(time(NULL));
    int n = get_size();
    int* arr = create_array(n);
    print_array(arr, n);
    quick_sort(arr, 0, n-1);
    print_array(arr, n);
    destroy(arr);
}
