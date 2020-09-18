#pragma once

#include <sys/socket.h>
#include <string_view>
#include <iostream>

#include "ClientHandlar.hpp"


namespace server_side {

    class Server {
        public:
            virtual void open(int port, cliecnt_side::ClientHandlar);
            virtual void close();
    };
};