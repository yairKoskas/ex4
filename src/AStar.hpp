#include "Graph.hpp"
#include <queue>
#include <string>
class AStarComparator {
    public:
        bool operator()(Node n1, Node n2) {
            if( n1.getDist() > n2.getDist() ) {
                return true;
            }
            return false;
        }
};


class AStar {
    public:
        void removeFromPQ(std::priority_queue<Node, std::vector<Node>,
                                    AStarComparator> *pq, Node *node);
        bool areConnected(Node *node1, Node *node2);
        std::pair<std::vector<Node>,double> search(Graph *graph, Node *init, Node *goal);
        std::string getOutString(Graph *graph, Node *init, Node *goal);
        bool isElementInPQ(Node *element, std::priority_queue<Node, std::vector<Node>,
                         AStarComparator> pq);
    private:
        std::vector<Node> m_closedVertices;
        std::priority_queue<Node, std::vector<Node>, AStarComparator> m_visitedNodes;
};