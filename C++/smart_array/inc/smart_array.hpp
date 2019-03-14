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
        void resize (int, int);
        int& operator[] (int);
        ~smart_array ();
};
