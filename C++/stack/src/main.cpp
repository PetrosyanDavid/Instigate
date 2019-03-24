#include "stack.hpp"

int main()
{
    stack<int> a;
    a.stack_push(12);
    a.stack_push(23);
    a.stack_push(34);
    a.stack_push(45);
    a.stack_push(56);
    std::cout << a;
    std::cout << a.stack_pop() << std::endl;
    std::cout<< a;
}
