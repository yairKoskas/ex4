#pragma once

#include <stdint.h>
#include <list>

#include "Searcher.hpp"
#include "Searchable.hpp"
#include "State.hpp"
#include "Solution.hpp"

class DFS : public Searcher{
private:
    std::list<State> stack;
    std::list<State> visited;
    uint32_t evaluateNodes = 0;

    //return a list of the States in the solution of the algorithem
    Solution backTrace(const State& state) const;

public:
    DFS();
    //the search method
    Solution search(Searchable& searchable) override;
    //the vertex you can go to from the current vertex
    uint32_t getNumberOfNodesEvaluated() const override;
    //which algorithem was used
    std::string getAlgorthemType() const override;
    ~DFS();
};