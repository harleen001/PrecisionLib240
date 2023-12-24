// Example.cpp
#include <iostream>
#include "GraphOperations.h"

int main() {
    Graph graph;
    createGraph(graph, 5);

    addEdge(graph, 0, 1, 10);
    addEdge(graph, 0, 2, 20);
    addEdge(graph, 1, 2, 5);
    addEdge(graph, 2, 3, 30);
    addEdge(graph, 3, 4, 15);

    std::cout << "Depth First Search: ";
    depthFirstSearch(graph, 0);
    std::cout << std::endl;

    std::cout << "Breadth First Search: ";
    breadthFirstSearch(graph, 0);
    std::cout << std::endl;

    if (isCyclic(graph)) {
        std::cout << "The graph contains a cycle." << std::endl;
    } else {
        std::cout << "The graph doesn't contain a cycle." << std::endl;
    }

    return 0;
}
