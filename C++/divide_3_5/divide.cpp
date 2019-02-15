#include "get_num.h"

int main(){
    float N = 0;
    int sum = 0;
    std::cout << "Please insert the range value" << std::endl;
    N = get_int();
    for (int i = 0; i < N; i++) {
        if (0 == i%3){
            sum += i;
        } else if (0 == i%5) {
            sum += i;
        }
    }
    std::cout << "Result is: " << sum << std::endl;
    return 0;
}
