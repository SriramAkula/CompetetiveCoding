#include <iostream>
using namespace std;


void insert(int arr[], int& n, int x, int pos) {
    for (int i = n; i >=pos; i--) {
        arr[i] = arr[i-1];
    }
    arr[pos-1] = x;
    n++;
}
void del(int *arr,int &n,int pos){
    for(int i=pos-1;i<n-1;i++){
        arr[i]=arr[i+1];
    }
    n--;
}
void display(int arr[],int n){
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}
void arrange(int arr[],int n){
    int ind=0;
    int res[n];
    for(int i=0;i<n;i++){
        if(arr[i]%2==0){
            res[ind++]=arr[i];
        }
    }
    for(int i=0;i<n;i++){
        if(arr[i]%2!=0){
            res[ind++]=arr[i];
        }
    }
    for(int i=0;i<n;i++){
        arr[i]=res[i];
    }
    

}
int main() {
    int n=5;
    int arr[n]={71,2,3,4,5};
    // insert(arr,n,7,3);
    // display(arr,n);
    // del(arr,n,2);
    // display(arr,n);
    arrange(arr,n);
    display(arr,n);
    return 0;
}