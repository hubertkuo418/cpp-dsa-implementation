#ifndef GRAPH_H
#define GRAPH_H

#include <vector>
using namespace std;

class Graph {
private:
    int V;
    vector<vector<int>> adj;

    void dfsUtil(int v, vector<bool>& visited);

public:
    Graph(int vertices);

    void addEdge(int u, int v);

    void DFS(int start);
    void BFS(int start);
};

#endif