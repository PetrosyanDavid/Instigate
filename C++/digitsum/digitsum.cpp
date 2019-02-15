#include "get_num.h"

int main(){
    int N = 0;
    int sum = 0;
    std::cout << "Please input your number" << std::endl;
    N = get_int();
    while(N>0){
        sum += N%10;
        N = N/10;
    }
    std::cout << "Sum of digits is: " << sum << std::endl;
}
