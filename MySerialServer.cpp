#include "MySerialServer.hpp"
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
#include <mutex>
#include <thread>
#include "ClientHandler.hpp"
#include "MySerialServer.hpp"

#define THROW_SYSTEM_ERROR() \
    throw std::system_error { errno, std::system_category() }

void serialClients(int sockfd, sockaddr_in connectAddress,
            MyClientHandler ch, socklen_t sizeOfCAddress) {
    while(true) {
        int client_sockfd = accept(sockfd, reinterpret_cast<sockaddr*>(&connectAddress),&sizeOfCAddress);
        if(client_sockfd < 0) {
            THROW_SYSTEM_ERROR();
        }
        ch.handleClient(client_sockfd);
        close(client_sockfd);
    }
}
void MySerialServer::open(int port, MyClientHandler ch) {
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
    if(0 > listen(m_sockfd,1024)) {
        closeServer();
        THROW_SYSTEM_ERROR();
    }
    socklen_t sizeOfCAddress = sizeof(connectAddress);
    std::thread t1(serialClients,m_sockfd, connectAddress, ch, sizeOfCAddress);
    t1.join();
    
}

void MySerialServer::closeServer() {
    close(m_sockfd);
} 