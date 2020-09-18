#pragma once

#include <sys/socket.h>
#include <string_view>
#include <iostream>
#include <string>


namespace cliecnt_side {

    class ClientHandlar {
        public:
            virtual int handleClient(std::string inputStream, std::string outputStream);
    };
};