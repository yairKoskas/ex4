#pragma once

#include <vector>
#include "Matrix.hpp"
#include <math.h>
class Node {
    private:
        int i,j,iSrc,jSrc;
        int astarDistance;
        double weight;

    public:
        Node() = default;
        bool equals(Node other) {
            return this->i == other.i && this->j == other.j;
        }
        Node(int iOther, int jOther, int iSrcOther, int jSrcOther, double weightOther) {
            this->i = iOther;
            this->j = jOther;
            this->iSrc = iSrcOther;
            this->jSrc = jSrcOther;
            this->weight = weightOther;
        }
        int getI() {
            return i;
        }
        int getJ() {
            return j;
        }
        int getISrc() {
            return iSrc;
        }
        int getJSrc() {
            return jSrc;
        }
        double getWeight() {
            return weight;
        }
        int getDist() {
            return astarDistance;
        }
        void setI(int iOther) {
            this->i = iOther;
        }
        void setJ(int jOther) {
            this->j = jOther;
        }
        void setISrc(int iSrcOther) {
            this->iSrc = iSrcOther;
        }
        void setJSrc(int jSrcOther) {
            this->jSrc = jSrcOther;
        }
        void setWeight(double weightOther) {
            this->weight = weightOther;
        }
        void setDist(int dist) {
            this->astarDistance = dist;
        }
};

class Graph {
    private:
        //because the graph is stored in a matrix, we know it has well-defined
        //height and width
        int m_width;
        int m_height;
        std::vector<std::vector<Node>> m_Vertices;
    public:
        Graph(Matrix mat);
        std::vector<Node*> getConnectedVerts(Node* node);
        Node* getNode(int i,int j);
        Graph(std::vector<std::vector<int>> graph, int height, int width);
        int getWidth() {
            return m_height;
        }
        int getHeight() {
            return m_width;
        }
};