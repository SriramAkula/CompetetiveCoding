#include <iostream>
using namespace std;

void reverse(int arr[],int st,int end){
    while(st<end){
        swap(arr[st],arr[end]);
        st++;
        end--;
    }
}
void display(int arr[],int n){
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

void rotateArr(int arr[], int k, int n) {
    k = k % n; 
    reverse(arr, 0, k - 1);   
    reverse(arr, k, n - 1);   
    reverse(arr, 0, n - 1);    
}

int main() {
    int n;
    cin>>n;

    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }

    // reverse(arr,0,n-1);
    // display(arr,n);
    rotateArr(arr,3,n);
    display(arr,n);
    return 0;
}