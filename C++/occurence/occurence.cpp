#include "get_num.h"

int main(){
    int count[10] = {0};
    int input = 0;
    std::cout << "Please input numbers from 1 to 10, or -1 to stop" << std::endl;
    while(true){
        input = get_int();
        if(-1 == input){
            break;
        }
        if(input < 1 || input > 10){
            std::cout << "Input not within range of 1 to 10, try again";
        }
        else {
            count[input]++;
        }
    }
    for(int i = 0; i < 10; i++){
        std::cout << "Number " << i << " occured " << count[i] << " times" << std::endl;
    }
}
