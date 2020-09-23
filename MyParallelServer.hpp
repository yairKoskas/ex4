#pragma once

#include "Server.hpp"

class MyParallelServer : public server_side::Server {
    private:
        int m_sockfd;
    public:
        void open(int port, client_side::ClientHandler ch);
        void closeServer();
        virtual ~MyParallelServer() = default;
};