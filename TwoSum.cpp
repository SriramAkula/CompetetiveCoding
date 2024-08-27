#include <bits/stdc++.h>
using namespace std;

int main() {
    int n=5;
    int arr[n]={1,4,7,2,4};
    sort(arr,arr+n);
    int i=0;
    int j=n-1;
    int target;
    cin>>target;
    while(i<j){
        
        int sum=arr[i]+arr[j];
        if(sum==target){
            cout<<"Found";
            break;
        }
        if(sum>target){
            j--;
        }else{
            i++;
        }
    }

    return 0;
}