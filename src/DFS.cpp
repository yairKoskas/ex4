#include <string>
#include <iterator>
#include <list>
#include <stdint.h>

#include "DFS.hpp"
#include "Searchable.hpp"
#include "State.hpp"
#include "Solution.hpp"

Solution DFS::search(Searchable& searchable) {
    // Mark the current node as visited and enqueue it 
    visited.push_back(searchable.getInitialState()); 
    stack.push_back(searchable.getInitialState()); 
  
    while(!stack.empty()) 
    { 
        // Dequeue a vertex from queue and print it 
        State state = stack.back(); 
        this->evaluateNodes++;
        stack.pop_back(); 
  
        //check if we found the goal state
        if(state.Equals(searchable.getGoalState())){
            return backTrace(state);
        }

        // Get all adjacent vertices of the dequeued 
        // vertex s. If a adjacent has not been visited,  
        // then mark it visited and enqueue it 
        std::list<State> succerssors = searchable.getAllPossibleStates(state);
        for (auto it = succerssors.begin(); it != succerssors.end(); ++it){

            bool is_in_visited = false;
            for (auto iter = visited.begin(); iter != visited.end(); ++iter){
                if((*iter).Equals(*it)){
                    is_in_visited = true;
                    break;
                }
            }

            if (!is_in_visited) 
            {  
                visited.push_back(*it);
                stack.push_back(*it);
            } 
        }
    } 
}

Solution DFS::backTrace(const State& state) const{
    Solution solu;
    //we know that visited is not empty because it has at least the initState
    solu.getVertexes().push_front(state);
    //remove States from closed until the top is the State that we came from
    //him to the current State
    while(true){
        //put attention that this code is based on the fact that the init state is the first
        //in visited and of course he is poart of the path of the algorithem
        while(!(*(visited.end())).Equals(*(*(solu.getVertexes().begin())).lastStateBeforeCurrent())){
            visited.erase(visited.end());
        }
        solu.getVertexes().push_front(*(visited.end()));
        visited.erase(visited.end());
        
        if(visited.empty()){
            return solu;
        }
    }
    //can not reach here
    return solu;
}

uint32_t DFS::getNumberOfNodesEvaluated() const {
    return this->evaluateNodes;
}

std::string DFS::getAlgorthemType() const {
    return "DFS";
}