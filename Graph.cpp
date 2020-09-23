#include "Graph.hpp"
#include "Matrix.hpp"
#include "State.hpp"
#include <list>


Graph::Graph(const Matrix& other, const State& initS, const State& goalS): matrix(other) ,initState(initS), goalState(goalS) {
}

State Graph::getInitialState() const {
    return this->initState;
}

State Graph::getGoalState() const {
    return this->goalState;
}

std::list<State> Graph::getAllPossibleStates(const State& s) const {
    std::list<State> allPossibeStates;
    if(s.getRow() > 0){
        State state = State(s.getRow() - 1, s.getCol(), s.getCost() + this->matrix(s.getRow() - 1, s.getCol()), &s);
        allPossibeStates.push_back(state);
    }
    if(s.getRow() < (this->matrix).getHeight()){
        State state = State(s.getRow() + 1, s.getCol(), s.getCost() + this->matrix(s.getRow() + 1, s.getCol()), &s);
        allPossibeStates.push_back(state);
    }
    if(s.getCol() > 0){
        State state = State(s.getRow(), s.getCol() - 1, s.getCost() + this->matrix(s.getRow(), s.getCol() - 1), &s);
        allPossibeStates.push_back(state);
    }
    if(s.getCol() < (this->matrix).getWidth()){
        State state = State(s.getRow(), s.getCol() + 1, s.getCost() + this->matrix(s.getRow(), s.getCol() + 1), &s);
        allPossibeStates.push_back(state);
    }
    return allPossibeStates;
}