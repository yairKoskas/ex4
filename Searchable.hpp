#pragma once

#include <list>

#include "State.hpp"

class Searchable
{
    public:
        virtual State getInitialState() const;
        virtual State getGoalState() const;
        virtual std::List<State> getAllPossibleStates(const State& s) const;
};
