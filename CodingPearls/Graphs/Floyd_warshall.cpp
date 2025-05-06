#include <bits/stdc++.h>
using namespace std;

void floyd_warshall(vector<vector<int>>& g){
    int v=g.size();
    for(int k=0;k<v;k++){
        for(int i=0;i<v;i++){
            for(int j=0;j<v;j++){
                if(g[i][k]!=INT_MAX && g[k][j]!=INT_MAX){
                    if(g[i][j]>g[i][k]+g[k][j]){
                        g[i][j]=g[i][k]+g[k][j];
                    }
                }
            }
        }
    }
}

int main() {
    int V;
    int E;
    cin>> V>>E;
    vector<vector<int>> g(V,vector<int>(V,INT_MAX));
    for(int i=0;i<E;i++){
        int u,v,wt;
        cin>>u>>v>>wt;
        g[u][v]=wt;
    }
    floyd_warshall(g);
    for(auto& i:g){
        for(int j:i){
            cout<<j<<" ";
        }
        cout<<endl;
    }


    return 0;
}