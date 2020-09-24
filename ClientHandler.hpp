#pragma once

namespace client_side {
    class ClientHandler {
        public:
            virtual void handleClient(int clientSock) = 0;
            virtual ~ClientHandler() = default;
    };
}