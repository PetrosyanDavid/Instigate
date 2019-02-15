#include "get_num.h"

int main()
{
    int n;
    std::cout << "Please input number of scores: " << std::flush;
    n = get_int();
    int a[n];
    int sum = 0;
    int less = 0;
    int more = 0;
    double avrg = 0;

    for (int i = 0 ; i < n ; ++i) {
        std::cout << "Please input the " << i+1 << " score: " << std::flush;
        a[i] = get_int();
        sum += a[i];
    }
    avrg = (double)sum/n;
    for (int i = 0; i < n; ++i) {
        if (a[i]>=avrg) {
            more++;
        } else {
            less++;
        }
    }
    std::cout << "The average score is: "<< avrg << std::endl;
    std::cout << "Number of scores above or equal to average: " << more << std::endl;
    std::cout << "Number of scores below average: " << less << std::endl;
    return 0;
}
