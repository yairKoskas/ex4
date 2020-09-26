#include <stdint.h>
#include <string>
#include "GraphSolver.hpp"
#include "Solver.hpp"
#include "Searchable.hpp"
#include "Searcher.hpp"
#include "Solution.hpp"

#include <iostream>

void GraphSolver::solve(Searcher& searcher, Searchable& searchable){

        std::cout << "GraphSolver solve debug1" << std::endl;

    solution = searcher.search(searchable);
            std::cout << "GraphSolver solve debug2" << std::endl;


    numberOfEvaluateVertex = searcher.getNumberOfNodesEvaluated();
            std::cout << "GraphSolver solve debug3" << std::endl;

    
    outString = std::to_string(solution.getNumberOfVertexesInWay())
                 + ',' + searcher.getAlgorthemType()
                 + ',' + solution.getWayThrowGraph();

            std::cout << "GraphSolver solve debug4" << std::endl;

}

std::string GraphSolver::getOutString() const{
    return outString;
}
