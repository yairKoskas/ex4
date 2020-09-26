
#include <string>
#include <list>
#include <iterator>

#include "BestFS.hpp"

Solution BestFS::search (Searchable& searchable) {
    if(searchable.getInitialState() == searchable.getGoalState()){
        Solution solution;
        solution.getVertexes().push_back(searchable.getInitialState());
        return solution;
    }

    State state = State(searchable.getInitialState().getRow(), searchable.getInitialState().getCol(), searchable.getInitialState().getCost(),  nullptr);
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
        if(st.equals(searchable.getGoalState())){
            return backTrace(st);
        }
        //get all the evaluate states from the current state
        std::list<State> succerssors = searchable.getAllPossibleStates(st);

        for (auto it = succerssors.begin(); it != succerssors.end(); ++it){
            //true if the state in the set, false if not
            const bool is_in_closed = ((closed.find(*it)) != (closed.end()));
            if(!is_in_closed){
                pq.push(*it);
            }
        }
    }
    //can not reach here
    Solution solu;
    return solu;
}

Solution BestFS::backTrace(const State& state) {
    Solution solu;
    std::set<State>::iterator it;

    solu.getVertexes().push_back(state);

    //we know that closed is not empty because it has at least the initState
    while(true){

        it = closed.find(*(*(solu.getVertexes().end())).lastStateBeforeCurrent());
        ++it;
        closed.erase(it, closed.end());
        
        it = closed.end();
        --it;
        solu.getVertexes().push_back(*it);
        closed.erase(it);

        if(closed.empty()){
            return solu;
        }
    }
    //can not reach here
    return solu;
}



uint32_t BestFS::getNumberOfNodesEvaluated() const{
    return this->evaluateNodes;
}

std::string BestFS::getAlgorthemType() const{
    return "BestFS";
}