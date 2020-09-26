#include "MyParallelServer.hpp"
#include "MySerialServer.hpp"
#include "Server.hpp"
#include "Graph.hpp"
#include "MyClientHandler.hpp"
#include "Matrix.hpp"
#include "AStar.hpp"
#include <string.h>
#include <string>
#include <cstdlib>
#include <iostream>
Matrix genRandomMatrix(int size) {
    Matrix x = Matrix(size,size);
    for(int i=0;i<size;++i){
        for(int j=0;j<size;++j){
            int randomValue = (rand() % 100) + 1;
            x.set(i,j,randomValue);
        }
    }
    return x;
}
int main(int argc, char *argv[]) {
    if(argc == 2) {
        int port = std::stoi(argv[1]);
        MyParallelServer s = MyParallelServer();
        MyClientHandler ch = MyClientHandler();
        s.open(port,ch);
    } else if(argc == 3) {
        if(strcmp(argv[2],"serial") == 0) {
        int port = std::stoi(argv[1]);
        MySerialServer s = MySerialServer();
        MyClientHandler ch = MyClientHandler();
        s.open(port,ch);
        } else if(strcmp(argv[2],"parallel") == 0) {
            int port = std::stoi(argv[1]);
            MyParallelServer s = MyParallelServer();
            MyClientHandler ch = MyClientHandler();
            s.open(port,ch);
        } else {
            return -1;
        }
    } else {
        return -1;
    }
}