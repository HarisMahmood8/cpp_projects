#include "adjacency_list.h"
#include <iostream>

void readGraph(const std::string& filename, std::vector<std::vector<int>>& adjList, int& numEdges) {
    std::ifstream inputFile(filename); 
    if (!inputFile) {
        throw std::runtime_error("Failed to open file " + filename);
    }

    int n, m;
    inputFile >> n >> m;

    adjList.resize(n);
    for (int i = 0; i < m; i++) {
        int u, v;
        inputFile >> u >> v;
        adjList[u].push_back(v);
        adjList[v].push_back(u);
    }

    numEdges = m;
}

const std::vector<int>& adj(const std::vector<std::vector<int>>& adjList, int node) {
    if (node < 0 || node >= adjList.size()) {
        throw std::out_of_range("Invalid index " + std::to_string(node));
    }
    return adjList[node];
}


