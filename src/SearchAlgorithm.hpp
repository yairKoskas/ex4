#pragma once

#include "Graph.hpp"
#include <vector>
#include <string>
typedef struct Node Node;
class Graph;
template<typename dataStructure> class SearchAlgorithm {
    protected:
        std::vector<Node> m_closedVertices;
        dataStructure m_visitedVertices;
    public:
        //rule of 5
        SearchAlgorithm() = default;
        virtual ~SearchAlgorithm() = default;
        SearchAlgorithm(const SearchAlgorithm& other) = default;
        SearchAlgorithm &operator=(const SearchAlgorithm& other) = default;
        SearchAlgorithm(SearchAlgorithm&& other) = default;
        SearchAlgorithm &operator=(SearchAlgorithm&& other) = default;

        void setVisited(Node* node);
        virtual Node popVertex() = 0;
        bool isEmpty();
        bool isVertexClosed(Node* node);
        virtual std::pair<std::vector<Node>,double> search(Graph *g, Node* init, Node* goal) = 0;
        virtual std::string getOutString(Graph *g,Node* init, Node* j) = 0;
};