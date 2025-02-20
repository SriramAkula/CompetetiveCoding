#include <bits/stdc++.h>
using namespace std;

    void extractMin(priority_queue<int,vector<int>,greater<int>>& pq){
        if(!pq.empty()) pq.pop();
    }
int main() {
    priority_queue<int,vector<int>,greater<int>> pq;
    int n;
    cin>>n;
    int k;
    cin>>k;
    for(int i=0;i<n;i++){
        int t;
        cin>>t;
        pq.push(t);
        if(pq.size()>k){
            extractMin(pq);
        }
    }
    cout<<pq.top();
    return 0;
}