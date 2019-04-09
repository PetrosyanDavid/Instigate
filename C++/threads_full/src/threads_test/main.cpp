#include "matrix.hpp"

#include <iostream>
#include <cassert>

int main()
{
        data a;
        data b;
        data c;
        data d;
        data e;
        data f;
        data g;
        a.init_identity();
        b.init_identity();
        c.init_identity();
        d.init_identity();
        a.print("a");
        b.print("b");
        c.print("c");
        d.print("d");
        // adder ab(&a, &b, &e);
        // adder cd(&c, &d, &f);
        // multiplier ef(&e, &f, &g);
        multiplier ab(&a, &b, &e);
        multiplier cd(&c, &d, &f);
        adder ef(&e, &f, &g);
        ab.create_thread();
        cd.create_thread();
        ef.create_thread();
        ab.join_thread();
        cd.join_thread();
        ef.join_thread();
        e.print("e");
        f.print("f");
        g.print("g");
	return 0;
}
