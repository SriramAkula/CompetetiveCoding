#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    
    int arr[11]={10, 12, 20, 30, 25, 40, 32, 31, 35, 50, 60};
    int n=11;
    
    int temp[n];
    cout<<"Initial Array: ";
    for(int i=0;i<n;i++){
        temp[i]=arr[i];
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    sort(arr,arr+n);
    int s = -1, e = -1;
    for(int i=0;i<n;i++){
        if(arr[i]!=temp[i]){
            s=i;
            break;
        }
    }
    for(int i=n-1;i>=0;i--){
        if(arr[i]!=temp[i]){
            e=i;
            break;
        }
    }
    cout<<(e-s+1);

    return 0;
}