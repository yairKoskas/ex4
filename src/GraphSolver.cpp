#include <stdint.h>
#include <string>
#include "GraphSolver.hpp"
#include "Solver.hpp"
#include "Searchable.hpp"
#include "Searcher.hpp"
#include "Solution.hpp"

void GraphSolver::solve(Searcher& searcher, Searchable& searchable){
<<<<<<< HEAD:GraphSolver.cpp

    solution = searcher.search(searchable);

    numberOfEvaluateVertex = searcher.getNumberOfNodesEvaluated();
    
    outString = std::to_string(solution.getNumberOfVertexesInWay())
                 + ',' + searcher.getAlgorthemType()
                 + ',' + solution.getWayThrowGraph();
=======
    solution = searcher.search(searchable);
    numberOfEvaluateVertex = searcher.getNumberOfNodesEvaluated();
    outString = std::to_string(solution.getNumberOfVertexesInWay())
                 + searcher.getAlgorthemType()
                 + solution.getWayThrowGraph();
>>>>>>> f6bf8785d96181ff8ed44160eacf4c799a069289:src/GraphSolver.cpp
}

std::string GraphSolver::getOutString() const{
    return outString;
}
