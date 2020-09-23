#pragma once

#include <bits/stdc++.h>
#include <vector>
#include <unordered_set>
#include <stdint.h>
#include <queue>

#include "Searcher.hpp"
#include "Searchable.hpp"
#include "State.hpp"
#include "Solution.hpp"

class BestFS : public Searcher{
private:
    std::priority_queue <State, std::vector<State>, MyComparator> pq;
    //closed will save the verteses we allready visited them
    std::set<State> closed;
    uint32_t evaluateNodes = 0;

    //return a list of the States in the solution of the algorithem
    Solution backTrace();

public:
    //the search method
    Solution search(Searchable searchable) override;
    //the vertex you can go to from the current vertex
    uint32_t getNumberOfNodesEvaluated() const override;
    //which algorithem was used
    std::string getAlgorthemType() const override;
    virtual ~BestFS() = default;

};