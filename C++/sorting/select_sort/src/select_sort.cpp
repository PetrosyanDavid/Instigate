#include "select_sort.hpp"
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

int find_min (int* arr, const int& n, const int& start)
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


void select_sort (int* arr, const int& n)
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

void print_array (int* arr, const int& n)
{
    for (int i = 0; i < n ; ++i) {
        std::cout << arr[i] << " " << std::flush;
    }
    std::cout << std::endl;
}


