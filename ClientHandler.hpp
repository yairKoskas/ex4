namespace client_side {
    class ClientHandler {
        public:
            virtual int handleClient(int client_socket, int server_socket);
            virtual ~ClientHandler() = default;
    };
}