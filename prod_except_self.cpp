#include <iostream>
using namespace std;

int main() {
    int n=4;
    int arr[n]={1,2,3,4};
    int L[n],R[n];
    L[0]=1;
    R[n-1]=1;
    int lp=1;
    for(int i=1;i<n;i++){
        lp=lp*arr[i-1];
        L[i]=lp;
    }
    int rp=1;
    for(int i=n-2;i>=0;i--){
        rp=rp*arr[i+1];
        R[i]=rp;
    }
    for(int i=0;i<n;i++){
        cout<<L[i]*R[i]<<" ";
    }
    return 0;
}