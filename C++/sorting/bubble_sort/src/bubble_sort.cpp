#include "bubble_sort.hpp"
#include "get_num.h"


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

int* create_array (int n)
{
    std::string gen("");
    try {
        int* arr = new int[n];
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
    } catch (...) {
        std::cout << "Memory allocation failed" << std::endl;
    }
}

void fill_array (int* arr, int n, std::string gen)
{
    if (gen == "a") {
        for (int i = 0; i < n; ++i) {
            arr[i] = rand()%1000;
        }
    } else {
        for (int i = 0; i < n; ++i) {
            arr[i] = get_int();
        }
    }
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


