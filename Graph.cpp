#include "Graph.hpp"
#include "Matrix.hpp"
#include "State.hpp"
#include <list>


Graph::Graph(const Matrix& other, const State& initState, const State& goalState){
    //what is the right line from the three below?
    //Matrix::Matrix(this->matrix, other);
    //(this->matrix).Matrix(other);
    //(this->matrix) = other;
    this->initState = initState;
    this->goalState = goalState;
}

Graph::getInitialState() const override{
    return this->initState;
}

Graph::getGoalState() const override{
    return this->goalState;
}

Graph::getAllPossibleStates(const State& s) const override{
    std::list<State> allPossibeStates;
    if(s.getRow() > 0){
        allPossibeStates.push_back(new State(s.getRow() - 1, s.getCol()));
    }
    if(s.getRow() < (this->matrix).getHeight()){
        allPossibeStates.push_back(new State(s.getRow() + 1, s.getCol()));
    }
    if(s.getCol() > 0){
        allPossibeStates.push_back(new State(s.getRow(), s.getCol() - 1));
    }
    if(s.getCol() < (this->matrix).getWidth()){
        allPossibeStates.push_back(new State(s.getRow(), s.getCol() + 1));
    }
    return allPossibeStates;
}