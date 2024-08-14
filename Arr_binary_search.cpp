#include <iostream>
using namespace std;
int bin_search(int arr[],int n,int k){
    int l=0;
    int r=n;
    // int mid=l+r/2;
    while(l<=r){
        int mid=(l+r)/2;
        if(arr[mid]==k) return mid;
        else if(arr[mid]>k){
            r=mid-1;
        }
        else if(arr[mid]<k){
            l=mid+1;
        }
        else{
            return -1;
        }
        mid=r+l/2;
    }
}
int main() {
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];

    }
    cout<<bin_search(arr,n,4);

    return 0;
}