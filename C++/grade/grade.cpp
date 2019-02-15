#include "get_num.h"
int main()
{
    int grade = 0;
    std::cout << "Input your grade: " << std::flush;
    do {
        grade = get_int();
        if (grade < 0 || grade > 100) {
            std::cout << "Input is not within range of"
                      <<" 1 - 100, try again" << std::endl;
            continue;
        } else {
            break;
        }
    } while (true);

    if (grade < 60) {
        std::cout << "Your grade is F" << std::endl;
    } else if (grade < 70) {
        std::cout << "Your grade is D" << std::endl;
    } else if (grade < 80) {
        std::cout << "Your grade is C" << std::endl;
    } else if (grade < 90) {
        std::cout << "Your grade is B" << std::endl;
    } else {
        std::cout << "Your grade is A" << std::endl;
    }
}
