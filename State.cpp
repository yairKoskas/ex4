#include <stdint.h>

#include "State.hpp"

State::State(uint32_t i, uint32_t j, double c, State* s){
    this->row = i;
    this->col = j;
    this->cost = c;
    this->cameFrom = s;
}

bool State::Equals(const State& other) const{
    return this->row == other.row && this->col == other.col;
}

uint32_t State::getRow() const{
    return this->row;
}

uint32_t State::getCol() const{
    return this->col;
}

double State::getCost() const{
    return this->cost;
}

State* State::lastStateBeforeCurrent() const{
    return this->cameFrom;
}

bool State::operator==(const State& s) const{
    return this->Equals(s);
}

bool State::operator!=(const State& s) const{
    return !(this->operator==(s));
}

bool State::operator<(const State& other) const{
    return this->getCost() < other.getCost();
}


uint32_t MyComparator::operator() (State& s1, State& s2) const{
        return s1.getCost() > s2.getCost();
}