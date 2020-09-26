//#include "MatrixClass.hpp"
#include "BFS.hpp"
#include "DFS.hpp"
#include "AStar.hpp"
//#include "MatrixGraphProblem.hpp"
//#include "Solver.hpp"
#include "BestFS.hpp"
#include <memory>
#include <random>
#include <string>
#include <stdint.h>
#include <algorithm>

#include "Matrix.hpp"
#include "SearchAlgorithm.hpp"
#include "file_reading.hpp"
#include "Graph.hpp"

#include <iostream>
#include <fstream>
#include <stdint.h>

//using namespace std;
// using namespace Matrix;
// using namespace graph;
// using namespace solver;
// using namespace solver::solution;

void initializeMatrix(Matrix* matrix) {
    for (uint32_t i = 0; i < matrix->getHeight(); ++i) {
        for (uint32_t j = 0; j < matrix->getWidth(); ++j) {
            matrix->set(i, j, rand() % 96 + 1);
        }
    }
}

// int getCost(const std::string& line) {
//     auto a = line.find_first_of(',') - 1;
//     auto b = line.substr(0, a);
//     auto c = b.c_str();
//     auto d = atoi(c);
//     return d;
// }

// int numOfSteps(const std::string& input) {
// 	int iSpaces = 0;

// 	for (auto i = 0; i < (int) input.length(); ++i) {
// 		if (input[i] == ',') { ++iSpaces; }
//     }

// 	return iSpaces - 2;
// }

std::string toString(Matrix* matrix){
	const std::uint32_t height = matrix->getHeight();
	const std::uint32_t width = matrix->getWidth();
	std::string matString;
	for (std::uint32_t i = 0; i < height; i++) {
		for (std::uint32_t j = 0; j < width; j++) {
			matString += std::to_string(matrix->operator()(i, j));
			if (j < width - 1) {
				matString += ",";
			}
		}
		if (i < height - 1) {
			matString += "\n";
		}
	}
	return matString;
}

int main() {
    
    srand((unsigned int) time(0));
    std::string s = "";

    auto dfs = DFS();
    auto bfs = BFS();
    auto a_star = AStar();
    auto best = BestFS();

    for (auto i = 0; i < 2; ++i) {

        std::cout << std::to_string(i) << std::endl;
        
        uint32_t x = (rand() % 96) + 5;
        uint32_t y = (rand() % 96) + 5;

        auto size = x * y;
        ++size;
        auto matrix = new Matrix(x, y);
        initializeMatrix(matrix);
        s = toString(matrix);

        std::cout << "debug1" << std::endl;

        writeFileContent("output2", std::to_string(i) + "experiment:/r/n");
        writeFileContent("output2", s + "/r/n");

        std::cout << "debug2" << std::endl;



        Graph graph = Graph(*matrix);
        Node* n1 = (graph.getNode(0,0));
        Node* n2 = (graph.getNode(graph.getWidth() - 1, graph.getHeight() - 1));

                std::cout << "debug3" << std::endl;


        std::string st1 = dfs.getOutString(&graph, n1, n2);
                std::cout << "debug100" << std::endl;


        std::string st2 = bfs.getOutString(&graph, n1, n2);
                        std::cout << "debug101" << std::endl;

        std::string st3 = best.getOutString(&graph, n1, n2);
                        std::cout << "debug102" << std::endl;

        std::string st4 = a_star.getOutString(&graph, n1, n2);
                        std::cout << "debug103" << std::endl;


                std::cout << "debug4" << std::endl;


        int counter1=0, counter2=0,counter3=0,counter4=0;
        double cost1, cost2, cost3, cost4;
        char ch = *(",");

                std::cout << "debug5" << std::endl;


        counter1 = std::count(st1.begin(), st1.end(), ch) - 1;
        counter2 = std::count(st2.begin(), st2.end(), ch) - 1;
        counter3 = std::count(st3.begin(), st3.end(), ch) - 1;
        counter4 = std::count(st4.begin(), st4.end(), ch) - 1;

                std::cout << "debug6" << std::endl;


        cost1 = dfs.search(&graph, n1, n2).second;
        cost2 = bfs.search(&graph, n1, n2).second;
        cost3 = best.search(&graph, n1, n2).second;
        cost4 = a_star.search(&graph, n1, n2).second;

                std::cout << "debug7" << std::endl;


        writeFileContent("output1", std::to_string(i) + "experiment:/r/n");
        writeFileContent("output1", "DFS: " + std::to_string(counter1)+ "   " + std::to_string(cost1) + "/r/n");
        writeFileContent("output1", "BFS: " + std::to_string(counter2) + "    " + std::to_string(cost2) + "/r/n");
        writeFileContent("output1", "BestFS: " + std::to_string(counter3) + "    " + std::to_string(cost3) + "/r/n");
        writeFileContent("output1", "AStar: " + std::to_string(counter4) + "    " + std::to_string(cost4) + "/r/n");

                std::cout << "debug8" << std::endl;

    }
}