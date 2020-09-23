#pragma once

#include <stdint.h>
#include <string>

#include "Searcher.hpp"
#include "Searchable.hpp"
#include "Solution.hpp"
#include "Solver.hpp"

class GraphSolver: public Solver{
private:
    Solution solution;
    uint32_t numberOfEvaluateVertex = 0;
    std::string outString;

public:
    //solve a problem with an algorithem and print the output
    void solve(Searcher searcher, Searchable searchable) override;
    std::string getOutString() const;
};