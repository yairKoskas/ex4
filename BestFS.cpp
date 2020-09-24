
#include <string>
#include <list>
#include <iterator>

#include "BestFS.hpp"

Solution BestFS::search (Searchable& searchable) {

    std::cout << "BestFS search debug1" << std::endl;

    State state = State(searchable.getInitialState().getRow(), searchable.getInitialState().getCol(), 0,  nullptr);
    pq.push(state);

    std::cout << "BestFS search debug2" << std::endl;

    while(!this->pq.empty()){
        std::cout << "BestFS search debug3" << std::endl;

        //pull the first state in the queue and add it to closed-set
        State st = pq.top();
        pq.pop();
        this->evaluateNodes++;
        
        std::cout << "BestFS search debug4" << std::endl;

        //the check if States are equals is only according to their place in th graph
        //and not according to the cost
        closed.insert(st);

        std::cout << "BestFS search debug10" << std::endl;

        //check if we arrive to the goal state
        if(st.Equals(searchable.getGoalState())){

            std::cout << "BestFS search debug5" << std::endl;

            return backTrace();
        }
        //get all the evaluate states from the current state

        std::cout << "BestFS search debug11" << std::endl;

        std::list<State> succerssors = searchable.getAllPossibleStates(st);

        std::cout << "BestFS search debug6" << std::endl;

        for (auto it = succerssors.begin(); it != succerssors.end(); ++it){
            //true if the state in the set, false if not
            const bool is_in_closed = ((closed.find(*it)) != (closed.end()));
            if(!is_in_closed){
                std::cout << "BestFS search debug7" << std::endl;

                pq.push(*it);
            }
            std::cout << "BestFS search debug8" << std::endl;

        }
    }
    std::cout << "BestFS search debug9" << std::endl;
    //can not reach here
    Solution solu;
    return solu;
}

Solution BestFS::backTrace() {
    std::cout << "BestFS backTrace debug1" << std::endl;

    Solution solu;
    //we know that closed is not empty because it has at least the initState
    while(true){
        solu.getVertexes().push_front(*(closed.end()));

        std::cout << "BestFS backTrace debug2" << std::endl;

        std::set<State>::iterator it;
        it = closed.end();
        --it;
        closed.erase(it);

        std::cout << "BestFS backTrace debug3" << std::endl;

        //remove States from closed until the top is the State that we came from
        //him to the current State
        if(closed.empty()){

            std::cout << "BestFS backTrace debug4" << std::endl;
            return solu;
        }
        std::cout << "BestFS backTrace debug5" << std::endl;

        closed.erase(closed.find(*(*(solu.getVertexes().begin())).lastStateBeforeCurrent()), closed.end());

        // while(!(*(closed.end())).Equals(*(*(solu.getVertexes().begin())).lastStateBeforeCurrent())){
        //     std::cout << "BestFS backTrace debug6" << std::endl;
        //     it = closed.end();
        //     --it;
        //     closed.erase(it);
        // }
        std::cout << "BestFS backTrace debug7" << std::endl;
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