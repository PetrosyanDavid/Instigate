#ifndef SOCKET_HPP
#define SOCKET_HPP
#include <cstdio>
#include <cstdlib>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>

namespace sockets
{
    class socket;
}


enum protocol {TCP,UDP};

class sockets::socket
{
    private:
        int m_socket;
    public:
        socket();
        socket(protocol);
        ~socket();
        int bind (int);
        int listen (int);
        int connect (int);
};

#endif
