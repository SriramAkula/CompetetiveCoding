#include <bits/stdc++.h>
using namespace std;

int v[4][4]={{1,1,1,0},
               {1,1,1,0},
               {1,1,1,1},
               {0,0,1,1}     
            };
void dfs(int node,bool visited[]){
    if(visited[node]) return;
    cout<<node<<" ";
    visited[node]=true;
    for(int i=0;i<4;i++){
        if(v[node][i]==1){
            dfs(i,visited);
        }
    }
}   
void dfs1(int node,vector<int> g[],bool visited[]){
    if(visited[node]) return;
    cout<<node<<" ";
    visited[node]=true;
    for(int neighbor:g[node]){
        if(!visited[neighbor]){
            dfs1(neighbor,g,visited);
        }
    }
}   
int main() {
    bool visited[4]={};
    vector<int> graph[4];
    for(int i=0;i<4;i++){
        for(int j=i+1;j<4;j++){
            if(v[i][j]==1){
                graph[i].push_back(j);
                graph[j].push_back(i);
            }
        }
    }
    dfs1(0,graph,visited);
    return 0;
}