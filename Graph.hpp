#pragma once

#include "Matrix.hpp"
#include "State.hpp"
#include "Searchable.hpp"


class Graph: public Searchable{

private:

    const Matrix matrix;
    const State initState;
    const State goalState;

public:
    Graph(const Matrix& other, const State& initState, const State& goalState);
    State getInitialState() const override;
    State getGoalState() const override;
    std::list<State> getAllPossibleStates(State& s) const override;
    //~Graph();
};
