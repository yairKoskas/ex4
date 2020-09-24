#pragma once

#include <list>
#include <stdint.h>
#include <string>

#include "State.hpp"

class Solution {
private:
    std::list<State> vertexes;
public:
    std::list<State> getVertexes() const;
    //return a string of the steps the solution
    std::string getWayThrowGraph() const;
    uint32_t getNumberOfVertexesInWay() const;
};