#include "Graph.hpp"
#include "Matrix.hpp"
#include <list>
#include  <iostream>


Graph::Graph(const Matrix& other, const State& initS, const State& goalS): matrix(other) ,initState(initS), goalState(goalS) {
}

State Graph::getInitialState() const {
    return this->initState;
}

State Graph::getGoalState() const {
    return this->goalState;
}

std::list<State> Graph::getAllPossibleStates(State& s) const {

    std::cout << "Graph getAllPossibleStates debug1" << std::endl;

    std::list<State> allPossibeStates;
    if(s.getRow() > 0){
        std::cout << "Graph getAllPossibleStates debug2" << std::endl;

        State state = State(s.getRow() - 1, s.getCol(), s.getCost() + this->matrix(s.getRow() - 1, s.getCol()), &s);
        allPossibeStates.push_back(state);

        std::cout << "Graph getAllPossibleStates debug3" << std::endl;
    }
    if(s.getRow() < (this->matrix).getHeight() - 1){
        std::cout << "Graph getAllPossibleStates debug4" << std::endl;

        State state = State(s.getRow() + 1, s.getCol(), s.getCost() + this->matrix(s.getRow() + 1, s.getCol()), &s);
        allPossibeStates.push_back(state);

        std::cout << "Graph getAllPossibleStates debug5" << std::endl;
    }
    if(s.getCol() > 0){
        std::cout << "Graph getAllPossibleStates debug6" << std::endl;

        State state = State(s.getRow(), s.getCol() - 1, s.getCost() + this->matrix(s.getRow(), s.getCol() - 1), &s);
        allPossibeStates.push_back(state);

        std::cout << "Graph getAllPossibleStates debug7" << std::endl;

    }
    if(s.getCol() < (this->matrix).getWidth() - 1){
        std::cout << "Graph getAllPossibleStates debug8" << std::endl;

        State state = State(s.getRow(), s.getCol() + 1, s.getCost() + this->matrix(s.getRow(), s.getCol() + 1), &s);

        std::cout << "Graph getAllPossibleStates debug12" << std::endl;

        allPossibeStates.push_back(state);

        std::cout << "Graph getAllPossibleStates debug10" << std::endl;

    }
    std::cout << "Graph getAllPossibleStates debug11" << std::endl;
    return allPossibeStates;
}