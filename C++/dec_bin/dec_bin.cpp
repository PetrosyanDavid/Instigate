#include "get_num.h"

int main(){
    int dec = 0;
    int n = 0;
    int sub =0;

    dec = get_int();
    sub = dec;
    while(sub >= 1){
        sub = sub/2;
        n++;
    }
    char bin[n];
    for (int i = 0; i < n; ++i) {
        if (dec%2 == 1) {
            bin[n-i-1] = '1';
        }
        else {
            bin[n-i-1] = '0';
        }
        dec = dec/2;
    }
    for (int i = 0; i < n; ++i) {
        std::cout << bin[i] << "  ";
    }
}
