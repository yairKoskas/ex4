#include "MyClientHandler.hpp"
#include <unistd.h>
#include <iostream>
#include <sys/socket.h>
#include <sys/types.h>
#include <string>
#include <system_error>
#include <errno.h>
#include <stack>
#include "Matrix.hpp"
#include "DFS.hpp"
#include "Graph.hpp"
#include "BestFS.hpp"
#include "BFS.hpp"
#define THROW_SYSTEM_ERROR() \
    throw std::system_error { errno, std::system_category() }


void MyClientHandler::handleClient(int clientSock) {
    std::string version = "1.0";
    int statusCode = 0;
    int responseLength = 0;
    std::string path = "";

    std::string getProblemAndAlg(1024,'\0');
    auto numBytesRead = read(clientSock, (void*)getProblemAndAlg.data(), getProblemAndAlg.size() - 1);
    if(numBytesRead < 0) {
        close(clientSock);
        THROW_SYSTEM_ERROR();
    }
    //we know the sentence is going to be "solve find-graph-path <alg>"
    //so we eliminate the "solve find-graph-path " part which leaves us with the <alg> part
    getProblemAndAlg = getProblemAndAlg.substr(getProblemAndAlg.find_first_of(' ')+1,getProblemAndAlg.size());
    getProblemAndAlg = getProblemAndAlg.substr(getProblemAndAlg.find_first_of(' ')+1,getProblemAndAlg.size());
    std::string algorithm = getProblemAndAlg;
    

    algorithm = algorithm.substr(0,algorithm.find_first_of('\0'));

    std::string toWrite = "Version: "+ version +
    "\nstatus: " + std::to_string(statusCode) + 
    "\nresponse length: " + std::to_string(responseLength) + 
    "\n" + path + "\n\n";
    if(0 > write(clientSock, toWrite.data(), toWrite.size())) {
        close(clientSock);
        THROW_SYSTEM_ERROR();
    }
    
    std::string buffer(1024, '\0');
    numBytesRead = read(clientSock, (void*)buffer.data(), buffer.size() - 1);
    if(numBytesRead < 0) {
        close(clientSock);
        THROW_SYSTEM_ERROR();
    }
    int index = buffer.find_first_of(',');
    uint32_t height = std::stoi(buffer.substr(0,index));
    uint32_t width = std::stoi(buffer.substr(index+1,buffer.size()));

    int nextInfo = buffer.find_first_of("\r\n");
    buffer = buffer.substr(nextInfo+1,buffer.size());

    auto mat = Matrix(height,width);
    try {
        for(uint32_t i=0;i<height;i++) {
            int line = buffer.find_first_of("\r\n");
            auto valuesBuffer = buffer.substr(0,line);
            for(uint32_t j=0;j<width;j++) {
                int indexComma = valuesBuffer.find_first_of(',');
                double value = std::stod(valuesBuffer.substr(0,indexComma));
                valuesBuffer = valuesBuffer.substr(indexComma+1,valuesBuffer.size());
                mat.set(i,j,value);
            }
            int indexLine = buffer.find_first_of("\r\n");
            buffer = buffer.substr(indexLine+1,buffer.size());
        }
    } catch (...) {
        //the client's input for the matrix was bad
        statusCode = 1;
    }
    Graph g = Graph(mat);

    int indexOfInitState = buffer.find_first_of(',');
    uint32_t i = std::stoi(buffer.substr(0,indexOfInitState));
    uint32_t j = std::stoi(buffer.substr(indexOfInitState+1,buffer.size()));
    Node* init = g.getNode(i,j);
    if(i >= height || j >= width) {
        //if the index' of the states were wrong
        statusCode = 2;
    }

    index = buffer.find_first_of("\r\n");
    buffer = buffer.substr(index+1,buffer.size());
    indexOfInitState = buffer.find_first_of(',');
    i = std::stoi(buffer.substr(0,indexOfInitState));
    j = std::stoi(buffer.substr(indexOfInitState+1,buffer.size()));
    Node* goal = g.getNode(i,j);
    if(i >= height || j >= width) {
        //if the index' of the states were wrong
        statusCode = 2;
    }
    toWrite = "Version: "+ version +
    "\nstatus: " + std::to_string(statusCode) + 
    "\nresponse length: " + std::to_string(responseLength) + 
    "\n" + path + "\n\n";
    if(0 > write(clientSock, toWrite.data(), toWrite.size())) {
        close(clientSock);
        THROW_SYSTEM_ERROR();
    }

    if(algorithm == "A*") {

    } else if(algorithm == "BestFS") {

    } else if(algorithm == "DFS") {
        DFS s = DFS();
        path = s.getOutString(&g,init,goal);
        responseLength = path.size();
    } else if(algorithm == "BFS") {
        BFS s = BFS();
        path = s.getOutString(&g,init,goal);
        responseLength = path.size();
    } else if(algorithm == ""){
        
    }else{
        //unknown algorithm
        statusCode = 3;
    }
    toWrite = "Version: "+ version +
    "\nstatus: " + std::to_string(statusCode) + 
    "\nresponse length: " + std::to_string(responseLength) + 
    "\n" + path + "\n\n";
    if(0 > write(clientSock, toWrite.data(), toWrite.size())) {
        close(clientSock);
        THROW_SYSTEM_ERROR();
    }
    return;
}