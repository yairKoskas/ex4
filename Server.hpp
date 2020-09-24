#pragma once

#include <sys/socket.h>
#include <string_view>
#include <iostream>

#include "MyClientHandler.hpp"


namespace server_side {
    class Server {
        public:
            virtual void open(int port, MyClientHandler ch) = 0;
            virtual void closeServer() = 0;
    };
}