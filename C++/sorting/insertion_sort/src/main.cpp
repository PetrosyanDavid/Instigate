#include "insertion_sort.hpp"

int main()
{
    srand(time(NULL));
    int n = get_size();
    int* arr = create_array(n);
    print_array(arr, n);
    insertion_sort(arr, n);
    print_array(arr, n);
    destroy(arr);
}
