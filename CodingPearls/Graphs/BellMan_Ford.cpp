#include <bits/stdc++.h>
using namespace std;


void bellMan(vector<pair<int,int>> g[],vector<int>& dist,int V){
    dist[0]=0;
    for(int i=0;i<V-1;i++){
        for(int u=0;u<V;u++){
            for(auto& neighbor:g[u]){
                int currNode=neighbor.first;
                int wt=neighbor.second;
                if (dist[u]!=INT_MAX && dist[u]+wt<dist[currNode]) {
                    dist[currNode] = dist[u] + wt;
                }
            }
        }
    }
    for (int u=0; u<V; u++) {
        for (auto& neighbor:g[u]) {
            int currNode=neighbor.first;
            int wt=neighbor.second;
            if (dist[u]!=INT_MAX && dist[u]+wt < dist[currNode]) {
                cout << "Negative weight cycle detected!" << endl;
                return;
            }
        }
    }
}

int main() {
    int V;
    int E;
    cin>>V>>E;
    vector<pair<int,int>> graph[V];
    for(int i=0;i<E;i++){
        int u,v,wt;
        cin>>u>>v>>wt;
        graph[u].push_back({v,wt});
    }
    vector<int> dist(V,INT_MAX);
    bellMan(graph,dist,V);
    cout<<"Final Dist Vector: "<<endl;
    for(auto& i:dist){
        cout<<i<<" ";
    }
    return 0;
}