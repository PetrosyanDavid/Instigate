#include "get_num.h"
#include "first.h"
#include "second.h"
#include "third.h"
#include "forth.h"
#include "fifth.h"
#include <iostream>

int main()
{
    int i = get_int();
    first_out();
    second_out();
    third_out();
    forth_out();
    fifth_out();
    std::cout << i << " Hello world" << std::endl;
    return 0;
}
