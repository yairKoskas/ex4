#include <string>

#include "MessageException.hpp"
#include "Matrix.hpp" 

#include "Searchable.hpp"
#include "Searcher.hpp"
#include "Solver.hpp"

#include "State.hpp" 
#include "Solution.hpp"
#include "GraphSolver.hpp"
#include "Graph.hpp" 

#include "DFS.hpp" 
#include "BFS.hpp" 
#include "BestFS.hpp" 
#include "AStar.hpp"

#include <iostream>

int main(void) {

    std::cout << "TestAlgo main debug1" << std::endl;
    Matrix matrix = Matrix(3,3);
        std::cout << "TestAlgo main debug2" << std::endl;

    matrix.set(0,0,1);
        std::cout << "TestAlgo main debug3" << std::endl;

    matrix.set(0,1,2);
    matrix.set(0,2,3);
    matrix.set(1,0,4);
    matrix.set(1,1,5);
    matrix.set(1,2,6);
    matrix.set(2,0,7);
    matrix.set(2,1,8);
    matrix.set(2,2,9);

    State s1 = State(0,0,1.0, nullptr);
    State s2 = State(2,2,9.0, nullptr);
        std::cout << "TestAlgo main debug4" << std::endl;


    Graph graph = Graph(matrix, s1, s2);
        std::cout << "TestAlgo main debug5" << std::endl;


    DFS MyAlgo = DFS();
        std::cout << "TestAlgo main debug6" << std::endl;


    GraphSolver gs = GraphSolver();
        std::cout << "TestAlgo main debug7" << std::endl;


    gs.solve(MyAlgo, graph);
        std::cout << "TestAlgo main debug8" << std::endl;


    std::cout << gs.getOutString() << std::endl;
        std::cout << "TestAlgo main debug9" << std::endl;


    return 0;
}
