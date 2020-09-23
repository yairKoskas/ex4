#include <stdint.h>
#include <string>

#include "Solver.hpp"
#include "Searchable.hpp"
#include "Searcher.hpp"
#include "Solution.hpp"

void GraphSolver::solve(Searcher searcher, Searchale searchable){
    solution = searcher.search(searchable);
    numberOfEvaluateVertex = searcher.getNumberOfNodesEvaluate();
    outString = std::to_string(solution.getNumberOfVertexesInWay())
                 + searcher.getAlgorthemType()
                 + solution.getWayThrowGraph();
}

std::string GraphSolver::getOutString(){
    return outString;
}
