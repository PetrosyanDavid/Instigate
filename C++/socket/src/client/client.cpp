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
        sockets::socket c(TCP);
        int connection = c.connect(4988);
        if (-1 == connection) {
                std::cout << "Error connection to remote server." << std::endl;
                c.close();
                return 0;
        }
        // receive data from the server
        char response[256];
        recv(c.m_socket, &response, sizeof(response), 0);

        // print server's response
        std::cout << "Server sent the data >>> " << response << std::endl;
        c.close();
        return 0;
}
