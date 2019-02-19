#include "generate.h"

bool check (char* a,const int& row,const int& col, const int& ship_len, const int& dir)
{
    int count = 0;
    if (0 == dir){
        for (int s = row-1; s <= row+1; ++s) {
            for (int f = col-1; f <= col+ship_len; ++f){
                if (a[12*s + f] == '#'){
                    count++;
                }
            }
        }
    } else if (1 == dir) {
        for (int s = row-1; s <= row+ship_len; ++s) {
            for (int f = col-1; f <= col+1; ++f){
                if (a[12*s + f] == '#'){
                    count++;
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

void show (const char* a)
{
    for (int row = 1; row < 11; ++row) {
        for (int col = 1; col < 11; ++col){
            std::cout << a[12 * row + col] << std::flush;
        }
        std::cout << std::endl;
    }
}


void  place_ship (char* field ,const int& ship_len, const int& dir)
{
    int row = 0;
    int col = 0;
    do {
        if (0 == dir) {
            row = rand()%10 + 1;
            col = rand()%(11 - ship_len) + 1;
        } else {
            row = rand()%(11 - ship_len) + 1;
            col = rand()%10 + 1;
        }
        if (check(field, row, col, ship_len, dir)) {
            for (int i = 0; i < ship_len; ++i) {
                field [12 * row + col] = '#';
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

char* generate ()
{
    srand(time(NULL));
    int dir = 0;
    char* field = new char[144];
    memset (field, '-', 144);
    for (int ship_len = 1; ship_len <= 4; ++ship_len) {
        for (int i = 0; i < 5 - ship_len; ++i) {
            dir = (rand())%2;
            place_ship(field, ship_len, dir);
        }
    }
    return field;
}



void destroy (char* a)
{
    delete [] a;
}


char** generate_empty()
{
    char** my_board = new char*[10];
    for (int i = 0; i < 10; ++i) {
        my_board[i] = new char[10];
    }
    return my_board;
}


void destroy_empty(char** a)
{
    for (int i = 0; i < 10; ++i){
        delete [] a[i];
    }
    delete a;
}

bool check_dead(char** a,const int& row,const int& col)
{
    if (check_right(a, row, col)){
        if (check_left(a, row, col)) {
            if (check_down(a, row, col)) {
                if (check_up(a, row, col)) {
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

bool check_right (char** a,const int& row,const int& col)
{
    int c = col;
    while(a[row][c] = '$') {
        if (c < 9){
            c++;
            if (a[row][c] == '-' || a[row][c] == '*') {
                return true;
            } else if (a[row][c] == '#') {
                return false;
            }
        } else {
            return true;
        }
    }
}

bool check_left (char** a,const int& row,const int& col)
{
    int c = col;
    while(a[row][c] = '$') {
        if (c > 0){
                c--;
                if (a[row][c] == '-' || a[row][c] == '*') {
                    return true;
                } else if (a[row][c] == '#') {
                    return false;
                }
        } else {
            return true;
        }
    }
}


bool check_down (char** a,const int& row,const int& col)
{
    int o = row;
    while(a[o][col] = '$') {
        if (o > 0) {
                o--;
                if (a[o][col] == '-' || a[o][col] == '*') {
                    return true;
                } else if (a[o][col] == '#') {
                    return false;
                }
        } else {
            return true;
        }
    }
}


bool check_up (char** a,const int& row,const int& col)
{
    int o = row;
    while(a[o][col] = '$') {
        if (o < 9) {
                o++;
                if (a[o][col] == '-' || a[o][col] == '*') {
                    return true;
                } else if (a[o][col] == '#') {
                    return false;
                }
        } else {
            return true;
        }
    }
}
