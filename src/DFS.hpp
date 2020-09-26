#pragma once
#include "SearchAlgorithm.hpp"
#include <string>
#include <stack>
class DFS : public SearchAlgorithm<std::stack<Node>> {
    public:
        void setVisited(Node* node);
        bool isEmpty();
        Node popVertex() override;
        bool isVertexClosed(Node* node);
        std::pair<std::vector<Node>,double> search(Graph *g, Node* init, Node* goal) override;
        std::string getOutString(Graph *g,Node* init, Node* j) override;
};