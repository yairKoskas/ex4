#pragma once

class State {
    private:
        int row;    //row inthe matrix
        int col;    //col in the matrix
        double cost;    //cost to reach this state
        State *cameFrom;   //the state we came from to this state

    public:
        State(int row, int col);
        bool Equals(const State& other) const;
        int getRow() const;
        int getCol() const;
        double getCost() const;
        State* lastStateBeforeCurrent() const;
};