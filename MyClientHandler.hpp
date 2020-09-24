#pragma once

#include "ClientHandler.hpp"

class MyClientHandler : public client_side::ClientHandler {
    public:
        void handleClient(int clientSock) override;
};