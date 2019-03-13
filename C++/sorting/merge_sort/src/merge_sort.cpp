#include "merge_sort.hpp"
#include "get_num.h"
#include <cassert>

int get_size()
{
    int n = 0;
    std::cout << "Please input the size of array" << std::endl;
    while (true) {
        n = get_int();
        if (n > 0) {
            break;
        } else {
            std::cout << "Invalid array size, try again" << std::endl;
        }
    }
    return n;
}

int* create_array (const int& n)
{
    int* arr = NULL;
    std::string gen("");
    arr = new int[n];
    assert (arr);
    std::cout << "Please input 'm' if you want to generate array manually," <<
        "\nor 'a' if you want it to be randomly generated" << std::endl;
    while (true) {
        getline(std::cin, gen);
        if (gen == "a" || gen == "m") {
            fill_array(arr, n, gen);
            break;
        } else {
            std::cout << "Wrong input, try again" << std::endl;
        }
    }
    return arr;
}

void fill_array (int* arr, const int& n,const std::string& gen)
{
    if (gen == "a") {
        for (int i = 0; i < n; ++i) {
            arr[i] = rand()%1000;
        }
    } else {
        std::cout << "Please input array elements" << std::endl;
        for (int i = 0; i < n; ++i) {
            arr[i] = get_int();
        }
    }
}

void destroy (int* arr)
{
    delete [] arr;
}

void merge (int* arr, const int& l, const int& m, const int& r)
{
    int* my_array = new int[r - l + 1];
    int i = 0;
    int k = 0;
    int p = 0;
    while (p <= r-l) {
        if (arr[l+i] < arr[m+1+k] && l+i <= m) {
            my_array[p] = arr [l+i];
            p++;
            i++;
        } else if (m + k < r){
            my_array [p] = arr [m+1+k];
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
    delete [] my_array;
}

void merge_sort (int* arr, const int& l, const int& r)
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

void print_array (int* arr, const int& n)
{
    for (int i = 0; i < n ; ++i) {
        std::cout << arr[i] << " " << std::flush;
    }
    std::cout << std::endl;
}
