#include "Graph.hpp"
#include <vector>
#include <iostream>
Graph::Graph(std::vector<std::vector<int>> graph,int height, int width) {
    std::vector<std::vector<Node>> nodes;
    for (int i = 0; i < height; ++i) {
        std::vector<Node> line;
        for (int j = 0; j < width; ++j) {
            Node node = Node(i,j,0,0,graph[i][j]);
            line.push_back(node);
        }
        nodes.push_back(line);
    }
    m_Vertices = nodes;
    m_height = height;
    m_width = width;
}

Graph::Graph(Matrix mat) {
    m_Vertices.clear();
    for(uint32_t i = 0; i < mat.getHeight(); ++i) {
        std::vector<Node> nodesVector;
        for(uint32_t j = 0; j < mat.getWidth(); ++j) {
            Node node = Node(i,j,0,0,mat(i,j));
            nodesVector.push_back(node);
        }
        m_Vertices.push_back(nodesVector);
    }
    m_height = mat.getHeight();
    m_width = mat.getWidth();
}
std::vector<Node*> Graph::getConnectedVerts(Node* node) {
    //goes to the vertices field and gets all the connected 
    //vertices in the given matrix input
    std::vector<Node*> connectedVerts;
    auto i = node->getI();
    auto j = node->getJ();
    Node *curr;
    curr = (*this).getNode(i - 1, j);
    if (curr != nullptr && curr->getWeight() != -1) {
        connectedVerts.push_back(curr);
    }
    curr = (*this).getNode(i + 1, j);
    if (curr != nullptr && curr->getWeight() != -1) {
        connectedVerts.push_back(curr);
    }
    curr = (*this).getNode(i, j - 1);
    if (curr != nullptr && curr->getWeight() != -1) {
        connectedVerts.push_back(curr);
    }
    curr = (*this).getNode(i, j + 1);
    if (curr != nullptr && curr->getWeight() != -1) {
        connectedVerts.push_back(curr);
    }
    return connectedVerts;
}

Node* Graph::getNode(int i,int j) {
    if (0 <= i && i < m_height && 0 <= j &&
      j < m_width) {
    return &m_Vertices[i][j];
    }
    return nullptr;
}