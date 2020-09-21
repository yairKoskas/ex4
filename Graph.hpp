#pragma once

#include "Matrix.hpp"
#include "State.hpp"


class Graph: public Searchable{

private:

    const Matrix matrix;
    const State initState;
    const State goalState;

public:
    Graph(const Matrix& other, const State& initState, const State& goalState);
};
