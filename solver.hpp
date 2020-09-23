#pragma once

#include "Searchable.hpp"
#include "Searcher.hpp"

class Solver {
public:
    //searcherable is the problem and searcher is the algorithem to solve it
    virtual void solve(Searcher algo, Searchable prob);
}