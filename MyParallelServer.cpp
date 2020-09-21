#include <arpa/inet.h>
#include <errno.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <iostream>
#include <string_view>
#include <mutex>
#include <vector>
#include <system_error>
#include <thread>

#include "ClientHandler.hpp"
#include "MyParallelServer.hpp"

#define THROW_SYSTEM_ERROR() \
    throw std::system_error { errno, std::system_category() }
#define THREAD_POOL_SIZE 10

void MyParallelServer::open(int port, client_side::ClientHandler ch) {
    std::vector<std::thread> threads;
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
}

void MyParallelServer::closeServer() {
    close(m_sockfd);
} 