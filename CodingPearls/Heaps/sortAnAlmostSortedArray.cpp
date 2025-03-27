#include <bits/stdc++.h>
using namespace std;

void sAsA(vector<int>& arr,int k){
    int n=arr.size();
    priority_queue<int,vector<int>,greater<int>> pq;
    for(int i=0;i<=k && i<n;i++){
        pq.push(arr[i]);
    }
    int ind=0;
    for(int i=k+1;i<n;i++){
        arr[ind++]=pq.top();
        pq.pop();
        pq.push(arr[i]);
    }
    while(!pq.empty()){
        arr[ind++]=pq.top();
        pq.pop();
    }

}

int main() {
    int n;
    cin>>n;
    vector<int> arr(n);
    int k;
    cin>>k;
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    sAsA(arr,k);
    for(int i:arr){
        cout<<i<<" ";
    }

    return 0;
}