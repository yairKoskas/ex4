#pragma once

#include "Server.hpp"
#include "MyClientHandler.hpp"
class MyParallelServer : public server_side::Server {
    private:
        int m_sockfd;
    public:
        void open(int port, MyClientHandler& ch);
        void closeServer();
        //virtual ~MyParallelServer() = default;
};