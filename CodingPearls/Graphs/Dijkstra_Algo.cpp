#include <bits/stdc++.h>
using namespace std;

int findMin(vector<int> dist,vector<bool> vis){
    int minI=-1;
    int minVal=INT_MAX;
    for(int i=0;i<vis.size();i++){
        if(!vis[i]){
            if(dist[i]<minVal){
                minI=i;
                minVal=dist[i];
            }
        }
    }
    return minI;
}
void DijKstra(int node,vector<pair<int,int>> graph[],vector<bool>& vis,vector<int>& dist){
    if(node==-1){
        return;
    }
    vis[node]=true;
    for(auto& edge:graph[node]){
        if(dist[edge.first]>dist[node]+edge.second){
            dist[edge.first]=dist[node]+edge.second;
        }
    }
    int minI=findMin(dist,vis);
    DijKstra(minI,graph,vis,dist);

}

int main() {
    int V;
    int E;
    cin>>V;
    cin>>E;
    vector<pair<int,int>> graph[V];
    for(int i=0;i<E;i++){
        int u,v,w;
        cin>>u>>v>>w;
        graph[u].push_back({v,w});
    }

    vector<bool> visited(V,false);
    vector<int> distance(V,INT_MAX);
    int start=0;
    visited[start]=true;
    distance[start]=0;
    DijKstra(start, graph, visited, distance);
    cout << "Shortest distances from node " << start << ":\n";
    for (int i = 0; i < V; i++) {
        cout << "To node " << i << ": ";
        if (distance[i] == INT_MAX) cout << "Unreachable\n";
        else cout << distance[i] << "\n";
    }
    return 0;
}