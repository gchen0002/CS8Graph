#ifndef GRAPH_H
#define GRAPH_H
#include <vector>

template <typename T>
class Graph{
private:
    int num_vertices = 0;

    std::vector<std::vector<int>> adjacency_list;
    std::vector<std::vector<int>> weights_list;
    std::vector<T> labels;
    bool directed = false;
public:
    Graph(){}
    void addVertex(const T& label);
    void addVertex();

    void addEdge(const int& source, const int& destination, const int& weight);
    T& operator[](const unsigned int& vertex);

    std::vector<int> shortest_path(const int& source, const int& destination);
    int getPathDistance(const std::vector<int>& path) const;
};

#include "Graph.cpp"

#endif