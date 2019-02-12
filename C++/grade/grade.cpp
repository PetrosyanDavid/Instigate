#include <iostream>
#include <string>
#include <sstream>
int main(){
    int grade = 0;
    std::cout << "Input your grade: " << std::flush;
    std::cin >> grade;
    if(grade < 60){
        std::cout << "Your grade is F" << std::endl;
    }
    else if (grade < 70){
        std::cout << "Your grade is D" << std::endl;
    }
    else if (grade < 80){
        std::cout << "Your grade is C" << std::endl;
    }
    else if (grade < 90){
        std::cout << "Your grade is B" << std::endl;
    }
    else{
        std::cout << "Your grade is A" << std::endl;
    }
}
