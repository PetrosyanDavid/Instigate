#include "get_num.h"

void shift(int* ,int, int);

int main()
{
    int n = 0;
    int input = 0;
    std::cout << "Enter your array size " << std::flush;
    n = get_int();
    int array[n];

    std::cout << "Enter your value to be searched " << std::flush;
    input = get_int();
    std::cout << "Input array numbers " << std::endl;
    for (int i = 0; i < n; ++i) {
        array[i] = get_int();
    }

    shift(array , n, input);
    for (int i = 0; i < n; ++i) {
        std::cout << array[i] << " " << std::flush;
    }
    std::cout << std::endl;
    return 0;
}

void shift ( int a[], int size, int input)
{
    for (int i = 0; i < size; ++i) {
        if (a[i] != input) {
            continue;
        } else {
            for (int j = i; j < size - 1; j++) {
                a[j] = a[j+1];
            }
            a[size-1] = 0;
            break;
        }
    }
}


