#include "dfs_bfs.h"
#include <iostream>
#include <queue>

using namespace std;

// constructor
Graph::Graph(int vertices) {
    V = vertices;
    adj.resize(V);
}

// add edge (undirected)
void Graph::addEdge(int u, int v) {
    adj[u].push_back(v);
    adj[v].push_back(u);
}

void Graph::dfsUtil(int v, vector<bool>& visited) {
    visited[v] = true;
    cout << v << " ";

    for (int neighbor : adj[v]) {
        if (!visited[neighbor]) {
            dfsUtil(neighbor, visited);
        }
    }
}

void Graph::DFS(int start) {
    vector<bool> visited(V, false);
    dfsUtil(start, visited);
    cout << endl;
}


void Graph::BFS(int start) {
    vector<bool> visited(V, false);
    queue<int> q;

    visited[start] = true;
    q.push(start);

    while (!q.empty()) {
        int node = q.front();
        q.pop();

        cout << node << " ";

        for (int neighbor : adj[node]) {
            if (!visited[neighbor]) {
                visited[neighbor] = true;
                q.push(neighbor);
            }
        }
    }

    cout << endl;
}