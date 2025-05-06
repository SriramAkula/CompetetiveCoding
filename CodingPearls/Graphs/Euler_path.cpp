#include <bits/stdc++.h>
using namespace std;

void dfs(int node, vector<vector<int>>& adj, vector<bool>& visited) {
    visited[node] = true;
    for (int neighbor : adj[node]) {
        if (!visited[neighbor]) {
            dfs(neighbor, adj, visited);
        }
    }
}

bool isConnected(vector<vector<int>>& adj, int V) {
    vector<bool> visited(V, false);
    int start = -1;

    for (int i = 0; i < V; i++) {
        if (!adj[i].empty()) {
            start = i;
            break;
        }
    }

    if (start == -1) return true; 

    dfs(start, adj, visited);

    for (int i = 0; i < V; i++) {
        if (!adj[i].empty() && !visited[i]) {
            return false;
        }
    }

    return true;
}

void checkEuler(vector<vector<int>>& adj, int V) {
    if (!isConnected(adj, V)) {
        cout << "Graph is not connected. No Euler Path or Cycle.\n";
        return;
    }

    int oddDegreeCount = 0;
    for (int i = 0; i < V; i++) {
        if (adj[i].size() % 2 != 0) {
            oddDegreeCount++;
        }
    }

    if (oddDegreeCount == 0) {
        cout << "Graph has an Euler Cycle.\n";
    } else if (oddDegreeCount == 2) {
        cout << "Graph has an Euler Path.\n";
    } else {
        cout << "Graph does not have an Euler Path or Cycle.\n";
    }
}

int main() {
    int V, E;
    cin >> V >> E;

    vector<vector<int>> adj(V);
    for (int i = 0; i < E; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    checkEuler(adj, V);

    return 0;
}
