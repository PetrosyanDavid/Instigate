#include <iostream>

class smart_array
{
    private:
        int* m_arr;
        int m_size;
        int m_def;
    public:
        smart_array ();
        smart_array (int, int);
        smart_array (const smart_array&);
        smart_array& operator= (const smart_array&);
        void resize (int ,const int& =7 );
        void psh_back (int);
        void pop ();
        void insert (int, int);
        void erase (int);
        int& operator[] (int);
        void print();
        ~smart_array ();
};
