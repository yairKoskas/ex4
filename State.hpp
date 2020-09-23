#pragma once

#include <stdint.h>

class State {
private:
    uint32_t row;    //row inthe matrix
    uint32_t col;    //col in the matrix
    double cost;    //cost to reach this state
    State *cameFrom;   //the state we came from to this state

public:
    State(uint32_t row, uint32_t col, double cost, State* state);
    bool Equals(const State& other) const;
    uint32_t getRow() const;
    uint32_t getCol() const;
    double getCost() const;
    State* lastStateBeforeCurrent() const;
    bool operator==(const State& s) const;
    bool operator!=(const State& s) const;
    bool operator<(const State& other) const;
};
//compare to States according to their cost
class MyComparator {
public:
    uint32_t operator() (State& s1, State& s2) const;
};