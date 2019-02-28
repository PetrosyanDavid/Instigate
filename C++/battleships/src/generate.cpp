#include "generate.h"

// Greeting message
void greet()
{
    std::cout << std::endl;
    std::cout << "\t\tWelcome to the game of battleship" << std::endl;
    std::cout << std::endl;
    std::cout << "Your goal is to guess the positions of enemy ships" << std::endl;
    std::cout << "Your input should have format of letter in range 'a-j' "
        << "followed by number in range 1-10." << std::endl;
    std::cout << "You can olso input '-1' to see the enemy board, "
        << "or '-2 to quit the game'" << std::endl;
    std::cout << std::endl;
}

// Run function for taking input from user and displaying the result
void run (char** p, char** my_board)
{
    int row = 0;
    int col = 0;
    int count = 0;
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
}

// function for taking input, parsing it and returning the coordinates on 10x10 field
void take_input (char** ar, int& a, int& b)
{
    std::string s = "";
    while (true) {
        getline(std::cin, s);
        if (s == "-1") {
            show (ar);
            continue;
        } else if ("-2" == s){
            a = -1;
            b = -1;
            break;
        } else if (s.length() < 2 || s.length() > 3) {
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
            if ((int)s[0] < 97 || (int)s[0] > 106 || (int)s[1] < 49 || (int)s[1] > 57) {
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

// function  checking if ship of length ship_len can be placed starting at
// coordinates  row, col horizontally (dir = 0) or vertically (dir = 1)
bool check (char** a, const int& row, const int& col, const int& ship_len, const int& dir)
{
    int count = 0;
    if (0 == dir) {
        for (int s = row-1; s <= row+1; ++s) {
            for (int f = col-1; f <= col+ship_len; ++f) {
                if (s < 0 || s > 9 || f < 0 || f > 9) {
                    continue;
                } else {
                    if (a[s][f] == '#') {
                        count++;
                    }
                }
            }
        }
    } else if (1 == dir) {
        for (int s = row-1; s <= row+ship_len; ++s) {
            for (int f = col-1; f <= col+1; ++f) {
                if (s < 0 || s > 9 || f < 0 || f > 9) {
                    continue;
                } else {
                    if (a[s][f] == '#') {
                        count++;
                    }
                }
            }
        }
    }
    if (count == 0) {
        return true;
    } else {
        return false;
    }
}

// function for showing 10x10 field
void show (char** a)
{
    std::cout << std::endl;
    std::cout << "  " << std::flush;
    for (int i = 1; i < 11; ++i) {
        std::cout << i << " " << std::flush;
    }
    std::cout << std::endl;
    for (int row = 0; row < 10; ++row) {
        std::cout << char(97 + row) << " " << std::flush;
        for (int col = 0; col < 10; ++col) {
            std::cout <<a[row][col] << " " << std::flush;
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;
}

// function for placing a single ship of length ship_len on field
bool  place_ship (char** field, const int& ship_len, const int& dir)
{
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
// function for generating 10x10 field with randomly placed ships as 2d array
char** generate ()
{
    int dir = 0;
    bool cond = true;
    char** field;
    while (cond) {
        cond = false;
        field = generate_empty();
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


// deleting dynamically defined 2d array
void destroy (char** a)
{
    for (int i =0; i < 10; ++i) {
        delete [] a[i];
    }
    delete [] a;
}

// generating empty 10x10 field as 2d array
char** generate_empty()
{
    while (true) {
        try {
            char** my_board = new char*[10];
            for (int i = 0; i < 10; ++i) {
                my_board[i] = new char[10];
            }
            for (int i = 0; i < 10; ++i) {
                for (int j = 0; j < 10; ++j) {
                    my_board[i][j] = '-';
                }
            }
            return my_board;
            break;
        }
        catch (std::bad_alloc& ba) {
            std::cout << "Memory allocation failed" << std::endl;
            continue;
        }
    }
}


// checking if injury resulted in the death of the ship
bool check_dead (char** my_a, char** a, const int& row, const int& col)
{
    if (check_dir(my_a, a, row, col, 1)) {
        if (check_dir(my_a, a, row, col, 2)) {
            if (check_dir(my_a, a, row, col, 3)) {
                if (check_dir(my_a, a, row, col, 4)) {
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

bool check_dir (char** my_a, char** a, int row, int col, const int& dir)
{
    while(my_a[row][col] = '$') {
        switch(dir){
            case 1:
                ++col;
                if (9 < col) {
                    return true;
                } else {
                    break;
                }
            case 2:
                --col;
                if (0 > col) {
                    return true;
                } else {
                    break;
                }
            case 3:
                ++row;
                if (9 < row) {
                    return true;
                } else {
                    break;
                }
            case 4:
                --row;
                if (0 > row){
                    return true;
                } else {
                    break;
                }
        }
        if (my_a[row][col] == '-') {
            if (a[row][col] == '-') {
                return true;
            } else if (a[row][col] == '#') {
                return false;
            }
        } else if (my_a [row][col] == '*') {
            return true;
        }
    }
}

// filling the spaces around dead ship
void fill (char** my_board, const int& row, const int& col)
{
    fill_dir(my_board, row, col, 1);
    fill_dir(my_board, row, col, 2);
    fill_dir(my_board, row, col, 3);
    fill_dir(my_board, row, col, 4);
}

void fill_dir (char** my_board, int row, int col, const int& dir)
{
    while ('$' == my_board[row][col]) {
        for (int i = row - 1; i <= row + 1; ++i) {
            for (int j = col - 1; j <= col + 1; ++j) {
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
        switch(dir){
            case 1:
                ++col;
                break;
            case 2:
                --col;
                break;
            case 3:
                ++row;
                break;
            case 4:
                --row;
                break;
        }
        if (col < 0 || col > 9 || row < 0 || row > 9) {
            break;
        } else {
            continue;
        }
    }
}
