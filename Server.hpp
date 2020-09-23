#pragma once

#include <sys/socket.h>
#include <string_view>
#include <iostream>

#include "ClientHandler.hpp"


namespace server_side {

    class Server {
        public:
            virtual void open(int port, client_side::ClientHandler ch);
            virtual void closeServer();
            virtual ~Server() = default;
    };
}