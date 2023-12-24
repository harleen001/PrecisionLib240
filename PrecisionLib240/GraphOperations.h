// GraphOperations.h
#pragma once
#include <vector>
#include <queue>
#include <stack>
#include <unordered_map>
#include <unordered_set>

struct Edge {
    int dest;
    int weight;
};

struct Graph {
    int vertices;
    std::vector<std::vector<Edge>> adjList;
};

void createGraph(Graph& graph, int vertices) {
    graph.vertices = vertices;
    graph.adjList.resize(vertices);
}

void addEdge(Graph& graph, int src, int dest, int weight) {
    graph.adjList[src].push_back({dest, weight});
}

bool hasEdge(const Graph& graph, int src, int dest) {
    for (const auto& edge : graph.adjList[src]) {
        if (edge.dest == dest) {
            return true;
        }
    }
    return false;
}

void removeEdge(Graph& graph, int src, int dest) {
    auto& edges = graph.adjList[src];
    edges.erase(std::remove_if(edges.begin(), edges.end(), [&](const Edge& e) { return e.dest == dest; }), edges.end());
}

bool isCyclicUtil(const Graph& graph, int vertex, std::vector<bool>& visited, std::vector<bool>& stack) {
    if (!visited[vertex]) {
        visited[vertex] = true;
        stack[vertex] = true;

        for (const auto& edge : graph.adjList[vertex]) {
            if (!visited[edge.dest] && isCyclicUtil(graph, edge.dest, visited, stack)) {
                return true;
            } else if (stack[edge.dest]) {
                return true;
            }
        }
    }
    stack[vertex] = false;
    return false;
}

bool isCyclic(const Graph& graph) {
    std::vector<bool> visited(graph.vertices, false);
    std::vector<bool> stack(graph.vertices, false);

    for (int i = 0; i < graph.vertices; ++i) {
        if (isCyclicUtil(graph, i, visited, stack)) {
            return true;
        }
    }
    return false;
}

void depthFirstSearch(const Graph& graph, int startVertex) {
    std::vector<bool> visited(graph.vertices, false);
    std::stack<int> stack;

    stack.push(startVertex);
    visited[startVertex] = true;

    while (!stack.empty()) {
        int current = stack.top();
        stack.pop();
        std::cout << current << " ";

        for (const auto& edge : graph.adjList[current]) {
            if (!visited[edge.dest]) {
                visited[edge.dest] = true;
                stack.push(edge.dest);
            }
        }
    }
}

void breadthFirstSearch(const Graph& graph, int startVertex) {
    std::vector<bool> visited(graph.vertices, false);
    std::queue<int> queue;

    visited[startVertex] = true;
    queue.push(startVertex);

    while (!queue.empty()) {
        int current = queue.front();
        queue.pop();
        std::cout << current << " ";

        for (const auto& edge : graph.adjList[current]) {
            if (!visited[edge.dest]) {
                visited[edge.dest] = true;
                queue.push(edge.dest);
            }
        }
    }
}

int getShortestPath(const Graph& graph, int src, int dest, std::vector<int>& path) {
    // Implementation of Dijkstra's algorithm or other shortest path algorithm here
    // Filling 'path' vector with the shortest path from src to dest
    // Return the shortest distance
    return 0;
}

int getMinimumSpanningTree(const Graph& graph, Graph& mst) {
    // Implementation of Prim's algorithm or Kruskal's algorithm here
    // Construct a minimum spanning tree (MST) in 'mst' graph
    // Return the total weight of the MST
    return 0;
}
