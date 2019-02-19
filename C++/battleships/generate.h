#include <iostream>
#include <string>
#include <ctime>
#include <cstdlib>
#include <cstring>



bool check(char* , const int&, const int&, const int&, const int&);
void show(const char*);
char* generate();
void destroy(char*);
char ** generate_empty();
void destroy_empty(char **);
bool check_dead (char**,const int& ,const int&);
bool check_right (char**,const int& ,const int&);
bool check_left (char**,const int& ,const int&);
bool check_down (char**,const int& ,const int&);
bool check_up (char**,const int& ,const int&);
