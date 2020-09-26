#ifndef CLIENT_HANDLER_H
#define CLIENT_HANDLER_H

namespace client_side {
    class ClientHandler {
        public:
            virtual void handleClient(int clientSock) = 0;
            virtual ~ClientHandler() = default;
    };
}

#endif //CLIENT_HANDLER_H