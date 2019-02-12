#include <iostream>

int main(){
    float N = 0;
    int sum = 0;
    std::cout << "please insert the range value" << std::endl;
    std::cin >> N;
    for(int i = 0; i < N; i++){
        if (0 == i%3){
            sum += i;
        }
        else if (0 == i%5){
            sum += i;
        }
    }
    std::cout << "Result is: " << sum << std::endl;
}
