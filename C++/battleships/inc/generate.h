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
void take_input (char**, int&, int&);
void fill (char**, const int&, const int&);
void greet ();
void run (char** , char**);
bool place_ship (char**, const int&, const int&);
char** generate_empty ();
bool check_dir (char**, char**, int, int, const int&);
void fill_dir (char**, int, int, const int&);
void help ();
