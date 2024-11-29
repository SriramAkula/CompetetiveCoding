#include <bits/stdc++.h>
using namespace std;

int main() {
    int m,n;
    cin>>m>>n;
    int arr1[m];
    for(int i=0;i<m;i++){
        cin>>arr1[i];
    }
    int arr2[m];
    for(int i=0;i<m;i++){
        cin>>arr2[i];
    }
    sort(arr1,arr1+m);
    sort(arr2,arr2+m);
    int gt=arr1[m-1];
    if(arr1[m-1]<arr2[m-1]){
        gt=arr2[m-1];
        for(int i=0;i<n;i++){
            cout<<gt+arr1[i]<<" ";
        }
    }else{
        
        for(int i=0;i<n;i++){
            cout<<gt+arr2[i]<<" ";
        }

    }

    
    return 0;
}