#include "get_num.h"

void gcd_lcm(int&, int&);

int main()
{
    std::cout << "Please input your integer numbers" << std::endl;
    while (true) {
        int a = get_int();
        int b = get_int();
        if (a <= 0 || b <= 0) {
            std::cout << "You inputed negative number, please try again" << std::endl;
            continue;
        } else {
            gcd_lcm(a, b);
            std::cout << "GCD is: " << a << std::endl;
            std::cout << "LCM is: " << b << std::endl;
            break;
        }
    }
}


void gcd_lcm(int& a, int& b)
{
    int min = 0;
    if (a <= b){
        min = a;
    } else {
        min = b;
    }
    for (int i = min; i >0 ; --i) {
        if (0 == a%i && 0 == b%i){
            min = i;
            break;
        } else {
            continue;
        }
    }
    b = (a*b)/min;
    a = min;
}
