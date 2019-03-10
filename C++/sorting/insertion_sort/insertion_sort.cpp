#include "insertion_sort.hpp"

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


void insertion_sort (int* arr, int n)
{
    int tmp = 0;
    for (int i = 1; i < n; ++i) {
        tmp = arr[i];
        for (int k = i-1; k >= 0; --k) {
            if (tmp < arr[k]){
                arr[k+1] = arr[k];
                if (0 == k) {
                    arr[k] = tmp;
                }
            } else {
                arr[k+1] = tmp;
                break;
            }
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


