#include "talker.hpp"
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
        int s = socket(AF_INET, SOCK_STREAM, 0);
        if (s < 0) {
                std::cout << "Can't open socket" << std::endl;
                return 0;
        }
        // define server address
        struct sockaddr_in sa;
        sa.sin_family = AF_INET;
        sa.sin_port = htons(9002);
        sa.sin_addr.s_addr = INADDR_ANY;
        //bind the socket to our speciied IP and port
        int r = bind(s, (struct sockaddr*)&sa, sizeof(sa));
        if (r < 0) {
                std::cout << "Can't bind socket" << std::endl;
                close(s);
                return 0;
        }
        r = listen(s, 1);
        if (r < 0) {
                std::cout << "listen error" << std::endl;
                close(s);
                return 0;
        }
        talker* t = 0;
        while (1) {
                int client_socket = accept(s, NULL, NULL);
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
        close(s);
        return 0;
}
