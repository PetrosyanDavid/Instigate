#include "generate.h"

bool check (char* a,const int& row,const int& col, const int& ship_len, const int& c)
{
    int count = 0;
    if (0 == c){
        for (int s = row-1; s <= row+1; ++s) {
            for (int f = col-1; f <= col+ship_len; ++f){
                if (a[12*s + f] == '#'){
                    count++;
                }
            }
        }
    } else if (1 == c) {
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


void  place_ship (char* field ,const int& ship_len,const int& dir)
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

