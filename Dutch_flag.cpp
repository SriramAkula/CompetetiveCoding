#include <iostream>
using namespace std;

int main() {
    int n=5;
    int arr[n]={0,2,1,0,1};
    int l=0;
    int m=0;
    int r=n-1;
    while(m<=r){
        if(arr[m]==2){
            swap(arr[r],arr[m]);
            r--;
            
        }
        else if(arr[m]==0){
            swap(arr[l],arr[m]);
            l++;
            m++;
        }else{
            m++;
        }
        
    }
    for(int i:arr){
        cout<<i<<" ";
    }
    return 0;
}