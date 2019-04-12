#include "talker.hpp"
#include "socket.hpp"
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>

int main ()
{
        // create a socket
        sockets::socket s(TCP);
        s.bind(4988);
        s.listen(5);
        talker* t = 0;
        while (1) {
                int client_socket = accept(s.m_socket, NULL, NULL);
                if (client_socket >= 0) {
                        t = new talker(client_socket);
                        t->create_thread();
                } else {
                        break;
                }
        }
        if (0 != t) {
                t->join_thread();
        }
        s.close();
        return 0;
}
