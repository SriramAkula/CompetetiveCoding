#include <bits/stdc++.h>
using namespace std;

int main() {
    int m,n;
    cin>>m>>n;
    int arr[m][n];
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            cin>>arr[i][j];
        }
    }
    int left=0,top=0;
    int bottom=m-1;
    int right=n-1;
    vector<int> v;
    while(left<=right && top<=bottom){
        for(int i=left;i<=right;i++){
            v.push_back(arr[top][i]);
        }
        top++;
        for(int i=top;i<=bottom;i++){
            v.push_back(arr[i][right]);
        }
        right--;
        if(top<=bottom){

            for(int i=right;i>=left;i--){
                v.push_back(arr[bottom][i]);
            }
            bottom--;
        }
        if(left<=right){

            for(int i=bottom;i>=top;i--){
                v.push_back(arr[i][left]);
            }
            left++;
        }
    }
    for(int i:v){
        cout<<i<<" ";
    }
    return 0;
}