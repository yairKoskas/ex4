#include "MyParallelServer.hpp"
#include "Server.hpp"
#include "MyClientHandler.hpp"
int main() {
    MyParallelServer server;
    MyClientHandler ch = MyClientHandler();
    server.open(8081,ch);
}