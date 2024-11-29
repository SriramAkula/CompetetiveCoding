#include <iostream>
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
    int dir=0;
    int r=0;
    int c=0;
    int res[m*n];
    int ind=0;
    while(ind<m*n){
        res[ind]=arr[r][c];
        ind++;
        if(dir==0){
            if(c==n-1){
                dir=1;
                r++;
            }else if(r==0){
                dir=1;
                c++;
            }else{
                r--;
                c++;
            }
        }else if(dir==1){
            if(r==m-1){
                c++;
                dir=0;
            }else if(c==0){
                r++;
                dir=0;
            }else{
                c--;
                r++;
            }
        }
    }
    for(int i=0;i<m*n;i++){
        cout<<res[i]<<" ";
    }
    return 0;
}