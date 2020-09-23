//#include <vector>
//#include <bits/stdc++.h>
//#include <unordered_set>
#include <string>
#include <list>
#include <iterator>
//#include <queue>
//#include <stdint.h>


#include "BestFS.hpp"
// #include "State.hpp"
// #include "Searchable.hpp"
// #include "Solution.hpp"

Solution BestFS::search (Searchable searchable) {
    State state = State(searchable.getInitialState().getRow(), searchable.getInitialState().getCol(), 0,  nullptr);
    pq.push(state);

    while(!this->pq.empty()){
        //pull the first state in the queue and add it to closed-set
        State st = pq.top();
        pq.pop();
        evaluateNodes++;
        //the check if States are equals is only according to their place in th graph
        //and not according to the cost
        closed.insert(st);
        //check if we arrive to the goal state
        if(st.Equals(searchable.getGoalState())){
            return backTrace();
        }
        //get all the evaluate states from the current state
        std::list<State> succerssors = searchable.getAllPossibleStates(st);
        for (auto it = succerssors.begin(); it != succerssors.end(); ++it){
            //true if the state in the set, false if not

            //check
            const bool is_in_closed = true;

            //const bool is_in_closed = ((closed.find(*it)) != (closed.end()));
            if(!is_in_closed){
                pq.push(*it);
            }
        }
    }
    //can not reach here
    Solution solu;
    return solu;
}

Solution BestFS::backTrace() {
    Solution solu;
    //std::list<State> solu
    //we know that closed is not empty because it has at least the initState
    while(true){
        solu.getVertexes().push_front(*(closed.end()));
        closed.erase(closed.end());
        //remove States from closed until the top is the State that we came from
        //him to the current State
        if(closed.empty()){
            return solu;
        }
        while(!(*(closed.end())).Equals(*(*(solu.getVertexes().begin())).lastStateBeforeCurrent())){
            closed.erase(closed.end());
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