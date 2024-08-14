#include <iostream>
using namespace std;

void display(int arr[],int n){
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
}
void deleteA(int arr[],int &n,int pos){
    for(int i=pos-1;i<n-1;i++){
        arr[i]=arr[i+1];
    }
    n--;

}
int main() {
    int n;
    cin>>n;
    int arr[n];

    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int pos,val;
    cout<<"Pos: ";
    cin>>pos;
    deleteA(arr,n,pos);
    display(arr,n);
    return 0;
}