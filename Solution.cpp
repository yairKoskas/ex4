#include <string>
#include <iterator>

#include "Solution.hpp"

std::list<State> Solution::getVertexes() const{
    return this->vertexes;
}

std::string Solution::getWayThrowGraph() const{
    std::string buffer;
    for(auto it = vertexes.begin(); next(it,1) != vertexes.end(); ++it){
        buffer += ",";
        //check what is the next step of the algorithem
        //and write it to the buffer
        if(it->getRow() > next(it,1)->getRow()){  
            buffer += "Up";
        }
        if(it->getRow() < next(it,1)->getRow()){
            buffer += "Down";
        }
        if(it->getCol() > next(it,1)->getCol()){
            buffer += "Left";
        }
        if(it->getCol() < next(it,1)->getCol()){
            buffer += "Right";
        }
    }
    //buffer is something like ",Left,Down,Up,Up,Lest,Right"
    //it contains the step of the algorithem
    return buffer;
}
uint32_t Solution::getNumberOfVertexesInWay() const{
    return vertexes.size();
}