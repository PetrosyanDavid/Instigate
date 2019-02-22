#include "generate.h"

int main()
{
    int row = 0;
    int col = 0;
    int count = 0;
    char** p = generate();
    char** my_board = generate_empty();
    std::cout << std::endl;
    std::cout << "\t\tWelcome to the game of battleship" << std::endl;
    std::cout << std::endl;
    std::cout << "Your goal is to guess the positions of enemy ships" << std::endl;
    std::cout << "Your input should have format of letter in range 'a-j' "
              << "followed by number in range 1-10." << std::endl;
    std::cout << "You can olso input '-1' to see the enemy board, "
              << "or '-2 to quit the game'" << std::endl;
    std::cout << std::endl;
    while (true) {
        take_input(p, row, col);
        if (-1 == row || -1 == col) {
            std::cout << "Quitting" << std::endl;
            break;;
        } else {
            if ('$' == my_board[row][col]) {
                std::cout << "Repeating hit" << std::endl;
            } else if ('*' == my_board[row][col]) {
                std::cout << "Repeating miss" << std::endl;
            } else if (p[row][col] == '-' || p[row][col] == '*') {
                std::cout << "Miss" << std::endl;
                my_board[row][col] = '*';
            } else if (p[row][col]=='#') {
                my_board[row][col] = '$';
                if(check_dead(my_board ,p , row, col)) {
                    std::cout << "A ship died" << std::endl;
                    fill(my_board, row, col);
                } else {
                    std::cout << "Injured" << std::endl;
                }
                count ++;
            }
        }
        show (my_board);
        if (count == 20) {
            std::cout << "Game won" << std::endl;
            break;
        }
    }
    destroy(my_board);
    destroy(p);
}
