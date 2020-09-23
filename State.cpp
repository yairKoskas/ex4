#include <stdint.h>

#include "State.hpp"

State::State(int i, int j, double c, const State* s) : row(i), col(j), cost(c), cameFrom(s) {
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

const State* State::lastStateBeforeCurrent() const{
    return this->cameFrom;
}

State& State::operator=(const State& other) {
    State state = State(other.getRow(), other.getCol(), other.getCost(), other.lastStateBeforeCurrent());
    return state;
}


uint32_t MyComparator::operator() (const State& s1, const State& s2){
        return s1.getCost() > s2.getCost();
}