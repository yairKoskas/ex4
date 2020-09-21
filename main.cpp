#include "MySerialServer.hpp"
#include "Server.hpp"
int main() {
    MySerialServer server;
    server.open(8081);
}