<<<<<<< HEAD
#pragma once

#include <stdint.h>
#include <list>

#include "Searcher.hpp"
#include "Searchable.hpp"
#include "State.hpp"
#include "Solution.hpp"

class BFS : public Searcher{
private:
    std::list<State> queue;
    std::list<State> visited;
    uint32_t evaluateNodes = 0;

    //return a list of the States in the solution of the algorithem
    Solution backTrace();

public:
    //the search method
    Solution search(Searchable& searchable) override;
    //the vertex you can go to from the current vertex
    uint32_t getNumberOfNodesEvaluated() const override;
    //which algorithem was used
    std::string getAlgorthemType() const override;
=======
#include "SearchAlgorithm.hpp"
#include <string>
#include <queue>
class BFS : public SearchAlgorithm<std::queue<Node>> {
    public:
        void setVisited(Node* node);
        bool isEmpty();
        Node popVertex() override;
        bool isVertexClosed(Node* node);
        std::pair<std::vector<Node>,double> search(Graph *g, Node* init, Node* goal) override;
        std::string getOutString(Graph *g,Node* init, Node* j) override;
>>>>>>> 537709e809e8dd667d4d72380a3ef49c44a97eee
};