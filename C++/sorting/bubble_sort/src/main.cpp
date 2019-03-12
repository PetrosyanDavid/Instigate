#include "bubble_sort.hpp"
#include "get_num.h"

int main()
{
    int n = get_size();
    srand(time(NULL));
    int* arr = create_array(n);
    print_array(arr, n);
    bubble_sort(arr, n);
    print_array(arr, n);
    destroy(arr);
}
