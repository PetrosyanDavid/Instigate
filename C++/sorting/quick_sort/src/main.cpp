#include "quick_sort.hpp"

int main()
{
    srand(time(NULL));
    int n = 10;
    int* arr = generate_array (n);
    print_array (arr, n);
    quick_sort (arr, 0, n-1);
    print_array (arr, n);
    destroy (arr);
}