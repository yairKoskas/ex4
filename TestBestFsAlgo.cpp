
#include <iostream>
#include <string>

#include "Graph.hpp"
#include "Matrix.hpp"
#include "State.hpp"
#include "Searchable.hpp"
#include "Searcher.hpp"
#include "GraphSolver.hpp"
#include "Solver.hpp"
#include "BestFS.hpp"

#include <iostream>

#

int  main(){

    std::cout << "main debug1" << std::endl;
    Matrix MyMatrix = Matrix(3, 3);
    std::cout << "main debug2" << std::endl;
    MyMatrix.set(0,0,1);
    std::cout << "main debug3" << std::endl;
    MyMatrix.set(0,1,2);
    MyMatrix.set(0,2,5);
    MyMatrix.set(1,0,4);
    MyMatrix.set(1,1,3);
    MyMatrix.set(1,2,6);
    MyMatrix.set(2,0,7);
    MyMatrix.set(2,1,8);
    MyMatrix.set(2,2,9);

    std::cout << "main debug4" << std::endl;

    State init = State(0, 0, 0.0, nullptr);
    State goal = State(2, 2, 0.0, nullptr);

    std::cout << "main debug5" << std::endl;

    Graph MyGraph = Graph(MyMatrix, init, goal);

    std::cout << "main debug6" << std::endl;

    BestFS MyAlgo;

    std::cout << "main debug7" << std::endl;

    GraphSolver graphSolver = GraphSolver();
    
    std::cout << "main debug8" << std::endl;

    graphSolver.solve(MyAlgo, MyGraph);
    
    std::cout << "main debug9" << std::endl;

    std::cout << graphSolver.getOutString() << std::endl;
    
    std::cout << "main debug10" << std::endl;

    return 0;
}
