#include <iostream>
#include <vector>
#include <pthread.h>
#include <cstdlib>
#include <ctime>

struct args
{
    int arg1;
    int arg2;
};

std::vector<std::vector<int>> a;
std::vector<std::vector<int>> b;
std::vector<std::vector<int>> c;

void* sum (void* argument)
{
    struct args* num = (args*) argument;
    int i = num->arg1;
    int j = num->arg2;
    c[i][j] = a[i][j] + b[i][j];
    return (void*) &c[i][j];
}

void print_m (std::vector<std::vector<int>> v)
{
    for (auto i : v) {
        for (auto j : i) {
            std::cout << j << " ";
        }
        std::cout << std::endl;
    }
}

void generate (std::vector<std::vector<int>>& v, int size)
{
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            v[i][j] = rand()%10;
        }
        std::cout << std::endl;
    }
}

int main()
{
    srand(time(NULL));
    int size = 0;
    args num;
    std::cout << "Please enter the size of your matrix" << std::endl;
    std::cin >> size;
    a.resize(size, std::vector<int>(size));
    b.resize(size, std::vector<int>(size));
    c.resize(size, std::vector<int>(size));
    generate(a, size);
    generate(b, size);
    print_m(a);
    std::cout << std::endl;
    print_m(b);
    std::cout << std::endl;
    std::vector<std::vector<pthread_t>> arr(size, std::vector<pthread_t>(size));
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            num.arg1 = i;
            num.arg2 = j;
            pthread_create(&arr[i][j], NULL, sum, (void*) &num);
            pthread_join (arr[i][j], NULL);
        }
    }
    //for (int i = 0; i < size; ++i) {
    //    for (int j = 0; j < size; ++j) {
    //        pthread_join (arr[i][j], NULL);
    //    }
    //}
    print_m(c);
}
