#include "generate.h"

int main()
{
    srand(time(NULL));
    char** p = generate();
    char** my_board = generate_empty();
    greet ();
    run (p, my_board);
    destroy(my_board);
    destroy(p);
}
