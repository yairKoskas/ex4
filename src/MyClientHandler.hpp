#ifndef MY_CLIENT_HANDLER_H
#define MY_CLIENT_HANDLER_H

#include "ClientHandler.hpp"

class MyClientHandler : public client_side::ClientHandler {
    public:
        void handleClient(int clientSock) override;
        ~MyClientHandler() = default;
};

#endif //MY_CLIENT_HANDLER_H