#include <sys/socket.h>
#include <string_view>
#include <iostream>
namespace server_side {
    class Server {
        public:
            virtual void open(int port);
            virtual void close();
    };
}
namespace client_side {
    class ClientHandler {
        public:
    };
};