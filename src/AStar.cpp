
#include <string>
#include <list>
#include <iterator>

#include "AStar.hpp"

Solution AStar::search (Searchable& searchable) {
    State state = State(searchable.getInitialState().getRow(), searchable.getInitialState().getCol(), 0,  nullptr);
    pq.push(state);

    while(!this->pq.empty()){
        //pull the first state in the queue and add it to closed-set
        State st = pq.top();
        pq.pop();
        this->evaluateNodes++;
        //the check if States are equals is only according to their place in th graph
        //and not according to the cost
        closed.insert(st);
        //check if we arrive to the goal state
        if(st == (searchable.getGoalState())){
            return backTrace();
        }
        //get all the evaluate states from the current state
        std::list<State> succerssors = searchable.getAllPossibleStates(st);
        for (auto it = succerssors.begin(); it != succerssors.end(); ++it){

            State temp = State((*it).getRow(), (*it).getCol(), (*it).getCost() + heuristics(*(it), searchable), (*it).lastStateBeforeCurrent());

            //true if the state in the set, false if not
            const bool is_in_closed = ((closed.find(temp)) != (closed.end()));
            if(!is_in_closed){
                pq.push(temp);
            }
        }
    }
    //can not reach here
    Solution solu;
    return solu;
}

double AStar::heuristics(const State& state, const Searchable& searchable) const {
    //the graph is a matrix, so the distance between the current state and the goal state is at least the sum of their distances at axis x and axis y
    return (abs(state.getRow() - searchable.getGoalState().getRow()) + abs(state.getCol() - searchable.getGoalState().getCol()));
}

Solution AStar::backTrace() {
    Solution solu;
    //we know that closed is not empty because it has at least the initState
    while(true){
        solu.getVertexes().push_front(*(closed.end()));
        closed.erase(closed.end());
        //remove States from closed until the top is the State that we came from
        //him to the current State
        if(closed.empty()){
            return solu;
        }
        while(!((*(closed.end())) == (*(*(solu.getVertexes().begin())).lastStateBeforeCurrent()))){
            closed.erase(closed.end());
        }
    }
    //can not reach here
    return solu;
}



uint32_t AStar::getNumberOfNodesEvaluated() const{
    return this->evaluateNodes;
}

std::string AStar::getAlgorthemType() const{
    return "BestFS";
}