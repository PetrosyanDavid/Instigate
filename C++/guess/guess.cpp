#include "get_num.h"
#include <cstdlib>
#include <ctime>

int main(){
    srand(time(NULL));
    int num = rand()%100 + 1; 
    int count = 0;
    int guess = 0;
    while(true){
        guess = get_int();
        if (guess < 1 || guess > 100){
            std::cout << "Input is not wuthin acceptabl range, try again" <<  std::endl;
            continue;
        }
        else{
            count++;
            if(guess == num){
                std::cout << "Correct guess" << std::endl;
                break;
            }
            else if(guess < num){
                std::cout << "Too low" << std::endl;
            }
            else{
                std::cout << "Too high" << std::endl;
            }
        }
    }
    std::cout << "Correct number is: " << guess << std::endl;
    std::cout << "Attempts made: " << count << std::endl;
}

