#pragma once

#include "Server.hpp"

class MySerialServer : public server_side::Server {
    private:
        int m_sockfd;
    public:
        void open(int port, client_side::ClientHandler ch) override;
        void closeServer() override;
};