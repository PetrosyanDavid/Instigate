#include "select_sort.hpp"

int* generate_array (int n)
{
    int* arr = new int[n];
    for (int i = 0; i < n; ++i) {
        arr[i] = rand()%1000;
        std::cout << arr[i] << " " << std::flush;
    }
    std::cout << std::endl;
    return arr;
}

void destroy (int* arr)
{
    delete [] arr;
}

int find_min (int* arr, int n, int start)
{
    int num = start;
    int min = arr[start];
    for (int i = start; i < n; ++i) {
        if (arr[i] < min ) {
            min = arr[i];
            num = i;
        } else {
            continue;
        }
    }
    return num;
}


void select_sort (int* arr, int n)
{
    int tmp = 0;
    int tmp_index = 0;
    for (int i = 0; i < n; ++i){
        tmp = arr[i];
        tmp_index = find_min (arr, n, i);
        arr[i] = arr[tmp_index];
        arr[tmp_index] = tmp;
    }
}

void print_array (int* arr, int n)
{
    for (int i = 0; i < n ; ++i) {
        std::cout << arr[i] << " " << std::flush;
    }
    std::cout << std::endl;
}


