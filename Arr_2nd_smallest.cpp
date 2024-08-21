#include <iostream>
using namespace std;

int Sec_Smallest(int arr[],int n){
    int s_idx=0;
    int sec_sidx=-1;
    for(int i=1;i<n;i++){
        if(arr[i]<arr[s_idx]){
            sec_sidx=s_idx;
            s_idx=i;
        }
    }
    return sec_sidx;
}

int main() {
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    cout<<Sec_Smallest(arr,n);
    return 0;
}