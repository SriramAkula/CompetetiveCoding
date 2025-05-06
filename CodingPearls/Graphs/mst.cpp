
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Edge {
    int u, v, weight;
    bool operator<(const Edge& other) const {
        return weight < other.weight;
    }
};

int find(int u, vector<int>& parent) {
    if (u != parent[u])
        parent[u] = find(parent[u], parent);
    return parent[u];
}

void unite(int u, int v, vector<int>& parent, vector<int>& rank) {
    int pu = find(u, parent);
    int pv = find(v, parent);
    if (rank[pu] < rank[pv])
        parent[pu] = pv;
    else if (rank[pu] > rank[pv])
        parent[pv] = pu;
    else {
        parent[pv] = pu;
        rank[pu]++;
    }
}

int main() {
    int V, E;
    cout << "Enter number of vertices and edges: ";
    cin >> V >> E;
    vector<Edge> edges(E);
    cout << "Enter edges (u v weight):" << endl;
    for (int i = 0; i < E; i++)
        cin >> edges[i].u >> edges[i].v >> edges[i].weight;

    sort(edges.begin(), edges.end());
    vector<int> parent(V), rank(V, 0);
    for (int i = 0; i < V; i++)
        parent[i] = i;

    int mstWeight = 0;
    cout << "Edges in MST:" << endl;
    for (auto& e : edges) {
        if (find(e.u, parent) != find(e.v, parent)) {
            cout << e.u << " - " << e.v << " (" << e.weight << ")" << endl;
            mstWeight += e.weight;
            unite(e.u, e.v, parent, rank);
        }
    }
    cout << "Total weight of MST: " << mstWeight << endl;
    return 0;
}
