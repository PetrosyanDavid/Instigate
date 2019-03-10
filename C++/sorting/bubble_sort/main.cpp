#include "bubble_sort.hpp"

int main()
{
    srand(time(NULL));
    int n = 10;
    int* arr = generate_array (n);
    print_array (arr, n);
    bubble_sort (arr, n);
    print_array (arr, n);
    destroy (arr);
}
