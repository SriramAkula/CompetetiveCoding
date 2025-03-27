#include <bits/stdc++.h>
using namespace std;

int main() {
    priority_queue<int,vector<int>,greater<int>> pq;

    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        int t;
        cin>>t;
        pq.push(t);
    }
    int sum=0;
    while(pq.size()!=1){
        int f=pq.top();
        pq.pop();
        int s=pq.top();
        pq.pop();
        int cost=f+s;
        pq.push(cost);
        sum+=cost;
    }
    cout<<sum;
    return 0;
}