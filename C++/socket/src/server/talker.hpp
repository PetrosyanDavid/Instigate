#ifndef TALKER_HPP
#define TALKER_HPP
#include "thread.hpp"
#include <cassert>
#include <sys/socket.h>
#include <unistd.h>

class talker : public threads::thread
{
public:
        void run()
        {
                // server message
                char msg[256] = "barev";
                assert(m_socket >= 0);
                //send the message
                send(m_socket, &msg, sizeof(msg), 0);
                close(m_socket);
        }
private:
        int m_socket;

public:
        talker(int socket)
                :m_socket(socket)
        {}
};

#endif //TALKER_HPP
