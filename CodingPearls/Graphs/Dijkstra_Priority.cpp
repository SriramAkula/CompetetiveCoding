#include <iostream>
#include <vector>
#include <queue>
#include<bits/stdc++.h>
using namespace std;

void Dijkstra(int start, vector<pair<int, int>> graph[], vector<int>& dist) {
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, start});
    dist[start] = 0;

    while (!pq.empty()) {
        int node=pq.top().second;
        int nodeDist=pq.top().first;
        pq.pop();
        for(auto& edge:graph[node]){
            int neighbor=edge.first;
            int wt=edge.second;
            if(nodeDist+wt<dist[neighbor]){
                dist[neighbor]=nodeDist+wt;
                pq.push({dist[neighbor],neighbor});
            }
        }
    }
}

int main() {
    int V, E;
    cin >> V >> E;
    vector<pair<int, int>> graph[V];

    for (int i = 0; i < E; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        graph[u].push_back({v, w});
    }

    vector<int> distance(V, INT_MAX);
    int start = 0;
    Dijkstra(start, graph, distance);

    cout << "Shortest distances from node " << start << ":\n";
    for (int i = 0; i < V; i++) {
        cout << "To node " << i << ": ";
        if (distance[i] == INT_MAX) cout << "Unreachable\n";
        else cout << distance[i] << "\n";
    }

    return 0;
}
