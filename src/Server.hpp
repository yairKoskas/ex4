#ifndef SERVER_H
#define SERVER_H

#include "ClientHandler.hpp"

namespace server_side {
    class Server {
        public:
            virtual void open(int port, client_side::ClientHandler& ch) = 0;
            virtual void closeServer() = 0;
            virtual ~Server() = default;
    };
}

#endif //SERVER_H