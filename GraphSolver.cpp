#include <stdint.h>
#include <string>

#include "Solver.hpp"
#include "Searchable.hpp"
#include "Searcher.hpp"
#include "Solution.hpp"
#include "GraphSolver.hpp"

void GraphSolver::solve(Searcher searcher, Searchable searchable){
    solution = searcher.search(searchable);
    numberOfEvaluateVertex = searcher.getNumberOfNodesEvaluated();
    outString = std::to_string(solution.getNumberOfVertexesInWay())
                 + searcher.getAlgorthemType()
                 + solution.getWayThrowGraph();
}

std::string GraphSolver::getOutString() const{
    return outString;
}
