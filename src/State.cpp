#include <stdint.h>

#include "State.hpp"

#include <iostream>

State::State(uint32_t i, uint32_t j, double c, State* s){
    this->row = i;
    this->col = j;
    this->cost = c;
    this->cameFrom = s;
}

bool State::equals(const State& other) const{
            std::cout << "State equals debug1" << std::endl;

    return this->row == other.row && this->col == other.col;
}

bool State::notEquals(const State& other) const{
            std::cout << "State equals debug1" << std::endl;

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
        std::cout << "State lastStateBeforeCurrent debug1" << std::endl;
    return this->cameFrom;
}

bool State::operator==(const State& s) const{
        std::cout << "State operator== debug1" << std::endl;

    return this->equals(s);
}

bool State::operator!=(const State& s) const{
        std::cout << "State operator!= debug1" << std::endl;

    return !(this->operator==(s));
}

bool State::operator<(const State& other) const{
    return this->getCost() < other.getCost();
}


bool MyComparator::operator() (const State& s1, const State& s2) const{
        return s1.getCost() > s2.getCost();
}

bool MySetComparator::operator() (const State& s1, const State& s2) const{
        return !(s1 == s2);
}