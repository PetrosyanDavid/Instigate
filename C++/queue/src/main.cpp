#include "queue.hpp"

int main()
{
    queue<int> a;
    a.queue_in(12);
    a.queue_in(23);
    a.queue_in(34);
    a.queue_in(45);
    a.print();
    a.queue_out();
    a.queue_out();
    a.print();
}
