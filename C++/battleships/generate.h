#include <iostream>
#include <string>
#include <ctime>
#include <cstdlib>
#include <cstring>



bool check(char** , const int&, const int&, const int&, const int&);
void show(char**);
char** generate();
void destroy(char**);
char** generate_empty();
void destroy_empty(char **);
bool check_dead (char**, char**,const int& ,const int&);
bool check_right (char**, char**,const int& ,int);
bool check_left (char**, char**,const int& ,int);
bool check_down (char**, char**,int ,const int&);
bool check_up (char**, char**,int ,const int&);
