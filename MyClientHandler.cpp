#include "MyClientHandler.hpp"
#include <unistd.h>
#include <iostream>
#include <sys/socket.h>
#include <sys/types.h>
#include <string>
#include <system_error>
#include <errno.h>
#include "State.hpp"
#include "Graph.hpp"
#include "Matrix.hpp"
#include "GraphSolver.hpp"
#include "AStar.hpp"
#include "BestFS.hpp"
#include "BFS.hpp"
#include "DFS.hpp"
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

    std::string toWrite = "Version: "+ version +
    "\r\nstatus: " + std::to_string(statusCode) + 
    "\r\nresponse length: " + std::to_string(responseLength) + 
    "\r\n" + path + "\r\n\r\n";
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
    int height = std::stoi(buffer.substr(0,index));
    int width = std::stoi(buffer.substr(index+1,buffer.size()));

    int nextInfo = buffer.find_first_of('\n');
    buffer = buffer.substr(nextInfo+1,buffer.size());

    auto mat = Matrix(height,width);
    try {
        for(uint32_t i=0;i<height;i++) {
            int line = buffer.find_first_of('\n');
            auto valuesBuffer = buffer.substr(0,line);
            for(uint32_t j=0;j<width;j++) {
                int index = valuesBuffer.find_first_of(',');
                double value = std::stod(valuesBuffer.substr(0,index));
                valuesBuffer = valuesBuffer.substr(index+1,valuesBuffer.size());
                mat.set(i,j,value);
                
            }
            int index = buffer.find_first_of('\n');
            buffer = buffer.substr(index+1,buffer.size());
        }
    } catch (...) {
        //the client's input for the matrix was bad
        statusCode = 1;
    }
            
    int indexOfInitState = buffer.find_first_of(',');
    int i = std::stoi(buffer.substr(0,indexOfInitState));
    int j = std::stoi(buffer.substr(indexOfInitState+1,buffer.size()));
    State init = State(i,j,mat(i,j),nullptr);
    if(i >= height || j >= width || i < 0 || j < 0) {
        //if the index' of the states were wrong
        statusCode = 2;
    }

    index = buffer.find_first_of('\n');
    buffer = buffer.substr(index+1,buffer.size());
    indexOfInitState = buffer.find_first_of(',');
    i = std::stoi(buffer.substr(0,indexOfInitState));
    j = std::stoi(buffer.substr(indexOfInitState+1,buffer.size()));
    if(i >= height || j >= width || i < 0 || j < 0) {
        //if the index' of the states were wrong
        statusCode = 2;
    }
    State goal = State(i,j,mat(i,j),nullptr);
    Graph g = Graph(mat,init,goal);

    toWrite = "Version: "+ version +
    "\r\nstatus: " + std::to_string(statusCode) + 
    "\r\nresponse length: " + std::to_string(responseLength) + 
    "\r\n" + path + "\r\n\r\n";
    if(0 > write(clientSock, toWrite.data(), toWrite.size())) {
        close(clientSock);
        THROW_SYSTEM_ERROR();
    }

    GraphSolver gS = GraphSolver();
    if(algorithm == "A*") {
        AStar alg = AStar();
        gS.solve(alg,g);
        path = gS.getOutString();
    } else if(algorithm == "BestFS") {
        BestFS alg = BestFS();
        gS.solve(alg,g);
        path = gS.getOutString();
    } else if(algorithm == "DFS") {
        DFS alg = DFS();
        gS.solve(alg,g);
        path = gS.getOutString();
    } else if(algorithm == "BFS") {
        BFS alg = BFS();
        gS.solve(alg,g);
        path = gS.getOutString();
    } else {
        //unknown algorithm
        statusCode = 3;
    }
    toWrite = "Version: "+ version +
    "\r\nstatus: " + std::to_string(statusCode) + 
    "\r\nresponse length: " + std::to_string(responseLength) + 
    "\r\n" + path + "\r\n\r\n";
    if(0 > write(clientSock, toWrite.data(), toWrite.size())) {
        close(clientSock);
        THROW_SYSTEM_ERROR();
    }
    return;
}