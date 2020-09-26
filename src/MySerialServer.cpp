#include "MySerialServer.hpp"
#include <arpa/inet.h>
#include <errno.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>

#include <system_error>
#include <mutex>
#include <thread>
#include <errno.h>
#include "MyClientHandler.hpp"

#define THROW_SYSTEM_ERROR() \
    throw std::system_error { errno, std::system_category() }

std::mutex g_mutex_serial;

void serialClients(int sockfd, sockaddr_in connectAddress,
            client_side::ClientHandler& ch, socklen_t sizeOfCAddress) {
    while(true) {
        int client_sockfd = accept(sockfd, reinterpret_cast<sockaddr*>(&connectAddress),&sizeOfCAddress);
        if(client_sockfd < 0) {
            THROW_SYSTEM_ERROR();
        }
        g_mutex_serial.lock();
        ch.handleClient(client_sockfd);
        g_mutex_serial.unlock();
        close(client_sockfd);
    }
}
void MySerialServer::open(int port, client_side::ClientHandler& ch) {
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
    std::thread t1(serialClients,m_sockfd, connectAddress, std::ref(ch), sizeOfCAddress);
    
}

void MySerialServer::closeServer() {
    close(m_sockfd);
}