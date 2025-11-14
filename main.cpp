#include <iostream>
#include "Graph.h"

int main()
{
    Graph<int> g;
    g.addVertex(0);
    g.addVertex(1);
    g.addVertex(2);
    g.addVertex(3);

    g.addEdge(0, 1, 1);
    g.addEdge(1, 2, 2);
    g.addEdge(0, 2, 4);
    g.addEdge(2, 3, 1);
    // Test 1: existing shortest path 0 -> 3

    auto path = g.shortest_path(0, 3);
    if (path.empty())
        std::cout << "Test1: no path" << std::endl;
    else{
        int dist = g.getPathDistance(path);
        std::cout << "Test1 distance: " << dist << std::endl;
        std::cout << "path:";
        for (int v : path)
            std::cout << " " << v;
        std::cout << std::endl;
    }

    // Test 2: no path case (vertex 4 is disconnected)
    g.addVertex(4);

    auto path2 = g.shortest_path(0, 4);
    if (path2.empty())
        std::cout << "Test2: no path (as expected)" << std::endl;
    else{
        int d2 = g.getPathDistance(path2);
        std::cout << "Test2 distance: " << d2 << std::endl;
        std::cout << "path:";
        for (int v : path2)
            std::cout << " " << v;
        std::cout << std::endl;
    }

    return 0;
}
