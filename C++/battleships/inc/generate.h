#include <iostream>
#include <string>
#include <ctime>
#include <cstdlib>
#include <cstring>



bool check (char** , const int&, const int&, const int&, const int&);
void show (char**);
char** generate ();
void destroy (char**);
bool check_dead (char**, char**, const int&, const int&);
bool check_right (char**, char**, const int&, int);
bool check_left (char**, char**, const int&, int);
bool check_down (char**, char**,int, const int&);
bool check_up (char**, char**, int, const int&);
void take_input (char**, int&, int&);
void fill (char**, const int&, const int&);
void fill_right (char**, const int&, int);
void fill_left (char**, const int&, int);
void fill_up (char**, int, const int&);
void fill_down (char**, int, const int&);
void greet ();
void run (char** , char**);
bool place_ship (char**, const int&, const int&);
char** generate_empty ();
