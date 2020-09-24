#include <string>
#include <iterator>
#include <list>
#include <stdint.h>
#include <set>

#include "DFS.hpp"
#include "Searchable.hpp"
#include "State.hpp"
#include "Solution.hpp"

Solution DFS::search(Searchable& searchable) {
    // Mark the current node as visited and enqueue it 
    visited.insert(searchable.getInitialState()); 
    stack.push_back(searchable.getInitialState()); 
  
    while(!stack.empty()) 
    { 
        // Dequeue a vertex from queue and print it 
        State state = stack.back(); 
        this->evaluateNodes++;
        stack.pop_back(); 
  
        //check if we found the goal state
        if(state.equals(searchable.getGoalState())){
            return backTrace(state);
        }

        // Get all adjacent vertices of the dequeued 
        // vertex s. If a adjacent has not been visited,  
        // then mark it visited and enqueue it 
        std::list<State> succerssors = searchable.getAllPossibleStates(state);
        for (auto it = succerssors.begin(); it != succerssors.end(); ++it){
            const bool is_in_visited = ((visited.find(*it)) != (visited.end()));

<<<<<<< HEAD:DFS.cpp
            if (!is_in_visited) {  
                visited.insert(*it);
=======
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
>>>>>>> f6bf8785d96181ff8ed44160eacf4c799a069289:src/DFS.cpp
                stack.push_back(*it);
            } 
        }
    } 
}

Solution DFS::backTrace(const State& state) const{
    Solution solu;
    //we know that visited is not empty because it has at least the initState
    solu.getVertexes().push_front(state);

    std::set<State>::iterator it;
    //remove States from closed until the top is the State that we came from
    //him to the current State
    while(true){
        //put attention that this code is based on the fact that the init state is the first
        //in visited and of course he is poart of the path of the algorithem
        it = visited.end();
        --it;

        it = visited.find(*(*(solu.getVertexes().begin())).lastStateBeforeCurrent());
        ++it;
        visited.erase(it, visited.end());
        
        it = visited.end();
        --it;
        solu.getVertexes().push_front(*it);
        visited.erase(it);
        
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