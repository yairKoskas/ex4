#pragma once

#include "SearchAlgorithm.hpp"
#include <string>
#include <queue>
class MyComparator{
    public:
        bool operator()(Node n1, Node n2);
};
class BestFS : public SearchAlgorithm<std::priority_queue<Node, std::vector<Node>,
            MyComparator>> {
    public:
        void setVisited(Node* node);
        bool isEmpty();
        Node popVertex();
        bool isVertexClosed(Node* node);
        std::pair<std::vector<Node>,double> search(Graph *g, Node* init, Node* goal);
        std::string getOutString(Graph *g,Node* init, Node* j);
};