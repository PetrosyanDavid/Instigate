#include "generate.h"

int main()
{
    int row = 0;
    int col = 0;
    int count = 0;
    char** p = generate();
    char** copy_board = generate_empty();
    char** my_board = generate_empty();
    while (true){
        std::cin >> row;
        std::cin >> col;
        if (row == -1) {
            show(p);
            continue;
        } else if (row == -2) {
            std::cout << "Quitting" << std::endl;
            break;
        }
        if (p[row][col] == '-' || p[row][col] == '*') {
            std::cout << "Miss" << std::endl;
            my_board[row][col] = '*';
        } else if (p[row][col]=='#') {
            my_board[row][col] = '$';
            if(check_dead(my_board ,p , row, col)){
//            if (false) {
            std::cout << "A ship died" << std::endl;
            } else {
                std::cout << "Injured" << std::endl;
            }
            count ++;
        }
        show (my_board);
        if (count == 20){
            std::cout << "Game won" << std::endl;
            break;
        }
    }
    destroy(my_board);
    destroy(copy_board);
    destroy(p);
}
