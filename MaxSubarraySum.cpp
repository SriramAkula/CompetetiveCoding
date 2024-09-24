#include <bits/stdc++.h>
using namespace std;

int main() {
    int arr[]={10,0,-8,-9,4,5,-3,8};
    int rsum=INT_MIN;
    int maxSum=INT_MIN;
    for(int i:arr){
        rsum=max(rsum+i,i);
        maxSum=max(maxSum,rsum);
    }
    cout<<maxSum;
    
    return 0;
}