#include <iostream>
using namespace std;

int main() {
    int m=3;
    int n=5;
    int arr[m][n]={{1,2,3,4,5},{6,7,8,9,10},{11,12,13,14,15}};

    int top=0;
    int bottom=m-1;
    int left=0;
    int right=n-1;
    int index=0;
    int result[(m*n)];
    while(top<=bottom && left<=right){

        for(int i=left;i<=right;i++){
            result[index]=arr[top][i];
            index++;
        }
        top++;
        for(int i=top;i<=bottom;i++){
            result[index]=arr[i][right];
            index++;
        }
        right--;
        if(top<=bottom){

            for(int i=right;i>=left;i--){
                result[index]=arr[bottom][i];
                index++;
            }
            bottom--;
        }
        if(left<=right){

            for(int i=bottom;i>=top;i--){
                result[index]=arr[i][left];
                index++;
            }
            left++;
        }
    }
    for(int i=0;i<(m*n);i++){
        cout<<result[i]<<" ";
    }

    return 0;
}