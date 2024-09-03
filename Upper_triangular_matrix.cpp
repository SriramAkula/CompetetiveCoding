#include <iostream>
using namespace std;

int main() {
    int n=4;
    int arr[n][n]={{1,2,3,4},{5,6,7,8},{9,10,11,12},{13,14,15,16}};
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(i>j){
                arr[i][j]=0;
            }
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(i>j){
                continue;
            }else{

                cout<<arr[i][j]<<" ";
            }
        }
        cout<<endl;
    }

    return 0;
}