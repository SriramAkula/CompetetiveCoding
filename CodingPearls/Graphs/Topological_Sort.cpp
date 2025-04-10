// O(V+E)
// O(V+E)

#include <bits/stdc++.h>
using namespace std;


bool TopSort(vector<int> graph[],vector<int>& indegree){
    queue<int> q;
    int c=0;
    for(int i=0;i<indegree.size();i++){
        if(indegree[i]==0){
            q.push(i);
            c++;
        }
    }
    while(!q.empty()){
        int vertex=q.front();
        q.pop();
        for(auto& neighbor:graph[vertex]){
            indegree[neighbor]--;
            if(indegree[neighbor]==0){
                q.push(neighbor);
                c++;
            }
        }
    }
    return c==indegree.size();
}

int main() {
    int n;
    cin>>n;
    int e;
    cin>>e;
    vector<pair<int,int>> lis;
    for(int i=0;i<e;i++){
        int u,v;
        cin>>u>>v;
        lis.push_back({u,v});
    }
    vector<int> graph[n];
    vector<int> indegree(n,0);
    for(auto& it:lis){
        graph[it.second].push_back(it.first);
        indegree[it.first]++;
    }
    cout << (TopSort(graph, indegree) ? "No Cycle" : "Cycle Detected");

    return 0;
}