#include "socket.hpp"

sockets::socket::socket ()
    : m_socket(0)
{}

sockets::socket::socket (protocol prot)
{
    switch (prot) {
        case TCP:
            m_socket = ::socket (AF_INET, SOCK_STREAM, 0);
            break;
        case UDP:
            m_socket = ::socket (AF_INET, SOCK_DGRAM, 0);
            break;
    }
}

int sockets::socket::bind(int port)
{
    struct sockaddr_in sa;
    sa.sin_family = AF_INET;
    sa.sin_port = htons(port);
    sa.sin_addr.s_addr = INADDR_ANY;
    int r = ::bind(m_socket, (struct sockaddr*)&sa, sizeof(sa));
    return r;
}

int sockets::socket::listen (int queue)
{
    int r = ::listen(m_socket, queue);
    return r;
}

int sockets::socket::connect (int port)
{
    struct sockaddr_in sa;
    sa.sin_family = AF_INET;
    sa.sin_port = htons(port);
    sa.sin_addr.s_addr = INADDR_ANY;
    int connection = ::connect(m_socket, (struct sockaddr*)& sa, sizeof(sa));
    return connection;
}

int sockets::socket::close ()
{
    int r = ::close(m_socket);
    return r;
}
