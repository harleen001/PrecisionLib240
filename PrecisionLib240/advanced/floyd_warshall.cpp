#include <iostream>
#include <vector>
#include <climits>

// Function to apply Floyd-Warshall algorithm
void floydWarshall(std::vector<std::vector<int>>& graph, int vertices) {
    // Initialize the distance matrix
    std::vector<std::vector<int>> distance(vertices, std::vector<int>(vertices, INT_MAX));

    // Set the diagonal elements to 0 and fill the distance matrix with input graph weights
    for (int i = 0; i < vertices; ++i) {
        distance[i][i] = 0;
        for (int j = 0; j < vertices; ++j) {
            if (i != j && graph[i][j] != 0) {
                distance[i][j] = graph[i][j];
            }
        }
    }

    // Apply Floyd-Warshall algorithm
    for (int k = 0; k < vertices; ++k) {
        for (int i = 0; i < vertices; ++i) {
            for (int j = 0; j < vertices; ++j) {
                if (distance[i][k] != INT_MAX && distance[k][j] != INT_MAX &&
                    distance[i][k] + distance[k][j] < distance[i][j]) {
                    distance[i][j] = distance[i][k] + distance[k][j];
                }
            }
        }
    }

    // Print the shortest paths
    std::cout << "Shortest paths between all pairs of vertices:\n";
    for (int i = 0; i < vertices; ++i) {
        for (int j = 0; j < vertices; ++j) {
            if (distance[i][j] == INT_MAX) {
                std::cout << "INF\t";
            } else {
                std::cout << distance[i][j] << "\t";
            }
        }
        std::cout << '\n';
    }
}

int main() {
    int vertices;

    // Get the number of vertices from the user
    std::cout << "Enter the number of vertices: ";
    std::cin >> vertices;

    // Initialize the graph
    std::vector<std::vector<int>> graph(vertices, std::vector<int>(vertices, 0));

    // Get the weighted graph from the user
    std::cout << "Enter the weighted graph (enter 0 for no edge):\n";
    for (int i = 0; i < vertices; ++i) {
        for (int j = 0; j < vertices; ++j) {
            std::cin >> graph[i][j];
        }
    }

    // Apply Floyd-Warshall algorithm
    floydWarshall(graph, vertices);

    return 0;
}
