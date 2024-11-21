#include <iostream>
using namespace std;
int partition(int *arr,int low,int high){
    int pivot=arr[high];
    int i=low-1;
    for(int j=low;j<high;j++){
        if(arr[j]<=pivot){
            i++;
            swap(arr[i],arr[j]);
        }
    }
    swap(arr[i+1],arr[high]);
    return i+1;
}
void qSort(int *arr,int low,int high){
    if(low<high){
        int pi=partition(arr,low,high);
        qSort(arr,low,pi-1);
        qSort(arr,pi+1,high);
    }
}
int main() {
    int arr[] = {12, 11, 13, 5, 6, 7};
    int n = 6;

    cout << "Given array: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    qSort(arr, 0, n - 1);

    cout << "Sorted array: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}