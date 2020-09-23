#include <stdint.h>

#include "Solver.hpp"
#include "Searchable.hpp"
#include "Searcher.hpp"

void GraphSolver::solve(Searcher searcher, Searchale searchable){
    solution = searcher.search(searchable);
    numberOfEvaluateVertex = searcher.getNumberOfNodesEvaluate();
    outString = std::to_string(solution.getNumberOfVertexesInWay())
                 + searcher.getAlgorthemType()
                 + solution.getWayThrowGraph();
}
