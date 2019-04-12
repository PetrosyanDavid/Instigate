#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>

int main ()
{
        //create a socket(client_socket)
        int c = socket(AF_INET, SOCK_STREAM, 0);
        //specify an address for the socket
        struct sockaddr_in sa;
        sa.sin_family = AF_INET;
        sa.sin_port = htons(9002);
        sa.sin_addr.s_addr = INADDR_ANY;
        // connetion
        int connection = connect(c, (struct sockaddr*)& sa, sizeof(sa));

        //check for error connection
        if (-1 == connection) {
                std::cout << "Error connection to remote server." << std::endl;
                close(c);
                return 0;
        }
        // receive data from the server
        char response[256];
        recv(c, &response, sizeof(response), 0);

        // print server's response
        std::cout << "Server sent the data >>> " << response << std::endl;
        close(c);
        return 0;
}
