#include "quick_sort.hpp"

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


int split (int* arr, int l, int r)
{
    int m = l;
    for (int i = l; i <= r - 1; ++i){
        if (arr[i] < arr[r]) {
            std::swap(arr[m], arr[i]);
            m++;
        }
    }
    std::swap(arr[m],arr[r]);
    return m;
}



void quick_sort (int* arr, int l, int r)
{
    if (r > l){
        int mid = split (arr, l, r);
        quick_sort (arr, l, mid-1);
        quick_sort (arr, mid + 1, r);
    }
}

void print_array (int* arr, int n)
{
    for (int i = 0; i < n ; ++i) {
        std::cout << arr[i] << " " << std::flush;
    }
    std::cout << std::endl;
}


