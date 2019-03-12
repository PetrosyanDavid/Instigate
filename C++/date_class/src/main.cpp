#include "Date.hpp"

int main()
{
Date a(12, 2, 2004);
Date b(12, 3, 2004);

a.display_date(1);
b.display_date(2);
a.compare_date(b);

}
