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
#include <queue>
#include "ClientHandler.hpp"
#include "MyParallelServer.hpp"

#define THREAD_POOL_SIZE 20

#define THROW_SYSTEM_ERROR() \
    throw std::system_error { errno, std::system_category() }

std::mutex g_mutex;

void threadClient(int serverSock, std::queue<int>& clientConnections, client_side::ClientHandler ch) {
    while(true) {
        g_mutex.lock();
        if(!clientConnections.empty()) {
            const auto clientSock = clientConnections.front();
            clientConnections.pop();
            g_mutex.unlock(); 
            ch.handleClient(clientSock, serverSock);           
        } else {
            g_mutex.unlock();
        }
    }
}

void MyParallelServer::open(int port, client_side::ClientHandler ch) {
    std::queue<int> clientConnections;
    std::thread pool[THREAD_POOL_SIZE];
    for(uint32_t i = 0 ; i < THREAD_POOL_SIZE ; ++i ) {
        pool[i] = std::thread(threadClient, m_sockfd ,std::ref(clientConnections), ch);
    }
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
    if(0 > listen(m_sockfd,512)) {
        closeServer();
        THROW_SYSTEM_ERROR();
    }
    socklen_t size = sizeof(connectAddress);
    while(true) {
        int clientSock = accept(m_sockfd, reinterpret_cast<sockaddr*>(&connectAddress),&size);
        std::cout << "CONNECTED" << std::endl;
        if(clientSock < 0) {
            THROW_SYSTEM_ERROR();
        }
        g_mutex.lock();
        clientConnections.push(clientSock);
        g_mutex.unlock();
    }
}

void MyParallelServer::closeServer() {
    close(m_sockfd);
}