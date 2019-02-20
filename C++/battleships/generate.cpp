#include "generate.h"

bool check (char** a,const int& row,const int& col, const int& ship_len, const int& dir)
{
    int count = 0;
    if (0 == dir){
        for (int s = row-1; s <= row+1; ++s) {
            for (int f = col-1; f <= col+ship_len; ++f){
                if (s < 0 || s > 9 || f < 0 || f > 9) {
                    continue;
                } else {
                    if (a[s][f] == '#'){
                        count++;
                    }
                }
            }
        }
    } else if (1 == dir) {
        for (int s = row-1; s <= row+ship_len; ++s) {
            for (int f = col-1; f <= col+1; ++f){
                if (s < 0 || s > 9 || f < 0 || f > 9) {
                    continue;
                } else {
                    if (a[s][f] == '#'){
                        count++;
                    }
                }
            }
        }
    }
    if (count == 0){
        return true;
    } else {
        return false;
    }
}

void show (char** a)
{
    for (int row = 0; row < 10; ++row) {
        for (int col = 0; col < 10; ++col){
            std::cout << a[row][col] << std::flush;
        }
        std::cout << std::endl;
    }
}


void  place_ship (char** field ,const int& ship_len, const int& dir)
{
    srand(time(NULL));
    int row = 0;
    int col = 0;
    do {
        if (0 == dir) {
            row = rand()%10;
            col = rand()%(10 - ship_len);
        } else {
            row = rand()%(10 - ship_len);
            col = rand()%10;
        }
        if (check(field, row, col, ship_len, dir)) {
            for (int i = 0; i < ship_len; ++i) {
                field [row][col] = '#';
                if (0 == dir) {
                    col++;
                } else {
                    row ++;
                }
            }
            break;
        }
    } while (true);
}

char** generate()
{
    srand(time(NULL));
    int dir = 0;
    char** field = new char*[12];
    for (int i = 0; i < 10; ++i){
        field[i] = new char[10];
    }
//    memset (field, '-', 10*10*sizeof field[0][0]);
    for (int i = 0; i < 10; ++i) {
        for (int j = 0; j < 10; ++j) {
            field[i][j] = '-';
        }
    }
    for (int ship_len = 1; ship_len <= 4; ++ship_len) {
        for (int i = 0; i < 5 - ship_len; ++i) {
            dir = (rand())%2;
            place_ship(field, ship_len, dir);
        }
    }
    return field;
}



void destroy (char** a)
{
    for (int i =0; i < 10; ++i){
        delete [] a[i];
    }
    delete [] a;
}


char** generate_empty()
{
    char** my_board = new char*[10];
    for (int i = 0; i < 10; ++i) {
        my_board[i] = new char[10];
    }
//    memset (my_board, '-', 10*10*sizeof my_board[0][0]);
    for (int i = 0; i < 10; ++i) {
        for (int j = 0; j < 10; ++j) {
            my_board[i][j] = '-';
        }
    }
    return my_board;
}



bool check_dead(char** my_a, char** a,const int& row,const int& col)
{
    if (check_right(my_a, a, row, col)){
        if (check_left(my_a, a, row, col)) {
            if (check_down(my_a, a, row, col)) {
                if (check_up(my_a, a, row, col)) {
                    return true;
                } else {
                    return false;
                }
            } else {
                return false;
            }
        } else {
            return false;
        }
    } else {
        return false;
    }
}

bool check_right (char** my_a, char** a,const int& row, int col)
{
    while(my_a[row][col] = '$') {
        if (col < 9){
            col++;
            if (a[row][col] == '-' || a[row][col] == '*') {
                return true;
            } else if (a[row][col] == '#') {
                return false;
            }
        } else {
            return true;
        }
    }
}

bool check_left (char** my_a, char** a,const int& row, int col)
{
    while(my_a[row][col] = '$') {
        if (col > 0){
            col--;
            if (a[row][col] == '-' || a[row][col] == '*') {
                return true;
            } else if (a[row][col] == '#') {
                return false;
            }
        } else {
            return true;
        }
    }
}


bool check_down (char** my_a, char** a, int row,const int& col)
{
    while(my_a[row][col] = '$') {
        if (row > 0) {
            row--;
            if (a[row][col] == '-' || a[row][col] == '*') {
                return true;
            } else if (a[row][col] == '#') {
                return false;
            }
        } else {
            return true;
        }
    }
}


bool check_up (char** my_a,char** a, int row,const int& col)
{
    while(my_a[row][col] = '$') {
        if (row < 9) {
            row++;
            if (a[row][col] == '-' || a[row][col] == '*') {
                return true;
            } else if (a[row][col] == '#') {
                return false;
            }
        } else {
            return true;
        }
    }
}
