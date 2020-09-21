#include "State.hpp"

State::State(int i, int j){
    this->row = i;
    this->col = j;
}

bool State::Equals(const State& other) const{
    return this->row == other.row && this->col == other.col;
}

int State::getRow() const{
    return this->row;
}

int State::getCol() const{
    return this->col;
}

double State::getCost() const{
    return this->cost;
}

State* State::lastStateBeforeCurrent() const{
    return this->cameFrom;
}