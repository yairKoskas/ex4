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
        virtual Solution search(Searchable searchable) const;
        //the vertex you can go to from the current vertex
        virtual uint32_t getNumberOfNodesEvaluated() const;
        //which algorithem was used
        virtual std::string getAlgorthemType() const;
        
};