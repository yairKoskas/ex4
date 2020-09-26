#include "BFS.hpp"
#include "Graph.hpp"
#include <stdlib.h>
#include <iostream>
void BFS::setVisited(Node* node) {
    m_visitedVertices.push(*node);
}
bool BFS::isEmpty() {
    return m_visitedVertices.empty();
}
Node BFS::popVertex() {
    auto node = m_visitedVertices.front();
    m_visitedVertices.pop();
    return node;
}

bool BFS::isVertexClosed(Node* node) {
    for (auto it = m_closedVertices.begin(); it != m_closedVertices.end(); ++it) {
      if ((*it).equals(*node)) {
        return true;
      }
    }
    return false;
}
std::pair<std::vector<Node>,double> BFS::search(Graph *g, Node* init, Node* goal) {
    //m_visitedVertices is a stack
    if (init == nullptr || goal == nullptr || init->getWeight() == -1 ||
        goal->getWeight() == -1) {
        return std::pair<std::vector<Node>,double>(std::vector<Node>(),-1);
    }
    if (init == goal || (*init).equals(*goal)) {
        return std::pair<std::vector<Node>,double>(std::vector<Node>(),-1);
    }
    setVisited(init);
    m_closedVertices.push_back(*init);
    while (!isEmpty()) {
        auto current = popVertex();
        if (current.equals(*goal)) {
            std::vector<Node> path;
            double weight;
            auto *node = &current;
            while (!(*node).equals(*init)) {
                path.emplace(path.begin(), *node);
                weight += node->getWeight();
                node = (*g).getNode(node->getISrc(), node->getJSrc());
            }
            return std::pair<std::vector<Node>,double>(path,weight);
        }
        for (auto neighbor : g->getConnectedVerts(&current)) {
            if (!isVertexClosed(neighbor)) {
                neighbor->setISrc(current.getI());
                neighbor->setJSrc(current.getJ());
                setVisited(neighbor);
                m_closedVertices.push_back(*neighbor);
            }
        }
    }
    return std::pair<std::vector<Node>,double>();
}

std::string BFS::getOutString(Graph *g,Node* init, Node* goal) {
    std::pair<std::vector<Node>,double> path = search(g,init,goal);
    std::string pathString;
    Node before = Node();
    Node curr = Node();
    pathString += std::to_string(path.second) + ",";
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