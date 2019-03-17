#include "insertion_sort.hpp"

int main()
{
    srand(time(NULL));
    int n = get_size();
    std::string type = " ";
    int* arr = create_array(n);
    print_array(arr, n);
    type = get_type();
    insertion_sort(arr, n, type);
    print_array(arr, n);
    destroy(arr);
}
