#include <iostream>
using namespace std;

void insert(int arr[],int &n,int pos,int val){
    n++;
    for(int i=n;i>=pos;i--){
        arr[i]=arr[i-1];
    }
    arr[pos-1]=val;
}
void display(int arr[],int n){
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
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
    cout<<"Val: ";
    cin>>val;
    insert(arr,n,pos,val);
    display(arr,n);
    return 0;
}