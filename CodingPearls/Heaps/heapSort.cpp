#include <bits/stdc++.h>
using namespace std;

void heapify(vector<int>& arr,int n,int i){
    int largest=i;
    int left=2*i+1;
    int right=2*i+2;
    if(left<n && arr[left]>arr[largest]){
        largest=left;
    }
    if(right<n && arr[right]>arr[largest]){
        largest=right;
    }
    if(largest!=i){
        swap(arr[largest],arr[i]);
        heapify(arr,n,largest);
    }
}
void heapSort(vector<int>& arr){
    int n=arr.size();
    for(int i=(n/2)-1;i>=0;i--){
        heapify(arr,n,i);
    }
    for(int i=n-1;i>=0;i--){
        swap(arr[0],arr[i]);
        heapify(arr,i,0);
    }
}

int main() {
    vector<int> v={4,3,2,5,1};
    heapSort(v);
    for(int i:v){
        cout<<i<<" ";
    }
    return 0;
}