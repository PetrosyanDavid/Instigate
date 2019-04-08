#include <iostream>
#include <thread>
#include <cassert>
#include "matrix.hpp"

int a[SIZE][SIZE];
int b[SIZE][SIZE];
int c[SIZE][SIZE];
/////////////////////////print function///////////////
/**
 * @fn print
 * @brief printind matrix
 * @param name
 * @brief matrix name
 * @param a[SIZE][SIZE]
 * @brief matrix
 */
void print(const char* name, int a[SIZE][SIZE])
{
    assert(0 != name);
    std::cout << name << " = \n";
    for (int i = 0; i < SIZE; ++i) {
        for (int j = 0; j < SIZE; ++j) {
            std::cout << a[i][j] << " ";
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;
}

////////////////////initalize function//////////////////////
/**
 * @fn initialize
 * @brief  matrix initialisation
 */
void initialize()
{
    for (int i = 0; i < SIZE; ++i) {
        for (int j = 0; j < SIZE; ++j) {
            a[i][j] = i * 2 + j;
            b[i][j] = j * 2 + i;
            c[i][j] = 0;
        }
    }
}

int main()
{
    initialize();
    print("a", a);
    print("b", b);
    print("c", c);
    adder* t[SIZE][SIZE];
    for (int i = 0; i < SIZE; ++i) {
        for (int j = 0; j < SIZE; ++j) {
            t[i][j] = new adder(i, j);
        }
    }
    for (int i = 0; i < SIZE; ++i) {
        for (int j = 0; j < SIZE; ++j) {
            t[i][j]->create_thread();
        }
    }
    for (int i = 0; i < SIZE; ++i) {
        for (int j = 0; j < SIZE; ++j) {
            t[i][j]->join_thread();
        }
    }
    print("c", c);
    return 0;
}
