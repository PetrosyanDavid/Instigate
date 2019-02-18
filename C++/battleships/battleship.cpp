#include "generate.h"

int main()
{
    char* p = generate();
    show(p);
    destroy(p);
}
