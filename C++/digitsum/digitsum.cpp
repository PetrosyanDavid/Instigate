#include <iostream>

int main(){
    int N = 0;
    int sum = 0;
    std::cout << "Please input your number" << std::endl;
    std::cin >> N;
    while(N>0){
        sum += N%10;
        N = N/10;
    }
    std::cout << "Sum is: " << sum << std::endl;
}
