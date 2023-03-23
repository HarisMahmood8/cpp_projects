#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "adjacency_list.h"

TEST_CASE("Testing reading in a graph from a file") {
    std::vector<std::vector<int>> adjList;
    int numEdges;
    readGraph("graph.txt", adjList, numEdges);

    CHECK(adjList.size() == 5);
    CHECK(numEdges == 6);

    CHECK(adj(adjList, 0) == std::vector<int>({1, 2}));
    CHECK(adj(adjList, 1) == std::vector<int>({0, 2, 3}));
    CHECK(adj(adjList, 2) == std::vector<int>({0, 1, 3}));
    CHECK(adj(adjList, 3) == std::vector<int>({1, 2, 4}));
    CHECK(adj(adjList, 4) == std::vector<int>({3}));
}

TEST_CASE("Testing getting the adjacency list for a node") {
    std::vector<std::vector<int>> adjList({
        {1, 2},
        {0, 2, 3},
        {0, 1, 3},
        {1, 2, 4},
        {3}
    });

    CHECK(adj(adjList, 0) == std::vector<int>({1, 2}));
    CHECK(adj(adjList, 1) == std::vector<int>({0, 2, 3}));
    CHECK(adj(adjList, 2) == std::vector<int>({0, 1, 3}));
    CHECK(adj(adjList, 3) == std::vector<int>({1, 2, 4}));
    CHECK(adj(adjList, 4) == std::vector<int>({3}));

    CHECK_THROWS_AS(adj(adjList, 5), std::out_of_range);
}

TEST_CASE("Testing number of edges in the graph") {
    std::vector<std::vector<int>> adjList = {{1, 2}, {0, 3}, {0, 3}, {1, 2, 4}, {3}};
    int numEdges = 5;
    int actualNumEdges = 0;
    for (const auto& neighbors : adjList) {
        actualNumEdges += neighbors.size();
    }
    
    actualNumEdges /= 2;
    REQUIRE(actualNumEdges == numEdges);
}

TEST_CASE("Testing invalid node index") {
    std::vector<std::vector<int>> adjList = {{1, 2}, {0, 3}, {0, 3}, {1, 2, 4}, {3}};
    CHECK_THROWS_AS(adj(adjList, -1), std::out_of_range);
    CHECK_THROWS_AS(adj(adjList, adjList.size()), std::out_of_range);
}
