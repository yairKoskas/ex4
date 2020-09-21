
#include <arpa/inet.h>
#include <errno.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>

#include <iostream>
#include <string_view>
#include <system_error>

#include "ClientHandler.hpp"
#include "MySerialServer.hpp"

#define THROW_SYSTEM_ERROR() \
    throw std::system_error { errno, std::system_category() }

MySerialServer::MySerialServer() {

}
void MySerialServer::open(int port) {
    m_sockfd = socket(AF_INET,SOCK_STREAM,0);
    if(m_sockfd < 0) {
        THROW_SYSTEM_ERROR();
    }
    sockaddr_in connectAddress{};
    if (0 == inet_aton("127.0.0.1", &connectAddress.sin_addr)) {
        closeServer();
        throw std::runtime_error{"Failed converting IP to 4-bytes"};
    }
    connectAddress.sin_family = AF_INET;
    connectAddress.sin_port = htons(port);
    if (0 > bind(m_sockfd, reinterpret_cast<const sockaddr*>(&connectAddress),
                    sizeof(connectAddress))) {
        closeServer();
        THROW_SYSTEM_ERROR();
    }
    socklen_t sizeOfCAddress = sizeof(connectAddress);
    while(true) {
        if (0 > accept(m_sockfd, reinterpret_cast<sockaddr*>(&connectAddress),&sizeOfCAddress)) {
            closeServer();
            THROW_SYSTEM_ERROR();
        }
        std::string buffer(1024, '\0');
        const auto numBytesRead = read(m_sockfd, (void*)buffer.data(), buffer.size() - 1);
        if (numBytesRead < 0) {
            closeServer();
            THROW_SYSTEM_ERROR();
        }
    }
}

void MySerialServer::closeServer() {
    close(m_sockfd);
} 