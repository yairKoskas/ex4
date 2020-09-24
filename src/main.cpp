#include "MyParallelServer.hpp"
#include "MySerialServer.hpp"
#include "Server.hpp"
#include "MyClientHandler.hpp"
#include <string.h>
int main(int argc, char *argv[]) {
    if(argc == 1){
        int port = std::stoi(argv[0]);
        MyParallelServer s = MyParallelServer();
        MyClientHandler ch = MyClientHandler();
        s.open(port,ch);
    }else if(argc == 2) {
        if(strcmp(argv[1],"serial") == 0) {
            int port = std::stoi(argv[0]);
            MySerialServer s = MySerialServer();
            MyClientHandler ch = MyClientHandler();
            s.open(port,ch);
        }else if(strcmp(argv[1],"parallel") == 0) {
            int port = std::stoi(argv[0]);
            MyParallelServer s = MyParallelServer();
            MyClientHandler ch = MyClientHandler();
            s.open(port,ch);
        }else{
            return -1;
        }
    }else {
        return -1;
    }
}