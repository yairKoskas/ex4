#pragma once

#include "Server.hpp"

class MySerialServer : public server_side::Server {
    private:
        int m_sockfd;
    public:
        MySerialServer();
        void open(int port);
        void closeServer();
};