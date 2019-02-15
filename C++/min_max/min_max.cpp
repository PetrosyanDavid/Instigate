#include "get_num.h"

int main()
{
    float a[10];
    float min = 0;
    float max = 0;
    std::cout << "Please input 10 numbers" << std::endl;
    for(int i = 0; i < 10; i++){
        a[i] = get_float();
        if(0 == i){
            min = a[i];
            max = a[i];
        }
        if(a[i] > max){max = a[i];}
        if(a[i] < min){min = a[i];}
    }
    std::cout << "Max number is: " << max << std::endl;
    std::cout << "Min number is: " << min << std::endl;
}

