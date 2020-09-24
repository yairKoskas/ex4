#pragma once

#include <stdint.h>

#include <list>
#include <string>

#include "State.hpp"
#include "Searchable.hpp"
#include "Solution.hpp"

class Searcher
{
    public:
        //the search method
        virtual Solution search(Searchable& searchable) = 0;
        //the vertex you can go to from the current vertex
        virtual uint32_t getNumberOfNodesEvaluated() const = 0;
        //which algorithem was used
        virtual std::string getAlgorthemType() const = 0;
        virtual ~Searcher() = default;
        
};