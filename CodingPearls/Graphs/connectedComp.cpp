#include <bits/stdc++.h>
using namespace std;

int v[4][4] = {
    {1, 1, 0, 0}, 
    {1, 1, 0, 0},
    {0, 0, 1, 0}, 
    {0, 0, 0, 1}  
};

void dfs(int node, vector<bool>& visited, vector<int> g[]) {
    if (visited[node]) return;
    visited[node] = true;
    for (int neighbor : g[node]) {
        if (!visited[neighbor]) {
            dfs(neighbor, visited, g);
        }
    }
}
int findComponents(vector<int> g[],vector<bool>& visited){
    int c = 0;
    
    for (int i = 0; i < 4; i++) {
        if (!visited[i]) {
            c++;
            dfs(i, visited, g);
        }
    }
    return c;

}
int main() {
    vector<int> graph[4];

    for (int i = 0; i < 4; i++) {
        for (int j = i; j < 4; j++) {
            if (v[i][j] == 1) {
                graph[i].push_back(j);
                graph[j].push_back(i);
            }
        }
    }

    vector<bool> visited(4, false);
    int res=findComponents(graph,visited);
    cout<<res;
    return 0;
}
