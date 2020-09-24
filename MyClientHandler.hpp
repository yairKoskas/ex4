#pragma once

#include "ClientHandler.hpp"

class MyClientHandler : public client_side::ClientHandler {
    public:
        int handleClient(int clientSock) override;
};