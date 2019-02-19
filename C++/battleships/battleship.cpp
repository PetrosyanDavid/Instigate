#include "generate.h"

int main()
{
    int row = 0;
    int col = 0;
    int count = 0;
    char* p = generate();
    char** copy_board = generate_empty();
    char** my_board = generate_empty();
    for (int i = 0; i < 10; ++i) {
        for(int j = 0; j < 10; ++j){
            copy_board[i][j] = p[12*(i+1)+j+1];
            std::cout << copy_board[i][j] << std::flush; 
        }
        std::cout<<std::endl;
    }
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
        if (copy_board[row][col] == '-' || copy_board[row][col] == '*') {
            std::cout << "Miss" << std::endl;
            copy_board[row][col] = '*';
            my_board[row][col] = '*';
        } else if (copy_board[row][col]=='#') {
            copy_board[row][col] = '$';
            my_board[row][col] = '$';
            if(check_dead(copy_board, row, col)){
                std::cout << "A ship died" << std::endl;
            } else {
                std::cout << "Injured" << std::endl;
            }
            count ++;
        }
        for (int i = 0; i < 10; ++i) {
            for(int j = 0; j < 10; ++j) {
                std::cout << copy_board[i][j] << std::flush; 
            }
            std::cout<<std::endl;
        }
        if (count == 20){
            std::cout << "Game won" << std::endl;
            break;
        }
    }
    destroy_empty(my_board);
    destroy_empty(copy_board);
    destroy(p);
}
