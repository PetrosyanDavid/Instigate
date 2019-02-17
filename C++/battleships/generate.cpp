#include <iostream>
#include <string>
#include <ctime>
#include <cstdlib>
#include <cstring>
bool check(char a[], int i, int j)
{
    int c = 0;
    if (10 != i && 10 != j) {
        for (int s = i - 1; s <= i + 1; ++s){
            for(int l = j - 1; l <= j + 1; ++l){
                if (a[11 * s + l] == '#') {
                    s++;
                }
            }
        }
    } else if (10 == i && 10 != j) {
        for (int s = i - 1; s <= i; ++s){
            for(int l = j - 1; l <= j+1; ++l){
                if (a[11 * s + l] == '#') {
                    s++;
                }
            }
        }
    } else if (10 != i && 10 == j) {
        for (int s = i - 1; s <= i + 1; ++s){
            for(int l = j - 1; l <= j; ++l){
                if (a[11 * s + l] == '#') {
                    s++;
                }
            }
        }
    } else if (10 == i && 10 == j) {
        for (int s = i - 1; s <= i; ++s){
            for(int l = j - 1; l <= j; ++l){
                if (a[11 * s + l] == '#') {
                    s++;
                }
            }
        }
    }
    if (0 != c) {
        return false;
    } else {
        return true;
    }
}



void show(char a[]){
    for (int i = 0; i < 11; ++i) {
        for (int j = 0; j < 11; ++j){
            if (0 == i) {
                if(0 == j){
                    std::cout << " " << std::flush;
                } else {
                    std::cout << j - 1 << std::flush;
                }
                } else {
                if (0 == j){
                    std::cout << i - 1 << std::flush;
                } else {
                    std::cout << a[11 * i + j] << std::flush;
                }
            }
        }
        std::cout << std::endl;
    }
}

void show1(char a[]){
    for (int i = 1; i < 11; ++i) {
        for (int j = 1; j < 11; ++j){
                    std::cout << a[11 * i + j] << std::flush;
        }
        std::cout << std::endl;
    }
}

char* generate(){
    srand(time(NULL));
    bool cond  = false;
    int d = 0;
    int i = 0;
    int j = 0;
    char* field = new char[121];
    memset (field, '*', 121);
   // show1(field);
    for (int k = 4; k > 0; --k) {
        d = 1;
        while (k + d <= 5){
            do {
                cond = false;
                if ((float)rand()/RAND_MAX <= 0.5) {
                    i = rand()%10 + 1;
                    j = rand()%(11 - k) + 1;
                    for (int u = 0; u < k; ++u) {
                        if (check (field, i, j)) {
                            field [11 * i + j] = '$';
                            j++;
                        } else {
                            for (int z = 0; z < 121; ++z) {
                                if (field[z] == '$') {
                                    field[z] = '*';
                                }
                            }
                            cond = true;
                            break;
                        }
                    }
                } else {
                    i = rand()%(11 - k) + 1;
                    j = rand()%10 + 1;
                    for (int u = 0; u < k; ++u) {
                        if (check (field, i, j)) {
                            field [11 * i + j] = '$';
                            i++;
                        } else {
                            for (int z = 0; z < 121; ++z) {
                                if (field[z] == '$') {
                                    field[z] = '*';
                                }
                            }
                            cond = true;
                            break;
                        }
                    }
                }
            } while (cond);
            d++;
            for (int x = 0; x < 121; ++x) {
                if (field[x] == '$') {
                    field[x] = '#';
                }
            }
        }
    }
    return field;
}



void destroy(char a[]){
    delete [] a;
}


int main()
{
    char* p = generate();
    show1(p);
    destroy(p);
}
