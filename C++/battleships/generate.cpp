#include "generate.h"


void take_input (char** ar, int& a, int& b)
{
    std::string s = "";
    while (true) {
        getline(std::cin, s);
        if (s == "-1") {
            show (ar);
        }else if (s.length() < 2 || s.length() > 3) {
            std::cout << "Wrong input, please try again" << std::endl;
            continue;
        } else if (3 == s.length()) {
            if ((int)s[0] < 97 || (int)s[0] > 106 || '1' != s[1] || '0' != s[2]) {
                std::cout << "Wrong input, please try again" << std::endl;
                continue;
            } else {
                a = (int)s[0] - 97;
                b = 9;
                break;
            }
        } else {
            if ((int)s[0] < 97 || (int)s[0] > 106 || (int)s[1] < 48 || (int)s[1] > 57) {
                std::cout << "Wrong input, please try again " << std::endl;
                continue;
            } else {
                a = (int)s[0] - 97;
                b = (int)s[1] - 49;
                break;
            }
        }
    }
}

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
    std::cout << std::endl;
    std::cout << "  " << std::flush;
    for (int i = 1; i < 11; ++i) {
        std::cout << i << std::flush;
    }
    std::cout << std::endl;
    for (int row = 0; row < 10; ++row) {
        std::cout << char(97 + row) << " " << std::flush;
        for (int col = 0; col < 10; ++col){
            std::cout <<a[row][col] << std::flush;
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;
}


bool  place_ship (char** field ,const int& ship_len, const int& dir)
{
    srand(time(NULL));
    int row = 0;
    int col = 0;
    int attempts = 0;
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
        } else {
            attempts++;
        }
        if (100 == attempts) {
            return false;
        } else {
            continue;
        }
    } while (true);
    return true;
}

char** generate()
{
    srand(time(NULL));
    int dir = 0;
    bool cond = true;
    char** field = new char*[12];
    for (int i = 0; i < 10; ++i){
        field[i] = new char[10];
    }
    while (cond) {
        cond = false;
        for (int i = 0; i < 10; ++i) {
            for (int j = 0; j < 10; ++j) {
                field[i][j] = '-';
            }
        }
        for (int ship_len = 1; ship_len <= 4; ++ship_len) {
            for (int i = 0; i < 5 - ship_len; ++i) {
                dir = (rand())%2;
                if (place_ship(field, ship_len, dir)) {
                    continue;
                } else {
                    ship_len = 5;
                    i  = 5;
                    cond = true;
                }
            }
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
            if (my_a[row][col] == '-'){
                if (a[row][col] == '-') {
                    return true;
                } else if (a[row][col] == '#') {
                    return false;
                }
            } else if (my_a [row][col] == '*') {
                return true;
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
            if (my_a[row][col] == '-'){
                if (a[row][col] == '-') {
                    return true;
                } else if (a[row][col] == '#') {
                    return false;
                }
            } else if (my_a [row][col] == '*') {
                return true;
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
            if (my_a[row][col] == '-'){
                if (a[row][col] == '-') {
                    return true;
                } else if (a[row][col] == '#') {
                    return false;
                }
            } else if (my_a [row][col] == '*') {
                return true;
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
            if (my_a[row][col] == '-'){
                if (a[row][col] == '-') {
                    return true;
                } else if (a[row][col] == '#') {
                    return false;
                }
            } else if (my_a [row][col] == '*') {
                return true;
            }
        } else {
            return true;
        }
    }
}


void fill (char** my_board, const int& row, const int& col)
{
    fill_right(my_board, row, col);
    fill_left(my_board, row, col);
    fill_up(my_board, row, col);
    fill_down(my_board, row, col);
}


void fill_right(char ** my_board, const int& row, int col)
{
    while ('$' == my_board[row][col]) {
        for (int i = row - 1; i <= row + 1; ++i) {
            for (int j = col - 1; j <= col + 1; ++j){
                if (i < 0 || i > 9 || j < 0 || j > 9) {
                    continue;
                } else {
                    if ('$' != my_board[i][j]) {
                        my_board[i][j] = '*';
                    } else {
                        continue;
                    }
                }
            }
        }
        if (9 != col){
            col++;
        } else  {
            break;
        }
    }
}

void fill_left(char ** my_board,const int& row, int col)
{
    while ('$' == my_board[row][col]) {
        for (int i = row - 1; i <= row + 1; ++i) {
            for (int j = col - 1; j <= col + 1; ++j){
                if (i < 0 || i > 9 || j < 0 || j > 9) {
                    continue;
                } else {
                    if ('$' != my_board[i][j]) {
                        my_board[i][j] = '*';
                    } else {
                        continue;
                    }
                }
            }
        }
        if (0 != col){
            col--;
        } else  {
            break;
        }
    }
}

void fill_up(char ** my_board, int row, const int& col)
{
    while ('$' == my_board[row][col]) {
        for (int i = row - 1; i <= row + 1; ++i) {
            for (int j = col - 1; j <= col + 1; ++j){
                if (i < 0 || i > 9 || j < 0 || j > 9) {
                    continue;
                } else {
                    if ('$' != my_board[i][j]) {
                        my_board[i][j] = '*';
                    } else {
                        continue;
                    }
                }
            }
        }
        if (0 != row){
            row--;
        } else  {
            break;
        }
    }
}

void fill_down(char ** my_board, int row, const int& col)
{
    while ('$' == my_board[row][col]) {
        for (int i = row - 1; i <= row + 1; ++i) {
            for (int j = col - 1; j <= col + 1; ++j){
                if (i < 0 || i > 9 || j < 0 || j > 9) {
                    continue;
                } else {
                    if ('$' != my_board[i][j]) {
                        my_board[i][j] = '*';
                    } else {
                        continue;
                    }
                }
            }
        }
        if (9 != row){
            row++;
        } else  {
            break;
        }
    }
}
