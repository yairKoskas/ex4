#pragma once

#include <stdint.h>

class State {
    private:
        const int row;    //row inthe matrix
        const int col;    //col in the matrix
        const double cost;    //cost to reach this state
        const State *cameFrom;   //the state we came from to this state

    public:
        State(const int row, const int col, const double cost, const State* state);
        bool Equals(const State& other) const;
        int getRow() const;
        int getCol() const;
        double getCost() const;
        const State* lastStateBeforeCurrent() const;
<<<<<<< HEAD
        //State& operator=(const State& other);
=======
        State& operator=(const State& other) noexcept;
>>>>>>> clientHandler_develop

};

//compare to States according to their cost
class MyComparator {
<<<<<<< HEAD
public:
    uint32_t operator() (const State& s1, const State& s2);
=======
    public:
        int operator() (const State& s1, const State& s2);
>>>>>>> clientHandler_develop
};