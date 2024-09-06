#include <iostream>
using namespace std;

int main() {
    // int arr[3][3]={{1,2,5},{3,4,6},{7,8,9}};
    // int m=3;
    // int n=3;
    int m;
    int n;
    cin>>m>>n;
    int arr[m][n];
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            cin>>arr[i][j];
        }
    }
    int res[m*n];
    int index=0;
    int dir=0;
    int r=0;
    int c=0;
    while(index<m*n){
        res[index]=arr[r][c];
        index++;
        if(dir==0){
            if(c==n-1){
                dir=1;
                r++;
            }
            else if(r==0){
                dir=1;
                c++;
            }
            else{
                r--;
                c++;
            }
        }
        else if(dir==1){
            if(r==m-1){
                
                dir=0;
                c++;
            }
            else if(c==0){
                dir=0;
                r++;
                
            }
            else{
                r++;
                c--;
            }
        }
    }
    for(int i=0;i<m*n;i++){
        cout<<res[i]<<" ";
    }
    return 0;
}