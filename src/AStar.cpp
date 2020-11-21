#include "AStar.hpp"
#include <limits>
#include <string>
#include <iostream>
bool AStar::isElementInPQ(Node *element, std::priority_queue<Node, std::vector<Node>,
                         AStarComparator> pq){
    while (!pq.empty()) {
        if ((*element).equals(pq.top())) {
            return true;
        }
        pq.pop();
    }
    return false;
}

void AStar::removeFromPQ(std::priority_queue<Node, std::vector<Node>,
                                AStarComparator> *pq, Node *node) {
	std::priority_queue<Node, std::vector<Node>, AStarComparator>
      copyPQ;
    while (!pq->empty()) {
		auto curr = pq->top();
		pq->pop();
		if (!(*node).equals(curr)) {
			copyPQ.push(curr);
		}
  	}
  	while (!copyPQ.empty()) {
    	auto curr = copyPQ.top();
    	copyPQ.pop();
    	pq->push(curr);
  	}
}
bool AStar::areConnected(Graph *g,Node *node1, Node *node2) {
    std::vector<Node*> connectionsToNode1 = g->getConnectedVerts(node1);
    if(connectionsToNode1.empty()){
        return false;
    }
    for(auto s : connectionsToNode1) {
        if(node2->equals(*s)) {
            return true;
        }
    }
    return false;
}
std::pair<std::vector<Node>,double> AStar::search(Graph *graph, Node *init, Node *goal) {
    if (init == nullptr || goal == nullptr || init->getWeight() == -1 ||
      goal->getWeight() == -1) {
    	return std::pair<std::vector<Node>,double>(std::vector<Node>(),-1);
  	}
  	if (init == goal || (*init).equals(*goal)) {
    	return std::pair<std::vector<Node>,double>(std::vector<Node>(),-1);
  	}
  	auto &g = *graph;
  	for (int i = 0; i < graph->getHeight(); ++i) {
    	for (int j = 0; j < graph->getWidth(); ++j) {
      		if (i == init->getI() && j == init->getJ()) {
        		g.getNode(j, i)->setDist(0);
      		} else {
        		g.getNode(j, i)->setDist(std::numeric_limits<int>::max());
      		}
      		m_visitedNodes.push(*(g.getNode(j, i)));
    	}
  	}
  	while (!m_visitedNodes.empty()) {
    	auto current = m_visitedNodes.top();
    	m_visitedNodes.pop();
    	if (current.equals(*goal)) {
            if (current.getISrc() == init->getI() &&
                current.getJSrc() == init->getJ() &&
                !areConnected(&g,&current, init)) {
                return std::pair<std::vector<Node>,double>(std::vector<Node>(),-1);
            }
            std::vector<Node> path;
            auto *node = &current;
            double weight = 0;
            while (!(*node).equals(*init)) {
                path.emplace(path.begin(), *node);
                weight += node->getWeight();
                node = g.getNode(node->getISrc(), node->getJSrc());
            }
            path.emplace(path.begin(), *node);
            weight += node->getWeight();
            return std::pair<std::vector<Node>,double>(path,weight);
    	}
    	for (auto *neighbor : graph->getConnectedVerts(&current)) {
      		if (isElementInPQ(neighbor,m_visitedNodes)) {
	        	auto alt = current.getDist() + abs(current.getI() - goal->getI()) + abs(current.getJ() - goal->getJ());
        		if (alt < neighbor->getDist()) {
          			removeFromPQ(&m_visitedNodes, neighbor);
          			auto i = neighbor->getI(), j = neighbor->getJ();
          			g.getNode(i, j)->setDist(alt);
          			g.getNode(i, j)->setISrc(current.getI());
          			g.getNode(i, j)->setJSrc(current.getJ());
          			m_visitedNodes.push(*(g.getNode(i, j)));
        		}
      		}
    	}
  	}
  	return std::pair<std::vector<Node>,double>(std::vector<Node>(),-1);
}
std::string AStar::getOutString(Graph *graph, Node *init, Node *goal) {
    std::pair<std::vector<Node>,double> path = search(graph,init,goal);
    std::string pathString;
    Node before = Node();
    Node curr = Node();
    pathString += std::to_string((int)path.second) + ",";
    for (auto p : path.first) {
        curr = p;
        if(before.getI() > curr.getI() && before.getJ() == curr.getJ()) {
            pathString += "Up,";
        }else if(before.getI() < curr.getI() && before.getJ() == curr.getJ()) {
            pathString += "Down,";
        }else if(before.getI() == curr.getI() && before.getJ() > curr.getJ()) {
            pathString += "Left,";
        }else if(before.getI() == curr.getI() && before.getJ() < curr.getJ()) {
            pathString += "Right,";
        }
        before = p;
    }
    return pathString;
}