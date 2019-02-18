#include "generate.h"
#include <string>
#include <ctime>
#include <cstdlib>
#include <cstring>

bool check(char a[],const int& row,const int& col, const int& ship_len, const int& c)
{
    int count = 0;
    if (1 == c){
        for (int s = row-1; s <= row+1; ++s) {
            for (int f = col-1; f <= col+ship_len; ++f){
                if (a[12*s + f] == '#'){
                    count++;
                }
            }
        }
    } else if (2 == c) {
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




void show(const char a[])
{
    for (int row = 1; row < 11; ++row) {
        for (int col = 1; col < 11; ++col){
            std::cout << a[12 * row + col] << std::flush;
        }
        std::cout << std::endl;
    }
}
/*
char* place_ship(char a[], i, j, len, ship)
{
    
}
*/
char* generate()
{
    srand(time(NULL));
    int row = 0;                 // row number
    int col = 0;                 // column number
    int dir = 0;                 // direction in which the ship will\
                                    be placed (1 horisontal, 2 vertical)
    char* field = new char[144]; // 12x12 array for ease of check
    memset (field, '-', 144);
    for (int ship_len = 1; ship_len <= 4; ++ship_len) {
        for (int i = 0; i < 5 - ship_len; ++i) {
                if ((float)rand()/RAND_MAX <= 0.5) {
                    do {
                        row = rand()%10 + 1;
                        col = rand()%(11 - ship_len) + 1;
                        dir = 1;
                        if (check(field, row, col, ship_len, dir)) {
                            for (int u = 0; u < ship_len; ++u) {
                                field [12 * row + col] = '#';
                                col++;
                            }
                            break;
                        }
                    } while(true);
                } else {
                    do {
                        row = rand()%(11 - ship_len) + 1;
                        col = rand()%10 + 1;
                        dir = 2;
                        if (check(field, row, col, ship_len, dir)) {
                            for (int u = 0; u < ship_len; ++u) {
                                field [12 * row + col] = '#';
                                row++;
                            }
                            break;
                        }
                    } while(true);
                }
        }
    }
    return field;
}



void destroy(char a[])
{
    delete [] a;
}

