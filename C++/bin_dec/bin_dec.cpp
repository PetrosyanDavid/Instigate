#include <iostream>
#include <sstream>
#include <cstdlib>
#include <cmath>
int main()
{
    std::string bin_num = "";
    int len = 0;
    int dec_num = 0;
    int dig = 0;
    bool cond = true;
    while (cond) {
        std::cout << "Enter your binary number" << std::endl;
        std::getline (std::cin, bin_num);
        len = bin_num.length();
        for (int i = 0; i < len; ++i) {
            if (bin_num[i] != '0' && bin_num[i] != '1') {
                std::cout << "Your input is not a binary number,"
                    << " please try again" << std::endl;
                break;
            } else {
                dig = bin_num[i] - '0';
                dec_num += pow(2, len - i -1)*dig;
                if (i == len -1) {
                    cond = false;
                }
            }
        }
    }
    std::cout << "Decimal number is: " << dec_num << std::endl;
}
