#include <bits/stdc++.h>
using namespace std;

void dfs(int node, vector<vector<int>>& g, vector<int>& color, bool &isBipartite) {
    if (!isBipartite) return; // If already determined to be not bipartite, stop processing
    for (auto& neighbor : g[node]) {
        if (color[neighbor] == 0) {
            color[neighbor]=color[node]==1?2:1;
            dfs(neighbor, g, color, isBipartite);
        }
        if (color[node] == color[neighbor]) {
            isBipartite = false; // Found conflict, mark as not bipartite
            return;
        }
    }
}
void bfs(int node, vector<vector<int>>& g, vector<int>& color, bool &isBipartite) {
    queue<int> q;
    q.push(node);
    color[node] = 1; // Start with color 1

    while (!q.empty()) {
        int curr = q.front();
        q.pop();

        for (auto& neighbor : g[curr]) {
            if (color[neighbor] == 0) { // Only process uncolored nodes
                color[neighbor] = (color[curr] == 1) ? 2 : 1;
                q.push(neighbor);
            }
            else if (color[neighbor] == color[curr]) { // Conflict detected
                isBipartite = false;
                return;
            }
        }
    }
}

int main() {
    int V, E;
    cin >> V >> E;
    vector<vector<int>> graph(V);
    
    for (int i = 0; i < E; i++) {
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    vector<int> colorb(V, 0);
    vector<int> colord(V, 0);
    bool isBipartite = true;
    // colord[0]=1;
    // dfs(0, graph, colord, isBipartite);
    bfs(0,graph,colorb,isBipartite);
    if (isBipartite) {
        cout << "Bipartite";
    } else {
        cout << "Not Bipartite";
    }

    cout << endl;
    for (int i : colorb) {
        cout << i << " ";
    }

    return 0;
}
