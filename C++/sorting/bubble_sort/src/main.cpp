#include "bubble_sort.hpp"
#include "get_num.h"

int main()
{
    srand(time(NULL));
    int n = get_size();
    int* arr = create_array(n);
    print_array(arr, n);
    bubble_sort(arr, n);
    print_array(arr, n);
    destroy(arr);
}
