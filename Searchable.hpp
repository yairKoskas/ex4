#pragma once

#include <list>

#include "State.hpp"

class Searchable
{
    public:
        virtual State getInitialState() const;
        virtual State getGoalState() const;
        //return a list of all the evaluate states from the current state
        virtual std::list<State> getAllPossibleStates(const State& s) const;
};
