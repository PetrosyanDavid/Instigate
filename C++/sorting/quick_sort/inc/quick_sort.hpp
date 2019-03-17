#include <iostream>
#include <cstdlib>
#include <ctime>

int* create_array (const int&);
int get_size ();
void fill_array (int*,const int&,const std::string&);
void print_array (int* , const int&);
void destroy (int*);
void quick_sort (int*, const int&, const int&, const std::string&);
int split (int*, const int&, const int&, const std::string&);
bool check_relation (const std::string&, const int&, const int&);
std::string get_type ();
