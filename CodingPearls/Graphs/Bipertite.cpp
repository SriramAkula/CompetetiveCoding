#include <bits/stdc++.h>
using namespace std;



bool dfs(int node,vector<int> g[],vector<int>& color,int flag){
    if(flag==1){
        color[node]=1;
        flag=0;
    }else{
        color[node]=2;
        flag=1;
    }

    for(auto& neighbor:g[node]){
        if(color[neighbor]==0){
            if (!dfs(neighbor, g, color, flag)) return false;
        }
        if(color[node]==color[neighbor]){
            return false;
        }
    }
    return true;
}

int main() {
    int V;
    int E;
    cin>>V>>E;
    vector<int> graph[V];
    for(int i=0;i<E;i++){
        int u,v;
        cin>>u>>v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    vector<int> color(V,0);
    int start=0;
    bool flag=1;
    bool res=dfs(start,graph,color,flag);
    if(res){
        cout<<"Bipertite";
    }else{
        cout<<"Not Bipertite";
    }
    cout<<endl;
    for(int i:color){
        cout<<i<<" ";
    }
    return 0;
}