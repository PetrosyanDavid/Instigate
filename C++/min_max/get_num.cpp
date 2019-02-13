#include <iostream>
#include <sstream>
#include "get_num.h"

int get_int(){
    bool fl=false;
    int result = 0;
    std::string s("");
    do{
        std::cout << "Input the number ... " << std::endl;
        getline(std::cin, s);
        fl = false;
        if (s[0] == '-') {
            for (int i = 1; i < s.size(); ++i) {
                if(s[i] < '0' || s[i] > '9') {
                    std::cout << "Error number ... " << s[i] << std::endl;
                    fl=true;
                    break;
                }
            }
        }
        else {
            for (int i = 0; i < s.size(); ++i) {
                if(s[i] < '0' || s[i] > '9') {
                    std::cout << "Error number ... " << s[i] << std::endl;
                    fl=true;
                    break;
                }
            }
        }
    } while(fl);
    std::stringstream str_int(s);
    str_int >> result;
    return result;
}


float get_float(){
    bool fl=false;
    float result = 0;
    int dot_count = 0;
    std::string s("");
    do{
        std::cout << "Input the number ... " << std::endl;
        getline(std::cin, s);
        fl = false;
        if (s[0] == '-') {
            for (int i = 1; i < s.size(); ++i) {
                if(s[i] < '0' || s[i] > '9') {
                    if(s[i] == '.' && 0 == dot_count){
                        dot_count += 1;
                        continue;
                    }
                    else{
                        std::cout << "Error number ... " << s[i] << std::endl;
                        fl=true;
                        break;
                    }
                }
            }
        }
        else {
            for (int i = 0; i < s.size(); ++i) {
                if(s[i] < '0' || s[i] > '9') {
                    if(s[i] == '.' && 0 == dot_count){
                        dot_count += 1;
                        continue;
                    }
                    else{
                        std::cout << "Error number ... " << s[i] << std::endl;
                        fl=true;
                        break;
                    }
                }
            }
        }
    } while(fl);
    std::stringstream str_float(s);
    str_float >> result;
    return result;
}

