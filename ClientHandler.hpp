#pragma once

#include <sys/socket.h>
#include <string_view>
#include <iostream>
#include <string>


namespace client_side {
    class ClientHandler {
        public:
            virtual int handleClient(int clientSock);
    };
};