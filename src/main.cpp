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
    std::cout << argc << argv << std::endl;
    //  if(argc == 2){
    //      int port = std::stoi(argv[1]);
    //      MyParallelServer s = MyParallelServer();
    //      MyClientHandler ch = MyClientHandler();
    //      s.open(port,ch);
    //      std::cout << "hello" << std::endl;
    //  }else if(argc == 3) {
    //      if(strcmp(argv[2],"serial") == 0) {
    //          int port = std::stoi(argv[1]);
    //          MySerialServer s = MySerialServer();
    //          MyClientHandler ch = MyClientHandler();
    //          s.open(port,ch);
    //      }else if(strcmp(argv[2],"parallel") == 0) {
    //          int port = std::stoi(argv[1]);
    //          MyParallelServer s = MyParallelServer();
    //          MyClientHandler ch = MyClientHandler();
    //          s.open(port,ch);
    //      }else{
    //          return -1;
    //      }
    //  }else {
    //      return -1;
    // }
    // for(int i=0;i<500;++i) {
    //     int size = (rand()%495) + 5;
    //     Matrix mat = genRandomMatrix(size);
    //     Graph g = Graph(mat);
    // }
    Matrix x = Matrix(5,5);
    for(int i=0;i<5;i++){
        for(int j=0;j<5;j++){
            x.set(i,j,i);
        }
    }
    Graph g = Graph(x);
    Node init = Node(0,0,0,0,x(0,0));
    Node goal = Node(4,2,0,0,x(4,2));
    AStar s = AStar();
    std::string path = s.getOutString(&g,&init,&goal);
    std::cout << path << std::endl;
}