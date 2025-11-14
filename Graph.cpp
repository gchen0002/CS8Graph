#include "Graph.h"

#ifndef GRAPH_CPP
#define GRAPH_CPP

#include <queue>
#include <algorithm>
#include <limits>

template <typename T>
void Graph<T>::addVertex(const T& label) {
    labels.push_back(label);
    adjacency_list.push_back(std::vector<int>());
    weights_list.push_back(std::vector<int>());
    num_vertices++;
}

template <typename T>
void Graph<T>::addVertex() {
    labels.push_back(T());
    adjacency_list.push_back(std::vector<int>());
    weights_list.push_back(std::vector<int>());
    num_vertices++;
}

template <typename T>
void Graph<T>::addEdge(const int& source, const int& destination, const int& weight){
    adjacency_list[source].push_back(destination);
    weights_list[source].push_back(weight);
    if (!directed){
        adjacency_list[destination].push_back(source);
        weights_list[destination].push_back(weight);
    }
}

template <typename T>
T& Graph<T>::operator[](const unsigned int& vertex){
    return labels[vertex];
}

template <typename T>
std::vector<int> Graph<T>::shortest_path(const int& source, const int& destination){

    using Pair = std::pair<int,int>; // (dist, vertex)


    std::vector<int> dist(num_vertices, INT_MAX);
    std::vector<int> prev(num_vertices, -1);

    dist[source] = 0;
    std::priority_queue<Pair, std::vector<Pair>, std::greater<Pair>> pq;
    pq.emplace(0, source);

    while(!pq.empty()){
        Pair top = pq.top(); pq.pop();
        int d = top.first;
        int u = top.second;
        if (d != dist[u]) continue; // stale
        if (u == destination) break; // early exit
        // explore neighbors
        for (size_t i = 0; i < adjacency_list[u].size(); ++i){
            int v = adjacency_list[u][i];
            int w = weights_list[u][i];
            int alt = dist[u] + w;
            if (alt < dist[v]){
                dist[v] = alt;
                prev[v] = u;
                pq.emplace(alt, v);
            }
        }
    }
    // no path found
    if (dist[destination] == INT_MAX) return std::vector<int>{};
    // reconstruct path
    std::vector<int> path;
    for (int x = destination; x != -1; x = prev[x]) path.push_back(x);
    std::reverse(path.begin(), path.end());
    return path;
}

template <typename T>
int Graph<T>::getPathDistance(const std::vector<int>& path) const {
    if (path.empty()) return 0;

    int total = 0;
    for (size_t i = 1; i < path.size(); ++i){
        int u = path[i-1];
        int v = path[i];

        bool found = false;
        // find edge u->v
        for (size_t k = 0; k < adjacency_list[u].size(); ++k){
            if (adjacency_list[u][k] == v){
                total += weights_list[u][k];
                found = true;
                break;
            }
        }
    }
    return total;
}
#endif 