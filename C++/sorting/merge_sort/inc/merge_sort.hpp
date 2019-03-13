#include <iostream>
#include <cstdlib>
#include <ctime>

int* create_array (const int&);
int get_size ();
void fill_array (int*,const int&,const std::string&);
void print_array (int* , const int&);
void destroy (int*);
void merge_sort (int*, const int&, const int&);
void merge (int*, const int&, const int&, const int&);
