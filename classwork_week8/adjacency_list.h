#ifndef _ADJACENCY_LIST_H
#define _ADJACENCY_LIST_H

#include <vector>
#include <string>
#include <fstream>
#include <stdexcept>


void readGraph(const std::string& filename, std::vector<std::vector<int>>& adjList, int& numEdges);

const std::vector<int>& adj(const std::vector<std::vector<int>>& adjList, int node);

#endif
