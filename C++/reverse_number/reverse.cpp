#include <iostream>
#include <string>
#include <sstream>
int main(){
    int num = 0;
    int len = 0;
    int rev = 0;
    char a = ' ';
    std::cout << "Input a number" << std::endl;
    std::cin >> num;
    std::string num_str = std::to_string(num);
    len = num_str.length();
    for(int i = 0; i < len/2; i++){
        a = num_str[i];
        num_str[i] = num_str[len - 1 -i];
        num_str[len - 1 -i] = a;
    }
//    rev = std::stoi(num_str);
    std::cout << "Reversed number is: " << num_str << std::endl;
    return 0;
}
