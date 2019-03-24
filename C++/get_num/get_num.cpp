#include <sstream>
#include "get_num.h"

int get_int(){
    bool fl = false;
    int result = 0;
    std::string s("");
    do{
        getline(std::cin, s);
        fl = check_string_int(s);
    } while (fl);
    std::stringstream str_int(s);
    str_int >> result;
    return result;
}

bool check_string_int (std::string s)
{
    bool fl = false;
    if (s.empty()) {
        std::cout << "Empty input, please try again" << std::endl;
        fl = true;
    } else {
        if (s[0] == '-') {
            fl = check_int(s,1);
        } else {
            fl =check_int(s,0);
        }
    }
    return fl;
}

bool check_int (std::string s, int min)
{
    for (int i = min; i < s.size(); ++i) {
        if(s[i] < '0' || s[i] > '9') {
            std::cout << "Wrong input, please try again " << std::endl;
            return true;
        }
    }
    return false;
}

float get_float(){
    bool fl=false;
    float result = 0;
    std::string s("");
    do{
        getline(std::cin, s);
        fl = check_string_float(s);
    } while (fl);
    std::stringstream str_float(s);
    str_float >> result;
    return result;
}

bool check_float (std::string s, int min)
{
    int dot_count = 0;
    for (int i = min; i < s.size(); ++i) {
        if(s[i] < '0' || s[i] > '9') {
            if(s[i] == '.' && 0 == dot_count){
                dot_count += 1;
                continue;
            } else {
                std::cout << "Wrong input, please try again " << std::endl;
                return true;
            }
        }
    }
    return false;
}

bool check_string_float (std::string s)
{
    bool fl = false;
    if (s.empty()){
        std::cout << "Empty input, please try again" << std::endl;
        fl = true;
    } else {
        if (s[0] == '-') {
            fl = check_float(s,1);
        }
        else {
            fl = check_float(s,0);
        }
    }
    return fl;
}
