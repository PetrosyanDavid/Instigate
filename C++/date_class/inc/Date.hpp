#include <iostream>

class Date
{
    private:
        int day;
        int month;
        int year;
    public:
        Date();
        Date(int x, int y, int z);
        void set_date (int x, int y, int z);
        void display_date (int f);
        void compare_date (Date& d);
        ~Date();
};
