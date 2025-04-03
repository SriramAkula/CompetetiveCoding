#include <bits/stdc++.h>
using namespace std;

int v[4][4]={{1,1,1,0},
               {1,1,1,0},
               {1,1,1,1},
               {0,0,1,1}     
            };
void bfs(int start){
    queue<int> q;
    bool visited[4]={};
    q.push(start);
    visited[start]=true;
    while(!q.empty()){
        int node=q.front();
        q.pop();
        cout<<node<<" ";
        for(int i=0;i<4;i++){
            if(v[node][i]==1 && !visited[i]){
                q.push(i);
                visited[i]=true;
            }
        }
    }
}   
void bfs1(int start,vector<int> g[]){
    queue<int> q;
    bool visited[4]={};
    q.push(start);
    visited[start]=true;
    while(!q.empty()){
        int node=q.front();
        q.pop();
        cout<<node<<" ";
        for(int neighbor:g[node]){
            if(!visited[neighbor]){
                q.push(neighbor);
                visited[neighbor]=true;
            }
        }
    }
}   
int main() {
    vector<int> graph[4];
    for(int i=0;i<4;i++){
        for(int j=0;j<4;j++){
            if(v[i][j]==1){
                graph[i].push_back(j);
                graph[j].push_back(i);
            }
        }
    }
    bfs1(0,graph);
    return 0;
}