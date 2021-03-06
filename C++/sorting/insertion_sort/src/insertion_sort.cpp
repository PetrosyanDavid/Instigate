#include "insertion_sort.hpp"
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
    int* arr = nullptr;
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

void fill_array (int* arr, const int& n, const std::string& gen)
{
    assert(arr);
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
    assert(arr);
    delete [] arr;
    arr = nullptr;
}

std::string get_type()
{
    std::string type = " ";
    std::cout << "Please input '+' for ascending sorting, or '-' "
        << "for descending sorting" << std::endl;
    while (true) {
        getline(std::cin, type);
        if (type == "+" || type == "-") {
            break;
        } else {
            std::cout << "Wrong input for type, try again" << std::endl;
            continue;
        }
    }
    return type;
}

bool check_relation (const std::string& type, const int& a, const int& b)
{
    bool cond = true;
    if (type == "+") {
        cond = (a > b);
    } else if (type == "-"){
        cond = (a <= b);
    }
    return cond;
}

void insertion_sort (int* arr,const int& n, const std::string& type)
{
    assert(arr);
    int tmp = 0;
    for (int i = 1; i < n; ++i) {
        tmp = arr[i];
        for (int k = i-1; k >= 0; --k) {
            if (!check_relation (type, tmp, arr[k])) {
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

void print_array (int* arr,const int& n)
{
    assert(arr);
    for (int i = 0; i < n ; ++i) {
        std::cout << arr[i] << " " << std::flush;
    }
    std::cout << std::endl;
}


