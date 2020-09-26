#ifndef MY_PARALLEL_SERVER_H
#define MY_PARALLEL_SERVER_H

#include "Server.hpp"
#include "ClientHandler.hpp"

class MyParallelServer : public server_side::Server {
    private:
        int m_sockfd;   
    public:
        void open(int port, client_side::ClientHandler& ch);
        void closeServer();
        ~MyParallelServer() = default;
};
#endif //MY_PARALLEL_SERVER_H
