#include <string>
#include <iterator>
#include <list>

#include "DFS.hpp"

#include <iostream>

Solution DFS::search(Searchable& searchable) {
    // Mark the current node as visited and enqueue it 
  
        std::cout << "DFS search debug1" << std::endl;
    visited.insert(searchable.getInitialState()); 
    stack.push_back(searchable.getInitialState()); 
            std::cout << "DFS search debug2" << std::endl;

    uint32_t aaa = 0;
    while(!stack.empty()) 
    {
        ++aaa;

        if(aaa == 10){
            std::exit(1);
        }
        for(auto it = visited.begin(); it != visited.end(); ++it){
            std::cout << std::to_string((*it).getRow()) + "," + std::to_string((*it).getCol()) + "!!";
        }
        std::cout << std::endl;
        // Dequeue a vertex from stack and print it 
        State state = stack.back(); 

            std::cout << std::to_string((state).getRow()) + "," + std::to_string((state).getCol()) << std::endl;

        this->evaluateNodes++;
        stack.pop_back(); 
  
          std::cout << "DFS search debug3" << std::endl;

        //check if we found the goal state
        if(state.equals(searchable.getGoalState())){
                    std::cout << "DFS search debug4" << std::endl;

            return backTrace(state);
        }
        

        // Get all adjacent vertices of the dequeued 
        // vertex s. If a adjacent has not been visited,  
        // then mark it visited and enqueue it 
        std::list<State> succerssors = searchable.getAllPossibleStates(state);

                std::cout << "DFS search debug5" << std::endl;

        for (auto it = succerssors.begin(); it != succerssors.end(); ++it){
                std::cout << "DFS search debug6" << std::endl;

            bool is_in_visited = false;
            for (auto iter = visited.begin(); iter != visited.end(); ++iter){
                if(*iter == *it){
                    is_in_visited = true;
                }
            }

            if (!is_in_visited) {  
                        std::cout << "DFS search debug7" << std::endl;

                visited.insert(*it);
                stack.push_back(*it);
            } 
        }
    }
            std::cout << "DFS search debug8" << std::endl;

    Solution solution;
    return solution;
}

Solution DFS::backTrace(const State& state) {
        std::cout << "DFS backTrace debug1" << std::endl;

    Solution solu;
    //we know that visited is not empty because it has at least the initState
    solu.getVertexes().push_front(state);

    std::cout << std::to_string(state.getRow()) + "," + std::to_string(state.getCol()) << std::endl;
    State st1 = State((*state.lastStateBeforeCurrent()).getRow(),(*state.lastStateBeforeCurrent()).getCol(), 0 , nullptr);
    std::cout << std::to_string(st1.getRow()) + "," + std::to_string(st1.getCol()) << std::endl;


    std::set<State>::iterator it;
    //remove States from closed until the top is the State that we came from
    //him to the current State
            std::cout << "DFS backTrace debug2" << std::endl;

    int bbb = 0;
    while(true){
        if(bbb == 7){
            break;
        }
        //put attention that this code is based on the fact that the init state is the first
        //in visited and of course he is poart of the path of the algorithm
            std::cout << "DFS backTrace debug3" << std::endl;

        if((solu.getVertexes().begin())->lastStateBeforeCurrent() == nullptr){
            return solu;
        }

        it = visited.find(*(*(solu.getVertexes().begin())).lastStateBeforeCurrent());
            std::cout << std::to_string((*it).getRow()) + "," + std::to_string((*it).getCol()) << std::endl;

        
        solu.getVertexes().push_front(*it);
        ++bbb;

        // ++it;
        // visited.erase(it, visited`.end());
        
        //         std::cout << "DFS backTrace debug4" << std::endl;

        // it = visited.end();
        // --it;
        // solu.getVertexes().push_front(*it);
        // visited.erase(it);
        //         std::cout << "DFS backTrace debug5" << std::endl;

        // if(visited.empty()){
        //             std::cout << "DFS backTrace debug6" << std::endl;

        //     return solu;
        // }
    }
            std::cout << "DFS backTrace debug7" << std::endl;

    //can not reach here
    return solu;
}

uint32_t DFS::getNumberOfNodesEvaluated() const {
    return this->evaluateNodes;
}

std::string DFS::getAlgorthemType() const {
    return "DFS";
}