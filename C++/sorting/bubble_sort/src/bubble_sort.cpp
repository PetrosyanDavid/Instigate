#include "bubble_sort.hpp"

int* generate_array (int n)
{
    int* arr = new int[n];
    for (int i = 0; i < n; ++i) {
        arr[i] = rand()%1000;
    }
    return arr;
}

void destroy (int* arr)
{
    delete [] arr;
}

void bubble_sort (int* arr, int n)
{
    for (int i = 0; i < n; ++i) {
        bool check = true;
        for (int j = 0; j < n-1; ++j) {
            if (arr[j] > arr [j+1]) {
                std::swap(arr[j],arr[j+1]);
                check = false;
            }
        }
        if (check) {
            break;
        }
    }
}

void print_array (int* arr, int n)
{
    for (int i = 0; i < n ; ++i) {
        std::cout << arr[i] << " " << std::flush;
    }
    std::cout << std::endl;
}


