

#include <iostream>
#include <string>

#include "Graph.hpp"
#include "Matrix.hpp"
#include "State.hpp"
#include "Searchable.hpp"
#include "Searcher.hpp"
#include "GraphSolver.hpp"
#include "Solver.hpp"

int  main(){
    Matrix MyMatrix = Matrix(3, 3);
    MyMatrix.set(0,0,1);
    MyMatrix.set(0,1,2);
    MyMatrix.set(0,1,5);
    MyMatrix.set(1,0,4);
    MyMatrix.set(1,1,3);
    MyMatrix.set(1,2,6);
    MyMatrix.set(2,0,7);
    MyMatrix.set(2,1,8);
    MyMatrix.set(2,2,9);

    State init = State(0, 0, 0.0, nullptr);
    State goal = State(2, 2, 0.0, nullptr);

    Searchable MyGraph = Graph(MyMatrix, init, goal);

    Searcher MyAlgo;

    GraphSolver graphSolver = GraphSolver();
    graphSolver.solve(MyAlgo, MyGraph);
    std::cout << graphSolver.getOutString() << std::endl;

    return 0;
}
