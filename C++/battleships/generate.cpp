#include <iostream>
#include <string>
#include <ctime>
#include <cstdlib>
#include <cstring>
bool check(char a[], int i, int j, int k, int c)
{
    int count = 0;
    if (1 == c){
        for (int s = i-1; s <= i+1; ++s) {
            for (int f = j-1; f <= j+k; ++f){
                if (a[12*s + f] == '#'){
                    count++;
                }
            }
        }
    } else if (2 == c) {
        for (int s = i-1; s <= i+k; ++s) {
            for (int f = j-1; f <= j+1; ++f){
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




void show(char a[]){
    for (int i = 1; i < 11; ++i) {
        for (int j = 1; j < 11; ++j){
            std::cout << a[12 * i + j] << std::flush;
        }
        std::cout << std::endl;
    }
}

char* generate(){
    srand(time(NULL));
    bool cond  = true;
    int d = 0;
    int i = 0;
    int j = 0;
    int c = 0;
    char* field = new char[144];
    memset (field, '-', 144);
   // show1(field);
    for (int k = 4; k > 0; --k) {
        d = 1;
        while (k + d <= 5){
            do {
                cond = true;
                if ((float)rand()/RAND_MAX <= 0.5) {
                    i = rand()%10 + 1;
                    j = rand()%(11 - k) + 1;
                    c = 1;
                    if (check (field, i, j, k, c)) {
                        for (int u = 0; u < k; ++u) {
                            field [12 * i + j] = '#';
                            j++;
                        }
                        cond = false;
                    }
                } else {
                    i = rand()%(11 - k) + 1;
                    j = rand()%10 + 1;
                    c = 2;
                    if (check(field, i, j, k, c)) {
                        for (int u = 0; u < k; ++u) {
                            field [12 * i + j] = '#';
                            i++;
                        }
                        cond = false;
                    }
                }
            } while (cond);
            d++;
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
    show(p);
    destroy(p);
}
