namespace client_side {
    class ClientHandler {
        public:
            virtual int handleClient(int clientSock) = 0;
    };
};