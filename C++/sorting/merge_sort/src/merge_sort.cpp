#include "merge_sort.hpp"

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


void merge (int* arr, int l, int m, int r)
{
    int my_array[r - l + 1];
    int start = m+1;
    int i = 0;
    int k = 0;
    int p = 0;
    while (p <= r-l) {
        if (arr[l+i] < arr[m+1+k] && l+i <= m) {
            my_array[p] = arr [l+i];
            p++;
            i++;
        } else if (arr[l + i] >= arr [m + k +1] && m + k < r){
            my_array [p] = arr [m+1+k];
            p++;
            k++;
        } else if (l + i > m && m + k < r) {
            my_array [p] = arr [m + k + 1];
            p++;
            k++;
        } else if (l + i <= m && m + k >= r) {
            my_array [p] = arr [l + i];
            p++;
            i++;
        }
    }
    for (int i = 0; i <= r - l; ++i) {
        arr[l + i] = my_array[i];
    }
}



void merge_sort (int* arr, int l, int r)
{
    int m = (r + l)/2;
    if (l != m) {
        merge_sort (arr, l, m);
    }
    if (m+1 != r) {
        merge_sort (arr, m+1, r);
    }
    merge (arr, l, m, r);

}

void print_array (int* arr, int n)
{
    for (int i = 0; i < n ; ++i) {
        std::cout << arr[i] << " " << std::flush;
    }
    std::cout << std::endl;
}


