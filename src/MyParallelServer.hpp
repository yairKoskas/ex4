#ifndef MY_PARALLEL_SERVER_H
#define MY_PARALLEL_SERVER_H

#include "Server.hpp"
#include "ClientHandler.hpp"

class MyParallelServer : public server_side::Server {
    private:
        int m_sockfd;   
    public:
<<<<<<< HEAD
        void open(int port, MyClientHandler& ch);
        void closeServer();
        //virtual ~MyParallelServer() = default;
};
=======
        void open(int port, client_side::ClientHandler& ch);
        void closeServer();
        ~MyParallelServer() = default;
};
#endif //MY_PARALLEL_SERVER_H
>>>>>>> 537709e809e8dd667d4d72380a3ef49c44a97eee
