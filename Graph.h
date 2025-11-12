#ifndef GRAPH_H
#define GRAPH_H
#include <vector>

template <typename T>
class Graph{
private:
    int num_vertices = 0;

    std::vector<std::vector<int>> adjacency_list;
    std::vector<T> labels;
    bool directed = false;
public:
    void addVertex(const T& label);
    void addVertex();

    void addEdge(int source, int destination);

};

#include "Graph.cpp"

#endif