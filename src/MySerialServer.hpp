#include "Server.hpp"

class MySerialServer : public server_side::Server {
    private:
        int m_sockfd;
    public:
        void open(int port, client_side::ClientHandler& ch) override;
        void closeServer() override;
<<<<<<< HEAD
};
=======
        ~MySerialServer() = default;
};
>>>>>>> 537709e809e8dd667d4d72380a3ef49c44a97eee
