#include <string>
#include <iterator>
#include <list>

#include "BFS.hpp"
#include "Searchable.hpp"
#include "State.hpp"
#include "Solution.hpp"

Solution BFS::search(Searchable& searchable) {
    // Mark the current node as visited and enqueue it 
    visited.push_back(searchable.getInitialState()); 
    queue.push_back(searchable.getInitialState()); 
  
    while(!queue.empty()) 
    { 
        // Dequeue a vertex from queue and print it 
        State state = queue.front(); 
        this->evaluateNodes++;
        queue.pop_front(); 
  
        //check if we found the goal state
        if(state.Equals(searchable.getGoalState())){
            return backTrace();
        }

        // Get all adjacent vertices of the dequeued 
        // vertex s. If a adjacent has not been visited,  
        // then mark it visited and enqueue it 
        std::list<State> succerssors = searchable.getAllPossibleStates(st);
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
                queue.push_back(*it);
            } 
        }
    } 
}

Solution BFS::backTrace(){
    Solution solu;
    //we know that visited is not empty because it has at least the initState
    while(true){
        solu.getVertexes().push_front(*(visited.end()));
        visited.erase(visited.end());
        //remove States from closed until the top is the State that we came from
        //him to the current State
        if(visited.empty()){
            return solu;
        }
        while(!(*(visited.end())).Equals(*(*(solu.getVertexes().begin())).lastStateBeforeCurrent())){
            visited.erase(visited.end());
        }
    }
    //can not reach here
    return solu;
}

uint32_t BFS::getNumberOfNodesEvaluated() const {
    return this->evaluateNodes;
}

std::string BFS::getAlgorthemType() const {
    return "BFS";
}