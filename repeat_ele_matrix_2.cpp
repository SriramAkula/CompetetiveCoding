#include <iostream>
using namespace std;

int main() {
    int m=4;
    int n=4;
    int arr[m][n]={{1,2,1,1},{2,4,1,1},{5,1,2,1},{6,2,1,1}};
    for(int k=0;k<4;k++){
        int target=arr[0][k];
        int cnt=0;
    
    for(int i=1;i<m;i++){
        bool check=false;
        for(int j=0;j<n;j++){
            if(target==arr[i][j]){
                arr[i][j]=-1;
                cnt++;
                check =true;
                break;
            }
        }
        if(check!=true){
            break;
        }
    }
        if(cnt==m-1){
            cout<<target<<" ";
        }
    }
    return 0;
}