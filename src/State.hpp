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
    bool equals(const State& other) const;
    bool notEquals(const State& other) const;
    uint32_t getRow() const;
    uint32_t getCol() const;
    double getCost() const;
    State* lastStateBeforeCurrent() const;
    bool operator==(const State& s) const;
    bool operator!=(const State& s) const;
    bool operator<(const State& other) const;
};
//compare to States according to their cost
struct MyComparator {
public:
    bool operator() (const State& s1, const State& s2) const;
};

struct MySetComparator {
public:
    bool operator() (const State& s1, const State& s2) const;
};